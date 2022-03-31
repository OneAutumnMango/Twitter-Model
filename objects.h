#include <stdlib.h>

#define TWEET_LENGTH 270
#define USERNAME_LENGTH 100
#define FOLLOW_MAX 30
#define TWEET_MAX 100 
#define USER_MAX 100


typedef struct tweet {
    char username[USERNAME_LENGTH];
    char tweet[TWEET_LENGTH];
    size_t tweetID;
    size_t time_stamp;
} tweet;

typedef struct user {
    char username[USERNAME_LENGTH];
    char followers[FOLLOW_MAX][USERNAME_LENGTH];
    size_t follower_count;
    char following[FOLLOW_MAX][USERNAME_LENGTH];
    size_t following_count;
} user;