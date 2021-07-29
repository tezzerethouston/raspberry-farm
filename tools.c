#include "tools.h"

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
