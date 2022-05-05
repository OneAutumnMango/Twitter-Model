#include "objects.h"

user* initialise_user(char username[USERNAME_LENGTH], twitter* twitter);
tweet initialise_tweet(size_t userID);
twitter initialise_twitter(void);
char *get_unique_username(twitter *twitter);
int list_users(twitter *twitter);
int list_users_following(twitter *twitter);
char *get_existing_username(twitter *twitter);


/* returns true if item is in list of length length -> is_in(item, list, length) */
int is_in(size_t item, size_t list[], size_t length);