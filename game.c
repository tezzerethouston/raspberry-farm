#include "game.h"
#include "tools.h"

int	game(char a) {

char	map[6][15];
char	collision[6][15];
int	i, j;
int	plpos[2];
char	facing;

loadmap(map, collision);
if (a == 's') loadsave(plpos, &facing, map);
else {
	plpos[0] = 3; plpos[1] = 1;
	facing = 's';
}

while (1) {

// DISPLAY
displaymap(map);
mvaddch(plpos[0], plpos[1], '@');
displayfacing(map, plpos, facing);
refresh();

// GAME
switch(getch()) {

case 'w':
	if (facing != 'w') facing = 'w';
	else if (plpos[0]-1>=0 && !collision[plpos[0]-1][plpos[1]])
		plpos[0]--; break;
case 'a':
	if (facing != 'a') facing = 'a';
	else if (plpos[1]-1>=0 && !collision[plpos[0]][plpos[1]-1])
		plpos[1]--; break;
case 's':
	if (facing != 's') facing = 's';
	else if (plpos[0]+1<6 && !collision[plpos[0]+1][plpos[1]])
		plpos[0]++; break;
case 'd':
	if (facing != 'd') facing = 'd';
	else if (plpos[1]+1<15 && !collision[plpos[0]][plpos[1]+1])
		plpos[1]++; break;

case 'p':
	switch(facing) {
	case 'w':
		if (plpos[0]-1>=0 && map[plpos[0]-1][plpos[1]]=='.')
			map[plpos[0]-1][plpos[1]] = '2';
		break;
	case 'a':
		if (plpos[1]-1>=0 && map[plpos[0]][plpos[1]-1]=='.')
			map[plpos[0]][plpos[1]-1] = '2';
		break;
	case 's':
		if (plpos[0]+1<6 && map[plpos[0]+1][plpos[1]]=='.')
			map[plpos[0]+1][plpos[1]] = '2';
		break;
	case 'd':
		if (plpos[1]+1<15 && map[plpos[0]][plpos[1]+1]=='.')
			map[plpos[0]][plpos[1]+1] = '2';
		break;
	}
	break;

case 'S':
	save(plpos, facing, map); break;
case 'q':
	endwin();
	return 0;
}
}

endwin();
return 0;
}
