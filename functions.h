#include "objects.h"

void initialise_user(char username[USERNAME_LENGTH], user* user, twitter* twitter);
tweet initialise_tweet(size_t userID);
twitter initialise_twitter(void);
char *get_unique_username(twitter *twitter);
void list_users(twitter *twitter);
char *get_existing_username(twitter *twitter);


/* returns true if item is in list of length length -> is_in(item, list, length) */
int is_in(size_t item, size_t list[], size_t length);