#include "objects.h"

user initialise_user(char username[USERNAME_LENGTH]);
tweet initialise_tweet(size_t userID);
twitter initialise_twitter(void);
char *get_username(twitter twitter);


/* returns true if item is in list of length length -> is_in(item, list, length) */
int is_in(size_t item, size_t list[], size_t length);