#include "tools.h"

// --- LOAD SAVE ---
int	loadsave(int plpos[2]) {

FILE	*f;

f = fopen("save", "r");
plpos[0] = getc(f);
plpos[1] = getc(f);
fclose(f);

return 0; }

// --- SAVE ---
int	save(int plpos[2]) {

FILE	*f;

f = fopen("save", "w");
putc(plpos[0], f);
putc(plpos[1], f);
fclose(f);

return 0; }

// --- DISPLAY MAP ---
void	displaymap(char map[][15]) {

int	i, j;

erase();
for (i=0; i<6; i++) {
	for (j=0; j<15; j++)
		addch(map[i][j]);
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
