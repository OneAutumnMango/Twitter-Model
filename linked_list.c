#include "linked_list.h"

TweetNode *push_tweet(tweet new_tweet, TweetNode *previous_node) { /* returns new start of linked list */
    TweetNode *new_node = malloc(sizeof(TweetNode));
    new_node->tweet = new_tweet;
    new_node->next_node = previous_node;
    return new_node;
}

void remove_users_tweets(twitter *twitter) { /* removes all the current users tweets from linked list */
    TweetNode *previous = twitter->most_recent_tweet;
    TweetNode *current = twitter->most_recent_tweet;
    while (current != NULL) {                                    /* go through all the tweets */
        if (current->tweet.userID == twitter->current_user->user->userID) { /* if the author is the current user */
            previous->next_node = current;                                  /* remove the tweet from the list */

            if (current == twitter->most_recent_tweet) {         /* if the tweet is the newest tweet */
                twitter->most_recent_tweet = current->next_node; /* remove the tweet from the front */
            }
            free(previous);
        }
        else {
            previous = current; /* move onto the next node */
        }
        current = current->next_node; /* move onto the next node */
    }
}

/* user linked list */

void push_user(user *user, twitter *twitter) {
    UserNode *new = malloc(sizeof(UserNode));
    new->user = user;
    new->next = twitter->userlist;
    if (twitter->userlist != NULL) {    /* if it is not the start of the list */
        twitter->userlist->previous = malloc(sizeof(UserNode));
        twitter->userlist->previous = new; /* points old start of userlist to most new */
    }
    twitter->userlist = new;
}

void delete_current_user(twitter *twitter) {
    UserNode *current = twitter->current_user;
    if (current->previous == NULL) {
        twitter->userlist = current->next;  /* does not account for if only 1 user, fix later */
    }
    else {
        current->previous->next = current; /* points previous node's 'next' to current */
        twitter->current_user = twitter->userlist;  /* set current user as most recently created account */
    }
    free(current);
}