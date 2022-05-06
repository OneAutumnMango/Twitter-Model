#include "objects.h"

/* Adds a new tweet to the linked list of tweets */
TweetNode *push_tweet(tweet new_tweet, TweetNode *previous_node);

/* Deletes the current user from the userlist */
void delete_current_user(twitter *twitter);

/* Adds a new user to the linked userlist*/
void push_user(user *user, twitter *twitter);

/* Removes all of a users tweets from the linked list of tweets*/
void remove_users_tweets(twitter *twitter);