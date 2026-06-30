/* C Program to Create student record management system */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILE_NAME "students.dat"

// Structure to store student details
typedef struct {
    int id;
    char name[50];
    int age;
    char gender;
    char course[50];
} Student;

// Function prototypes
void addStudent();
void displayStudents();
void searchStudent();
void deleteStudent();
void updateStudent();
int isValidName(const char *name);
int isValidGender(char gender);

int main() {
    int choice;

    while (1) {
        printf("\n===== Student Record Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Delete Student by ID\n");
        printf("5. Update Student by ID\n");
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
            case 4: deleteStudent(); break;
            case 5: updateStudent(); break;
            case 6: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Validate name (only alphabets and spaces allowed)
int isValidName(const char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i]) && name[i] != ' ')
            return 0;
    }
    return 1;
}

// Validate gender (M/F)
int isValidGender(char gender) {
    gender = toupper(gender);
    return (gender == 'M' || gender == 'F');
}

// Add a new student
void addStudent() {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    Student s;
    printf("Enter Student ID: ");
    scanf("%d", &s.id);

    printf("Enter Name: ");
    getchar(); // clear newline
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    if (!isValidName(s.name)) {
        printf("Invalid name! Only alphabets and spaces allowed.\n");
        fclose(fp);
        return;
    }

    printf("Enter Age: ");
    scanf("%d", &s.age);

    printf("Enter Gender (M/F): ");
    scanf(" %c", &s.gender);
    if (!isValidGender(s.gender)) {
        printf("Invalid gender! Use M or F.\n");
        fclose(fp);
        return;
    }

    printf("Enter Course: ");
    getchar();
    fgets(s.course, sizeof(s.course), stdin);
    s.course[strcspn(s.course, "\n")] = '\0';

    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
    printf("Student added successfully!\n");
}

// Display all students
void displayStudents() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    Student s;
    printf("\n%-5s %-20s %-5s %-7s %-20s\n", "ID", "Name", "Age", "Gender", "Course");
    printf("-------------------------------------------------------------\n");

    while (fread(&s, sizeof(Student), 1, fp)) {
        printf("%-5d %-20s %-5d %-7c %-20s\n", s.id, s.name, s.age, s.gender, s.course);
    }
    fclose(fp);
}

// Search student by ID
void searchStudent() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    int id, found = 0;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    Student s;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.id == id) {
            printf("\nID: %d\nName: %s\nAge: %d\nGender: %c\nCourse: %s\n",
                   s.id, s.name, s.age, s.gender, s.course);
            found = 1;
            break;
        }
    }
    if (!found) printf("Student not found!\n");
    fclose(fp);
}

// Delete student by ID
void deleteStudent() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        printf("Error creating temp file!\n");
        fclose(fp);
        return;
    }

    int id, found = 0;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    Student s;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.id != id) {
            fwrite(&s, sizeof(Student), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) printf("Student deleted successfully!\n");
    else printf("Student not found!\n");
}

// Update student by ID
void updateStudent() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    int id, found = 0;
    printf("Enter Student ID to update: ");
    scanf("%d", &id);

    Student s;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.id == id) {
            printf("Enter new Name: ");
            getchar();
            fgets(s.name, sizeof(s.name), stdin);
            s.name[strcspn(s.name, "\n")] = '\0';

            printf("Enter new Age: ");
            scanf("%d", &s.age);

            printf("Enter new Gender (M/F): ");
            scanf(" %c", &s.gender);
            if (!isValidGender(s.gender)) {
                printf("Invalid gender! Update cancelled.\n");
                fclose(fp);
                return;
            }

            printf("Enter new Course: ");
            getchar();
            fgets(s.course, sizeof(s.course), stdin);
            s.course[strcspn(s.course, "\n")] = '\0';

            // Seek back to the start of the record we just read, then overwrite it
            fseek(fp, -(long)sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, fp);
            fflush(fp); // Sync stream after modifying file contents
            
            printf("Student updated successfully!\n");
            found = 1;
            break; 
        }
    }
    
    if (!found) printf("Student not found!\n");
    fclose(fp);
}