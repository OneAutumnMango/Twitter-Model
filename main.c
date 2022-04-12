#include <stdio.h>
#include "objects.h"
#include "user_functions.h"
#include "functions.h"

int main(void) {

    twitter twitter = initialise_twitter();
    printf("%u %u\n", twitter.current_userID, twitter.user_count);
    twitter.current_userID = create_account(&twitter);
    printf("%u %u\n", twitter.current_userID, twitter.user_count);
    twitter.current_userID = create_account(&twitter);
    printf("%u %u\n", twitter.current_userID, twitter.user_count);
   /* login(&twitter);
    printf("%u %u\n", twitter.current_userID, twitter.user_count);*/

    postTweet(&twitter);
    postTweet(&twitter);
    getNewsfeed(&twitter);

    return 0;
}