#include "functions.h"
#include <stdio.h>
#include <string.h>

/* Contains hidden functions not available to the user */
/* Struct initialisers */

void initialise_user(char *username, user* user,twitter *twitter) {
    strcpy(user->username, username);
    user->following_count = 0;
    user->follower_count = 0;
    user->userID = twitter->user_count; /* give user new userid, and increments usercount */
    twitter->user_count++;
}

tweet initialise_tweet(size_t userID) { /* twitter.current_user */
    tweet tweet = {userID, "", ""};     /* {userID, username, tweet} */
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

void list_users(twitter *twitter) { /* to list users to follow */
    user *user = twitter->current_user->user;
    UserNode *current = twitter->userlist;
    size_t i = 0;
    while (current != NULL) {
        if (current == twitter->current_user || is_in(i, user->following, user->following_count)) {
            current = current->next;
            continue; /* no need to list yourself or people you are already following */
        }
        printf("%s\n", current->user->username);
        i++;
        current = current->next;
    }
}

int is_unique(twitter *twitter, char *username) { /* Checks if the username given already exists */
    UserNode *current = twitter->userlist;
    while (current != NULL) {
        if (strcmp(username, current->user->username) == 0) {
            return 0;
        }
        current = current->next;
    }
    return 1;
}

char *get_unique_username(twitter *twitter) {
    char *username = malloc(sizeof(char) * USERNAME_LENGTH);
    do {
        printf("Please enter a unique username:");
        fgets(username, USERNAME_LENGTH, stdin);
        int len = strlen(username);
        if (username[len - 1] == '\n')
            username[len - 1] = '\0';

    } while (!is_unique(twitter, username));
    return username;
}

char *get_existing_username(twitter *twitter) {
    char *username = malloc(sizeof(char) * USERNAME_LENGTH);
    do {
        printf("\nPlease enter a username from above: ");
        fgets(username, USERNAME_LENGTH, stdin);
        int len = strlen(username);
        if (username[len - 1] == '\n')
            username[len - 1] = '\0';

    } while (is_unique(twitter, username));
    return username;
}
