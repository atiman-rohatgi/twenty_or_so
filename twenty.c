#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Function to get a single character input from the user.
char get_user_input() {
    char c;
    scanf(" %c", &c);
    return c;
}

// Recursive function to play the guessing game.
void play_game(struct node* node) {
    if (node == NULL) {
        printf("I give up. What is it?\n");
        return;
    }

    if (node->question[0] != '\0') {
        printf("%s\n", node->question);
        printf("y/n:");
        char answer = get_user_input();

        if (answer == 'y') { //If the user answers 'y', move to the left child node.
            play_game(node->left);
        } else if (answer == 'n') { //If the user answers 'n', move to the right child node.
            play_game(node->right);
        } else { //If the user provides an invalid input, ask again.
            printf("Invalid input. Please enter 'y' or 'n'.\n");
            play_game(node);
        }
    } else {
        printf("%s\n", node->guess);
        printf("y/n:");
        char confirm = get_user_input();
        if (confirm == 'y') { //If the user confirms, then the computer wins.
            printf("I win!\n");
        } else if (confirm == 'n') { //If the user denies, then the user wins.
            printf("You win!\n");
        } else { //If the user provides an invalid input, ask again.
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    }
}


int main() {
    //Creating the initial game tree.
    struct node* game_tree = create_game_tree();
    char c;

    while (1) {
        printf("Welcome! Press 'q' to quit or any other key to continue:\n");
        c = get_user_input();

        if (c == 'q') { //If the user presses 'q' exit the game loop.
            break;
        } else {
            printf("You think of a fruit or vegetable and I will try to guess it!\n");
            play_game(game_tree);
        }
    }

    printf("Bye Bye!\n");

    return 0;
}