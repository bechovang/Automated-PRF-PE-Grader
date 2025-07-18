#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Function: get_game_result
 *  - Input: Two strings, 'player1_choice' and 'player2_choice'.
 *           Each string will be one of "rock", "paper", or "scissors".
 *  - Output: Returns an integer representing the result:
 *            - 1 if Player 1 wins.
 *            - 2 if Player 2 wins.
 *            - 0 if it's a tie.
 */
int get_game_result(const char* player1_choice, const char* player2_choice) {
    // so sánh tie
    if (strcmp(player1_choice, player2_choice) == 0) {
        return 0;
    }
    // Player 1 win
    if ((strcmp(player1_choice, "rock") == 0     && strcmp(player2_choice, "scissors") == 0) ||
        (strcmp(player1_choice, "paper") == 0    && strcmp(player2_choice, "rock") == 0)     ||
        (strcmp(player1_choice, "scissors") == 0 && strcmp(player2_choice, "paper") == 0)) {
        return 1;
    }
    // Player 2 win
    if ((strcmp(player2_choice, "rock") == 0     && strcmp(player1_choice, "scissors") == 0) ||
        (strcmp(player2_choice, "paper") == 0    && strcmp(player1_choice, "rock") == 0)     ||
        (strcmp(player2_choice, "scissors") == 0 && strcmp(player1_choice, "paper") == 0)) {
        return 2;
    }
    // Nếu vào đây tức là input không hợp lệ
    return -1;
}



//====DO NOT ADD OR CHANGE ANY STATEMENTS IN THE MAIN FUNCTION====
int main() {
    system("cls");
    printf("\nTEST Q3:\n");
    char p1[20], p2[20];

    printf("Enter Player 1 choice: ");
    scanf("%s", p1);
    printf("Enter Player 2 choice: ");
    scanf("%s", p2);

    int result = get_game_result(p1, p2);

    //====DO NOT ADD OR CHANGE ANY STATEMENTS AFTER THIS LINE====
    //==THE OUTPUT AFTER THIS LINE WILL BE USED TO GRADE YOUR SUBMISSION==
    printf("\nOUTPUT:\n");
    switch (result) {
        case 1:
            printf("Player 1 wins\n");
            break;
        case 2:
            printf("Player 2 wins\n");
            break;
        case 0:
            printf("It's a tie\n");
            break;
        default:
            printf("Invalid result\n");
    }

    printf("\n");
    system("pause");
    return 0;
}