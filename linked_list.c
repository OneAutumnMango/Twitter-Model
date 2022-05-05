#include "linked_list.h"
#include "user_functions.h"
#include <stdio.h>

TweetNode *push_tweet(tweet new_tweet, TweetNode *previous_node) { /* returns new start of linked list */
    TweetNode *new_node = malloc(sizeof(TweetNode));
    new_node->tweet = new_tweet;
    new_node->next = previous_node;
    return new_node;
}

void remove_users_tweets(twitter *twitter) { /* removes all the current users tweets from linked list */
    TweetNode *prev;
    TweetNode *cur = twitter->most_recent_tweet;
    while (cur != NULL) { /* go through all the tweets */
        prev = cur;
        if (cur->tweet.userID == twitter->current_user->user->userID) { /* to delete */
            if (cur->next == NULL) {
                free(cur);
                return;
            }
            else {
                twitter->most_recent_tweet = cur = cur->next;
                free(prev);
            }
        }
        else { // not delete
            if (cur->next == NULL) {
                return;
            }
            else {
                cur = cur->next;
            }
        }
    }
}


void push_user(user *user, twitter *twitter) {
    UserNode *new = malloc(sizeof(UserNode));
    new->user = user;
    new->next = twitter->userlist;
    new->previous = NULL;
    if (twitter->userlist != NULL) { /* if it is not the start of the list */
        twitter->userlist->previous = malloc(sizeof(UserNode));
        twitter->userlist->previous = new; /* points old start of userlist to most new */
    }
    twitter->userlist = new;
}

void delete_current_user(twitter *twitter) {
    UserNode *current = twitter->current_user;
    if (current->previous == NULL) { /* if at start */
        if (current->next == NULL) { /* if only user */
            twitter->userlist = twitter->current_user = NULL;
            twitter->user_count--;
            puts("User successfully Deleted");
            puts("No users exist");
            create_account(twitter);
            return;
        }
        else {
            twitter->userlist = current->next;
            twitter->current_user = current->next;
            current->next->previous = NULL;
        }
    }
    else if (current->next == NULL) { /* if at end */
        current->previous->next = NULL;
    }
    else { /* if in middle */
        current->previous->next = current->next;
        current->next->previous = current->previous;
    }
    puts("User successfully Deleted");
    free(current);
}