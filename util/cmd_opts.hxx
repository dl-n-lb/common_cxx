#ifndef OPT_PARSER_HXX_
#define OPT_PARSER_HXX_

#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>
#include <memory>
#include <optional>
#include <type_traits>
#include <cassert>
#include <cmath>

#include "../types/type_alias.hxx"
#ifndef OPT_NO_MACRO
#define with_default(val) #val // little bit of macro >:)
#endif
// OptParser is a class that parses command line options 
// by overloading the make function with any custom type 
// OptParser can be made to accept that type as well, 
// though behaviour with the with_default macro may be strange
// the macro is used because I am lazy and didn't like my 
// other solution which required double inheritance for 
// dynamic polymorphism but didn't make using the libary less janky

// MAKE is like a cast but funny
template<typename T>
T make(str val) {
  return static_cast<T>(val);
}

template<>
u32 make(str val) {
  u32 digit = pow(10, val.size()-1);
  u32 result = 0;
  for (auto c : val) {
    auto adj = c - '0';
    if (adj > 9 || adj < 0) {
      fprintf(stderr, "Invalid integral provided\nProvided: %s\n", val.c_str());
      exit(1);
    }
    result += digit * adj; 
    digit /= 10;
  }
  return result;
}

template<>
str make(str val) {
  return val;
}

// Option Parser class
// REQUIRES: Each option has a unique first letter s.t they can be used as abbreviations uniquely
class OptParser {
  struct value_t {
    str default_v = "";

    template<typename T>
    std::optional<T> get() {
      return (default_v == "") ? std::nullopt : std::make_optional(make<T>(default_v));
    }
  };

  class OptAdder {
    OptParser* _parent;
  public: 
    OptAdder(OptParser* parent) : _parent(parent) {}

    OptAdder operator()(str flag, str description, value_t val = value_t{""}) {
      _parent->add_option(flag, description, val);
      return OptAdder(_parent);
    }
  };

public:
  OptParser() {}

  void add_option(str flag, str description, value_t val) {
    auto shortened = flag[0];
    if (shortened_names_to_names.count(shortened) > 0) {
      fprintf(stderr, "Flag with abbreviation %c already exists.\n", shortened);
      exit(1);
    }
    shortened_names_to_names[shortened] = flag;
    names_to_descriptions[flag] = description;
    names_to_values[flag] = val;
  }

  OptAdder add_options() {
    return OptAdder(this);
  }

  template<typename T> 
  std::optional<T> get(str flag) const {
    if (names_to_values.count(flag) == 0) {
      fprintf(stderr, "Illegal access of flag %s, which does not exist.\n", flag.c_str());
      exit(1);
    }
    auto val = names_to_values.at(flag);
    return val.get<T>();
  }

  void print_help(char** argv) {
    printf("----------------------------------------\n");
    printf("%s help command\n", argv[0]);
    printf("-------------------------------\n");
    for (auto& it: names_to_descriptions) {
      printf("%s: %s\n", it.first.c_str(), it.second.c_str());
    }
    printf("----------------------------------------\n");
  }

  void parse_argument(str option, str argument) {
    names_to_values.at(option).default_v = argument;
  }

  void parse(i32 argc, char** argv) {
    auto parser_error = [this, argv](const char* arg_, const char* extra_msg = "") {
      fprintf(stderr, "Error: argument %s is not recognised.\n%s", arg_, extra_msg);
      print_help(argv);
      exit(1);
    };

    auto is_argument = [](const char* arg) {
      return arg[0] == '-';
    };
    auto is_long_argument = [=](const char* arg) {
      return is_argument(arg) && arg[1] == '-';
    };

    for(i32 i = 0; i < argc; ++i) {
      auto arg = argv[i];
      if (is_long_argument(arg)) { // parse full word
        if (strlen(arg) < 3) {
          parser_error(arg, "Argument cannot be empty\n");
        }
        auto name = std::string(arg+2);
        if (names_to_values.count(name) == 0) {
          if (name == std::string("help")) {
            parser_error(arg, "Help Command called:\n");
          }
          parser_error(arg);
        }
        if (i+1 == argc) {
          parser_error(arg, "No argument provided for option\n");
        }
        parse_argument(name, argv[i+1]);
      } else if (is_argument(arg))  { // parse shortened version
        if (strlen(arg) > 2) {
          parser_error(arg, "Note: use -- for longer versions of arguments\n");
        }
        if (shortened_names_to_names.count(arg[1]) == 0) {
          parser_error(arg);
        }
        if (i+1 == argc) {
          parser_error(arg, "No argument provided for option\n");
        }
        // parse the argument with its value
        parse_argument(shortened_names_to_names.at(arg[1]), argv[i+1]);
      }
    }
  }

  static value_t value(const char* default_v = "") {
    return value_t{str(default_v)};
  }

private:
  hashmap<str, str> names_to_descriptions;
  hashmap<char, str> shortened_names_to_names;
  hashmap<str, value_t> names_to_values;
};

#endif //OPT_PARSER_HXX_
