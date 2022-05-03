#include <stdio.h>
#include "objects.h"
#include "user_functions.h"
#include "functions.h"

int main(void) {

    twitter twitter = initialise_twitter();
    initialise_user("poopy", &twitter);
    create_account(&twitter);
    create_account(&twitter);
    printf("%lu %lu\n", twitter.current_user->user->userID, twitter.user_count);
    create_account(&twitter);
    printf("%lu %lu\n", twitter.current_user->user->userID, twitter.user_count);
//    login(&twitter);
//    printf("%u %u\n", twitter.current_userID, twitter.user_count);
//    list_users(&twitter);
    follow(&twitter);
    postTweet(&twitter);
    postTweet(&twitter);
    postTweet(&twitter);
    postTweet(&twitter);
    postTweet(&twitter);
    postTweet(&twitter);
    postTweet(&twitter);
    postTweet(&twitter);
    postTweet(&twitter);
    postTweet(&twitter);
    postTweet(&twitter);
    getNewsfeed(&twitter);
    printf("%lu %lu\n", twitter.current_user->user->userID, twitter.user_count);

    printf("%lu %lu\n", twitter.current_user->user->userID, twitter.user_count);
//    getNewsfeed(&twitter);
    printf("%lu %lu\n", twitter.current_user->user->userID, twitter.user_count);
    twitter.current_user->user->userID = 1;
    postTweet(&twitter);
    getNewsfeed(&twitter);


    return 0;
}