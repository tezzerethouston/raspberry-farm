#ifndef TOOLS_H
#define TOOLS_H

#include <ncurses.h>
#include <stdio.h>

void	displaymap(char map[][15]);
int	loadmap(char map[][15], char collision[][15]);

#endif
