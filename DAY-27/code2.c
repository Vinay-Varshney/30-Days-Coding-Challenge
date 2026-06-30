/* C Program to Create employee management system */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "employees.dat"

// Employee structure
typedef struct {
    int id;
    char name[50];
    char department[30];
    float salary;
} Employee;

// Function prototypes
void addEmployee();
void displayEmployees();
void searchEmployee();
void updateEmployee();
void deleteEmployee();
int employeeExists(int id);

int main() {
    int choice;

    while (1) {
        printf("\n===== Employee Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

// Check if employee with given ID exists
int employeeExists(int id) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return 0;

    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, fp)) {
        if (emp.id == id) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

// Add new employee
void addEmployee() {
    Employee emp;
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);

    if (employeeExists(emp.id)) {
        printf("Employee with ID %d already exists.\n", emp.id);
        fclose(fp);
        return;
    }

    printf("Enter Name: ");
    getchar(); // clear newline
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = '\0'; // remove newline

    printf("Enter Department: ");
    fgets(emp.department, sizeof(emp.department), stdin);
    emp.department[strcspn(emp.department, "\n")] = '\0';

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(Employee), 1, fp);
    fclose(fp);
    printf("Employee added successfully.\n");
}

// Display all employees
void displayEmployees() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    Employee emp;
    printf("\n%-5s %-20s %-15s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("------------------------------------------------------\n");

    while (fread(&emp, sizeof(Employee), 1, fp)) {
        printf("%-5d %-20s %-15s %-10.2f\n", emp.id, emp.name, emp.department, emp.salary);
    }
    fclose(fp);
}

// Search employee by ID
void searchEmployee() {
    int id;
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    Employee emp;
    int found = 0;
    while (fread(&emp, sizeof(Employee), 1, fp)) {
        if (emp.id == id) {
            printf("\nEmployee Found:\n");
            printf("ID: %d\nName: %s\nDepartment: %s\nSalary: %.2f\n",
                   emp.id, emp.name, emp.department, emp.salary);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

// Update employee details
void updateEmployee() {
    int id;
    printf("Enter Employee ID to update: ");
    scanf("%d", &id);

    FILE *fp = fopen(FILE_NAME, "rb+");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    Employee emp;
    int found = 0;
    while (fread(&emp, sizeof(Employee), 1, fp)) {
        if (emp.id == id) {
            printf("Enter new Name: ");
            getchar();
            fgets(emp.name, sizeof(emp.name), stdin);
            emp.name[strcspn(emp.name, "\n")] = '\0';

            printf("Enter new Department: ");
            fgets(emp.department, sizeof(emp.department), stdin);
            emp.department[strcspn(emp.department, "\n")] = '\0';

            printf("Enter new Salary: ");
            scanf("%f", &emp.salary);

            fseek(fp, -sizeof(Employee), SEEK_CUR);
            fwrite(&emp, sizeof(Employee), 1, fp);
            printf("Employee updated successfully.\n");
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

// Delete employee
void deleteEmployee() {
    int id;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        printf("Error creating temporary file.\n");
        fclose(fp);
        return;
    }

    Employee emp;
    int found = 0;
    while (fread(&emp, sizeof(Employee), 1, fp)) {
        if (emp.id == id) {
            found = 1;
            continue; // skip writing this record
        }
        fwrite(&emp, sizeof(Employee), 1, temp);
    }
    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) {
        printf("Employee deleted successfully.\n");
    } else {
        printf("Employee with ID %d not found.\n", id);
    }
}
