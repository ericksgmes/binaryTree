#include "t_binarytree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

t_binary_tree* create_tree() {
    t_binary_tree *tree = malloc(sizeof(t_binary_tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}

t_node* create_node(char item) {
    t_node *node = malloc(sizeof(t_node));
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    return node;
}

t_node* insert_rec(t_node *node, int new_item) {
    if (node == NULL) {
        return create_node(new_item);
    }
    if (new_item < node->item) {
        node->left = insert_rec(node->left, new_item);
    } else if (new_item > node->item) {
        node->right = insert_rec(node->right, new_item);
    }
    return node;
}

void insert(t_binary_tree *tree, int item) {
    tree->root = insert_rec(tree->root, item);
    tree->n++;
}

t_node* search_rec(t_node *node, int item) {
    if (node == NULL || node->item == item) {
        return node;
    }
    if (item  < node->item) {
        return search_rec(node->left, item);
    } else {
        return search_rec(node->right, item);
    }
}

t_node* search(t_binary_tree *tree, int item) {
    return search_rec(tree->root, item);
}

void pre_order(t_node *node) {
    if (node != NULL) {
        printf("%c\t", node->item);
        pre_order(node->left);
        pre_order(node->right);
    }
}

void in_order(t_node *node) {
    if (node != NULL) {
        in_order(node->left);
        printf("%c\t", node->item);
        in_order(node->right);
    }
}

void post_order(t_node *node) {
    if (node != NULL) {
        post_order(node->left);
        post_order(node->right);
        printf("%c\t", node->item);
    }
}

t_node* parse_tree(const char **str) {
    if (**str == '\0' || **str == ')') {
        return NULL;
    }

    if (**str == '(') {
        (*str)++;
    }

    if (**str == ')') {
        (*str)++;
        return NULL;
    }

    char item = **str;
    t_node *node = create_node(item);
    (*str)++;

    if (**str == ',') {
        (*str)++;
    }

    node->left = parse_tree(str);

    if (**str == ',') {
        (*str)++;
    }

    node->right = parse_tree(str);

    if (**str == ')') {
        (*str)++;
    }

    return node;
}


t_binary_tree* create(const char *str) {
    t_binary_tree *tree = create_tree();
    const char *p = str;
    tree->root = parse_tree(&p);
    return tree;
}

void clear(t_node *node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        free(node);
    }
}

void destroy(t_binary_tree *tree) {
    if (tree != NULL) {
        clear(tree->root);
        free(tree);
    }
}

void print_tree(t_node *node, int space) {
    if (node == NULL) {
        return;
    }
    space += 10;
    print_tree(node->right, space);
    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%c\n", node->item);
    print_tree(node->left, space);
}

int height(t_node *node) {
    if (node == NULL) {
        return -1;
    } else {
        int left_height = height(node->left);
        int right_height = height(node->right);
        if (left_height > right_height) {
            return left_height + 1;
        } else {
            return right_height + 1;
        }
    }
}

