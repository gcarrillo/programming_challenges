#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW_MAX 250
#define COL_MAX 250

/* Optimizer will remove code for non-debug builds */
/* TODO: check this with compiler explorer */
#define dbg_pr(fmt, ...) \
	do { \
		if (DEBUG) \
			fprintf(stderr, "%s(): " fmt, __func__,  __VA_ARGS__); \
	} while (0)

#define err_pr(fmt, ...) \
	do { \
		fprintf(stderr, "error: " fmt, ##__VA_ARGS__); \
	} while (0)

void
clear_image(char (*image)[COL_MAX], int rows, int cols)
{
	int i, j;

	dbg_pr("rows = %d, cols = %d\n", rows, cols);

	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			image[i][j] = '0';
}

void
color_pixel(char (*image)[COL_MAX], int row, int col, char color)
{
	image[row][col] = color;
}

void
print_image(char *filename, char (*image)[COL_MAX], int nrows, int ncols)
{
	int i, j;

	printf("%s\n", filename);

	for (i = 0; i < nrows; i++) {
		for (j = 0; j < ncols; j++) {
			printf("%c", image[i][j]);
		}

		putchar('\n');
	}
}

int
main()
{
	char cmd;
	char params[64];
	int rows = INT_MAX;
	int cols = INT_MAX;
	char image[ROW_MAX][COL_MAX] = {0};
	int ret;

	while (scanf(" %c %[^\n]s", &cmd, params) != EOF) {
		switch (cmd) {
		case 'I':
			dbg_pr("Got I command, params = \"%s\"\n", params);

			ret = sscanf(params, "%d %d", &cols, &rows);
			if (ret != 2) {
				err_pr("bad parameters for I cmd\n");
				exit(EXIT_FAILURE);
			}

			clear_image(image, rows, cols);
			break;

		case 'C':
			break;
		case 'L':
		{
			int row, col;
			char color;

			dbg_pr("Got L command, params = \"%s\"\n", params);
			ret = sscanf(params, "%d %d %c", &row, &col, &color);
			if (ret != 3) {
				err_pr("bad parameters for L cmd\n");
				exit(EXIT_FAILURE);
			}

			color_pixel(image, col - 1, row - 1, color);

			break;
		}
		case 'V':
			break;
		case 'H':
			break;
		case 'K':
			break;
		case 'F':
			break;
		case 'S':
		{
			char filename[128];
			dbg_pr("Got S command, params = \"%s\"\n", params);

			ret = sscanf(params, "%[^\n]s", filename);
			if (ret != 1) {
				err_pr("bad parameters for S cmd\n");
				exit(EXIT_FAILURE);
			}

			print_image(filename, image, rows, cols);

			break;
		}
		case 'X':
			break;
		default:
			/* unrecognized command */
			return -1;
		}
	}

	return 0;
}
