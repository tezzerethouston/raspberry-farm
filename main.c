#include <ncurses.h>
#include "game.h"

int	main (int ac, char **av) {

char	c;

initscr();	// starts curses mode
cbreak();	// no buffering
noecho();
//nodelay(stdscr, TRUE);	// getch doesn't wait
curs_set(0);	// no cursor

start_color();
init_pair(1, COLOR_GREEN, COLOR_BLACK);

menu:
erase();
printw("Hello Raspberry Farm!\n\n");
printw("t - tutorial\n");
printw("n - new game\n");
printw("s - load save\n");
printw("a - about\n");
printw("q - quit\n");
refresh();

while(1) {
	c = getch();
	switch (c) {
	case 't':
		return game('t');
	case 'n':
		return game('n');
	case 's':
		return game('s');
	case 'a':
		erase();
		printw("Hello Raspberry Farm!\n\n");
		printw("    This little game was coded by Tezzeret Houston.\n");
		printw("Find me on GitHub @tezzerethouston.\n\n");
		printw("    It is a simulation game, where the player takes\n");
		printw("care of a small raspberry farm.\n\n\n");
		printw("  HOW TO USE:\n\n");
		printw("  wasd - move around\n");
		printw("  p - plant raspberries\n\n");
		printw("  [shift] S - save\n");
		printw("  q - quit\n\n\n");
		printw("Press a key...\n");
		getch();
		goto menu;
	case 'q':
		goto exit;
	}
}

exit:
endwin();
return 0; }
