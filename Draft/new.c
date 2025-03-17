#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 50

int seatStatus[MAX_SEATS] = {0};

// Define a structure for the driver
typedef struct Driver {
    char name[20];        // Driver name
    char contact[15];     // Driver contact number
    struct Driver *next;   // Pointer to the next driver
} Driver;

// Define a structure for the bus
typedef struct Bus {
    int bus_no;      // Bus number
    struct Driver *d; // Pointer to the driver assigned
} Bus;

// Define a structure for the passenger
typedef struct Passenger {
    char name[50];
    int id;
    int seatNumber;
    struct Passenger *next;
} Passenger;

// Define a structure for the transport destination and price
typedef struct Destination {
    char name[20];
    int base_price;
} Destination;

// Array to store destinations and prices
Destination destinations[] = {{"Mirpur", 30}, {"Dhanmondi", 30}, {"Narayanganj", 50}, {"Uttara", 20}};
int num_destinations = sizeof(destinations) / sizeof(Destination);

// Define a structure for transport
typedef struct Transport {
    char time[10];  // Time of departure
    char place[20]; // Destination place
    int seats;      // Number of seats required
    Bus b;          // Bus and driver assigned
    int seat_no[10]; // Seat numbers assigned
    int payment;    // Payment amount in taka
    char method[10]; // Payment method
    int status;     // Payment status (0 for not done, 1 for done)
} Transport;

// Function prototypes
Driver *createDriver(char *name, char *contact);
void insertDriver(Driver **head, char *name, char *contact);
void deleteDriver(Driver **head, char *name);
void displayDriver(Driver *d);
void displayDrivers(Driver *head);
void bookSeat(char name[], int id, int seatNumber, Driver *drivers, Bus *buses);
void displayAvailableSeats();
void displayDestinations();
int calculatePrice(int destinationIndex, int seats);
void display(Transport t);
void adminPanel(Driver **drivers, Bus **buses);
void passengerPanel();

