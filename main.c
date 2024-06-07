#include "t_binarytree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char n[1000];
    t_binary_tree *tree = NULL;

    while (1) {
        scanf(" %[^\n]", n);

        if (strncmp(n, "create", 6) == 0) {
            char *tree_str = strchr(n, '(');
            if (tree_str) {
                tree = create(tree_str);
            }
        } else if (strncmp(n, "pre", 3) == 0) {
            if (tree) {
                pre_order(tree->root);
                printf("\n");
            } else {
                printf("Tree not created yet.\n");
            }
        } else if (strncmp(n, "in", 2) == 0) {
            if (tree) {
                in_order(tree->root);
                printf("\n");
            } else {
                printf("Tree not created yet.\n");
            }
        } else if (strncmp(n, "post", 4) == 0) {
            if (tree) {
                printf("Post-order traversal:\n");
                post_order(tree->root);
                printf("\n");
            } else {
                printf("Tree not created yet.\n");
            }
        } else if (strncmp(n, "height", 6) == 0) {
            if (tree) {
                printf("Height of the tree: %d\n", height(tree->root));
            } else {
                printf("Tree not created yet.\n");
            }
        } else if (strncmp(n, "print", 5) == 0) {
            if (tree) {
                printf("Tree structure:\n");
                print_tree(tree->root, 0);
            } else {
                printf("Tree not created yet.\n");
            }
        } else if (strncmp(n, "exit", 4) == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    if (tree) {
        destroy(tree);
    }
    return 0;
}

