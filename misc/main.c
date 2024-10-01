#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;
    int next;
};
int survivor(struct node **head, int n)
{
    // head is pointer to first node

    struct node *p, *q;
    int i;
    q = p = *head;
    while (p->next != p)
    {
        for (i = 0; i < n - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        printf("%d has been killed.\n", p->num);
        free(p);
        p = q->next;
    }
    *head = p;
    return (p->num);
}
