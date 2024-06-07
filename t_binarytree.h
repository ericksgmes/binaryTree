#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct _node {
    char item;
    struct _node *left;
    struct _node *right;
} t_node;

typedef struct {
    t_node *root;
    int n;
} t_binary_tree;

t_binary_tree* create_tree();
t_node* create_node(char item);
t_binary_tree* create(const char *str);
t_node* insert_rec(t_node *node, int new_item);
void insert(t_binary_tree *tree, int item);
t_node* search_rec(t_node *node, int item);
t_node* search(t_binary_tree *tree, int item);
void pre_order(t_node *node);
void in_order(t_node *node);
void post_order(t_node *node);
void clear(t_node *node);
void destroy(t_binary_tree *tree);
int height(t_node *p);
void print_tree(t_node *node, int space);

#endif
