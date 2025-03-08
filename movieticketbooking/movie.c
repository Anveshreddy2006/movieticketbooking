#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 10

typedef struct {
    char name[50];
    int age;
    int seat_number;
} Ticket;

Ticket booked_tickets[MAX_SEATS];
int booked_count = 0;

// Function to display available seats
void displaySeats() {
    printf("\nAvailable Seats: ");
    for (int i = 1; i <= MAX_SEATS; i++) {
        int booked = 0;
        for (int j = 0; j < booked_count; j++) {
            if (booked_tickets[j].seat_number == i) {
                booked = 1;
                break;
            }
        }
        if (!booked) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Function to book a ticket
void bookTicket() {
    if (booked_count >= MAX_SEATS) {
        printf("All seats are booked!\n");
        return;
    }

    Ticket t;
    printf("Enter your name: ");
    scanf("%s", t.name);
    printf("Enter your age: ");
    scanf("%d", &t.age);

    displaySeats();
    printf("Enter seat number to book: ");
    scanf("%d", &t.seat_number);

    if (t.seat_number < 1 || t.seat_number > MAX_SEATS) {
        printf("Invalid seat number! Please try again.\n");
        return;
    }

    for (int i = 0; i < booked_count; i++) {
        if (booked_tickets[i].seat_number == t.seat_number) {
            printf("Seat already booked! Choose another seat.\n");
            return;
        }
    }

    booked_tickets[booked_count++] = t;
    printf("Ticket booked successfully for %s (Seat %d).\n", t.name, t.seat_number);
}

// Function to cancel a ticket
void cancelTicket() {
    if (booked_count == 0) {
        printf("No tickets booked yet!\n");
        return;
    }

    int seat_num;
    printf("Enter seat number to cancel: ");
    scanf("%d", &seat_num);

    int found = 0;
    for (int i = 0; i < booked_count; i++) {
        if (booked_tickets[i].seat_number == seat_num) {
            found = 1;
            for (int j = i; j < booked_count - 1; j++) {
                booked_tickets[j] = booked_tickets[j + 1];
            }
            booked_count--;
            printf("Ticket for seat %d cancelled successfully.\n", seat_num);
            break;
        }
    }

    if (!found) {
        printf("No ticket found for the given seat number!\n");
    }
}

// Function to view booked tickets
void viewBookings() {
    if (booked_count == 0) {
        printf("No tickets booked yet!\n");
        return;
    }

    printf("\nBooked Tickets:\n");
    for (int i = 0; i < booked_count; i++) {
        printf("Name: %s, Age: %d, Seat: %d\n", booked_tickets[i].name, booked_tickets[i].age, booked_tickets[i].seat_number);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Movie Ticket Booking System ---\n");
        printf("1. Book Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. View Bookings\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookTicket();
                break;
            case 2:
                cancelTicket();
                break;
            case 3:
                viewBookings();
                break;
            case 4:
                printf("Exiting the system. Thank you!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}