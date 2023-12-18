#ifndef BST_H
#define BST_H

// Structure to represent a node in the binary search tree.
struct node
{
    int data;
    char* question;
    char* guess;
    struct node* left;
    struct node* right;
};

//Creating a new game tree.
struct node* create_game_tree();

//Inserting a new node into the binary search tree.
struct node* insert(struct node* root, int data, char* question, char* guess);

#endif