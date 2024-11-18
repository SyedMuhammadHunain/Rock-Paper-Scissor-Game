#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char* choice(int choice) {
    switch (choice) {
        case 1:
            return "Rock";
        case 2:
            return "Paper";
        case 3:
            return "Scissor";
        default:
            return "Invalid";
    }
}

void game_instructions() {
    printf("|        INSTRUCTIONS       |\n");
    printf("| Press 1 to choose Rock    |\n");
    printf("| Press 2 to choose Paper   |\n");
    printf("| Press 3 to choose Scissor |\n");
    printf("| Press Q to Quit           |\n\n");
}

void title() {
    printf("================================================\n\n");
    printf("     WELCOME TO THE ROCK, PAPER, SCISSOR GAME   \n\n");
    printf("           Presented To You By:                    \n");
    printf("                    Syed Muhammad Hunain          \n\n");
    printf("=================================================\n\n");
}

int main() {
    int player_score = 0, computer_score = 0;
    char player_choice[10];
    
    title();
    game_instructions();

    char player_name[30];

    printf("Enter Your Name Here: ");
    scanf("%[^\n]s", player_name);
    getchar();  // remove \n

    srand(time(0));

    while (1) {
        printf("\nYour Choice Here: ");
        scanf("%s", player_choice);
        getchar();  

        if (player_choice[0] == 'Q' || player_choice[0] == 'q') {
            printf("\nTHANK YOU FOR PLAYING, %s!\n", player_name);
            break;
        }

        int player_num = atoi(player_choice);
        if (player_num < 1 || player_num > 3) {
            printf("Invalid choice. Try again.\n");
            continue;
        }

        int computer_num = rand() % 3 + 1;

        printf("\nYou chose: %s\n", choice(player_num));
        printf("Computer chose: %s\n", choice(computer_num));

        if ((player_num == 1 && computer_num == 3) || 
            (player_num == 2 && computer_num == 1) || 
            (player_num == 3 && computer_num == 2)) {
            player_score++;
            printf("\n------------------------------\n");
            printf("\tYou Win!\n");
        } else if (player_num == computer_num) {
            printf("\n------------------------------\n");
            printf("\tIt's a Tie!\n");
        } else {
            computer_score++;
            printf("\n------------------------------\n");
            printf("\tYou Lose!\n");
        }

        printf("------------------------------\n");
        printf("%s Score: %d\nBot Score: %d\n", player_name, player_score, computer_score);
    }

    return 0;
}
