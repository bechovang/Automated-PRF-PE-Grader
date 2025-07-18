#include <stdio.h>
#include <stdlib.h>

/*
 * Function: find_next_day
 *  - Input: Pointers to day and month variables.
 *  - Task: Update the variables to represent the next day and month.
 */
void find_next_day(int *day, int *month) {
    // WRITE YOUR CODE HERE
    
    // Array storing the number of days in each month. February always has 28.
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Increment the day by 1.
    (*day)++;

    // If the day exceeds the number of days in the current month...
    if (*day > days_in_month[*month]) {
        *day = 1;      // ...reset day to 1.
        (*month)++;    // ...increment the month.
        
        // If the month exceeds 12 (i.e., after December)...
        if (*month > 12) {
            *month = 1; // ...wrap around to January.
        }
    }
    
    // END OF YOUR CODE
}

//====DO NOT ADD OR CHANGE ANY STATEMENTS IN THE MAIN FUNCTION====
int main() {
    system("cls");
    printf("\nTEST Q4:\n");
    int d, m;

    printf("Enter day and month (dd mm): ");
    scanf("%d %d", &d, &m);

    // Assume the input is always valid.
    find_next_day(&d, &m);
    
    //====DO NOT ADD OR CHANGE ANY STATEMENTS AFTER THIS LINE====
    //==THE OUTPUT AFTER THIS LINE WILL BE USED TO GRADE YOUR SUBMISSION==
    printf("\nOUTPUT:\n");
    printf("The next day is: %02d/%02d", d, m);

    printf("\n");
    system("pause");
    return 0;
}