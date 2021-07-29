#include "game.h"
#include "tools.h"

int	game(char a) {

char	map[6][15];
char	collision[6][15];
int	i, j;
int	plpos[2];

loadmap(map, collision);
if (a == 's') loadsave(plpos);
else { plpos[0] = 3; plpos[1] = 1; }

while (1) {
displaymap(map);
mvaddch(plpos[0], plpos[1], '@');

switch(getch()) {
case 'w':
	if (plpos[0]-1>=0 && !collision[plpos[0]-1][plpos[1]])
		plpos[0]--; break;
case 'a':
	if (plpos[1]-1>=0 && !collision[plpos[0]][plpos[1]-1])
		plpos[1]--; break;
case 's':
	if (plpos[0]+1<6 && !collision[plpos[0]+1][plpos[1]])
		plpos[0]++; break;
case 'd':
	if (plpos[1]+1<15 && !collision[plpos[0]][plpos[1]+1])
		plpos[1]++; break;
case 'S':
	save(plpos); break;
case 'q':
	endwin();
	return 0;
}
}

endwin();
return 0;
}
