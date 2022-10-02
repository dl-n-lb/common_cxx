#ifndef NCURSES_APP_H_
#define NCURSES_APP_H_

#include "../types/type_alias.hxx"
#include <ncurses.h>

// NCursesApp(width, height, top_left_x, top_left_y)
// 0 width and height (default) gives a fullscreen window 
// top_left and top_right can only be set for windows smaller than fullscreen
class NCursesApp {
  WINDOW *win;

  char exit_key = 'q';

public:
  NCursesApp(const u32 width = 0, const u32 height = 0,
             const u32 tlx = 0, const u32 tly = 0) {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    if ((width || height) > 0) {
      // TODO: CHECK IF width + tlx < max width, height + tly < max height
      i32 w, h;
      getmaxyx(stdscr, h, w);
      assert(width + tlx < static_cast<u32>(w));
      assert(height + tly < static_cast<u32>(h));
      win = newwin(width, height, tlx, tly);
    } else {
      win = stdscr;
    }
  }

  void set_exit_key(char key) {
    exit_key = key;
  }

  void loop(auto key_event_function) {
    bool done = false;
    for (;!done;) {
      i32 ch = getch();
      switch (ch) {
        case exit_key: done = true; break;
        default: key_event_function(win, ch); break;
      }
      wrefresh(stdscr);
    }
  }

  ~NCursesApp() {
    endwin();
  }
};

#endif // NCURSES_APP_H_
