#include <stdio.h>

int
compute_cycle_length(int n)
{
	int cycle_length = 1;

	while (n != 1) {
		n = ((n & 0x1) == 0) ? n >> 1 : n * 3 + 1;
		++cycle_length;
	}

	return cycle_length;
}

int
main(int argc, char **argv)
{
	int start, stop, i, max, len;

	while (fscanf(stdin, "%d %d", &start, &stop) != EOF) {
		max = 0;

		for (i = start; i < stop; i++) {
			len = compute_cycle_length(i);
			max = (len > max) ? len : max;
		}

		fprintf(stdout, "%d %d %d\n", start, stop, max);
	}
}
