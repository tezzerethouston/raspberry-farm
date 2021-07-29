#include "tools.h"

// --- DISPLAY FACING ---
void	displayfacing(char map[][15], int plpos[2], char facing) {

attron(A_REVERSE);
switch(facing) {
case 'w':
	if(plpos[0]-1<0)
		mvaddch(plpos[0]-1, plpos[1], ' ');
	else
		mvaddch(plpos[0]-1, plpos[1], map[plpos[0]-1][plpos[1]]);
	break;
case 'a':
	if(plpos[1]-1<0)
		mvaddch(plpos[0], plpos[1]-1, ' ');
	else
		mvaddch(plpos[0], plpos[1]-1, map[plpos[0]][plpos[1]-1]);
	break;
case 's':
	if(plpos[0]+1>=6)
		mvaddch(plpos[0]+1, plpos[1], ' ');
	else
		mvaddch(plpos[0]+1, plpos[1], map[plpos[0]+1][plpos[1]]);
	break;
case 'd':
	if(plpos[1]+1>=15)
		mvaddch(plpos[0], plpos[1]+1, ' ');
	else
		mvaddch(plpos[0], plpos[1]+1, map[plpos[0]][plpos[1]+1]);
}
attroff(A_REVERSE);

return; }

// --- LOAD SAVE ---
int	loadsave(int plpos[2], char *pfacing, char map[][15]) {

FILE	*f;
int	i, j;

f = fopen("save", "r");
plpos[0] = getc(f);
plpos[1] = getc(f);
*pfacing = getc(f);
for (i=0; i<6; i++)
	for (j=0; j<15; j++)
		map[i][j] = getc(f);
fclose(f);

return 0; }

// --- SAVE ---
int	save(int plpos[2], char facing, char map[][15]) {

FILE	*f;
int	i, j;

f = fopen("save", "w");
putc(plpos[0], f);
putc(plpos[1], f); 
putc(facing, f);
for (i=0; i<6; i++)
	for (j=0; j<15; j++)
		putc(map[i][j], f);
fclose(f);

return 0; }

// --- DISPLAY MAP ---
void	displaymap(char map[][15]) {

int	i, j;

erase();
for (i=0; i<6; i++) {
	for (j=0; j<15; j++) {
		if (map[i][j]=='2') {
			attron(COLOR_PAIR(1));
			addch(map[i][j]);
			attroff(COLOR_PAIR(1));
		}
		else addch(map[i][j]);
	}
	addch('\n');
}
refresh();

return; }

// --- LOAD MAP ---
int	loadmap(char map[][15], char collision[][15]) {

FILE	*f;
int	i, j;
char	c;

f = fopen("raspberry-farm-map", "r");
for (i=0; i<6; i++) {
	for (j=0; j<15; j++)
		map[i][j] = getc(f);
	getc(f);
}
for (i=0; i<6; i++) {
	for (j=0; j<15; j++) {
		c = getc(f);
		if (c != '1') collision[i][j] = 0;
		else collision[i][j] = 1; }
	getc(f);
}
fclose(f);

return 0; }
