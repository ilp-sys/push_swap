#include <stdio.h>
#include "push_swap.h"

void	show_menu()
{
	printf(" 1. sa\n");
	printf(" 2. sb\n");
	printf(" 3. ss\n");
	printf(" 4. pa\n");
	printf(" 5. pb\n");
	printf(" 6. ra\n");
	printf(" 7. rb\n");
	printf(" 8. rr\n");
	printf(" 9. rra\n");
	printf("10. rrb\n");
	printf("11. rrr\n");
	printf("12. exit\n");
	printf(">>");
}

void	print_queues(t_deq *stack_a, t_deq *stack_b)
{
	t_node	*head = stack_a->head;
	printf("[STACK_A(%d)]: ", stack_a->size);
	while (head)
	{
		printf("%d - ", head->content);
		head = head->next;
	}
	printf("\n[STACK_B(%d)]: ", stack_b->size);
	head = stack_b->head;
	while (head)
	{
		printf("%d - ", head->content);
		head = head->next;
	}
	printf("\n\n");
}

void	print_queues_reverse(t_deq *stack_a, t_deq *stack_b)
{
	printf("Reversed\n");
	t_node	*head = stack_a->head;
	printf("[STACK_A(%d)]: ", stack_a->size);
	while (head && head->next)
		head = head->next;
	while (head)
	{
		printf("%d - ", head->content);
		head = head->prev;
	}
	printf("\n[STACK_B(%d)]: ", stack_b->size);
	head = stack_b->head;
	while (head && head->next)
		head = head->next;
	while (head)
	{
		printf("%d - ", head->content);
		head = head->prev;
	}
	printf("\n\n");
}

int main(int argc, char *argv[])
{
	int flag = 1;

	t_deq	*stack_a = (t_deq *)malloc(sizeof(t_deq));
	t_deq	*stack_b = (t_deq *)malloc(sizeof(t_deq));

	//init queus
	stack_a->size = 0;
	stack_a->head = NULL;
	stack_b->size = 0;
	stack_b->head = NULL;

	//insert some values
	t_node *tmp1 = get_new_node(1);
	queue_push_front(stack_a, tmp1);
	t_node *tmp2 = get_new_node(2);
	queue_push_front(stack_a, tmp2);
	t_node *tmp3 = get_new_node(3);
	queue_push_front(stack_a, tmp3);
	t_node *tmp4 = get_new_node(4);
	queue_push_front(stack_a, tmp4);
	t_node *tmp5 = get_new_node(5);
	queue_push_front(stack_a, tmp5);
	
	//testing
	while (flag)
	{
		print_queues(stack_a, stack_b);
		print_queues_reverse(stack_a, stack_b);
		show_menu();
		int input;
		scanf("%d", &input);
		switch (input)
		{
			case 1: operation_swap(stack_a); break;
			case 2: operation_swap(stack_b); break;
			case 3: operation_swap(stack_a); operation_swap(stack_b); break;
			case 4: operation_push(stack_b, stack_a); break;
			case 5: operation_push(stack_a, stack_b); break;
			case 6: operation_rotate(stack_a); break;
			case 7: operation_rotate(stack_b); break;
			case 8: operation_rotate(stack_a); operation_rotate(stack_b); break;
			case 9: operation_reverse_rotate(stack_a); break;
			case 10: operation_reverse_rotate(stack_b); break;
			case 11:
			{
				operation_reverse_rotate(stack_a);
				operation_reverse_rotate(stack_b);
				break;
			}
			case 12: flag = 0; break;
		}
	}
	return (0);
}
