#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PERCISION (0.0000001)
#define MAX_ANSWER (10000)

double
sq (double x)
{
	double hi = MAX_ANSWER;
	double lo = 0;
	double h;

	while (hi - lo > PERCISION)
	{
		h = (hi + lo) / 2.0;
		if (h * h > x)
			hi = h;
		else
			lo = h;	
	}
	return h;
}

int
main (int argc, char *argv[])
{
	double x;
	if (argc != 2
		|| !(x = atof (argv[1])))
	{
		printf ("USAGE: %s <number>\n", argv[0]);
		return 0;
	}

	printf ("sq(%f) = %f (%f)\n", x,  sq (x), sqrt (x));
	return 0;
}