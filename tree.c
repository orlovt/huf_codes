#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    int freq; //acts as "priority" in this case
    struct node *left;
    struct node *right;
} Node;

/*
Not sure how your tree will interface with my heap,
but we'll figure it out. Implement it any way you'd
like. Use my struct above, or change it how you see
fit.
*/

