/* C Program to Create library management system */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "library.dat"

// Structure to store book details
typedef struct {
    int id;
    char title[100];
    char author[100];
    int quantity;
} Book;

// Function prototypes
void addBook();
void displayBooks();
void searchBook();
void deleteBook();
void issueBook();
void returnBook();
int bookExists(int id);
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n===== Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Delete Book by ID\n");
        printf("5. Issue Book\n");
        printf("6. Return Book\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: issueBook(); break;
            case 6: returnBook(); break;
            case 7: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

// Helper function to reliably clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Check if a book with given ID exists
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
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    Book b;
    printf("Enter Book ID: ");
    scanf("%d", &b.id);

    if (bookExists(b.id)) {
        printf("Book with ID %d already exists.\n", b.id);
        fclose(fp);
        clearInputBuffer(); // Clear buffer before returning
        return;
    }

    printf("Enter Title: ");
    clearInputBuffer(); // Clear trailing newline from ID scan
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = '\0';

    printf("Enter Author: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = '\0';

    printf("Enter Quantity: ");
    scanf("%d", &b.quantity);
    clearInputBuffer(); // Clear trailing newline from quantity scan

    fwrite(&b, sizeof(Book), 1, fp);
    fclose(fp);
    printf("Book added successfully.\n");
}

// Display all books
void displayBooks() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No books found.\n");
        return;
    }

    Book b;
    printf("\n%-5s %-30s %-20s %-10s\n", "ID", "Title", "Author", "Quantity");
    printf("---------------------------------------------------------------\n");
    while (fread(&b, sizeof(Book), 1, fp)) {
        printf("%-5d %-30s %-20s %-10d\n", b.id, b.title, b.author, b.quantity);
    }
    fclose(fp);
}

// Search for a book by ID
void searchBook() {
    int id;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);
    clearInputBuffer();

    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No books found.\n");
        return;
    }

    Book b;
    int found = 0;
    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.id == id) {
            printf("\nBook Found:\nID: %d\nTitle: %s\nAuthor: %s\nQuantity: %d\n",
                   b.id, b.title, b.author, b.quantity);
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
    scanf("%d", &id);
    clearInputBuffer();

    FILE *fp = fopen(FILE_NAME, "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (!fp || !temp) {
        printf("Error opening file.\n");
        if(fp) fclose(fp);
        if(temp) fclose(temp);
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
        printf("Book deleted successfully.\n");
    } else {
        printf("Book with ID %d not found.\n", id);
    }
}

// Issue a book
void issueBook() {
    int id;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);
    clearInputBuffer();

    FILE *fp = fopen(FILE_NAME, "rb+");
    if (!fp) {
        printf("No books found.\n");
        return;
    }

    Book b;
    int found = 0;
    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.id == id) {
            found = 1;
            if (b.quantity > 0) {
                b.quantity--;
                fseek(fp, -(long)sizeof(Book), SEEK_CUR); // Cast to long fixed
                fwrite(&b, sizeof(Book), 1, fp);
                printf("Book issued successfully.\n");
            } else {
                printf("Book is out of stock.\n");
            }
            break;
        }
    }
    fclose(fp);

    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
}

// Return a book
void returnBook() {
    int id;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);
    clearInputBuffer();

    FILE *fp = fopen(FILE_NAME, "rb+");
    if (!fp) {
        printf("No books found.\n");
        return;
    }

    Book b;
    int found = 0;
    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.id == id) {
            found = 1;
            b.quantity++;
            fseek(fp, -(long)sizeof(Book), SEEK_CUR); // Cast to long fixed
            fwrite(&b, sizeof(Book), 1, fp);
            printf("Book returned successfully.\n");
            break;
        }
    }
    fclose(fp);

    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
}