/* contains hidden functions like 
 * initialise_user()
 * initialise_twitter()
 * initialise_tweet()
 * 
 */
#include "objects.h"

user initialise_user(char username[USERNAME_LENGTH]) {
    user tmp_user = {username, "", 0, "", 0}; /* {username, followers, count, following, count} */
    return tmp_user;
}

tweet initialise_tweet(char username[USERNAME_LENGTH]) {  /* twitter.current_user */
    tweet tmp_tweet = {username, "", 0}; /* {username, tweet, tweetID} */
    return tmp_tweet;
}

twitter initialise_twitter(void) {
    twitter twitter = {NULL, NULL, NULL};
    return twitter;
}