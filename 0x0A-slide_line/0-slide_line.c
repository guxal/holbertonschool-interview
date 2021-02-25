#include "slide_line.h"

/**
 * initvalue - initialization value for loop
 * @size: size array
 * @direction: direction to match
 * Return: Success 0 or greater, -1 Error
 */
int initvalue(int size, int direction)
{
	if (direction == SLIDE_LEFT)
		return (0);
	else if (direction == SLIDE_RIGHT)
		return (size - 1);
	return (-1);
}

/**
 * logic - increment o decrement index
 * @n: index
 * @direction: direction to match
 * Return: Success 0 or greater, -1 Error
 */
int logic(int n, int direction)
{
	if (direction == SLIDE_LEFT)
		return (++n);
	else if (direction == SLIDE_RIGHT)
		return (--n);
	return (-1);
}

/**
 * condition - set condition to use
 * @j: index
 * @n: index general
 * @size: size array
 * @direction: direction to match
 * Return: Success 0 or greater, -1 Error
 */
int condition(int j, int n, int size, int direction)
{
	const int min = 0;

	if (j == 0)
	{
		if (direction == SLIDE_LEFT)
			return (n < size);
		else if (direction == SLIDE_RIGHT)
			return (min <= n);
	}
	else
	{
		if (direction == SLIDE_LEFT)
			return (j < size - n);
		else if (direction == SLIDE_RIGHT)
			return (j - 1 < n);
	}
	return (-1);
}

/**
 * index2 - index to evaluate
 * @n: index general
 * @j: index
 * @direction: direction to match
 * Return: Success 0 or greater, -1 Error
 */
int index2(int n, int j, int direction)
{
	if (direction == SLIDE_LEFT)
		return (n + j);
	else if (direction == SLIDE_RIGHT)
		return (n - j);
	return (-1);
}

/**
 * slide_line - math to R or L
 * @line: array match
 * @size: size array
 * @direction: direction to match
 * Return: Success 0 or greater, -1 Error
 */
int slide_line(int *line, size_t size, int direction)
{
	int PB = NULL;
	int n, j;


	for (n = initvalue(size, direction);
		 condition(0, n, size, direction);
		 n = logic(n, direction))
	{
		if (line[n] > 0)
		{
			for (j = 1; condition(j, n, size, direction); j++)
			{
				if (line[n] == line[index2(n, j, direction)])
				{
					line[n] = 2 * line[n];
					line[index2(n, j, direction)] = 0;
					break;
				}
				else if (line[index2(n, j, direction)] > 0)
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