// Main function
int main() {
    int userType;

    Driver *driverList = NULL;
    Bus *busList = NULL;

    do {
        printf("\nUser Type\n");
        printf("1. Admin\n");
        printf("2. Passenger\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &userType);

        switch (userType) {
            case 1:
                adminPanel(&driverList, &busList);
                break;

            case 2:
                passengerPanel();
                break;

            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (userType != 0);

    return 0;
}

// Function to create a new driver node
Driver *createDriver(char *name, char *contact) {
    Driver *newDriver = (Driver *)malloc(sizeof(Driver));
    strcpy(newDriver->name, name);
    strcpy(newDriver->contact, contact);
    newDriver->next = NULL;
    return newDriver;
}

// Function to insert a driver node at the end of the list
void insertDriver(Driver **head, char *name, char *contact) {
    Driver *newDriver = createDriver(name, contact);

    if (*head == NULL) {
        *head = newDriver;
    } else {
        Driver *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newDriver;
    }
}

// Function to delete a driver node by name
void deleteDriver(Driver **head, char *name) {
    if (*head == NULL) {
        return;
    }

    if (strcmp((*head)->name, name) == 0) {
        Driver *temp = *head;
        *head = (*head)->next;
        free(temp);
    } else {
        Driver *prev = *head;
        Driver *curr = (*head)->next;
        while (curr != NULL && strcmp(curr->name, name) != 0) {
            prev = curr;
            curr = curr->next;
        }

        if (curr != NULL) {
            prev->next = curr->next;
            free(curr);
        }
    }
}

// Function to display the driver details
void displayDriver(Driver *d) {
    printf("Driver name: %s\n", d->name);
    printf("Driver contact number: %s\n", d->contact);
}

// Function to display the list of drivers
void displayDrivers(Driver *head) {
    printf("\nList of Drivers:\n");
    Driver *temp = head;
    while (temp != NULL) {
        displayDriver(temp);
        printf("-----------------\n");
        temp = temp->next;
    }
}

// Function to book a seat
void bookSeat(char name[], int id, int seatNumber, Driver *drivers, Bus *buses) {
    Transport t;
    int destinationIndex;
    int seats;

    printf("\nEnter the time of departure (HH:MM): ");
    scanf("%s", t.time);

    displayDestinations();

    printf("Enter the destination number (1-%d): ", num_destinations);
    scanf("%d", &destinationIndex);

    // Validate destination choice
    if (destinationIndex < 1 || destinationIndex > num_destinations) {
        printf("Invalid destination choice.\n");
        return;
    }

    printf("Enter the number of seats: ");
    scanf("%d", &seats);

    // Validate the number of seats
    if (seats <= 0) {
        printf("Invalid number of seats.\n");
        return;
    }

    // Display selected destination and calculate the price
    printf("Selected Destination: %s\n", destinations[destinationIndex - 1].name);
    int price = calculatePrice(destinationIndex - 1, seats);
    printf("Price for %d seat(s): %d taka\n", seats, price);

    // Choose payment method
    printf("Choose payment method (bkash/nagad/1card): ");
    scanf("%s", t.method);

    // Additional logic to integrate with your existing transport struct and booking process
    // ...

    // Display booking details
    printf("\nBooking Details:\n");
    printf("Time: %s\n", t.time);
    printf("Destination: %s\n", destinations[destinationIndex - 1].name);
    printf("Seats booked: ");
    for (int i = 0; i < seats; i++) {
        t.seat_no[i] = i + 1;
        printf("%d ", t.seat_no[i]);
    }
    printf("\n");

    // Display payment status
    printf("Is the payment done? (yes/no): ");
    char choice[10];
    scanf("%s", choice);

    if (strcmp(choice, "yes") == 0) {
        t.status = 1;
        printf("Payment status: Success\n");
    } else {
        t.status = 0;
        printf("Payment status: Make payment complete first.\n");
    }

    // Additional logic to integrate with your existing transport struct and booking process
    // ...

    // Check if the seat is available, handle seat booking logic here
    if (seatNumber < 1 || seatNumber > MAX_SEATS) {
        printf("Invalid seat number. Please choose a valid seat.\n");
        return;
    }

    // Mark the seat as booked
    seatStatus[seatNumber - 1] = 1;
    printf("\nTransport booked successfully!\n");
}

// Function to display available seats
void displayAvailableSeats() {
    printf("Available Seats:\n");
    for (int i = 0; i < MAX_SEATS; ++i) {
        if (seatStatus[i] == 0) {
            printf("Seat %d\n", i + 1);
        }
    }
}

// Function to display destinations and prices
void displayDestinations() {
    printf("\nDestinations and Prices:\n");
    for (int i = 0; i < num_destinations; i++) {
        printf("0%d. %-15s %dtaka\n", i + 1, destinations[i].name, destinations[i].base_price);
    }
}

// Function to calculate the price based on the destination and number of seats
int calculatePrice(int destinationIndex, int seats) {
    int base_price = destinations[destinationIndex].base_price;
    return base_price * seats;
}

// Function to display transport details
void display(Transport t) {
    // Your existing display logic here
    // ...
}

// Function for the admin panel
void adminPanel(Driver **drivers, Bus **buses) {
    int adminChoice;
    char name[50];
    int id, seatNumber, destination;

    do {
        printf("\nAdmin Panel\n");
        printf("1. Add Driver\n");
        printf("2. Remove Driver\n");
        printf("3. Search Driver Information\n");
        printf("4. Display List of Drivers\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &adminChoice);

        switch (adminChoice) {
            case 1:
                printf("Enter the name of the new driver: ");
                scanf("%s", name);
                printf("Enter the contact number of the new driver: ");
                scanf("%s", name);
                insertDriver(drivers, name, name);
                printf("Driver added successfully!\n");
                break;

            case 2:
                printf("Enter the name of the driver to be removed: ");
                scanf("%s", name);
                deleteDriver(drivers, name);
                printf("Driver removed successfully!\n");
                break;

            case 3:
                printf("Enter driver ID to search: ");
                scanf("%d", &id);
                Driver *foundDriver = searchDriver(id);
                if (foundDriver != NULL) {
                    printf("Driver found: %s\n", foundDriver->name);
                } else {
                    printf("Driver not found.\n");
                }
                break;

            case 4:
                displayDrivers(*drivers);
                break;

            case 0:
                printf("Exiting admin panel.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (adminChoice != 0);
}

// Function for the passenger panel
void passengerPanel() {
    int passengerChoice;

    do {
        printf("\nPassenger Panel\n");
        printf("1. Display Available Seats\n");
        printf("2. Book Seat\n");
        printf("3. Get Destination Expense\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &passengerChoice);

        switch (passengerChoice) {
            case 1:
                displayAvailableSeats();
                break;

            case 2:
                char name[50];
                printf("Enter passenger name: ");
                scanf("%s", name);
                printf("Enter passenger ID: ");
                scanf("%d", &id);
                printf("Enter seat number: ");
                scanf("%d", &seatNumber);
                bookSeat(name, id, seatNumber);
                break;

            case 3:
                displayDestinations();
                break;

            case 0:
                printf("Exiting passenger panel.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (passengerChoice != 0);
}
