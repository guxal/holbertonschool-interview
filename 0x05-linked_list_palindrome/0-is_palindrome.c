#include "lists.h"
/**
 * revlist - reverses a linked list
 * @head: pointer to address of a list
 *
 * Return: pointer to first node of reversed list
 */
listint_t *revlist(listint_t **head)
{
	listint_t *tmp, *cur, *rev;

	tmp = *head;
	rev = NULL;
	for (cur = *head; cur; cur = tmp)
	{
		tmp = tmp->next;
		cur->next = rev;
		rev = cur;
	}
	return (rev);
}

/**
 * is_palindrome - checks if singly linked list is a palindrome
 * @head: linked list head
 *
 * Return: 1 if palindrome, otherwise 0
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow, *fast, *cur;

	slow = cur = *head;
	if (*head)
	{
		for (fast = *head; fast && fast->next; fast = fast->next->next)
			slow = slow->next;
		slow = revlist(&slow);
		for (; slow; slow = slow->next)
		{
			if (cur->n != slow->n)
				return (0);
			cur = cur->next;
		}
	}
	return (1);
}
