#include <stdio.h>
#include <stdlib.h>

//calculate hamming weight
int
weight (int a)
{
	int c;
	for (c=0;a;c++)
		a &= a - 1;

	return c;
}

int 
main (int argc, char *argv[])
{
	int a;

	if (argc != 2 || !(a = atoi (argv[1])))
	{
		printf ("USAGE: %s <int>\n", argv[0]);
		return 0;
	}

	printf ("hamming weight: %d\n", weight (a));

	return 0;
}
