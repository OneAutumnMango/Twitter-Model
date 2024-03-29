#include "functions.h"
#include "linked_list.h"
#include "objects.h"
#include "user_functions.h"
#include <stdio.h>

int main(void) {

    twitter twitter = initialise_twitter();

    puts("---- Welcome to Twitter! ----\n\n");

    create_account(&twitter);

    char *buffer = malloc(sizeof(char));
    int choice = 1;

    while (choice != 9) { /* Loops the program until program is ended by the user */
        puts("\nWhat do you want to do?\n\n"
             "1 - Create a new account\n"
             "2 - Log into an existing account\n"
             "3 - Print Current User Info\n"
             "4 - Post a Tweet\n"
             "5 - Get your News Feed\n"
             "6 - Follow a user\n"
             "7 - Unfollow a user\n"
             "8 - Delete this account\n"
             "9 - Exit Twitter\n"
             "\n"
             "Please select a number corresponding to one of the options above\n");

        scanf("%c", buffer);
        fflush(stdin); /* This function doesn't seem to work in Linux so don't use Linux i guess. */
        choice = atol(buffer);

        switch (choice) { /* Switch Statement for all of the choices outlined above */
        case 1:
            create_account(&twitter);
            break;
        case 2:
            login(&twitter);
            break;
        case 3:
            print_user_info(&twitter);
            break;
        case 4:
            postTweet(&twitter);
            break;
        case 5:
            getNewsfeed(&twitter);
            break;
        case 6:
            follow(&twitter);
            break;
        case 7:
            unfollow(&twitter);
            break;
        case 8:
            remove_users_tweets(&twitter);
            delete_current_user(&twitter);
            break;
        case 9:
            exit_twitter();
            break;
        case -1: /* secret hidden user function ooh hooh */
            print_all_tweets(&twitter);
            break;
        default:
            puts("Sorry, that was not a valid command.\n");
        }
    }

    return 0;
}