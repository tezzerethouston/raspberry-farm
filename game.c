#include "game.h"
#include "tools.h"

int	game(char a) {

char	map[6][15];
char	collision[6][15];
int	i, j;
int	plpos[2];
char	facing;
int	plants[6][15];

clock_t	tstart, tend, tdiff;
int	tint;
tint = 0;

time_t	t;
srand((unsigned)time(&t));

loadmap(map, collision);
if (a == 's') loadsave(plpos, &facing, map);
else {
	plpos[0] = 3; plpos[1] = 1;
	facing = 's';
}
for (i=0; i<6; i++)
	for (j=0; j<15; j++)
		if (map[i][j] == '2') plants[i][j] = 3;
		else plants[i][j] = 0;

tstart = clock();

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
		if (plpos[0]-1>=0 && map[plpos[0]-1][plpos[1]]=='.') {
			map[plpos[0]-1][plpos[1]] = '2';
			plants[plpos[0]-1][plpos[1]] = 1; }
		break;
	case 'a':
		if (plpos[1]-1>=0 && map[plpos[0]][plpos[1]-1]=='.') {
			map[plpos[0]][plpos[1]-1] = '2';
			plants[plpos[0]][plpos[1]-1] = 1; }
		break;
	case 's':
		if (plpos[0]+1<6 && map[plpos[0]+1][plpos[1]]=='.') {
			map[plpos[0]+1][plpos[1]] = '2';
			plants[plpos[0]+1][plpos[1]] = 1; }
		break;
	case 'd':
		if (plpos[1]+1<15 && map[plpos[0]][plpos[1]+1]=='.') {
			map[plpos[0]][plpos[1]+1] = '2';
			plants[plpos[0]][plpos[1]+1] = 1; }
		break;
	}
	break;

case 'S':
	save(plpos, facing, map); break;
case 'q':
	endwin();
	return 0;
}

tend = clock();
tdiff = tend-tstart;
tstart = clock();
tint += tdiff;//* 1000 / CLOCKS_PER_SEC;
if (tint >= 1000) {
	for (i=0; i<6; i++)
		for (j=0; j<15; j++) {
			if (plants[i][j])
				plants[i][j]++;
			if (plants[i][j] > 10)
				if (!(rand()%4)) {
					map[i][j] = 'o';
					plants[i][j] = 0; }
		}
	tint -=1000;
}

}

endwin();
return 0;
}
