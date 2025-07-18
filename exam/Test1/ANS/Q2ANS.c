#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

/*
 * Function: find_min_max_indices
 *  - Input: An array 'arr', its size 'n', a pointer to the min index, a pointer to the max index.
 *  - Task: Find and store the min/max indices in the pointer variables.
 */
void find_min_max_indices(int arr[], int n, int *min_idx, int *max_idx) {
    // WRITE YOUR CODE HERE
    
    // Assume the first element is both min and max initially.
    *min_idx = 0;
    *max_idx = 0;
    int i;

    // Iterate from the second element to compare.
    for (i = 1; i < n; i++) {
        // If a smaller number is found, update the min_idx.
        if (arr[i] < arr[*min_idx]) {
            *min_idx = i;
        }
        // If a larger number is found, update the max_idx.
        if (arr[i] > arr[*max_idx]) {
            *max_idx = i;
        }
    }

    // END OF YOUR CODE
}

//====DO NOT ADD OR CHANGE ANY STATEMENTS IN THE MAIN FUNCTION====
int main() {
    system("cls");
    printf("\nTEST Q2:\n");
    int arr[MAX_SIZE];
    int n, i;
    int min_index, max_index;

    printf("Enter the number of elements n = ");
    scanf("%d", &n);

    if (n > 0 && n <= MAX_SIZE) {
        printf("Enter %d elements for the array:\n", n);
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        find_min_max_indices(arr, n, &min_index, &max_index);

        //====DO NOT ADD OR CHANGE ANY STATEMENTS AFTER THIS LINE====
        //==THE OUTPUT AFTER THIS LINE WILL BE USED TO GRADE YOUR SUBMISSION==
        printf("\nOUTPUT:\n");
        printf("Index of largest element: %d\n", max_index);
        printf("Index of smallest element: %d\n", min_index);

    } else {
        printf("Invalid number of elements.\n");
    }

    printf("\n");
    system("pause");
    return 0;
}