#include "common.h"
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>

int main(int argc, char **argv) {
	int rows = ROWS;
	int cols = COLS;
	int dist[rows][cols];
	int i = 0, j = 0;
	while (i < rows) {
		while (j < cols) {
			dist[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	char *out = "out.txt";
	if (!(argc == 2 || argc == 3)) {
		printf("Format: ./dvrouting <fileName> <output file>\n");
		return -1;
	}
	char *file = argv[1];
	if (argc == 3) {
		out = argv[2];
	}
	FILE *inFile, *fOut;
	char *line;
	char *token;
	size_t length = 0;
	char node1, node2;
	int distance;
	char substr[5];
	if ((inFile = fopen(file, "r")) == NULL) {
		printf("File Error.\n");
	return 0;
	}

	if ((fOut = fopen(out, "w")) == NULL) {
		printf("Output file cannot be opened. \n");
		return 0;	
	}
	if (getline(&line, &length, inFile) != -1) {
		size_t a = 0;
		token = strtok(line, ",");
		node1 = token[0];
		memcpy(substr, &token[4], 5);
		distance = (int) (atoi(substr));
		if (node1 > 97) {
			node1 -= 32;
		}
		dist[node1 - 65][node1 - 65] = distance;
		token = strtok(NULL, ","); 
		while(token != NULL) {
			node1 = token[1];
			memcpy(substr, &token[5], 5);
			distance = (int) (atoi(substr));
			if (node1 > 97) {
				node1 -= 32;
			}
			dist[node1 - 65][node1 - 65] = distance;
			token = strtok (NULL, ",");
		}
	}
	printMatrix(dist, 0, fOut);
	int c = 1; 
	while (getline(&line, &length, inFile) != -1) {
		token = strtok(line, ";");
		while (token != NULL) {
			node1 = token[1];
			node2 = token[3];
			memcpy(substr, &token[5], 5);
			distance = (int) atoi(substr);
			if (node1 > 97) {
				node1 -= 32;
			}
			if (node2 > 97) {
				node2 -= 32;
			}
			if (node1 - 65 == 0) {node1 = node2;}
			dist[node2 - 65][node1 - 65] = distance;
			token = strtok(NULL, ";");
		}	
	printMatrix(dist, c, fOut);
	c++;
	}
}
