/* C Program to Develop complete mini project using arrays, strings and functions */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50

// Structure to store student details
typedef struct {
    int rollNo;
    char name[NAME_LEN];
    float marks;
} Student;

// Global array to store students
Student students[MAX_STUDENTS];
int studentCount = 0;

// Function prototypes
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Update Student Details\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function to clear input buffer
void clearInputBuffer() {
    while (getchar() != '\n');
}

// Add a new student
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students. Limit reached.\n");
        return;
    }

    Student s;
    printf("Enter Roll No: ");
    if (scanf("%d", &s.rollNo) != 1) {
        printf("Invalid roll number!\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    // Check for duplicate roll number
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == s.rollNo) {
            printf("Roll number already exists!\n");
            return;
        }
    }

    printf("Enter Name: ");
    fgets(s.name, NAME_LEN, stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // Remove newline

    printf("Enter Marks: ");
    if (scanf("%f", &s.marks) != 1) {
        printf("Invalid marks!\n");
        clearInputBuffer();
        return;
    }

    students[studentCount++] = s;
    printf("Student added successfully!\n");
}

// Display all students
void displayStudents() {
    if (studentCount == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n%-10s %-20s %-10s\n", "Roll No", "Name", "Marks");
    printf("---------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%-10d %-20s %-10.2f\n", students[i].rollNo, students[i].name, students[i].marks);
    }
}

// Search student by roll number
void searchStudent() {
    int roll;
    printf("Enter Roll No to search: ");
    if (scanf("%d", &roll) != 1) {
        printf("Invalid input!\n");
        clearInputBuffer();
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == roll) {
            printf("Student Found: Roll No: %d, Name: %s, Marks: %.2f\n",
                   students[i].rollNo, students[i].name, students[i].marks);
            return;
        }
    }
    printf("Student not found.\n");
}

// Update student details
void updateStudent() {
    int roll;
    printf("Enter Roll No to update: ");
    if (scanf("%d", &roll) != 1) {
        printf("Invalid input!\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == roll) {
            printf("Enter new name: ");
            fgets(students[i].name, NAME_LEN, stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';

            printf("Enter new marks: ");
            if (scanf("%f", &students[i].marks) != 1) {
                printf("Invalid marks!\n");
                clearInputBuffer();
                return;
            }
            printf("Student updated successfully!\n");
            return;
        }
    }
    printf("Student not found.\n");
}

// Delete student
void deleteStudent() {
    int roll;
    printf("Enter Roll No to delete: ");
    if (scanf("%d", &roll) != 1) {
        printf("Invalid input!\n");
        clearInputBuffer();
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == roll) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student deleted successfully!\n");
            return;
        }
    }
    printf("Student not found.\n");
}
