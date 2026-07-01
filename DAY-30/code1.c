/* C Program to Create student record system using arrays and strings */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define COURSE_LEN 50

// Structure to store student details
typedef struct {
    int rollNo;
    char name[NAME_LEN];
    char course[COURSE_LEN];
    float marks;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

// Function prototypes
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main() {
    int choice;

    while (1) {
        printf("\n===== Student Record Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("Exiting program.\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Add a new student
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students. Limit reached.\n");
        return;
    }

    Student s;
    printf("Enter Roll No: ");
    scanf("%d", &s.rollNo);
    getchar(); // consume newline

    printf("Enter Name: ");
    fgets(s.name, NAME_LEN, stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // remove newline

    printf("Enter Course: ");
    fgets(s.course, COURSE_LEN, stdin);
    s.course[strcspn(s.course, "\n")] = '\0';

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    students[studentCount++] = s;
    printf("Student added successfully!\n");
}

// Display all students
void displayStudents() {
    if (studentCount == 0) {
        printf("No student records found.\n");
        return;
    }

    printf("\n%-10s %-20s %-20s %-10s\n", "Roll No", "Name", "Course", "Marks");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%-10d %-20s %-20s %-10.2f\n",
               students[i].rollNo,
               students[i].name,
               students[i].course,
               students[i].marks);
    }
}

// Search student by roll number
void searchStudent() {
    int roll;
    printf("Enter Roll No to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == roll) {
            printf("Record Found:\n");
            printf("Roll No: %d\nName: %s\nCourse: %s\nMarks: %.2f\n",
                   students[i].rollNo,
                   students[i].name,
                   students[i].course,
                   students[i].marks);
            return;
        }
    }
    printf("Student with Roll No %d not found.\n", roll);
}

// Update student record
void updateStudent() {
    int roll;
    printf("Enter Roll No to update: ");
    scanf("%d", &roll);
    getchar();

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == roll) {
            printf("Enter New Name: ");
            fgets(students[i].name, NAME_LEN, stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';

            printf("Enter New Course: ");
            fgets(students[i].course, COURSE_LEN, stdin);
            students[i].course[strcspn(students[i].course, "\n")] = '\0';

            printf("Enter New Marks: ");
            scanf("%f", &students[i].marks);

            printf("Record updated successfully!\n");
            return;
        }
    }
    printf("Student with Roll No %d not found.\n", roll);
}

// Delete student record
void deleteStudent() {
    int roll;
    printf("Enter Roll No to delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == roll) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Record deleted successfully!\n");
            return;
        }
    }
    printf("Student with Roll No %d not found.\n", roll);
}
