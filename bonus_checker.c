#include "push_swap.h"

void s_move(char *info, t_stack **stack_a, t_stack **stack_b)
{
        if(ft_stacksize(*stack_a) >= 2)
                if(info[1] == 'a')
                {
                        move_swap(stack_a, "");
                }
        if(ft_stacksize(*stack_b) >= 2)
                if(info[1] == 'b')
                        move_swap(stack_b, "");
        if(ft_stacksize(*stack_a) >= 2 && ft_stacksize(*stack_b) >= 2)
                if(info[1] == 'r')
                {
                        move_swap(stack_a, "");
                        move_swap(stack_b, "");
                }
}

void r_move(char *info, t_stack **stack_a, t_stack **stack_b)
{
        printf("entrou\n"); 
        if(ft_stacksize(*stack_a) >= 2)
                if(info[1] == 'a')
                        move_reverse(stack_a, "");
        if(ft_stacksize(*stack_b) >= 2)
                if(info[1] == 'b')
                        move_reverse(stack_b, "");
        if(ft_stacksize(*stack_a) >= 2 && ft_stacksize(*stack_b) >= 2)
                if(info[1] == 'r')
                {
                        move_reverse(stack_a, "");
                        move_reverse(stack_b, "");
                }
}

void rr_move(char *info, t_stack **stack_a, t_stack **stack_b)
{
        if(ft_stacksize(*stack_a) >= 2)
                if(info[2] == 'a')
                        move_rreverse(stack_a, "");
        if(ft_stacksize(*stack_b) >= 2)
                if(info[2] == 'b')
                        move_rreverse(stack_b, "");
        if(ft_stacksize(*stack_a) >= 2 && ft_stacksize(*stack_b) >= 2)
                if(info[2] == 'r')
                {
                        move_rreverse(stack_a, "");
                        move_rreverse(stack_b, "");
                }
}

void p_move(char *info, t_stack **stack_a, t_stack **stack_b)
{
        if(stack_b != NULL && ft_stacksize(*stack_b) >= 1)
                if(info[1] == 'a')
                        move_push(stack_a, stack_b, "");
        if(stack_a != NULL && ft_stacksize(*stack_a) >= 1)
                if(info[1] == 'b')
                        move_push(stack_b, stack_a, "");
} 

void verify_info(char *info, t_stack **stack_a, t_stack **stack_b)
{
        if(info[0] == 's')
                s_move(info, stack_a, stack_b);
        else if(info[0] == 'r')
        {
                
                if(ft_strlen(info) == 3)
                {
                        printf("entrou\n");
                        r_move(info, stack_a, stack_b);
                }
                else
                        rr_move(info, stack_a, stack_b);
        }
        else if(info[0] == 'p')
                p_move(info, stack_a, stack_b);
}

void print_stack(t_stack *stacka)
{
        t_stack *tmp_stack;

        tmp_stack = stacka;
        while(tmp_stack != NULL)
        {
                printf("stack number %d\n", tmp_stack->number);
                tmp_stack = tmp_stack->next;
        }
}

void bonus_checker(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
        char *info;

        create_stack(&stack_a, argc, argv);
	if(check(argc, argv) == 0 && argc > 2)
        {
                info = get_next_line(0);
                while(info != NULL)
                {
                        verify_info(info, &stack_a, &stack_b);
                        free(info);
                        print_stack(stack_a);
                        info = get_next_line(0);
                }
                printf("stack size %d", ft_stacksize(stack_b));
                if(sort(stack_a) && stack_a != NULL && ft_stacksize(stack_b) == 0)
                        ft_printf("OK\n");
                else
                        ft_printf("KO\n");
        }
	else
		ft_printf("Error\n");
	free_stack(stack_a);
	free_stack(stack_b);
}

int main(int argc, char **argv)
{
        t_stack *stack_a;
        t_stack *stack_b;

        stack_a = NULL;
        stack_b = NULL;
        bonus_checker(stack_a, stack_b, argc, argv);
}