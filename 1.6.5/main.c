#include <stdio.h>
#include <limits.h>

#define ROW_MAX 250
#define COL_MAX 250

void clear_image(int (*image)[COL_MAX], int rows, int cols)
{
	int i, j;

	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			image[i][j] = 0;
}

int
main()
{
	char cmd;
	char params[64];
	int rows = INT_MAX;
	int cols = INT_MAX;
	int image[ROW_MAX][COL_MAX] = {0};

	while (scanf(" %c %[^\n]s", &cmd, params) != EOF) {
		switch (cmd) {
		case 'I':
			/* TODO: check errors */
			sscanf(params, "%d %d", &cols, &rows);
			clear_image(image, rows, cols);
			break;
		case 'C':
			break;
		case 'L':
			printf("Got L command, params = \"%s\"\n", params);
			break;
		case 'V':
			break;
		case 'H':
			break;
		case 'K':
			break;
		case 'F':
			break;
		case 'S':
			printf("Got S command, params = \"%s\"\n", params);
			break;
		case 'X':
			break;
		default:
			/* unrecognized command */
			return -1;
		}
	}

	return 0;
}
