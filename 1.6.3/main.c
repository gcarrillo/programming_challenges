#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define MAX_NUM_STUDENTS 1000
#define CENTS_PER_DOLLAR 100
#define MILLS_PER_CENT 10

int
main(int argc, char **argv)
{
	int num_students, i;
	uint64_t mills, avg, sum, spent[MAX_NUM_STUDENTS];
	int dollars, cents;

	while (scanf("%d", &num_students) != EOF) {
		if (num_students == 0)
			break;

		sum = 0;

		for (i = 0; i < num_students; i++) {
			scanf("%d.%d", &dollars, &cents);
			/* Work with mills (tenths of a cent) in order to
			 * account for rounding errors when computing the
			 * average with integers
			 */
			mills = (dollars * CENTS_PER_DOLLAR + cents) *
				MILLS_PER_CENT;
			spent[i] = mills;
			sum += mills;
		}

		/* Compute average number of mills spent */
		avg = sum / num_students;

		/* Check the least significant digit and round up in the next
		 * place if necessary
		 */
		if (avg % 10 >= 5)
			avg += 10;

		/* Convert from mills to cents */
		avg /= 10;

		sum = 0;
		for (i = 0; i < num_students; i++) {
			/* Convert student's spend from mills to cents */
			spent[i] /= 10;

			if (spent[i] > avg)
				sum += spent[i] - avg;
		}

		cents = sum % 100;
		dollars = sum / 100;

		printf("$%d.%02d\n", dollars, cents);
	}

	return 0;
}
