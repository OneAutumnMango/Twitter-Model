#include "objects.h"
#include <stdlib.h>

struct tweet {
    char username[USERNAME_LENGTH];
    char tweet[TWEET_LENGTH];
    size_t tweetID;
    size_t time_stamp;
};
typedef struct tweet tweet;

struct user {
    char username[USERNAME_LENGTH];
    tweet feed[TWEET_MAX];
    
};
typedef struct user user;