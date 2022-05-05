#include "objects.h"

/* creates user, adds it to the user list and logs-in as them */
void create_account(twitter *twitter);

/* logs-in as given user */
void login(twitter *twitter);

void postTweet(twitter *twitter);

/* prints up to 10 most recent tweets from you and the users you follow */
void getNewsfeed(twitter *twitter);

void follow(twitter *twitter);
void unfollow(twitter *twitter);

void print_user_info(twitter* twitter);

/* closes the program */
void exit_twitter(void);


