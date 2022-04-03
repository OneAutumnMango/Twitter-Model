#include "functions.h"


/* Contains hidden functions no available to the user */
/* Struct initialisers */

user initialise_user(char username[USERNAME_LENGTH]) {
    user user = {username, NULL, 0, NULL, 0}; /* {username, followers, count, following, count} */
    return user;
}

tweet initialise_tweet(size_t userID) {  /* twitter.current_user */
    tweet tweet = {userID, ""}; /* {username, tweet} */
    return tweet;
}

twitter initialise_twitter(void) {
    twitter twitter = {{NULL}, NULL, NULL};  /* {userlist, curr_userID, mr_tweet} */
    return twitter;
}



bool is_in(size_t item, size_t list[], size_t length) {  /* returns true is item is in list[] */
    for (size_t i = 0; i < length; i++) {  /* might have to declare size of list[] */
        if (list[i] == item)
            return true;
    }
    return false;
}