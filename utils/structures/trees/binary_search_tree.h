/**
 * Implementation a binary search tree
 *
 * A Binary Search Tree (BST) is a tree in which all the nodes follow the below-mentioned properties −
 *     The left sub-tree of a node has a key less than or equal to its parent node's key.
 *     The right sub-tree of a node has a key greater than to its parent node's key.
 * Thus, BST divides all its sub-trees into two segments; the left sub-tree and the right sub-tree and can be defined as −
 *     left_subtree (keys)  ≤  node (key)  ≤  right_subtree (keys)
 *
 */

/*
https://www.tutorialspoint.com/data_structures_algorithms/binary_search_tree.htm
http://www.thegeekstuff.com/2013/02/c-binary-tree/
http://www.cprogramming.com/tutorial/c/lesson18.html
http://www.learn-c.org/en/Binary_trees
https://www.tutorialspoint.com/data_structures_algorithms/binary_search_tree.htm
http://stackoverflow.com/questions/16452854/binary-search-tree-c-implementation
http://quiz.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
https://gist.github.com/ArnonEilat/4611213
http://www.c4learn.com/c-programs/c-program-to-implement-binary-search-tree-traversal.html
*/


#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__


#include <stdio.h>
#include <stdbool.h>
#include <errno.h>


#define BINARY_SEARCH_TREE_ERROR "BinarySearchTreeError"
#define BINARY_SEARCH_TREE_ERROR_CREATION "Can`t create a new item"
#define BINARY_SEARCH_TREE_PRINT_TAB 1


typedef struct _binary_search_tree {
    int data;
    struct _binary_search_tree *left;
    struct _binary_search_tree *right;
} binary_search_tree_t;


binary_search_tree_t *
binary_search_tree_item_new(const int data)
{
    binary_search_tree_t *binary_search_tree;
    binary_search_tree = (binary_search_tree_t *)malloc(sizeof(binary_search_tree_t));

    if (!binary_search_tree) {
        fprintf(stderr, "%s: %s\n", BINARY_SEARCH_TREE_ERROR, BINARY_SEARCH_TREE_ERROR_CREATION);
        return NULL;
    }

    binary_search_tree->data = data;
    binary_search_tree->left = NULL;
    binary_search_tree->right = NULL;

    return binary_search_tree;
}


/*
    Posible variants:
        allow duplication
        deny duplication
        count duplication

    http://www.geeksforgeeks.org/how-to-handle-duplicates-in-binary-search-tree/
 */
binary_search_tree_t *
binary_search_tree_item_insert(binary_search_tree_t **binary_search_tree, const int data)
{
    binary_search_tree_t *new_item, *current, *parent;

    new_item = binary_search_tree_item_new(data);

    if (*binary_search_tree == NULL)
        *binary_search_tree = new_item;
    else {
        current = *binary_search_tree;
        while(current != NULL) {
            parent = current;
            if (data < parent->data) {
                current = parent->left;
                if (current == NULL)
                    parent->left = new_item;
            } else if (data > parent->data) {
                current = parent->right;
                if (current == NULL)
                    parent->right = new_item;

            // duplication is deny
            } else
                return NULL;
        }
    }

    return new_item;

}


// Proof implemented
void
binary_search_tree_print(binary_search_tree_t *binary_search_tree, int indent)
{

    if (binary_search_tree == NULL)
        return;

    for (int i = 0; i < indent; ++i)
        putchar('\t');
    printf("%d\n", binary_search_tree->data);

    binary_search_tree_print(binary_search_tree->left, indent + BINARY_SEARCH_TREE_PRINT_TAB);
    binary_search_tree_print(binary_search_tree->right, indent + BINARY_SEARCH_TREE_PRINT_TAB);
}


binary_search_tree_t *
binary_search_tree_search(binary_search_tree_t *binary_search_tree, const int value)
{

    if (binary_search_tree == NULL)
        return NULL;

    binary_search_tree_t *item = binary_search_tree;

    while(item != NULL) {
        if (value < item->data)
            item = item->left;
        else if (value > item->data)
            item = item->right;
        else
            return item;
    }
    return item;
}


// Not implemented
void
binary_search_tree_traversal(binary_search_tree_t *binary_search_tree)
{

}


// Not implemented
void
binary_search_tree_clear(binary_search_tree_t **binary_search_tree)
{
}


// Not implemented
bool
binary_search_tree_remove(binary_search_tree_t *binary_search_tree, const int value)
{
    return false;
}


void
binary_search_tree_destroy(binary_search_tree_t **binary_search_tree)
{
    if ((*binary_search_tree)->left != NULL)
        binary_search_tree_destroy(&(*binary_search_tree)->left);

    if ((*binary_search_tree)->right != NULL)
        binary_search_tree_destroy(&(*binary_search_tree)->right);

    free(*binary_search_tree);
    *binary_search_tree = NULL;
}


/**
 * Tests
 */


void
binary_search_tree_insert_test(binary_search_tree_t **binary_search_tree)
{
    binary_search_tree_item_insert(binary_search_tree, 45);
    binary_search_tree_item_insert(binary_search_tree, -45);
    binary_search_tree_item_insert(binary_search_tree, 0);
    binary_search_tree_item_insert(binary_search_tree, -10);
    binary_search_tree_item_insert(binary_search_tree, -58);
    binary_search_tree_item_insert(binary_search_tree, 1);
    binary_search_tree_item_insert(binary_search_tree, 62);
    binary_search_tree_item_insert(binary_search_tree, 62);
}


void
binary_search_tree_search_test(binary_search_tree_t *binary_search_tree)
{
    binary_search_tree_t *item;
    int data[7] = {-3, -45, -1, 0, 1, 45, 3};

    for (int i = 0; i < 7; ++i) {
        item = binary_search_tree_search(binary_search_tree, data[i]);
        if (item == NULL)
            printf("Not found %d\n", data[i]);
        else
            printf("Found %d\n", data[i]);
    }
}


void
binary_search_tree_remove_test(binary_search_tree_t *binary_search_tree)
{
    bool status;
    int data[7] = {-3, -45, -1, 1, 1, 45, 3};

    for (int i = 0; i < 7; ++i) {
        status = binary_search_tree_remove(binary_search_tree, data[i]);
        if (status == true)
            printf("Removed %d\n", data[i]);
        else
            printf("Not found for remove %d\n", data[i]);
    }
}


void
binary_search_tree_test() {
    binary_search_tree_t *binary_search_tree;

    binary_search_tree_insert_test(&binary_search_tree);

    binary_search_tree_print(binary_search_tree, 0);

    // binary_search_tree_search_test(binary_search_tree);
    binary_search_tree_remove_test(binary_search_tree);

    binary_search_tree_destroy(&binary_search_tree);
}


#endif // __BINARY_SEARCH_TREE_H__
