#include <stdio.h>
#include <stdlib.h>

#include "tree.c"

void swap (Node *x, Node *y) {
    Node temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(Node *root) {
    Node *largest = root;

    if (root->left != NULL && root->left->priority > largest->priority) {
        largest = root->left;
    }
    
    if (root->right != NULL && root->right->priority > largest->priority) {
        largest = root->right;
    }

    if (largest != root) {
        swap(root, largest);
        heapify(largest);
    }
}

void build_heap(Node *node) {
    if (node == NULL) {
        return;
    }

    build_heap(node->left);
    build_heap(node->right);
    heapify(node);
}

void print_tree(Node *node) {
    if (node == NULL) {
        return;
    }

    printf("(%d, %d) ", node->value, node->priority);
    if (node->left != NULL) {
        printf("left: (%d, %d) ", node->left->value, node->left->priority);
    }
    if (node->right != NULL) {
        printf("right: (%d, %d) ", node->right->value, node->right->priority);
    }
    printf("\n");

    print_tree(node->left);
    print_tree(node->right);
}

//This implementation tries to keep the tree created in tree.c, but I don't know if that's the route to take. We'll have to check.