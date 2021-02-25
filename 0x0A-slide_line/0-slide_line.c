#include "slide_line.h"

int initvalue(int size, int direction)
{
	if (direction == SLIDE_LEFT)
		return (0);
	else if (direction == SLIDE_RIGHT)
		return (size - 1);

	return (-1);
}

int logic(int n, int direction)
{
	if (direction == SLIDE_LEFT)
		return ++n;
	else if (direction == SLIDE_RIGHT)
		return --n;
	return (-1);
}

int condition(int n, int size, int direction)
{
	if (direction == SLIDE_LEFT)
		return n < size;
	else if (direction == SLIDE_RIGHT)
		return 0 <= n;
	return (-1);
}

int condition2(int j, int n, int size, int direction)
{
	if (direction == SLIDE_LEFT)
		return j < size - n;
	else if (direction == SLIDE_RIGHT)
		return j - 1 < n;
	return (-1);
}

int index2(int n, int j, int direction)
{
	if (direction == SLIDE_LEFT)
		return (n + j);
	else if (direction == SLIDE_RIGHT)
		return (n - j);
	return (-1);
}

int slide_line(int *line, size_t size, int direction)
{
	int PB = NULL;
	int n, j;


	for (n = initvalue(size, direction); condition(n, size, direction); n = logic(n, direction))
	{
		printf("%d\n", n);
		if (line[n] > 0)
		{
			printf("mayor a 0\n");
			for(j = 1; condition2(j, n, size, direction); j++)
			{
				printf("index : %d\n", index2(n, j, direction));
				if (line[n] == line[index2(n, j, direction)])
				{
					line[n] = 2 * line[n];
					line[index2(n, j, direction)] = 0;
					break;
				}
				else if(line[index2(n, j, direction)] > 0)
				{
					break;
				}
			}
			if (PB != '\0')
			{
				line[PB] = line[n];
				line[n] = 0;
				if (direction == SLIDE_LEFT)
					PB++;
				else
					PB--;
			}
		}
		else
		{
			if (PB == '\0')
				PB = n;
		}
	}

	return (1);
}
