#include <ncurses.h>

int	main (int ac, char **av) {

initscr();	// starts curses mode
cbreak();	// no buffering
noecho();
//nodelay(stdscr, TRUE);	// getch doesn't wait

printw("Hello Raspberry Farm!");
refresh();

getch();

endwin();
return 0; }
