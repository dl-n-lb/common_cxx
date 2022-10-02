# utils
## index
- [cmd parser](#cmd-parser)
- [ncurses app](#ncurses-app)

## cmd parser
### about
A simple command line argument parser.
**NOTE**:
- All options passed in must have unique first letters due to the nature of the argument shortening (FIXME)
- Be aware that this parser exposes a single macro to the user in the form of `with_default(val)` which is a simple stringify macro, since type erasure is done by converting to string.
  - This can be disabled by defining `#OPT_NO_MACRO` before including the file.
- User must provide template specialisations of `auto make<T>(std::string) -> T` in order to use any types other than (currently) int and string as outputs for the parser
### linking
It is a header only utility, so simply include the file to use in your projects

### usage
To use the parser, first create and initialize an `OptParser` object, then add the options using the 
`add_options(name, description, default value = none)` function, and then using the `()` operator repeatedly, resulting in code similar to 
the following:
```cpp
OptParser opt{};
opt.add_options()("width", "the width of the screen in pixels");
```

To pass in a default argument, pass in an argument to the  `default value` parameter of `add_options`:
```cpp
opt.add_options()("height", "the height of the screen in pixels", value(with_default(600)));
```
Note that the default set in this way must be a compile time value, as `with_default` will simply stringify the value passed in.
In order to get more consistent behaviour, it may be better to define your own function to pass in a value,
or simply pass in the string as in:
```cpp
opt.add_options()("particle-count", "the number of particles", value("200");
```

### TODO:
- Make it s.t. individual arguments can specify their own shortening
- Along w this, make it s.t. shortened versions needn't be single characters (perhaps)
- ADD THE PROPER HELP COMMAND (URGENT)


## ncurses app
### about 
simple wrapper around the ncurses api (WIP)
**NOTE**
this literally does nothing at the moment

###linking
this is a header only utility, so just include the file to use it in your projects

### usage 
To use, create an ncurses app using:
```cpp
NCursesApp app{};
```

And then run:
```cpp
fun = [=](WINDOW*, char) {... event function};
app.loop(fun);
```
To run the app. The app will automatically close on the exit button press.
To set the exit button use:
```cpp
app.set_exit_key(char key);
```
The default key is 'q' (not 'Q'!).

### TODO:

