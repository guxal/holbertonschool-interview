#include "slide_line.h"

int initvalue(int size, int direction)
{
	if (direction == SLIDE_LEFT)
		return (0);
	else if (direction == SLIDE_RIGHT)
		return (size);

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
		return j < n;
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
		if (line[n] > 0)
		{
			for(j = 1; condition2(j, n, size, direction); j++)
			{
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
