#include <stdio.h>
#include <stdlib.h>

/*
 * Function: calculate_gcd_lcm
 *  - Input: Two positive integers 'a' and 'b'.
 *  -         Pointers to store the results for the Greatest Common Divisor (gcd_result)
 *  -         and Least Common Multiple (lcm_result).
 *  - Task: Calculate the GCD and LCM of 'a' and 'b' and store them in the result pointers.
 */
 
// PHẦN 2: XỬ LÝ SỐ HỌC & NGÀY THÁNG
long long UCLN(long long a, long long b) {
    a = llabs(a); b = llabs(b);
    while (b) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long BCNN(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return (llabs(a) / UCLN(a, b)) * llabs(b);
}

 
 
void calculate_gcd_lcm(int a, int b, int *gcd_result, long long *lcm_result) {
    // WRITE YOUR CODE HERE
	
	*gcd_result = UCLN(a,b);
	*lcm_result = BCNN(a,b);

    // END OF YOUR CODE
}

//====DO NOT ADD OR CHANGE ANY STATEMENTS IN THE MAIN FUNCTION====
int main() {
    system("cls");
    printf("\nTEST Q1:\n");
    int a, b, gcd;
    long long lcm;

    printf("Enter a = ");
    scanf("%d", &a);
    printf("Enter b = ");
    scanf("%d", &b);

    calculate_gcd_lcm(a, b, &gcd, &lcm);

    //====DO NOT ADD OR CHANGE ANY STATEMENTS AFTER THIS LINE====
    //==THE OUTPUT AFTER THIS LINE WILL BE USED TO GRADE YOUR SUBMISSION==
    printf("\nOUTPUT:\n");
    printf("GCD: %d\n", gcd);
    printf("LCM: %lld\n", lcm);

    printf("\n");
    system("pause");
    return 0;
}