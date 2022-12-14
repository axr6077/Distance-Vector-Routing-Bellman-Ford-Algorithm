#ifndef __DVROUTING_H__
#define __DVROUTING_H__

#include <stdio.h>
#define ROWS 26
#define COLS 26

void printMatrix(int dist[ROWS][COLS], int time, FILE *out);

#endif
