#include<stdlib.h>
#include<stdio.h>

void rarray (char *b, char *e)
{
	char t;
	while (b < e)
	{
		t = *b;
		*b++ = *--e;
		*e = t;
	}
}

void rsentence(char *s)
{
	char *b = s;
	char *e = b;

	while (*e != '\0') e++;
	rarray (s, e);

	e = b;
	while (*b != '\0')
	{
		e++;
		if (*e == ' ' || *e == '\0')
		{
			rarray (b,e);
			b = ++e;
		}
	}
}

int main (int argc, char *argv[])
{
	int len;
	if (argc != 2)
	{
		printf ("USAGE: %s \"<string>\"\n", argv[0]);
		return 0;
	}
	
	rsentence (argv[1]);
	printf ("%s\n", argv[1]);

	return 0;
}