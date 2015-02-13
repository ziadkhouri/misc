#include <stdio.h>
#include <stdlib.h>

//return deepest node of a binary tree (not balanced)

typedef struct _NODE
{
	int depth;
	int val;
	struct _NODE *p_left;
	struct _NODE *p_right;
} NODE;



NODE*
deepest (NODE *p_node, int depth)
{
	NODE *p_l = NULL;
	NODE *p_r = NULL;

	if (p_node)
	{	
		p_node->depth = depth;
		p_l = deepest (p_node->p_left, depth + 1);
		p_r = deepest (p_node->p_right, depth + 1);

		if (p_l && p_r)
		{
			if (p_l->depth > p_r->depth)
				return p_l;
			else 
				return p_r;
		}
		if (p_l)
			return p_l;
		if (p_r)
			return p_r;
	}

	return p_node;
}

/*
generate a tree for testing
	0
/		\
1 		2
/\		/\
3 4 	5 6
/		/\
7		8 9
		\
		 10

*/
void 
generate (NODE* t, int sz)
{
	int i;
	for (i = 0; i < sz; i++)
	{
		t[i].depth = 0;
		t[i].val = i;
		t[i].p_left = NULL;
		t[i].p_right = NULL;
	} 
	t[0].p_left = &t[1];
	t[0].p_right = &t[2];

	t[1].p_left = &t[3];
	t[1].p_right = &t[4];

	t[2].p_left = &t[5];
	t[2].p_right = &t[6];

	t[3].p_left = &t[7];

	t[5].p_left = &t[8];
	t[5].p_right = &t[9];

	t[8].p_right = &t[10];
}

int 
main (int argc, char *argv[])
{
	NODE tree[16];
	NODE *p_out = NULL;

	generate (tree, 16);
	
	if (p_out = deepest (tree, 0))
		printf ("Node %d @ level %d", p_out->val, p_out->depth);
	else
		printf ("null\n");

	return 0;
}
