/* C Program to Create ticket booking system */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 40
#define MAX_NAME_LEN 50

// Structure to store passenger details
typedef struct {
    int seatNumber;
    char name[MAX_NAME_LEN];
    int isBooked; // 0 = available, 1 = booked
} Seat;

// Function prototypes
void initializeSeats(Seat seats[], int totalSeats);
void displayAvailableSeats(Seat seats[], int totalSeats);
void bookTicket(Seat seats[], int totalSeats);
void cancelTicket(Seat seats[], int totalSeats);
void viewBookings(Seat seats[], int totalSeats);

int main() {
    Seat seats[MAX_SEATS];
    int choice;

    initializeSeats(seats, MAX_SEATS);

    while (1) {
        printf("\n===== Ticket Booking System =====\n");
        printf("1. View Available Seats\n");
        printf("2. Book Ticket\n");
        printf("3. Cancel Ticket\n");
        printf("4. View All Bookings\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                displayAvailableSeats(seats, MAX_SEATS);
                break;
            case 2:
                bookTicket(seats, MAX_SEATS);
                break;
            case 3:
                cancelTicket(seats, MAX_SEATS);
                break;
            case 4:
                viewBookings(seats, MAX_SEATS);
                break;
            case 5:
                printf("Thank you for using the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Initialize all seats as available
void initializeSeats(Seat seats[], int totalSeats) {
    for (int i = 0; i < totalSeats; i++) {
        seats[i].seatNumber = i + 1;
        seats[i].isBooked = 0;
        strcpy(seats[i].name, "");
    }
}

// Display available seats
void displayAvailableSeats(Seat seats[], int totalSeats) {
    printf("\nAvailable Seats: ");
    int found = 0;
    for (int i = 0; i < totalSeats; i++) {
        if (!seats[i].isBooked) {
            printf("%d ", seats[i].seatNumber);
            found = 1;
        }
    }
    if (!found) {
        printf("No seats available.");
    }
    printf("\n");
}

// Book a ticket
void bookTicket(Seat seats[], int totalSeats) {
    int seatNum;
    char name[MAX_NAME_LEN];

    displayAvailableSeats(seats, totalSeats);
    printf("Enter seat number to book: ");
    if (scanf("%d", &seatNum) != 1 || seatNum < 1 || seatNum > totalSeats) {
        printf("Invalid seat number.\n");
        while (getchar() != '\n');
        return;
    }

    if (seats[seatNum - 1].isBooked) {
        printf("Seat %d is already booked.\n", seatNum);
        return;
    }

    printf("Enter passenger name: ");
    while (getchar() != '\n'); // clear buffer
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // remove newline

    seats[seatNum - 1].isBooked = 1;
    strncpy(seats[seatNum - 1].name, name, MAX_NAME_LEN - 1);
    printf("Ticket booked successfully for %s (Seat %d)\n", name, seatNum);
}

// Cancel a ticket
void cancelTicket(Seat seats[], int totalSeats) {
    int seatNum;
    printf("Enter seat number to cancel: ");
    if (scanf("%d", &seatNum) != 1 || seatNum < 1 || seatNum > totalSeats) {
        printf("Invalid seat number.\n");
        while (getchar() != '\n');
        return;
    }

    if (!seats[seatNum - 1].isBooked) {
        printf("Seat %d is not booked.\n", seatNum);
        return;
    }

    seats[seatNum - 1].isBooked = 0;
    strcpy(seats[seatNum - 1].name, "");
    printf("Booking for seat %d has been canceled.\n", seatNum);
}

// View all bookings
void viewBookings(Seat seats[], int totalSeats) {
    printf("\nBooked Seats:\n");
    int found = 0;
    for (int i = 0; i < totalSeats; i++) {
        if (seats[i].isBooked) {
            printf("Seat %d - %s\n", seats[i].seatNumber, seats[i].name);
            found = 1;
        }
    }
    if (!found) {
        printf("No bookings found.\n");
    }
}
