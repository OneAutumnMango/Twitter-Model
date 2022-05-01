#include <stdlib.h>

#define TWEET_LENGTH 280
#define USERNAME_LENGTH 100
#define FOLLOW_MAX 30

#ifndef OBJECTS
#define OBJECTS

typedef struct tweet {
    size_t userID;  /* index of user in userlist */
    char tweetAuthor[USERNAME_LENGTH];
    char tweet[TWEET_LENGTH];
} tweet;

typedef struct user {
    char username[USERNAME_LENGTH];
    size_t userID;
    size_t followers[FOLLOW_MAX];  /* collection of userID's */
    size_t follower_count;  /* need to check if < FOLLOW_MAX before adding to followers[] */
    size_t following[FOLLOW_MAX];
    size_t following_count;
} user;


typedef struct TweetNode {
    tweet tweet;
    struct TweetNode *next_node;  /* link to previously most recent tweet */
} TweetNode;

typedef struct UserNode {
    user* user;
    struct UserNode *next;
    struct UserNode *previous;
} UserNode;


typedef struct twitter {
    UserNode* userlist;  /* start of userlist */
    size_t user_count;
    UserNode* current_user;  /* pointer to current usernode */
    TweetNode *most_recent_tweet;  /* Probably want to change the name
    of this (start of the linked list) */
} twitter;

#endif