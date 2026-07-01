/* C Program to Create mini library system */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "library.dat"
#define MAX_TITLE 100
#define MAX_AUTHOR 100

// Structure to store book details
typedef struct {
    int id;
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
} Book;

// Function prototypes
void addBook();
void displayBooks();
void searchBook();
void deleteBook();
int bookExists(int id);

int main() {
    int choice;

    while (1) {
        printf("\n===== Mini Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Delete Book by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function to check if a book with given ID already exists
int bookExists(int id) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return 0;

    Book b;
    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.id == id) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

// Add a new book
void addBook() {
    Book b;
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Book ID: ");
    if (scanf("%d", &b.id) != 1) {
        printf("Invalid input! ID must be a number.\n");
        while (getchar() != '\n');
        fclose(fp);
        return;
    }

    if (bookExists(b.id)) {
        printf("Book with ID %d already exists!\n", b.id);
        fclose(fp);
        return;
    }

    while (getchar() != '\n'); // clear buffer
    printf("Enter Book Title: ");
    fgets(b.title, MAX_TITLE, stdin);
    b.title[strcspn(b.title, "\n")] = '\0'; // remove newline

    printf("Enter Author Name: ");
    fgets(b.author, MAX_AUTHOR, stdin);
    b.author[strcspn(b.author, "\n")] = '\0';

    fwrite(&b, sizeof(Book), 1, fp);
    fclose(fp);
    printf("Book added successfully!\n");
}

// Display all books
void displayBooks() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No books found!\n");
        return;
    }

    Book b;
    printf("\n%-10s %-30s %-30s\n", "Book ID", "Title", "Author");
    printf("------------------------------------------------------------\n");
    while (fread(&b, sizeof(Book), 1, fp)) {
        printf("%-10d %-30s %-30s\n", b.id, b.title, b.author);
    }
    fclose(fp);
}

// Search for a book by ID
void searchBook() {
    int id;
    printf("Enter Book ID to search: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input! ID must be a number.\n");
        while (getchar() != '\n');
        return;
    }

    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No books found!\n");
        return;
    }

    Book b;
    int found = 0;
    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.id == id) {
            printf("\nBook Found:\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\n", b.id, b.title, b.author);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
}

// Delete a book by ID
void deleteBook() {
    int id;
    printf("Enter Book ID to delete: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input! ID must be a number.\n");
        while (getchar() != '\n');
        return;
    }

    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No books found!\n");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }

    Book b;
    int found = 0;
    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.id == id) {
            found = 1;
        } else {
            fwrite(&b, sizeof(Book), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) {
        printf("Book deleted successfully!\n");
    } else {
        printf("Book with ID %d not found.\n", id);
    }
}
