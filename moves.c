#include "push_swap.h"

static int update_moves(int a, int b)
{
    int a_b;

    a_b = 0;
    while(a > 0 && b > 0)
    {
        a--;
        b--;
        a_b++;
    }
    return a_b;
}

int move_together(int ra, int rra, int rb, int rrb)
{   
    int rr;
    int rrr;
    int rarrb;
    int rrarb;

    rarrb = ra + rrb;
    rrarb = rra + rb;
    rr = update_moves(ra, rb);
    rrr = update_moves(rra, rrb);
    while(ra > 0 && rb > 0)
    {
        ra--;
        rb--;
        rr++;
    }
    while (rra > 0 && rrb > 0)
    {
        rra--;
        rrb--;
        rrr++;
    }
    if (rarrb < rr + ra + rb && rarrb < rrr + rra + rrb && rarrb < rrarb)
        return rarrb + 1;
    else if (rrarb < rr + ra + rb && rrarb < rrr + rra + rrb && rrarb < rarrb)
        return rrarb + 1;
    else if (rr + ra + rb <= rrr + rra + rrb)
        return rr + ra + rb + 1;
    else
        return rrr + rra + rrb + 1;
}