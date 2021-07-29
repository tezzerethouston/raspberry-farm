#ifndef TOOLS_H
#define TOOLS_H

#include <ncurses.h>
#include <stdio.h>

void	displayfacing(char map[][15], int plpos[2], char facing);
int	loadsave(int plpos[2], char *pfacing);
int	save(int plpos[2], char facing);
void	displaymap(char map[][15]);
int	loadmap(char map[][15], char collision[][15]);

#endif
