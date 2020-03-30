#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CHARS 10
#define MAP_NROWS 5
#define MAP_NCOLS 3
#define MAP_NCHARS 10

#define H '-' // horizontal segment
#define V '|' // vertical segment
#define B ' ' // blank

#define NROWS(s) ((s) * 2 + 3)
#define MIDDLE_ROW(s) ((s) + 1)
#define NCOLS(s) ((s) + 2)

/* Arrays with static storage duration require constant expressions in
 * initializer lists. This is in contrast to arrays with automatic storage
 * duration, whose initializer lists can have variables.
 */

char char_maps[MAP_NCHARS][MAP_NROWS][MAP_NCOLS] = {
	{	//zero
		{B, H, B},
		{V, B, V},
		{B, B, B},
		{V, B, V},
		{B, H, B},
	},
	{	//one
		{B, B, B},
		{B, B, V},
		{B, B, B},
		{B, B, V},
		{B, B, B},
	},
	{	//two
		{B, H, B},
		{B, B, V},
		{B, H, B},
		{V, B, B},
		{B, H, B},
	},
	{	//three
		{B, H, B},
		{B, B, V},
		{B, H, B},
		{B, B, V},
		{B, H, B},
	},
	{	//four
		{B, B, B},
		{V, B, V},
		{B, H, B},
		{B, B, V},
		{B, B, B},
	},
	{	//five
		{B, H, B},
		{V, B, B},
		{B, H, B},
		{B, B, V},
		{B, H, B},
	},
	{	//six
		{B, H, B},
		{V, B, B},
		{B, H, B},
		{V, B, V},
		{B, H, B},
	},
	{	//seven
		{B, H, B},
		{B, B, V},
		{B, B, B},
		{B, B, V},
		{B, B, B},
	},
	{	//eight
		{B, H, B},
		{V, B, V},
		{B, H, B},
		{V, B, V},
		{B, H, B},
	},
	{	//nine
		{B, H, B},
		{V, B, V},
		{B, H, B},
		{B, B, V},
		{B, H, B},
	},
};

static inline bool
is_in_region_1(int r, int c, int s)
{

	if (r == 0 && (c >= 1 && c < NCOLS(s) - 1))
		return true;

	return false;
}

static inline bool
is_in_region_2(int r, int c, int s)
{

	if ((r >= 1 && r < MIDDLE_ROW(s)) && c == 0)
		return true;

	return false;
}

static inline bool
is_in_region_3(int r, int c, int s)
{
	if ((r >= 1 && r < MIDDLE_ROW(s)) &&
	    (c >= 1 && c < NCOLS(s) - 1))
		return true;

	return false;
}

static inline bool
is_in_region_4(int r, int c, int s)
{

	if ((r >= 1 && r < MIDDLE_ROW(s)) &&
	    (c == NCOLS(s) - 1))
		return true;

	return false;
}

static inline bool
is_in_region_5(int r, int c, int s)
{
	if (r == MIDDLE_ROW(s) && (c >= 1 && c < NCOLS(s) - 1))
		return true;

	return false;
}

static inline bool
is_in_region_6(int r, int c, int s)
{
	if ((r > MIDDLE_ROW(s) && r < NROWS(s) - 1) && c == 0)
		return true;

	return false;
}

static inline bool
is_in_region_7(int r, int c, int s)
{
	if ((r > MIDDLE_ROW(s) && r < NROWS(s) - 1) &&
	    (c >= 1 && c < NCOLS(s) - 2 ))
		return true;

	return false;
}

static inline bool
is_in_region_8(int r, int c, int s)
{
	if ((r > MIDDLE_ROW(s) && r < NROWS(s) - 1) &&
	    (c == NCOLS(s) - 1))
		return true;

	return false;
}

static inline bool
is_in_region_9(int r, int c, int s)
{
	if (r == NROWS(s) - 1 &&
	    (c >= 1 && c < NCOLS(s) - 1))
		return true;

	return false;
}

char
get_segment_char(int d, int s, int row, int col)
{
	char c = B;

	if (is_in_region_1(row, col, s))
		c = char_maps[d][0][1];
	else if (is_in_region_2(row, col, s))
		c = char_maps[d][1][0];
	else if (is_in_region_3(row, col, s))
		c = char_maps[d][1][1];
	else if (is_in_region_4(row, col, s))
		c = char_maps[d][1][2];
	else if (is_in_region_5(row, col, s))
		c = char_maps[d][2][1];
	else if (is_in_region_6(row, col, s))
		c = char_maps[d][3][0];
	else if (is_in_region_7(row, col, s))
		c = char_maps[d][3][1];
	else if (is_in_region_8(row, col, s))
		c = char_maps[d][3][2];
	else if (is_in_region_9(row, col, s))
		c = char_maps[d][4][1];

	return c;
}

void
print_lcd(int s, char *str)
{
	int i, j, str_idx, d;
	char c;

	for (i = 0; i < NROWS(s); i++) {
		for (str_idx = 0; str_idx < strlen(str); str_idx++) {
			c = str[str_idx];
			d = c - '0';

			for (j = 0; j < NCOLS(s); j++) {
				putchar(get_segment_char(d, s, i, j));
			}

			putchar(B);
		}

		putchar('\n');
	}
}

int
main(int argc, char **argv)
{
	int s;
	char nstr[MAX_CHARS];

	while (scanf("%d %s", &s, nstr) != EOF) {
		if (s == 0)
			break;

		print_lcd(s, nstr);
		putchar('\n');
	}

	return 0;
}
