#include <ncurses.h>

int	main (int ac, char **av) {

char	c;

initscr();	// starts curses mode
cbreak();	// no buffering
noecho();
//nodelay(stdscr, TRUE);	// getch doesn't wait
curs_set(0);	// no cursor

menu:
erase();
printw("Hello Raspberry Farm!\n\n");
printw("t - tutorial\n");
printw("n - new game\n");
printw("s - saves\n");
printw("a - about\n");
printw("q - quit\n");
refresh();

while(1) {
	c = getch();
	switch (c) {
	case 't':
		break;
	case 'n':
		break;
	case 's':
		erase();
		printw("Hello Raspberry Farm!\n\n");
		printw("Saves:\n\n");
		printw("b - back\n");
		c = getch();
		switch(c) {
		case 'b':
			goto menu;
		}
		break;
	case 'a':
		erase();
		printw("Hello Raspberry Farm!\n\n");
		printw("    This little game was coded by Tezzeret Houston.\n");
		printw("Find me on GitHub @tezzerethouston.\n\n");
		printw("    It is a simulation game, where the player takes\n");
		printw("care of a small raspberry farm.\n\n");
		printw("b - back\n");
		while((c = getch())!='b');
		goto menu;
	case 'q':
		goto exit;
	}
}

exit:
endwin();
return 0; }
