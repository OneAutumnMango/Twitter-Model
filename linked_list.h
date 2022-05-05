#include "objects.h"
TweetNode* push_tweet(tweet new_tweet, TweetNode *previous_node);
void delete_current_user(twitter *twitter);
void push_user(user *user, twitter *twitter);
void remove_users_tweets(twitter *twitter);