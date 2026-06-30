/* C Program to Create salary management system */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define NAME_LEN 50

// Structure to store employee details
typedef struct {
    int id;
    char name[NAME_LEN];
    float basicSalary;
    float hra;   // House Rent Allowance
    float da;    // Dearness Allowance
    float grossSalary;
} Employee;

Employee employees[MAX_EMPLOYEES];
int empCount = 0;

// Function to calculate gross salary
float calculateGrossSalary(float basic, float hra, float da) {
    return basic + hra + da;
}

// Function to add a new employee
void addEmployee() {
    if (empCount >= MAX_EMPLOYEES) {
        printf("Error: Employee limit reached.\n");
        return;
    }

    Employee e;
    printf("Enter Employee ID: ");
    if (scanf("%d", &e.id) != 1) {
        printf("Invalid input. ID must be an integer.\n");
        while (getchar() != '\n'); // clear buffer
        return;
    }

    // Check for duplicate ID
    for (int i = 0; i < empCount; i++) {
        if (employees[i].id == e.id) {
            printf("Error: Employee ID already exists.\n");
            return;
        }
    }

    printf("Enter Name: ");
    while (getchar() != '\n'); // clear buffer
    fgets(e.name, NAME_LEN, stdin);
    e.name[strcspn(e.name, "\n")] = '\0'; // remove newline

    printf("Enter Basic Salary: ");
    if (scanf("%f", &e.basicSalary) != 1 || e.basicSalary < 0) {
        printf("Invalid salary amount.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Enter HRA: ");
    if (scanf("%f", &e.hra) != 1 || e.hra < 0) {
        printf("Invalid HRA amount.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Enter DA: ");
    if (scanf("%f", &e.da) != 1 || e.da < 0) {
        printf("Invalid DA amount.\n");
        while (getchar() != '\n');
        return;
    }

    e.grossSalary = calculateGrossSalary(e.basicSalary, e.hra, e.da);
    employees[empCount++] = e;

    printf("Employee added successfully!\n");
}

// Function to display all employees
void displayEmployees() {
    if (empCount == 0) {
        printf("No employee records found.\n");
        return;
    }

    printf("\n%-5s %-20s %-10s %-10s %-10s %-10s\n", "ID", "Name", "Basic", "HRA", "DA", "Gross");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < empCount; i++) {
        printf("%-5d %-20s %-10.2f %-10.2f %-10.2f %-10.2f\n",
               employees[i].id, employees[i].name,
               employees[i].basicSalary, employees[i].hra,
               employees[i].da, employees[i].grossSalary);
    }
}

// Function to update salary of an employee
void updateSalary() {
    int id;
    printf("Enter Employee ID to update salary: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }

    for (int i = 0; i < empCount; i++) {
        if (employees[i].id == id) {
            printf("Enter new Basic Salary: ");
            if (scanf("%f", &employees[i].basicSalary) != 1 || employees[i].basicSalary < 0) {
                printf("Invalid salary.\n");
                while (getchar() != '\n');
                return;
            }

            printf("Enter new HRA: ");
            if (scanf("%f", &employees[i].hra) != 1 || employees[i].hra < 0) {
                printf("Invalid HRA.\n");
                while (getchar() != '\n');
                return;
            }

            printf("Enter new DA: ");
            if (scanf("%f", &employees[i].da) != 1 || employees[i].da < 0) {
                printf("Invalid DA.\n");
                while (getchar() != '\n');
                return;
            }

            employees[i].grossSalary = calculateGrossSalary(employees[i].basicSalary, employees[i].hra, employees[i].da);
            printf("Salary updated successfully!\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

// Main menu
int main() {
    int choice;
    while (1) {
        printf("\n===== Salary Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Update Salary\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: updateSalary(); break;
            case 4: printf("Exiting program.\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
