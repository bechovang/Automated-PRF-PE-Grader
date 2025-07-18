#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * Function: transform_string
 *  - Input: A string 'str'.
 *  - Task: Modify the string 'str' in-place according to the following rules:
 *          1. Convert all alphabetic characters to their uppercase form.
 *          2. Remove any leading and trailing spaces.
 *          3. Ensure that multiple spaces between words are reduced to a single space.
 */
 
 
void stringToUpper(char s[]) {
    for (int i = 0; s[i] != '\0'; i++) s[i] = toupper(s[i]);
}

 
  
void trim(char s[]) {
    int i, j;
    while (isspace(s[0])) strcpy(s, s + 1);
    i = strlen(s) - 1;
    while (i >= 0 && isspace(s[i])) s[i--] = '\0';
    for (i = 0, j = 0; s[i]; ++i) {
        if (!isspace(s[i]) || (i > 0 && !isspace(s[i - 1]))) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}
 
 
void transform_string(char *str) {
    // WRITE YOUR CODE HERE
	stringToUpper(str);
	
	trim(str);
	
	

    // END OF YOUR CODE
}

//====DO NOT ADD OR CHANGE ANY STATEMENTS IN THE MAIN FUNCTION====
int main() {
    system("cls");
    printf("\nTEST Q4:\n");
    char s[256] = {0}; // Initialize buffer to all zeros

    printf("Enter a string: ");
    // Read a full line of text, including spaces
    fgets(s, sizeof(s) - 1, stdin);
    // Remove trailing newline character from fgets, if it exists
    s[strcspn(s, "\n")] = 0;

    transform_string(s);

    //====DO NOT ADD OR CHANGE ANY STATEMENTS AFTER THIS LINE====
    //==THE OUTPUT AFTER THIS LINE WILL BE USED TO GRADE YOUR SUBMISSION==
    printf("\nOUTPUT:\n");
    printf("%s\n", s);

    printf("\n");
    system("pause");
    return 0;
}