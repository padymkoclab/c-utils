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
https://en.wikipedia.org/wiki/Tree_(data_structure)
https://en.wikipedia.org/wiki/Binary_search_tree
http://www.algolist.net/Data_structures/Binary_search_tree/Removal
http://www.zentut.com/c-tutorial/c-binary-search-tree/
http://www.cprogramming.com/tutorial/c/lesson18.html
http://www.learn-c.org/en/Binary_trees
http://stackoverflow.com/questions/16452854/binary-search-tree-c-implementation
http://quiz.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
https://gist.github.com/ArnonEilat/4611213
http://www.c4learn.com/c-programs/c-program-to-implement-binary-search-tree-traversal.html
http://www.geeksforgeeks.org/binary-search-tree/
*/


#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__


#include <stdio.h>
#include <stdbool.h>


#define BINARY_SEARCH_TREE_ERROR "BinarySearchTreeError"
#define BINARY_SEARCH_TREE_ERROR_CREATION "Can`t create a new item"
#define BINARY_SEARCH_TREE_PRINT_TAB 1


typedef struct _binary_search_tree {
    int key;
    struct _binary_search_tree *left;
    struct _binary_search_tree *right;
} binary_search_tree_t;



/*
    Posible variants:
        allow duplication
        deny duplication
        count duplication

    http://www.geeksforgeeks.org/how-to-handle-duplicates-in-binary-search-tree/
 */
