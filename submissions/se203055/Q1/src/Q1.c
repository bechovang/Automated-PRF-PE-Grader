#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Function: is_perfect_square
 *  - Input: an integer n
 *  - Output: returns 1 if n is a perfect square, otherwise returns 0
 */
int is_perfect_square(int n) {
    // VIẾT MÃ CỦA BẠN VÀO ĐÂY

    // 1. Một số âm không thể là số chính phương.
    if (n < 0) {
        return 0;
    }

    // 2. Tính căn bậc hai của n và ép về kiểu số nguyên.
    //    Việc này sẽ loại bỏ phần thập phân.
    int root = (int)sqrt(n);

    // 3. Kiểm tra xem bình phương của phần nguyên căn bậc hai có bằng chính số n hay không.
    //    Nếu bằng nhau, n là số chính phương.
    if (root * root == n) {
        return 1; // Trả về 1: là số chính phương
    } else {
        return 0; // Trả về 0: không phải là số chính phương
    }

    // KẾT THÚC PHẦN MÃ CỦA BẠN
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