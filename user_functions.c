/*
postTweet(...): Allows a user to post a tweet. In other words, a new tweet will be added to the news_feed containing the posted tweets in the Twitter System. Note that each tweet should be identified by a unique id. This should be an integer representing a timestamp which is incremented every time a new tweet is posted.
getNewsFeed(...): Retrieves and prints  the 10 most recent tweets posted by users whom the user is following or by the user themself. Tweets must be ordered and printed from the most to the least recent. Note that you should not visualise tweets from users who deleted their account.
follow(...): Allows a user to follow a valid user that s/he is not following yet. This function should first retrieve and print the usernames of the users that the current user does not follow. This will allow the current user to select a valid username of a user s/he wants to follow - if available.
unfollow(...): Allows a user to unfollow a valid user that s/he is following.
delete (...): Allows a user to delete his/her account
endTurn(): tells the Twitter System to move to the next user
endTwitter(): terminates the program.
 */

/* All functions available to user */

#include "user_functions.h"
#include <stdio.h>

// Returns the tweet written by the user
tweet postTweet(size_t current_userID)
{
    tweet newTweet = {current_userID, NULL};
    printf("Write your tweet here. You have 280 characters:\n\n");
    scanf("%s", newTweet.tweet);
    printf("\n Tweet Sent!");
    return newTweet;
}
