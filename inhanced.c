// t_instractions inhansed_a_down_b_up(t_stack *a, t_stack *b, size_t b_pz, size_t a_instractions_down)
// // t_instractions inhansed_a_down_b_up(t_stack *b, size_t b_pz)
// {
// 	int *a_array;
// 	int *b_array_1;
// 	int b_item;
// 	int a_item;
// 	int *b_array_2;

// 	size_t poz;
// 	t_node *b_stack;
// 	t_node *a_stack;

// 	b_array_1 = malloc(sizeof(int) * (b->size - 1));
// 	b_array_2 = malloc(sizeof(int) * (b->size - 1));
// 	a_array = malloc(sizeof(int) * (a->size + 1));

// 	poz = 0;
// 	b_stack = b->head;
// 	while (poz < b_pz)
// 	{
// 		if (poz == b_pz-1)
// 			b_item = b_stack->item;
// 		b_stack = b_stack->next;
// 		poz++;
// 	}
// 	poz = 0;
// 	while (poz < b->size - 1)
// 	{
// 		if (b_item == b_stack->item)
// 			b_stack = b_stack->next;;
// 		b_array_1[poz] = b_stack->item; 
// 		poz++;
// 		b_stack = b_stack->next;
// 	}
// 	print_stack(b);
// 	printf("\n%li\n\n", b_pz);
// 	poz = 0;
// 	while (poz < b->size - 1)
// 	{
// 		ft_printf("%i ", b_array_1[poz]);
// 		poz++;
// 	}

// 	poz = 0;
// 	b_stack = b->head;
// 	while (poz < b_pz - 2)
// 	{
// 		b_stack = b_stack->next;
// 		poz++;
// 	}
// 	b_item = b_stack->next->item;
// 	poz = 0;
// 	while (poz < b->size - 1)
// 	{
// 		if (b_item == b_stack->item)
// 			b_stack = b_stack->next;;
// 		b_array_2[poz] = b_stack->item; 
// 		poz++;
// 		b_stack = b_stack->next;
// 	}
// 	printf("\n");
// 	poz = 0;
// 	while (poz < b->size - 1)
// 	{
// 		ft_printf("%i ", b_array_2[poz]);
// 		poz++;
// 	}

// 	a_array[0] = b_item;
// 	poz = 0;
// 	a_stack = a->head;
// 	while (poz < a_instractions_down)
// 	{
// 		if (poz == a_instractions_down - 1)
// 			a_item = a_stack->item;
// 		a_stack = a_stack->next;
// 		poz++;
// 	}
// 	poz = 1;
// 	while (poz < a->size + 1)
// 	{
// 		if (b_item == a_stack->item)
// 			a_item = a_stack->item;
// 		a_array[poz] = a_stack->item; 
// 		poz++;
// 		a_stack = a_stack->next;
// 	}
// 	printf("\n");
// 	print_stack(a);
// 	printf("\n%li\n\n", a_instractions_down);
// 	poz = 0;
// 	while (poz < a->size + 1)
// 	{
// 		ft_printf("%i ", a_array[poz]);
// 		poz++;
// 	}
// 	free(a_array);
// 	free(b_array_1);
// 	free(b_array_2);
// 	t_instractions t;
// 	t.all = 9;
// 	return (t);
// }

// void	sort_3_2(t_stack *a)
// {
// 	t_stack *b;
// 	t_node *b_stack;
// 	size_t b_pz;
// 	size_t poz;
// 	t_instractions insts;
// 	size_t a_instractions_up;
// 	size_t a_instractions_down;
// 	t_instractions lowest_insts;
// 	t_instractions tmp_insts;

// 	if (is_sorted(a))
// 		return ;
// 	if (a->size <= 3)
// 	{
// 		sort_three(a);
// 		return ;
// 	}
// 	b = new_stack();
// 	if (!b)
// 		return ;
// 	while (a->size - 5)
// 		pb(a, b);
// 	sort_three(a);
// 	if (b->size == 2 && is_sorted(b))
// 		sb(b);
// 	while (b->size)
// 	{
// 		b_stack = b->head;
// 		b_pz = 0;
// 		while (b_pz < b->size)
// 		{
// 			poz = find_position_3_3(a, b_stack->item);
// 			a_instractions_up = poz;
// 			a_instractions_down = a->size - poz;
// 			if (b_pz <= b->size / 2) // b up
// 			{
// 				insts = a_up_b_up(b_pz, a_instractions_up);
// 				tmp_insts = a_down_b_up(b_pz, a_instractions_down);
// 				if (tmp_insts.all < insts.all)
// 					insts = tmp_insts;
// 				// if poz+1 != 1 and only if b up
// 				tmp_insts = inhansed_a_down_b_up(a, b, 4, 5);
// 				// tmp_insts = inhansed_a_down_b_up(b, 3);
// 				return ;
// 				tmp_insts = a_down_b_down(b->size - b_pz, a_instractions_down);
// 				if (tmp_insts.all < insts.all)
// 					insts = tmp_insts;
// 				tmp_insts = a_up_b_down(b->size - b_pz, a_instractions_up);
// 				// if (tmp_insts.all < insts.all)
// 				// 	insts = tmp_insts;
// 			}
// 			else // b down
// 			{
// 				insts = a_up_b_up(b_pz, a_instractions_up);
// 				tmp_insts = a_up_b_down(b->size - b_pz, a_instractions_up);
// 				if (tmp_insts.all < insts.all)
// 					insts = tmp_insts;
// 				tmp_insts = a_down_b_down(b->size - b_pz, a_instractions_down);
// 				if (tmp_insts.all < insts.all)
// 					insts = tmp_insts;
// 				// tmp_insts = a_down_b_up(b_pz, a_instractions_down);
// 				// if (tmp_insts.all < insts.all)
// 				// 	insts = tmp_insts;
// 			}
// 			if (b_pz == 0)
// 				lowest_insts = insts;
// 			else
// 			{
// 				if (insts.all < lowest_insts.all)
// 					lowest_insts = insts;
// 			}
// 			b_stack = b_stack->next;
// 			b_pz++;
// 		}
// 		applay_opperations(a, b, lowest_insts);
// 	}
// 	get_the_smallest_to_the_top(a);
// 	free_stack(b);
// }

