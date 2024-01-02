#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for transport
typedef struct transport {
    char time[10]; // Time of departure
    char place[20]; // Destination place
    int seats; // Number of seats required
    int bus_no; // Bus number assigned
    int seat_no[10]; // Seat numbers assigned
    char driver[20]; // Driver name
    char contact[15]; // Driver contact number
} transport;

// Define a function to display the transport details
void display(transport t) {
    printf("Your transport details are:\n");
    printf("Time: %s\n", t.time);
    printf("Place: %s\n", t.place);
    printf("Seats: %d\n", t.seats);
    printf("Bus number: %d\n", t.bus_no);
    printf("Seat numbers: ");
    for (int i = 0; i < t.seats; i++) {
        printf("%d ", t.seat_no[i]);
    }
    printf("\n");
    printf("Driver name: %s\n", t.driver);
    printf("Driver contact number: %s\n", t.contact);
}

// Define a main function to test the program
int main() {
    // Create a transport object
    transport t;
    // Get the input from the user
    printf("Enter the time of departure (HH:MM): ");
    scanf("%s", t.time);
    printf("Enter the destination place: ");
    scanf("%s", t.place);
    printf("Enter the number of seats required: ");
    scanf("%d", &t.seats);
    // Assign a random bus number and seat numbers
    t.bus_no = rand() % 100 + 1;
    for (int i = 0; i < t.seats; i++) {
        t.seat_no[i] = rand() % 50 + 1;
    }
    // Assign a random driver name and contact number
    strcpy(t.driver, "John Doe");
    strcpy(t.contact, "+880123456789");
    // Display the transport details
    display(t);
    return 0;
}
