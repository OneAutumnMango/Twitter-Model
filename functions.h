#include "objects.h"

user *initialise_user(char username[USERNAME_LENGTH], twitter *twitter);

tweet initialise_tweet(size_t userID);

twitter initialise_twitter(void);

size_t list_users_login(twitter *twitter);
size_t list_users_to_follow(twitter *twitter);
size_t list_users_following(twitter *twitter);

/* prompts for an unique username, keeps trying until given */
char *get_unique_username(twitter *twitter);

/* prompts for an existing username, keeps trying until given */
char *get_existing_username(twitter *twitter);


/* returns true if item is in list of length length -> is_in(item, list, length) */
int is_in(size_t item, size_t list[], size_t length);

void print_all_tweets(twitter* twitter);