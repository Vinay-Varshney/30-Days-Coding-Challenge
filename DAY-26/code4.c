/* C Program to Create quiz application */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Structure to store a quiz question
typedef struct {
    char question[256];
    char options[4][128];
    char correctOption; // 'A', 'B', 'C', or 'D'
} QuizQuestion;

// Function to trim newline from fgets input
void trimNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Function to run the quiz
void runQuiz(QuizQuestion quiz[], int totalQuestions) {
    int score = 0;
    char answer[10];

    printf("\n===== Welcome to the Quiz Game =====\n");
    printf("Enter the letter (A/B/C/D) for your answer.\n\n");

    for (int i = 0; i < totalQuestions; i++) {
        printf("Q%d: %s\n", i + 1, quiz[i].question);
        for (int j = 0; j < 4; j++) {
            printf("  %c) %s\n", 'A' + j, quiz[i].options[j]);
        }

        // Input validation loop
        while (1) {
            printf("Your answer: ");
            if (fgets(answer, sizeof(answer), stdin) == NULL) {
                printf("Invalid input. Try again.\n");
                continue;
            }
            trimNewline(answer);

            if (strlen(answer) == 1 && strchr("ABCDabcd", answer[0])) {
                answer[0] = toupper(answer[0]);
                break;
            } else {
                printf("Please enter A, B, C, or D only.\n");
            }
        }

        // Check answer
        if (answer[0] == quiz[i].correctOption) {
            printf("✅ Correct!\n\n");
            score++;
        } else {
            printf("❌ Wrong! Correct answer: %c\n\n", quiz[i].correctOption);
        }
    }

    printf("===== Quiz Finished =====\n");
    printf("Your Score: %d/%d\n", score, totalQuestions);
}

int main() {
    // Define quiz questions
    QuizQuestion quiz[] = {
        {
            "What is the capital of India?",
            {"New Delhi", "Mumbai", "Kolkata", "Chennai"},
            'A'
        },
        {
            "Which language is used to create this quiz?",
            {"Python", "C", "Java", "C++"},
            'B'
        },
        {
            "Which planet is known as the Red Planet?",
            {"Earth", "Mars", "Jupiter", "Venus"},
            'B'
        },
        {
            "Who is known as the father of computers?",
            {"Charles Babbage", "Alan Turing", "Bill Gates", "Steve Jobs"},
            'A'
        }
    };

    int totalQuestions = sizeof(quiz) / sizeof(quiz[0]);
    runQuiz(quiz, totalQuestions);

    return 0;
}
