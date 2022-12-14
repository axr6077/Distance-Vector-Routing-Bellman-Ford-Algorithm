#include "common.h"
#include <stdint.h>
#include <stdio.h>

int rows = ROWS;
int cols = COLS;

void printMatrix(int dist[rows][cols], int time, FILE *out) {
	int distRow[rows]; 
	int distCol[cols];
	int message[rows];
	int i = 0, j = 0;
	fprintf(out, "Time %d: \n \tDistance Table for A: \n", time);
	fprintf(out, "--------------------\n\tTo\t\t\tVia\n");
	while (i < rows) {
		distRow[i] = 0;
		distCol[i] = 0;
		message[i] = 0;
		i++;
	}

	// reset i
	i = 0;
	while (i < cols) {
		while (j < cols) {
			if (dist[i][j] != 0) {
				dist[i] = 1;
				dist[j] = 1;
			}
		j++;
		}
	i++;
	}
	//reset j
	j = 0;
	while (j < rows) {
		if (dist[j] == 1) {
				fprintf(out, "\t\t%c", 'A' + j, "\n");
			}
		j++;
	}
	i = 1;
	while (i < rows) {
		if (dist[i] == 1) {
			j = 0;
 			fprintf(out, "\t%c:", 'A' + i);
			while (j < rows) {
					if (dist[j] == 1) {
						fprintf(out, "\t\t");
						if (dist[i][j] == 0) {
								fprintf(out, "--");

							}
						else{
								int val = dist[i][j];
								if(i != j) {
										val += dist[i][j];
									}
							if ((val < dist[i][message[i]] || message[i] == 0) && dist[i])[j] != 0{
									message[i] = j;
								}
							if (val < 10) {
									fprintf(out, "	");
								}
							fprintf(out, "%u", val);
							dist[i][j] = val;
							}
					}
				j++;
				}
		fprintf(out, "\n");
		}
		i++;
	}
	fprintf("\n\tRouting Table for A: \n\t----------------------\n");
	fprintf(out, "\tDest NxtHp\n");
	i = 1;
	while(i < rows) {
		if (dist[i] == 1) {
			fprintf(out, "\t\t%c\t\t%c\n", 'A' + i, 'A' + message[i]);
		}
		i++;
	}
	fprintf(out, "\n\tMessages Sent:\n\t");
	i = 1;
	while (i < rows) {
			if (dist[i] == 1) {
				fprintf(out, "{A, %c, %u}", 'A' + i, dist[i][message[i]]);
			}
			i++;
		}
		fprintf(out, "\n\n");
}
