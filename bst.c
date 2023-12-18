#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Function to create a new node with the data, questions and guess.
struct node* create_node(int data, char* question, char* guess) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Initializing the node fields.
    new_node->data = data;
    new_node->question = question;
    new_node->guess = guess;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// A recursive function to insert a new node in the binary search tree.
struct node* insert(struct node* root, int data, char* question, char* guess) {
    if (root == NULL) { //creating a new node, if the root is NULL.
        return create_node(data, question, guess);
    }

    if (data < root->data) {
        // If the value is less than the current node's value, insert into the left subtree.
        root->left = insert(root->left, data, question, guess);
    } else {
        // If the value is greater or equal, insert into the right subtree.
        root->right = insert(root->right, data, question, guess);
    }

    return root;
}

//Creating the initial game tree and returning its root.
struct node* create_game_tree() {
    //The root node as NULL.
    struct node* root = NULL;

    //Inserting nodes into the binary search tree.
    root = insert(root, 100, "Does it grow underground?", "");
    insert(root, 50, "Is it long in shape?", "");
    insert(root, 25, "Is it orange in color?", "");
    insert(root, 15, "", "It's a carrot!");
    insert(root, 35, "", "It's a parsnip!");
    insert(root, 75, "Is it red in color?", "");
    insert(root, 65, "", "It's a radish!");
    insert(root, 85, "", "It's a potato!");
    insert(root, 150, "Does it grow on a tree?", "");
    insert(root, 125, "Is it red in color?", "");
    insert(root, 115, "", "It's an apple!");
    insert(root, 135, "", "It's a peach!");
    insert(root, 175, "Is it red in color?", "");
    insert(root, 165, "", "It's a tomato!");
    insert(root, 185, "", "It's a pea!");

    return root;
}
