#include "linked_list.h"

Node* add_to_list(tweet new_tweet, Node *previous_node) {  /* returns new start of linked list */
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->tweet = new_tweet;
    new_node->previous_node = previous_node;
    return new_node;  
}