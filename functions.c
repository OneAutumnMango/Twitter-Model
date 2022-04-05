#include "functions.h"
#include <stdio.h>
#include <string.h>

/* Contains hidden functions not available to the user */
/* Struct initialisers */

user initialise_user(char username[USERNAME_LENGTH]) {
    user user = {username, NULL, 0, NULL, 0}; /* {username, followers, count, following, count} */
    return user;
}

tweet initialise_tweet(size_t userID) { /* twitter.current_user */
    tweet tweet = {userID, ""};         /* {username, tweet} */
    return tweet;
}

twitter initialise_twitter(void) {
    twitter twitter = {NULL, 0, NULL, NULL}; /* {userlist, user_count, curr_userID, mr_tweet} */
    return twitter;
}

int is_in(size_t item, size_t list[], size_t length) { /* returns true is item is in list[] */
    for (size_t i = 0; i < length; i++) {              /* might have to declare size of list[] */
        if (list[i] == item)
            return 1;
    }
    return 0;
}

void list_users(twitter twitter) { /* to list users to follow */
    user user = twitter.userlist[twitter.current_userID];
    for (size_t i = 0; i < twitter.user_count; i++) {
        if (i == twitter.current_userID || is_in(i, user.following, user.following_count)) {
            continue; /* no need to list yourself to follow or if you are following them */
        }
        printf("%s", twitter.userlist[i].username);
    }
}

int is_unique(twitter twitter, char* username) { /* Checks if the username given already exists */
    for (size_t i = 0; i < twitter.user_count; i++) {
        if (strcmp(username, twitter.userlist[i].username) == 0) {
            return 0;
        }
    }
    return 1;
}

char *get_username(twitter twitter) {
    char *username = (char *)malloc(USERNAME_LENGTH);
    do {
        size_t i = 0;
        printf("Please enter a unique username.");
        fgets(username, USERNAME_LENGTH, stdin);
        i++;

    } while (!is_unique(twitter, username));
    return username;
}
/* need this cause if a user wants to log into an already existing account,
   we have to either search a parallel string array, or check userlist[i].username
   (which should work with the same funciton) */
// int is_in_str(char item[], char list[][], size_t length);

/* go through userlist[i].username stop once found, or if at end*/
