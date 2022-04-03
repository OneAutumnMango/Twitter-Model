/* contains hidden functions like 
 * initialise_user()
 * initialise_twitter()
 * initialise_tweet()
 * 
 */
#include "objects.h"
#include <stdlib.h>

user initialise_user(char username[USERNAME_LENGTH]) {
    user tmp_user = {username, NULL, 0, NULL, 0}; /* {username, followers, count, following, count} */
    return tmp_user;
}

tweet initialise_tweet(size_t userID) {  /* twitter.current_user */
    tweet tmp_tweet = {userID, ""}; /* {username, tweet} */
    return tmp_tweet;
}

twitter initialise_twitter(void) {
    twitter twitter = {{NULL}, NULL, NULL};
    return twitter;
}