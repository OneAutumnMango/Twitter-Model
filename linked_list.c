#include "objects.h"



Node* add_to_list(tweet new_tweet, Node *previous_tweet) {  /* returns new start of linked list */
    Node *new = (Node*)malloc(sizeof(Node));
    new->tweet = new_tweet;
    new->previous_node = previous_tweet;

    return new;

    /* go through list until pointer = NULL
     * create a Node with new tweet and pointer = NULL
     * let pointer = pointer to new Node (of new tweet)
     */
}

/* 
go through linked list, whenever username is in user.following return tweet
count these until 10 tweets returned then stop, or stop if no tweets left
 */