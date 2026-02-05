#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int secretnum = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    printf("Number Guessing Game!\n");
    printf("Try to guess the number I'm thinking of (between 1 and 100).\n");
    printf("You have unlimited attempts!\n");

    while (1) { // This creates an infinite loop
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < secretnum) {
            printf("Too low! Try again.\n");
        } else if (guess > secretnum) {
            printf("Too high! Try again.\n");
        } else if (guess == secretnum) {
            printf("Congratulations! You guessed the number in %d attempts!\n", attempts);
            break; // Exit the loop when the guess is correct
        }
    }

    return 0;
}