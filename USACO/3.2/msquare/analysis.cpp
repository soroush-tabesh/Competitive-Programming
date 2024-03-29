#include <stdio.h>
#include <assert.h>

/* the distance from the initial configuration (+1) */
/* dist == 0 => no know path */
int dist[40320];

/* calculate the index of a board */
int encode(int *board){
	static int mult[8] = 
	{1, 8, 8*7, 8*7*6, 8*7*6*5,
		8*7*6*5*4, 8*7*6*5*4*3, 8*7*6*5*4*3*2};

	/* used to calculate the position of a number within the
	remaining ones */
	int look[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	int rlook[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	/* rlook[look[p]] = p and look[rlook[p]] = p */

	int lv, rv;
	int t;

	rv = 0;
	for (lv = 0; lv < 8; lv++)
	{
		t = look[board[lv]]; /* the rank of the board position */
		assert(t < 8-lv); /* sanity check */
		rv += t * mult[lv]; 

		assert(look[rlook[7-lv]] == 7-lv); /* sanity check */

		/* delete t */
		look[rlook[7-lv]] = t;
		rlook[t] = rlook[7-lv];
	}
	return rv;
}

/* the set of transformations, in order */
static int tforms[3][8] = { {8, 7, 6, 5, 4, 3, 2, 1},
{4, 1, 2, 3, 6, 7, 8, 5}, {1, 7, 2, 4, 5, 3, 6, 8} };

void do_trans(int *inboard, int *outboard, int t){
	/* calculate the board (into outboard) that results from doing
	the t'th transformation to inboard */
	int lv;
	int *tform = tforms[t];

	assert(t >= 0 && t < 3);

	for (lv = 0; lv < 8; lv++)
	outboard[lv] = inboard[tform[lv]-1];
}

void do_rtrans(int *inboard, int *outboard, int t){
	/* calculate the board (into outboard) that which would result
	in inboard if the t'th transformation was applied to it */
	int lv;
	int *tform = tforms[t];

	assert(t >= 0 && t < 3);

	for (lv = 0; lv < 8; lv++)
		outboard[tform[lv]-1] = inboard[lv];
}

/* queue for breadth-first search */
int queue[40325][8];
int qhead, qtail;

/* calculate the distance from each board to the ending board */
void do_dist(int *board)
{
	int lv;
	int t1;
	int d, t;

	qhead = 0;
	qtail = 1;

	/* the ending board is 0 steps away from itself */
	for (lv = 0; lv < 8; lv++) queue[0][lv] = board[lv];
		dist[encode(queue[0])] = 1; /* 0 steps (+ 1 offset for dist array) */

	while (qhead < qtail)
	{
		t1 = encode(queue[qhead]);
		d = dist[t1];

		/* for each transformation */
		for (lv = 0; lv < 3; lv++)
		{
			/* apply the reverse transformation */
			do_rtrans(queue[qhead], queue[qtail], lv);

			t = encode(queue[qtail]);
			if (dist[t] == 0) 
			{ /* found a new board position!  add it to queue */
				qtail++;
				dist[t] = d+1;
			}
		}

		qhead++;
	}
}

/* find the path from the initial configuration to the ending board */
void walk(FILE *fout)
{
	int newboard[8];
	int cboard[8];
	int lv, lv2;
	int t, d;

	for (lv = 0; lv < 8; lv++) cboard[lv] = lv;
	d = dist[encode(cboard)];
	/* start at the ending board */
	while (d > 1)
	{
		for (lv = 0; lv < 3; lv++)
		{
			do_trans(cboard, newboard, lv);
			t = encode(newboard);
			if (dist[t] == d-1) /* we found the previous board! */
			{
				/* output transformatino */
				fprintf (fout, "%c", lv+'A');

				/* find the rest of the path */
				for (lv2 = 0; lv2 < 8; lv2++)
					cboard[lv2] = newboard[lv2];
				break;
			}
		}
		assert(lv < 3);
		d--;
	}
	fprintf (fout, "\n");
}

int main(int argc, char **argv)
{
	FILE *fout, *fin;
	int board[8];
	int lv;

	if ((fin = fopen("msquare.in", "r")) == NULL)
	{
		perror ("fopen fin");
		exit(1);
	}
	if ((fout = fopen("msquare.out", "w")) == NULL)
	{
		perror ("fopen fout");
		exit(1);
	}

	for (lv = 0; lv < 8; lv++) 
	{
		fscanf (fin, "%d", &board[lv]);
		board[lv]--; /* use 0-based instead of 1-based */
	}

	/* calculate the distance from each board to the ending board */
	do_dist(board);

	for (lv = 0; lv < 8; lv++)
		board[lv] = lv;

	/* output the distance from and the path from the initial configuration */
	fprintf (fout, "%d\n", dist[encode(board)]-1);
	walk(fout);

	return 0;
}