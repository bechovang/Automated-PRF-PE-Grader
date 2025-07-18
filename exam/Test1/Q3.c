#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

/*
 * Function: calculate_conditional_sum
 *  - Input: An array 'arr' and its size 'n'.
 *  - Output: Returns the sum of even or odd numbers based on the condition.
 */
long long calculate_conditional_sum(int arr[], int n) {
    // WRITE YOUR CODE HERE



    // END OF YOUR CODE
}

//====DO NOT ADD OR CHANGE ANY STATEMENTS IN THE MAIN FUNCTION====
int main() {
    system("cls");
    printf("\nTEST Q3:\n");
    int arr[MAX_SIZE];
    int n, i;

    printf("Enter the number of elements n = ");
    scanf("%d", &n);
    
    if (n > 0 && n <= MAX_SIZE) {
        printf("Enter %d elements for the array:\n", n);
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        long long total = calculate_conditional_sum(arr, n);

        //====DO NOT ADD OR CHANGE ANY STATEMENTS AFTER THIS LINE====
        //==THE OUTPUT AFTER THIS LINE WILL BE USED TO GRADE YOUR SUBMISSION==
        printf("\nOUTPUT:\n");
        printf("%lld", total);

    } else {
        printf("Invalid number of elements.\n");
    }

    printf("\n");
    system("pause");
    return 0;
}