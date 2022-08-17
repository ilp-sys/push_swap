#include "push_swap.h"
#include <stdio.h>

void    show_menu()
{
    printf(" 1. swap a\n");
    printf(" 2. swap b\n");
    printf(" 3. swap a and swap b\n");
    printf(" 4. push a\n");
    printf(" 5. push b\n");
    printf(" 6. rotate a\n");
    printf(" 7. rotate b\n");
    printf(" 8. rotate a and rotate b\n");
    printf(" 9. reverse rotate a\n");
    printf("10. reverse rotate b\n");
    printf("11. reverse rotate a and reverse rotate b\n");
    printf("12. exit\n");
    printf(">>");
}

void    print_stacks(t_list *stack_a, t_list *stack_b)
{
    printf("\n[STACK_A] ");
    while (stack_a)
    {
        printf("%d ", (int)stack_a->content);
        stack_a = stack_a->next;
    }
    printf("\n[STACK_B] ");
    while (stack_b)
    {
        printf("%d ", (int)stack_b->content);
        stack_b = stack_b->next;
    }
    printf("\n");
}

int main()
{
    t_list  *stack_a = NULL;
    t_list  *stack_b = NULL;

	t_list	*new1 = ft_lstnew((void *)1);
	ft_lstadd_front(&stack_a, new1);
	t_list	*new2 = ft_lstnew((void *)2);
	ft_lstadd_front(&stack_a, new2);
	t_list	*new3 = ft_lstnew((void *)3);
	ft_lstadd_front(&stack_a, new3);
	t_list	*new4 = ft_lstnew((void *)4);
	ft_lstadd_front(&stack_a, new4);
	t_list	*new5 = ft_lstnew((void *)5);
	ft_lstadd_front(&stack_a, new5);

    int flag = 1;
    while (flag)
    {
        print_stacks(stack_a, stack_b);
        show_menu();
        int input;
        scanf("%d", &input);
        switch(input)
        {
			case 1: operation_swap(&stack_a); break;
			case 2: operation_swap(&stack_b); break;
			case 3: operation_swap(&stack_a); operation_swap(&stack_b); break;
			case 4: operation_push(&stack_b, &stack_a); break;
			case 5: operation_push(&stack_a, &stack_b); break;
			case 6: operation_rotate(&stack_a); break ;
			case 7: operation_rotate(&stack_b); break;
			case 8: operation_rotate(&stack_a); operation_rotate(&stack_b); break;
			case 9: operation_reverse_rotate(&stack_a); break;
			case 10: operation_reverse_rotate(&stack_b); break;
			case 11: operation_reverse_rotate(&stack_a); operation_reverse_rotate(&stack_b); break;
			case 12: flag = 0; break;
        }
    }
	ft_lstclear(&stack_a, NULL);
	ft_lstclear(&stack_b, NULL);
	system("leaks a.out");
    return (0);
}
