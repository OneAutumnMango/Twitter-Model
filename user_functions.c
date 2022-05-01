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

size_t create_account(twitter *twitter) {
    char username[USERNAME_LENGTH];
    strcpy(username, get_username(twitter));
    user user = initialise_user(username);

    twitter->userlist[twitter->user_count] = user;
    twitter->user_count++;

    return twitter->user_count - 1;  /* returns userID */
}

void login(twitter *twitter) {
    char username[USERNAME_LENGTH];
    printf("Please enter your username:");
    fgets(username, USERNAME_LENGTH, stdin);
    
    for (size_t i = 0; i < twitter->user_count; i++) {
        if (strcmp(username, twitter->userlist[i].username) == 0) {
            twitter->current_userID = i;
            printf("User successfully logged-in.\n");
            return;
        }
    }
    printf("Error: Username specified not found.\n");
}

// Returns the tweet written by the user
void postTweet(twitter *twitter) {
    tweet newTweet = initialise_tweet(twitter->current_userID);
    strcpy(newTweet.tweetAuthor,twitter->userlist->username);

    printf("Write your tweet here. You have 280 characters:\n\n");
    fgets(newTweet.tweet, TWEET_LENGTH, stdin);
    printf("\n Tweet Sent!\n\n");
    twitter->most_recent_tweet = push(newTweet, twitter->most_recent_tweet); /* adds newTweet to the linked list */
}

void getNewsfeed(twitter *twitter) {
    size_t count = 0;
    user user = twitter->userlist[twitter->current_userID];
    Node *current_node = twitter->most_recent_tweet;
    printf("**************\nYour News Feed\n**************\n");
    while (count < 10 || current_node->next_node != NULL) { /* found 10 tweets or reached end of list */
        if (is_in(current_node->tweet.userID, user.following, user.following_count)) {
            count++;
            /* add time sent + formatting + L + ratio */
            printf("\n\t%s - TIME HERE?", current_node->tweet.tweetAuthor);
            printf("\n%s\n", current_node->tweet.tweet);
        }
        current_node = current_node->next_node; /* cycle to next node */
    }
    printf("****************\nEnd of News Feed\n****************\n");
}

void follow(twitter *twitter) {
    char* wantToFollow;
    twitter->userlist->following_count++;
    while (1) {
        puts("These are the users available to follow:");
        list_users(&twitter);
        puts("Which user would you like to follow? :");
        fgets(wantToFollow, USERNAME_LENGTH, stdin);  /* UPDATE TO LINKED LIST*/
        for (size_t i = 0; i < USER_MAX; i++) {
            if (strcmp(wantToFollow, twitter->userlist[i].username) == 0) {
                twitter->userlist[i].follower_count++;
                twitter->userlist[i].followers[twitter->current_userID] = 1;
                return;
            }
        }
        puts("That username was not found");
    }

}