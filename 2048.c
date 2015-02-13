#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _BOARD
{
	int score;
	int cells[4][4];
}	BOARD;

void
draw (BOARD *b)
{
	int i;
	printf ("\nSCORE: %d\n\n", b->score);
	for (i = 0; i < 4; i++)
	{
		printf ("%4d %4d %4d %4d\n"
			, b->cells[i][0]
			, b->cells[i][1]
			, b->cells[i][2]
			, b->cells[i][3]);
	}
	printf ("\n");
}

int
squash (int *s)
{
	int o[4] = {0,0,0,0};
	int t = 0;
	int i = 0;
	int j;
	if (s[0] != 0)
	{
		o[i] = s[0];
		i++;
	}
	for (j = 1; j < 4; j++)
	{
		if (s[j] != 0)
		{
			if (i > 0 
				&& o[i - 1] == s[j])
			{
				o[i - 1] *= 2;
				t += o[i - 1];
			}
			else
			{
				o[i] = s[j];
				i++;
			}
		}
	}
	for (j = 0; j < 4; j++)
	{
		s[j] = o[j];
	}

	return t;
}

void
left (BOARD *b)
{
	int i;
	int s[4];
	for (i = 0; i < 4; i++)
	{
		s[0] = b->cells[i][0];
		s[1] = b->cells[i][1];
		s[2] = b->cells[i][2];
		s[3] = b->cells[i][3];
		b->score += squash (s);
		b->cells[i][0] = s[0];
		b->cells[i][1] = s[1];
		b->cells[i][2] = s[2];
		b->cells[i][3] = s[3];
	}
}

void
right (BOARD *b)
{
	int i;
	int s[4];
	for (i = 0; i < 4; i++)
	{
		s[0] = b->cells[i][3];
		s[1] = b->cells[i][2];
		s[2] = b->cells[i][1];
		s[3] = b->cells[i][0];
		b->score += squash (s);
		b->cells[i][3] = s[0];
		b->cells[i][2] = s[1];
		b->cells[i][1] = s[2];
		b->cells[i][0] = s[3];
	}
}

void
up (BOARD *b)
{
	int i;
	int s[4];
	for (i = 0; i < 4; i++)
	{
		s[0] = b->cells[0][i];
		s[1] = b->cells[1][i];
		s[2] = b->cells[2][i];
		s[3] = b->cells[3][i];
		b->score += squash (s);
		b->cells[0][i] = s[0];
		b->cells[1][i] = s[1];
		b->cells[2][i] = s[2];
		b->cells[3][i] = s[3];
	}
}

void
down (BOARD *b)
{
	int i;
	int s[4];
	for (i = 0; i < 4; i++)
	{
		s[0] = b->cells[3][i];
		s[1] = b->cells[2][i];
		s[2] = b->cells[1][i];
		s[3] = b->cells[0][i];
		b->score += squash (s);
		b->cells[3][i] = s[0];
		b->cells[2][i] = s[1];
		b->cells[1][i] = s[2];
		b->cells[0][i] = s[3];
	}
}

bool
grow (BOARD *b)
{
	int r, c, s;
	int a[4 * 4];
	s = 0;

	for (r = 0; r < 4; r++)
	{
		for (c = 0; c < 4; c++)
		{
			if (b->cells[r][c] == 0)
			{
				a[s] = c * 4 + r;
				s++;
			}
		}
	}
	if (s > 0)
	{
		s =  a[rand () % s];
		b->cells[s % 4][s / 4] = 2;
		return true;
	}
		
	return false;
}

int 
main (int argc, char *argv[])
{
	BOARD b;
	char c;
	memset (&b, 0, sizeof(BOARD));
	draw(&b);

	while (c = getchar())
	{
		switch (c)
		{
			case 'w':
				up (&b);
				break;
			case 's':
				down (&b);
				break;
			case 'a':
				left (&b);
				break;
			case 'd':
				right (&b);
				break;
			case 'q':
				exit(0);
			default:
				printf ("(w)p,(s)own,(a)eft,(d)ight or (q)uit?\n");
				continue;
		}
		if (!grow (&b))
		{
			printf ("GAME OVER\n");
			exit(0);
		}
		
		draw (&b);
	}
	return 0;
}