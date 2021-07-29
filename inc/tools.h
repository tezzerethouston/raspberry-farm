#ifndef TOOLS_H
#define TOOLS_H

#include <ncurses.h>
#include <stdio.h>

int	loadsave(int plpos[2]);
int	save(int plpos[2]);
void	displaymap(char map[][15]);
int	loadmap(char map[][15], char collision[][15]);

#endif
