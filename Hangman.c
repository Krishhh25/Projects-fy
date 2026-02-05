#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

void draw_hangman(int mistakes) {
    if (mistakes >= 1) {
        printf("\t \t  O\n");
    }
    if (mistakes >= 2) {
        printf("\t \t  |\n");
    }
    if (mistakes >= 3) {
        printf("\t \t / \\\n");
    }
    if (mistakes >= 4) {
        printf("\t \t  |\n");
    }
    if (mistakes >= 5) {
        printf("\t \t / \\\n");
    }
    if (mistakes >= 6) {
        printf("\t \t-------\n"); 
    }
    if (mistakes == 0) {
        printf("\n"); 
    }
}    
int main() {

srand(time(NULL));
char *words[] = { "cry" , "fruit", "audio", "banana", "red", "hand"};
int a,i;
int mistakes=0;
int max_attempts=6;
int num_words = sizeof(words) / sizeof(words[0]);
int random_index = rand() % num_words;
char *secret_word = words[random_index];
int word_length = strlen(secret_word);
char guessed_letter;
bool guessed_correctly[word_length];
int letters_guessed_correctly;
char *guessed_word_display;

printf("Hangman Game!\n");

printf("You have to guess the word letter by letter\n");

printf("The secret word has %d letters: ", word_length);
for (int i=0;i<word_length;i++)
{
printf(" _");
}
 for (int i = 0; i < word_length; i++) {
        guessed_correctly[i] = false; 
    }
    int letters_guessed = 0;
    bool game_over = false;

    while (!game_over && mistakes < max_attempts) {
        printf("Enter your guess: ");
        scanf(" %c", &guessed_letter); 

        bool found = false;
        for (int i = 0; i < word_length; i++) {
            if (guessed_letter == secret_word[i]) {
                if (!guessed_correctly[i]) { 
                    printf("Correct!\n");
                    guessed_correctly[i] = true;
                    letters_guessed++;
                } else {
                    printf("You already guessed '%c' correctly.\n", guessed_letter);
                }
                found = true;
            }
        }

        if (!found) {
            printf("Wrong! Try next guess.\n");
            mistakes++;
            draw_hangman(mistakes);
        }

        
        if (letters_guessed == word_length) {
            printf("Congratulations! You guessed the word: %s\n", secret_word);
            game_over = true;
        }

        
        if (mistakes >= max_attempts) {
            printf("You ran out of attempts! The secret word was: %s\n", secret_word);
            game_over = true;
        }

        
        printf("Current word: ");
        for (int i = 0; i < word_length; i++) {
            if (guessed_correctly[i]) {
                printf("%c ", secret_word[i]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }

    return 0;
}