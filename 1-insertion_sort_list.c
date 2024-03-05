#include "sort.h"

/**
 * insertion_sort_list - a function that sorts
 * doubly linked list of integers.
 * @list: list of integers.
 *
 * Return: nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *runner, *tmp;
	int flag;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current)
	{
		runner = current;
		while (runner->prev)
		{
			flag = 0;
			if (runner->n < runner->prev->n)
			{
				if (runner->prev->prev)
					runner->prev->prev->next = runner;
				runner->prev->next = runner->next;
				tmp = runner->prev->prev;
				runner->prev->prev = runner;
				if (runner->next)
					runner->next->prev = runner->prev;
				runner->next = runner->prev;
				runner->prev = tmp;
				flag = 1;
				if (runner->prev == NULL)
					*list = runner;
				print_list(*list);
			}
			if (flag == 0)
				runner = runner->prev;
		}
		current = current->next;
	}
}
