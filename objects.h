#include <stdlib.h>

#define TWEET_LENGTH 280
#define USERNAME_LENGTH 100
#define FOLLOW_MAX 30 
#define USER_MAX 100


typedef struct tweet {
    size_t userID;  /* index of user in userlist */
    char tweet[TWEET_LENGTH];
} tweet;

typedef struct user {
    char username[USERNAME_LENGTH];
    size_t followers[FOLLOW_MAX];  /* collection of userID's */
    size_t follower_count;  /* need to check if < FOLLOW_MAX before adding to followers[] */
    size_t following[FOLLOW_MAX];
    size_t following_count;
} user; 

/* linked list of all tweets, go through them until you have 10 with username in following */

typedef struct Node {
    tweet tweet;
    Node *previous_node;  /* link to previously most recent tweet */
} Node;

typedef struct twitter {
    user userlist[USER_MAX];
    size_t user_count;  /* when making new user, userID = user_count, then increment count */
    size_t current_userID;
    Node *most_recent_tweet;  /* Probably want to change the name 
    of this (start of the linked list) */
} twitter;