binary_search_tree_t *
binary_search_tree_item_insert(binary_search_tree_t **binary_search_tree, const int key)
{
    binary_search_tree_t *new_item, *current, *parent;

    // create a new item
    new_item = (binary_search_tree_t *)malloc(sizeof(binary_search_tree_t));
    if (!new_item) {
        fprintf(stderr, "%s: %s\n", BINARY_SEARCH_TREE_ERROR, BINARY_SEARCH_TREE_ERROR_CREATION);
        return NULL;
    }
    new_item->key = key;
    new_item->left = NULL;
    new_item->right = NULL;

    // if a tree is empty
    if (*binary_search_tree == NULL)
        *binary_search_tree = new_item;

    // add the new item to the tree
    else {
        current = *binary_search_tree;
        while(current != NULL) {
            parent = current;
            if (key < parent->key) {
                current = parent->left;
                if (current == NULL)
                    parent->left = new_item;
            } else if (key > parent->key) {
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


void
binary_search_tree_print(binary_search_tree_t *binary_search_tree, int indent)
{
    if (binary_search_tree != NULL) {
        for (int i = 0; i < indent; ++i)
            putchar('\t');
        printf("%d\n", binary_search_tree->key);

        binary_search_tree_print(binary_search_tree->left, indent + BINARY_SEARCH_TREE_PRINT_TAB);
        binary_search_tree_print(binary_search_tree->right, indent + BINARY_SEARCH_TREE_PRINT_TAB);
    }
}


binary_search_tree_t *
binary_search_tree_search(binary_search_tree_t *binary_search_tree, const int value)
{
    if (binary_search_tree == NULL)
        return NULL;

    binary_search_tree_t *item = binary_search_tree;

    while(item != NULL) {
        if (value < item->key)
            item = item->left;
        else if (value > item->key)
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


void
binary_search_tree_clear(binary_search_tree_t **binary_search_tree)
{
    if (*binary_search_tree != NULL) {
        if ((*binary_search_tree)->left != NULL)
            binary_search_tree_clear(&(*binary_search_tree)->left);
        if ((*binary_search_tree)->right != NULL)
            binary_search_tree_clear(&(*binary_search_tree)->right);
        free(*binary_search_tree);
        *binary_search_tree = NULL;
    }
}


// Not implemented
// https://en.wikipedia.org/wiki/Tree_traversal
bool
binary_search_tree_remove(binary_search_tree_t **binary_search_tree, const int value)
{
    if (binary_search_tree == NULL)
        return false;

    binary_search_tree_t **current = binary_search_tree;

    while (*current != NULL) {
        if (value < (*current)->key) {
            current = &((*current)->left);
        } else if (value > (*current)->key) {
            current = &((*current)->right);
        } else {

            // no children
            if ((*current)->left == NULL && (*current)->right == NULL) {
                free(*current);
                *current = NULL;
                // puts("No");

            // two children
            } else if ((*current)->left != NULL && (*current)->right != NULL) {
                // puts("Two");

            // a single left child
            } else if ((*current)->left != NULL) {
                // puts("Only left");

            // a single right child
            } else {
                // puts("Only right");

            }
            return true;
        }
    }
    return false;
}


static void
__binary_search_tree_length_count(binary_search_tree_t *item, unsigned int *count)
{
    if (item != NULL) {
        ++(*count);
        __binary_search_tree_length_count(item->right, count);
        __binary_search_tree_length_count(item->left, count);
    }
}


unsigned int
binary_search_tree_length(binary_search_tree_t *binary_search_tree)
{
    if (binary_search_tree == NULL)
        return 0;

    unsigned int count = 1;
    __binary_search_tree_length_count(binary_search_tree->left, &count);
    __binary_search_tree_length_count(binary_search_tree->right, &count);

    return count;
}


// Not implemented
binary_search_tree_t *
binary_search_tree_parent(binary_search_tree_t *binary_search_tree)
{
    return NULL;
}


// Not implemented
binary_search_tree_t **
binary_search_tree_children(binary_search_tree_t *binary_search_tree)
{
    return NULL;
}


// Not implemented
binary_search_tree_t **
binary_search_tree_siblings(binary_search_tree_t *binary_search_tree)
{
    return NULL;
}


// Not implemented
binary_search_tree_t **
binary_search_tree_descendant(binary_search_tree_t *binary_search_tree)
{
    return NULL;
}


// Not implemented
binary_search_tree_t **
binary_search_tree_ancestors(binary_search_tree_t *binary_search_tree)
{
    return NULL;
}


// Not implemented
binary_search_tree_t **
binary_search_tree_level(binary_search_tree_t *binary_search_tree)
{
    return NULL;
}


/**
 * Tests
 */


void
binary_search_tree_insert_test(binary_search_tree_t **binary_search_tree)
{
    binary_search_tree_item_insert(binary_search_tree, 45);
    binary_search_tree_item_insert(binary_search_tree, -5);
    binary_search_tree_item_insert(binary_search_tree, 10);
    binary_search_tree_item_insert(binary_search_tree, -10);
    binary_search_tree_item_insert(binary_search_tree, -1);
    binary_search_tree_item_insert(binary_search_tree, 11);
    binary_search_tree_item_insert(binary_search_tree, 62);
    binary_search_tree_item_insert(binary_search_tree, 62);
    binary_search_tree_item_insert(binary_search_tree, 90);
    binary_search_tree_item_insert(binary_search_tree, 100);
    binary_search_tree_item_insert(binary_search_tree, -11);
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
binary_search_tree_remove_test(binary_search_tree_t **binary_search_tree)
{
    bool status;
    int data[9] = {100, 62, -10, 10, -5, 45, 3, 0};

    for (int i = 0; i < 4; ++i) {
        status = binary_search_tree_remove(binary_search_tree, data[i]);
        if (status == true) {}
        //     printf("Removed %d\n", data[i]);
        else {}
        //     printf("Not found for remove %d\n", data[i]);
    }
}


void
binary_search_tree_test() {

    binary_search_tree_t *binary_search_tree;

    // printf("Length = %d\n", binary_search_tree_length(binary_search_tree));
    binary_search_tree_insert_test(&binary_search_tree);
    // printf("Length = %d\n", binary_search_tree_length(binary_search_tree));

    binary_search_tree_print(binary_search_tree, 0);

    // binary_search_tree_search_test(binary_search_tree);
    binary_search_tree_remove_test(&binary_search_tree);

    binary_search_tree_print(binary_search_tree, 0);
    // binary_search_tree_clear(&binary_search_tree);
}


#endif // __BINARY_SEARCH_TREE_H__
