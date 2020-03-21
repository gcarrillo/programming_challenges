#include <stdio.h>

struct field {
#define MAX_ROWS 100
#define MAX_COLS 100
	int rows;
	int cols;
	char mat[MAX_ROWS][MAX_COLS];
};

int
count_mines(struct field *f, int rpos, int cpos)
{
	int i, j, count = 0;

	for (i = rpos - 1; i <= rpos + 1; i++) {
		if (i < 0 || i >= f->rows)
			continue;

		for (j = cpos - 1; j <= cpos + 1; j++) {
			if (j < 0 || j >= f->cols)
				continue;

			if (f->mat[i][j] == '*')
				count++;
		}
	}

	return count;
}

void
display_field(struct field *f, int field_num)
{
	int i, j;

	printf("Field #%d:\n", field_num);

	for (i = 0; i < f->rows; i++) {
		for (j = 0; j < f->cols; j++) {
			if (f->mat[i][j] == '*')
				printf("*");
			else {
				printf("%1d", count_mines(f, i, j));
			}
		}

		printf("\n");
	}
}

int
main(int argc, char **argv)
{
	int rows, cols, i, j, field_count = 1;
	struct field f;

	while (scanf("%d %d\n", &f.rows, &f.cols) != EOF) {
		/* end of input; don't process */
		if (f.rows == 0 && f.cols == 0)
			break;

		/* read in the field */
		for (i = 0; i < f.rows; i++) {
			for (j = 0; j < f.cols; j++) {
				scanf(" %c", &f.mat[i][j]);
			}
		}

		display_field(&f, field_count++);
		printf("\n");
	}

	return 0;
}
