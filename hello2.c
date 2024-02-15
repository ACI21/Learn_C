// get_string and printf with %s

#include <stdio.h>

int main(void)
{

    char answer[50]; // Array to store the name
    printf("What's your name? ");
    fgets(answer, sizeof(answer), stdin); // Read input into the array

    // Remove the newline character at the end (optional)
    answer[strcspn(answer, "\n")] = '\0';
    printf("hello, %s\n", answer);
}
