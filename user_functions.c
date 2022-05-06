#include "user_functions.h"
#include "functions.h"
#include "linked_list.h"
#include <stdio.h>
#include <string.h>

/* All functions available to user */

void create_account(twitter *twitter) {
    char *username = malloc(sizeof(char) * USERNAME_LENGTH);
    strcpy(username, get_unique_username(twitter));

    user *user = initialise_user(username, twitter);
    push_user(user, twitter);                  /* Add user to linked list */
    twitter->current_user = twitter->userlist; /* set created user as current user */

    puts("Your account has been created!\n");
}

void login(twitter *twitter) {
    char username[USERNAME_LENGTH];
    puts("---- Which user would you like to login as? ----\n");
    list_users_login(twitter);
    puts("\n---- Please enter a username ----\n");
    strcpy(username, get_existing_username(twitter));

    UserNode *current = twitter->userlist;
    while (current != NULL) {
        if (strcmp(username, current->user->username) == 0) { /* if username matches current */
            twitter->current_user = current;                  /* set user as current user */
            puts("---- User successfully logged-in ----\n");

            return;
        }
        current = current->next; /* cycle to next */
    }
    puts("Error: Username specified not found.\n");

    puts("Press Enter to Continue\n");
    while (getchar() != '\n');
}

// Returns the tweet written by the user
void postTweet(twitter *twitter) {
    tweet newTweet = initialise_tweet(twitter->current_user->user->userID);         /* Create a tweet */
    strcpy(newTweet.tweetAuthor, twitter->current_user->user->username);       /* Add username to tweet */

    printf("---- Write your tweet here ----\n\nYou have 280 characters:\n");
    fgets(newTweet.tweet, TWEET_LENGTH, stdin);                          /* Add the text to the tweet*/
    printf("\n---- Tweet Sent! ----\n");
    twitter->most_recent_tweet = push_tweet(newTweet, twitter->most_recent_tweet); /* adds newTweet to the linked list */
}

void getNewsfeed(twitter *twitter) {
    size_t count = 0;
    user *user = twitter->current_user->user;
    TweetNode *current = twitter->most_recent_tweet;

    printf("---- Your News Feed ----\n");
    while (count < 10 && current != NULL) { /* found 10 tweets or reached end of list */
        if (is_in(current->tweet.userID, user->following, user->following_count) ||
            current->tweet.userID == user->userID) {
            count++;    /* count increments only if a tweet is displayed */
            /* add time sent? + formatting + L + ratio */
            printf("\n - %s", current->tweet.tweetAuthor);  /* Prints the Tweet's Author */
            printf("\n%s\n", current->tweet.tweet);         /* Prints the Tweet's Text */
        }
        current = current->next; /* cycle to next node */
    }
    printf("---- End of News Feed ----\n");
    printf("\nPress Enter to Continue\n");
    while (getchar() != '\n');
}

void follow(twitter *twitter) {
    char *wantToFollow = malloc(sizeof(char) * USERNAME_LENGTH);
    while (1) {
        UserNode *current = twitter->userlist;
        puts("These are the users available to follow:");
        size_t listLen = list_users_to_follow(twitter);

        if (listLen == 0) { /* If there are no users available to follow */
            puts("There are no users available to follow");
            printf("\nPress Enter to Continue\n");
            while (getchar() != '\n');
            return;
        }

        strcpy(wantToFollow, get_existing_username(twitter));
        while (current != NULL) {
            if (strcmp(wantToFollow, current->user->username) == 0) {                                                           /* If the username matches, follow them by;*/
                current->user->followers[current->user->follower_count] = twitter->current_user->user->userID;                  /* Add your userID to their follower array */
                twitter->current_user->user->following[twitter->current_user->user->following_count] = current->user->userID;   /* Add their userID to your following array*/
                current->user->follower_count++;                                                                                /* Increment their follower_count */
                twitter->current_user->user->following_count++;                                                                 /* Increment your following_count */

                printf("%s has been followed\n", wantToFollow);
                free(wantToFollow);

                return;
            }
            current = current->next;
        }
        puts("That username was not found");
    }
}

void unfollow(twitter *twitter) {
    char *wantToUnfollow = malloc(sizeof(char) * USERNAME_LENGTH);
    while (1) {
        UserNode *current = twitter->userlist;
        puts("These are the users you follow:");
        size_t listLen = list_users_following(twitter);

        if (listLen == 0) { /* If there are no users available to unfollow */
            puts("You do not follow anybody!");
            printf("\nPress Enter to Continue\n");
            while (getchar() != '\n');
            return;
        }

        strcpy(wantToUnfollow, get_existing_username(twitter));
        while (current != NULL) {
            if (strcmp(wantToUnfollow, current->user->username) == 0) {                         /* If the username matches */
                for (int i = 0; i < current->user->follower_count; ++i) {                       /* Loop through their followers[] */
                    if (current->user->followers[i] == twitter->current_user->user->userID) {   /* Once you find your userID */
                        current->user->followers[i] = -1;                                       /* set it to an unreachable userID */
                    }
                }
                for (int i = 0; i < twitter->current_user->user->following_count; ++i) {        /* Loop through your following[] */
                    if (current->user->userID == twitter->current_user->user->following[i]) {   /* Once you find their userID */
                        twitter->current_user->user->following[i] = -1;                         /* set it to an unreachable userID */
                    }
                }
                printf("%s has been unfollowed!\n", wantToUnfollow);
                free(wantToUnfollow);

                return;
            }
            current = current->next;
        }
        puts("That username was not found");
    }
}

void print_user_info(twitter *twitter) {    /* Was very useful for debugging even though it was not outlined in problem spec */
    user *user = twitter->current_user->user;
    printf("---- User %lu's Account Info. ----\n - Username: %s\n - Follower Count: %lu\n - Following Count: %lu\n--------------------------------\n", user->userID, user->username, user->follower_count, user->following_count);
}

void exit_twitter(void) {   /* Yes */
    printf("Exiting twitter!\nThanks for using our program!");
    exit(0);
}