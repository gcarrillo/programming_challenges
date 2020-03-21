#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int
count_mines(char (*field)[MAX_COLS], int rows, int cols, int rpos, int cpos)
{
	int i, j, count = 0;

	for (i = rpos - 1; i <= rpos + 1; i++) {
		if (i < 0 || i >= rows)
			continue;

		for (j = cpos - 1; j <= cpos + 1; j++) {
			if (j < 0 || j >= cols)
				continue;

			if (field[i][j] == '*')
				count++;
		}
	}

	return count;
}

void
print_field(int rows, int cols, char (*field)[MAX_COLS])
{
	int i, j;

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			if (field[i][j] == '*')
				putchar('*');
			else
				printf("%d",
				       count_mines(field, rows, cols, i, j));
		}

		printf("\n");
	}
}

int
main(int argc, char **argv)
{
	int rows, cols, i, j, field_count = 1;
	char field[MAX_ROWS][MAX_COLS];

	while (scanf("%d %d", &rows, &cols) != EOF) {
		if (rows == 0 && cols == 0)
			break;

		for (i = 0; i < rows; i++)
			for (j = 0; j < cols; j++)
				scanf(" %c", &field[i][j]);

		printf("Field #%d:\n", field_count++);
		print_field(rows, cols, field);
		printf("\n");
	}

	return 0;
}
