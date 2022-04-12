#include "linked_list.h"

Node* push(tweet new_tweet, Node *previous_node) {  /* returns new start of linked list */
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->tweet = new_tweet;
    new_node->next_node = previous_node;
    return new_node;  
}

void remove_users_tweets(twitter *twitter) {     /* removes all the current users tweets from linked list */
    Node* previous = twitter->most_recent_tweet;
    Node* current = twitter->most_recent_tweet;
    while(current->next_node != NULL) { /* go through all the tweets */
        if (current->tweet.userID == twitter->current_userID) { /* if the author is the current user */
            previous->next_node = current;      /* remove the tweet from the list */

            if(current == twitter->most_recent_tweet) {     /* if the tweet is the newest tweet */
                twitter->most_recent_tweet = current->next_node;    /* remove the tweet from the front */
            }
            free(previous);
        }
        else {
            previous = current;     /* move onto the next node */
        }
        current = current->next_node;   /* move onto the next node */
    }
}