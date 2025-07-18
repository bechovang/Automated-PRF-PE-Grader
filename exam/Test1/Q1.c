#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Function: is_perfect_square
 *  - Input: an integer n
 *  - Output: returns 1 if n is a perfect square, otherwise returns 0
 */
int is_perfect_square(int n) {
    // WRITE YOUR CODE HERE



    // END OF YOUR CODE
}

//====DO NOT ADD OR CHANGE ANY STATEMENTS IN THE MAIN FUNCTION====
int main() {
    system("cls");
    printf("\nTEST Q1:\n");
    int n;
    printf("Enter an integer n = ");
    scanf("%d", &n);

    int result = is_perfect_square(n);

    //====DO NOT ADD OR CHANGE ANY STATEMENTS AFTER THIS LINE====
    //==THE OUTPUT AFTER THIS LINE WILL BE USED TO GRADE YOUR SUBMISSION==
    printf("\nOUTPUT:\n");
    if (result == 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    printf("\n");
    system("pause");
    return 0;
}