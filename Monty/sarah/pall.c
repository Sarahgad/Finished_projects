size_t print_dlistint(const stackk_t *h)
{
	size_t count = 0;
	const stackk_t *curr = h;

	for (; curr != NULL; curr = curr->prev, count++)
	printf("%d\n", curr->n);
	return (count);
}
