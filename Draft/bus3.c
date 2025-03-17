#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for driver
typedef struct driver {
    char name[20]; // Driver name
    char contact[15]; // Driver contact number
    struct driver *next; // Pointer to the next driver
} driver;

// Define a structure for bus
typedef struct bus {
    int bus_no; // Bus number
    driver *d; // Pointer to the driver assigned
} bus;

// Define a structure for transport destination and price
typedef struct destination {
    char name[20];
    int base_price;
} destination;

// Array to store destinations and prices
destination destinations[] = {{"Mirpur", 30}, {"Dhanmondi", 30}, {"Narayanganj", 50}, {"Uttara", 20}};
int num_destinations = sizeof(destinations) / sizeof(destination);

// Define a structure for transport
typedef struct transport {
    char time[10]; // Time of departure
    char place[20]; // Destination place
    int seats; // Number of seats required
    bus b; // Bus and driver assigned
    int seat_no[10]; // Seat numbers assigned
    int payment; // Payment amount in taka
    char method[10]; // Payment method
    int status; // Payment status (0 for not done, 1 for done)
} transport;

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

// Define a function to create a new driver node
driver *create_driver(char *name, char *contact) {
    // Allocate memory for the driver node
    driver *new_driver = (driver *)malloc(sizeof(driver));
    // Copy the name and contact to the node
    strcpy(new_driver->name, name);
    strcpy(new_driver->contact, contact);
    // Set the next pointer to NULL
    new_driver->next = NULL;
    // Return the new driver node
    return new_driver;
}

// Define a function to insert a driver node at the end of the list
void insert_driver(driver **head, char *name, char *contact) {
    // Create a new driver node
    driver *new_driver = create_driver(name, contact);
    // If the list is empty, make the new node as the head
    if (*head == NULL) {
        *head = new_driver;
    }
    // Else, traverse the list until the last node and insert the new node
    else {
        driver *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_driver;
    }
}

// Define a function to delete a driver node by name
void delete_driver(driver **head, char *name) {
    // If the list is empty, do nothing
    if (*head == NULL) {
        return;
    }
    // If the head node matches the name, delete the head node
    if (strcmp((*head)->name, name) == 0) {
        driver *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    // Else, traverse the list until the node to be deleted is found and delete it
    else {
        driver *prev = *head;
        driver *curr = (*head)->next;
        while (curr != NULL && strcmp(curr->name, name) != 0) {
            prev = curr;
            curr = curr->next;
        }
        // If the node is found, delete it and link the previous and next nodes
        if (curr != NULL) {
            prev->next = curr->next;
            free(curr);
        }
    }
}

// Define a function to display the driver details
void display_driver(driver *d) {
    printf("Driver name: %s\n", d->name);
    printf("Driver contact number: %s\n", d->contact);
}

// Define a function to display the transport details
void display(transport t) {
    printf("Your transport details are:\n");
    printf("Time: %s\n", t.time);
    printf("Place: %s\n", t.place);
    printf("Seats: %d\n", t.seats);
    printf("Bus number: %d\n", t.b.bus_no);
    printf("Driver name: %s\n", t.b.d->name);
    printf("Destination: %s\n", t.place);
    printf("Seat numbers: ");
    for (int i = 0; i < t.seats; i++) {
        printf("%d ", t.seat_no[i]);
    }
    printf("\n");
    display_driver(t.b.d);
    printf("Payment amount: %d taka\n", t.payment);
    printf("Payment method: %s\n", t.method);
    printf("Payment status: %s\n", t.status ? "Success" : "Pending");
}

// Function to book transport
void bookTransport(driver *drivers, bus *buses) {
    transport t;
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

    printf("\nTransport booked successfully!\n");
}

int main() {
    // Create a linked list of drivers
    driver *drivers = NULL;
    // Insert some drivers to the list
    insert_driver(&drivers, "John Doe", "+880123456789");
    insert_driver(&drivers, "Jane Smith", "+880987654321");
    insert_driver(&drivers, "Bob Lee", "+880456789123");
    insert_driver(&drivers, "Alice Chen", "+880321654987");

    // Create an array of 50 buses
    bus buses[50];
    // Assign random values to the buses
    for (int i = 0; i < 50; i++) {
        buses[i].bus_no = i + 1;
        // Assign a random driver from the list to the bus
        driver *temp = drivers;
        int r = rand() % 4; // Random index from 0 to 3
        while (r > 0 && temp != NULL) {
            temp = temp->next;
            r--;
        }
        buses[i].d = temp;
    }

    // Run the transport management system in a loop
    while (1) {
        printf("\n\t\t\t\t\t   ----------------------------------------------\n");
        printf("\t\t\t\t\t\t\t    MAIN MENU\n");
        printf("\t\t\t\t\t   ----------------------------------------------\n");
        printf("\t\t\t\t\t\t\t1. Book Transport\n");
        printf("\t\t\t\t\t\t\t2. Admin Panel\n");
        printf("\t\t\t\t\t\t\t3. Exit\n");
        printf("\t\t\t\t\t   ----------------------------------------------\n");
        printf("\t\t\t\t\t\t\tEnter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookTransport(drivers, buses);
                break;
            case 2:
                // Add admin panel functionality
                break;
            case 3:
                printf("Exiting the program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose a valid option.\n");
                break;
        }
    }

    return 0;
}
