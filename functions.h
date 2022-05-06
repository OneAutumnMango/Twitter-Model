#include "objects.h"

/* Allocates space in memory for a new user & sets the username + counts */
user *initialise_user(char username[USERNAME_LENGTH], twitter *twitter);

/* Allocates space in memory for a new tweet */
tweet initialise_tweet(size_t userID);

/* Creates the Twitter object */
twitter initialise_twitter(void);

/* lists different sets of users */
size_t list_users_login(twitter *twitter);      /* all other users*/
size_t list_users_to_follow(twitter *twitter);  /* all users that you dont follow */
size_t list_users_following(twitter *twitter);  /* all users that you follow */

/* prompts for an unique username, keeps trying until given */
char *get_unique_username(twitter *twitter);

/* prompts for an existing username, keeps trying until given */
char *get_existing_username(twitter *twitter);

/* returns true if item is in list of length length -> is_in(item, list, length) */
int is_in(size_t item, size_t list[], size_t length);

/* secret command for testing ;) */
void print_all_tweets(twitter *twitter);