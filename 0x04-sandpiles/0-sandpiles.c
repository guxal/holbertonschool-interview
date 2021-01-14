#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_toop - recursive derrame
 * @grid1: Left 3x3 grid
 * @derrame: is true repeat
 */
void sandpiles_toop(int grid1[3][3], int derrame)
{
	int i, j;

	if (derrame == 1)
	{
		printf("=\n");
		print_grid(grid1);
		derrame = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					grid1[i][j] = grid1[i][j] - 4;
					if (i + 1 < 3)
						grid1[i + 1][j] = grid1[i + 1][j] + 1;
					if (i - 1 >= 0)
						grid1[i - 1][j] = grid1[i - 1][j] + 1;
					if (j + 1 < 3)
						grid1[i][j + 1] = grid1[i][j + 1] + 1;
					if (j - 1 >= 0)
						grid1[i][j - 1] = grid1[i][j - 1] + 1;
				}
			}
		}
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
					derrame = 1;
			}
		}
		if (derrame == 1)
			sandpiles_toop(grid1, derrame);
	}
}

/**
 * sandpiles_sum - sum sandpiles
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, derrame;
	/* sum */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
			if (grid1[i][j] > 3)
				derrame = 1;
		}
	}
	/* derrame */

	sandpiles_toop(grid1, derrame);
}
