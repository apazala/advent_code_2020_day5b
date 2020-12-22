#include <stdio.h>

int seats[1024];
int main() {
	char s[12];

	FILE *fin = fopen("input.txt", "r");
	if (!fin) {
		fprintf(stderr, "Unable to open input file\n");
		return 1;
	}

	while (fscanf(fin, "%s", s) == 1) {
		int id = 0;
		for (char *p = s; *p; p++) {
			id <<= 1;
			if (*p == 'B' || *p == 'R')
				id++;
		}

		seats[id] = 1;
	}

	int i = 0;
	while (i < 1024 && !seats[i])
		i++;


	while (i < 1024 && seats[i])
		i++;

	printf("%d\n", i);

	fclose(fin);
	return 0;
}