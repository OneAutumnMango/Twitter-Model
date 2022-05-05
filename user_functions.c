/*
postTweet(...): Allows a user to post a tweet. In other words, a new tweet will be added to the news_feed containing the posted tweets in the Twitter System. Note that each tweet should be identified by a unique id. This should be an integer representing a timestamp which is incremented every time a new tweet is posted.
getNewsFeed(...): Retrieves and prints  the 10 most recent tweets posted by users whom the user is following or by the user themself. Tweets must be ordered and printed from the most to the least recent. Note that you should not visualise tweets from users who deleted their account.
follow(...): Allows a user to follow a valid user that s/he is not following yet. This function should first retrieve and print the usernames of the users that the current user does not follow. This will allow the current user to select a valid username of a user s/he wants to follow - if available.
unfollow(...): Allows a user to unfollow a valid user that s/he is following.
delete (...): Allows a user to delete his/her account
endTurn(): tells the Twitter System to move to the next user
after endTurn() prompt login/create account same as when you start twitter up

endTwitter(): terminates the program.
*/
/* All functions available to user */

#include "user_functions.h"
#include "functions.h"
#include "linked_list.h"
#include <stdio.h>
#include <string.h>

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
    list_users_to_follow(twitter);
    puts("\n---- Please enter a username ----\n");
    strcpy(username, get_existing_username(twitter));

    UserNode *current = twitter->current_user;
    while (current != NULL) {
        if (strcmp(username, current->user->username) == 0) { /* if username matches current */
            twitter->current_user = current;                  /* set user as current user */
            puts("---- User successfully logged-in ----\n");

            puts("\nPress Enter to Continue\n");
            while (getchar() != '\n');
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
    tweet newTweet = initialise_tweet(twitter->current_user->user->userID);
    strcpy(newTweet.tweetAuthor, twitter->current_user->user->username);

    printf("---- Write your tweet here ----\n\nYou have 280 characters:\n");
    fgets(newTweet.tweet, TWEET_LENGTH, stdin);
    printf("\n---- Tweet Sent! ----\n");
    twitter->most_recent_tweet = push_tweet(newTweet,
                                            twitter->most_recent_tweet); /* adds newTweet to the linked list */
    printf("\nPress Enter to Continue\n");
    while (getchar() != '\n');
}

void getNewsfeed(twitter *twitter) {
    size_t count = 0;
    user *user = twitter->current_user->user;
    TweetNode *current = twitter->most_recent_tweet;
    printf("---- Your News Feed ----\n");
    while (count < 10 && current != NULL) { /* found 10 tweets or reached end of list */
        if (is_in(current->tweet.userID, user->following, user->following_count) ||
            current->tweet.userID == user->userID) {
            count++; /* add time sent + formatting + L + ratio */
            printf("\n - %s", current->tweet.tweetAuthor);
            printf("\n%s\n", current->tweet.tweet);
        }
        current = current->next_node; /* cycle to next node */
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

        if (listLen == 0) {     /* If there are no users available to follow */
            puts("There are no users available to follow");
            printf("\nPress Enter to Continue\n");
            while (getchar() != '\n');
            return;
        }

        strcpy(wantToFollow, get_existing_username(twitter));
        while (current != NULL) {
            if (strcmp(wantToFollow, current->user->username) == 0) {
                current->user->followers[current->user->follower_count] = current->user->userID;
                current->user->follower_count++;
                twitter->current_user->user->following_count++;

                printf("%s has been followed\n", wantToFollow);
                free(wantToFollow);

                printf("\nPress Enter to Continue\n");
                while (getchar() != '\n');
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

        if (listLen == 0) {     /* If there are no users available to unfollow */
            puts("You do not follow anybody!");
            printf("\nPress Enter to Continue\n");
            while (getchar() != '\n');
            return;
        }

        strcpy(wantToUnfollow, get_existing_username(twitter));
        while (current != NULL) {
            if (strcmp(wantToUnfollow, current->user->username) == 0) {
                for (int i = 0; i < current->user->follower_count; ++i) {
                    if (current->user->userID == twitter->current_user->user->userID) {
                        current->user->followers[current->user->follower_count] = 100;
                    }
                }
                printf("%s has been unfollowed!\n", wantToUnfollow);
                free(wantToUnfollow);

                printf("\nPress Enter to Continue\n");
                while (getchar() != '\n');
                return;
            }
            current = current->next;
        }
        puts("That username was not found");
    }
}

void exit_twitter(void) {
    printf("Exiting twitter!\nThanks for using our program!");
    exit(0);
}