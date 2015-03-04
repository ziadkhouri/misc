#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char* 
mergesort (char *a, int sz)
{
	int h, i, j, n;
	char *t;

	if (!(t = malloc (sz)))
		return NULL;

	h = sz / 2;

	if (sz > 2)
	{
		mergesort (a, h);
		mergesort (a + h, sz - h);
	}

	i = 0;
	j = h;
	for (n = 0; n < sz; n++)
	{
		if (
			(i < h && a[i] < a[j])
			|| j >= sz
		)
			t[n] = a[i++];
		else
			t[n] = a[j++];

	}

	for (n = 0; n < sz; n++)
		a[n] = t[n];

	free (t);
	return a;
}

int
main (int argc, char *argv[])
{

	if (argc != 2)
	{
		printf ("USAGE: %s <string>\n", argv[0]);
		return 0;
	}

	printf ("%s\n", mergesort (argv[1], strlen (argv[1])));

	return 0;
}