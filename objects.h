#include <stdlib.h>

#define TWEET_LENGTH 280
#define USERNAME_LENGTH 100
#define FOLLOW_MAX 30 
#define USER_MAX 100


typedef struct tweet {
    char username[USERNAME_LENGTH];
    char tweet[TWEET_LENGTH];
    size_t tweetID;
} tweet;

typedef struct user {
    char username[USERNAME_LENGTH];
    char followers[FOLLOW_MAX][USERNAME_LENGTH];
    size_t follower_count;  /* need to check if < FOLLOW_MAX before adding to followers[] */
    char following[FOLLOW_MAX][USERNAME_LENGTH];
    size_t following_count;
} user; 

/* linked list of all tweets, go through them until you have 10 with username in following */

typedef struct Node {
    tweet tweet;
    Node *next;
} Node;

typedef struct twitter {
    user users[USER_MAX];
    user current_user;
    Node *inital_tweet;  /* first tweet in linked list of Nodes */
} twitter;