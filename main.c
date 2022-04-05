#include <stdio.h>
#include "objects.h"
#include "user_functions.h"
#include "functions.h"

int main(void) {
    twitter twitter = initialise_twitter();
    twitter.current_userID = create_account(twitter);
    

    return 0;
}