#include <stdio.h>
#include <stdlib.h>

/*
 * Function: calculate_taxi_fare
 *  - Input: A floating-point number 'distance' in kilometers.
 *  - Output: Returns the calculated total fare as a double.
 *  - Rules:
 *    - The first kilometer costs $1.50.
 *    - From the 2nd to the 10th kilometer (inclusive), each kilometer costs $1.00.
 *    - Any kilometer over 10km costs $0.75.
 */
double calculate_taxi_fare(double distance) {
    // WRITE YOUR CODE HERE

	double ans;
	double k= distance;
	
	if (k <= 1){
		ans =  1.5 * 1;
	}
	else if (k>1 && k<10){
		ans =  1.5 * 1;
		ans = ans + ( 1.0 * (k-1.0) );
	}
	else if (k>=10){
		ans =  1.5 * 1;
		ans = ans + ( 1.0 * 9 );
		ans = ans + ( 0.75 * (k-10) );
	}



	return ans;
    // END OF YOUR CODE
}

//====DO NOT ADD OR CHANGE ANY STATEMENTS IN THE MAIN FUNCTION====
int main() {
    system("cls");
    printf("\nTEST Q2:\n");
    double distance, fare;

    printf("Enter the distance in km: ");
    scanf("%lf", &distance);

    fare = calculate_taxi_fare(distance);

    //====DO NOT ADD OR CHANGE ANY STATEMENTS AFTER THIS LINE====
    //==THE OUTPUT AFTER THIS LINE WILL BE USED TO GRADE YOUR SUBMISSION==
    printf("\nOUTPUT:\n");
    printf("Total Fare: $%.2f\n", fare);

    printf("\n");
    system("pause");
    return 0;
}