#include "palindrome.h"

/**
 * is_palindrome_rec - check whether a number is palindrome or not.
 * @n: number to check
 * Return: 1 if the number is palindrome otherwise 0.
 */
int is_palindrome_rec(unsigned long n)
{
	static int reverse_num = 0, rem;

	if (n != 0)
	{
		rem = n % 10;
		reverse_num = reverse_num * 10 + rem;
		is_palindrome_rec(n / 10);
	}
	return (reverse_num);
}

/**
 * is_palindrome - check if is palindrome
 * @n: number check
 * Return: 1 Success, 0 False
 */
int is_palindrome(unsigned long n)
{
	unsigned long reverse = is_palindrome_rec(n);

	if (reverse == n)
		return (1);
	else
		return (0);
}

