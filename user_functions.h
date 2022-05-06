#include "objects.h"

/* creates user, adds it to the user list and logs-in as them */
void create_account(twitter *twitter);

/* logs-in as given user */
void login(twitter *twitter);

/* Allows user to type a tweet in & pushes that tweet to the linked list */
void postTweet(twitter *twitter);

/* prints up to 10 most recent tweets from you and the users you follow */
void getNewsfeed(twitter *twitter);

/* Allows the user to follow/unfollow other users */
void follow(twitter *twitter);
void unfollow(twitter *twitter);

/* Used in debugging, gives stats about logged in user */
void print_user_info(twitter *twitter);

/* closes the program */
void exit_twitter(void);
