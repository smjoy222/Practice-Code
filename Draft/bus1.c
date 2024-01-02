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
    printf("Seat numbers: ");
    for (int i = 0; i < t.seats; i++) {
        printf("%d ", t.seat_no[i]);
    }
    printf("\n");
    display_driver(t.b.d);
    printf("Payment amount: %d taka\n", t.payment);
    printf("Payment method: %s\n", t.method);
    printf("Payment status: %s\n", t.status ? "Done" : "Not done");
}

// Define a function to print a ticket
void print_ticket(transport t) {
    printf("_________________________________________\n");
    printf("Your Ticket Is:\n");
    printf("******************************\n");
    printf("* Time: %s\n", t.time);
    printf("* Place: %s\n", t.place);
    printf("* Seats: %d\n", t.seats);
    printf("* Bus number: %d\n", t.b.bus_no);
    printf("* Seat numbers: ");
    for (int i = 0; i < t.seats; i++) {
        printf("%d ", t.seat_no[i]);
    }
    printf("\n");
    printf("* Payment amount: %d taka\n", t.payment);
    printf("* Payment method: %s\n", t.method);
    printf("_________________________________________\n");
}

// Define a main function to test the program
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
    // Create a transport object
    transport t;
    // Get the input from the user
    char type[10]; // User type
    printf("Are you a Passenger or an Admin? ");
    scanf("%s", type);
    // If the user is a passenger, get the transport details
    if (strcmp(type, "passenger") == 0) {
        printf("_________________________________________\n");
        printf("Enter the time of departure (HH:MM): ");
        scanf("%s", t.time);
        printf("Enter the destination place: ");
        scanf("%s", t.place);
        printf("Enter the number of seats required: ");
        scanf("%d", &t.seats);
        // Assign a random bus and driver from the array
        t.b = buses[rand() % 50];
        // Assign random seat numbers
        for (int i = 0; i < t.seats; i++) {
            t.seat_no[i] = rand() % 50 + 1;
        }
        // Assign a random payment amount within 100 taka
        t.payment = rand() % 100 + 1;
        // Get the payment method from the user
        printf("Select a payment method: bkash/rocket/1card: ");
        scanf("%s", t.method);
        // Get the payment status from the user
        char choice[10]; // User choice
        printf("Is the payment done? Yes/No: ");
        scanf("%s", choice);
        // If the payment is done, set the status to 1 and print the ticket
        if (strcmp(choice, "yes") == 0) {
            t.status = 1;
            print_ticket(t);
        }
        // Else, set the status to 0 and print a message
        else {
            t.status = 0;
            printf("Please make the payment first.\n");
        }
        // Display the transport details
        display(t);
    }
    // If the user is an admin, get the driver details
    else if (strcmp(type, "admin") == 0) {
        char choice[10]; // User choice
        char name[20]; // Driver name
        char contact[15]; // Driver contact number
        printf("Do you want to insert or delete a driver? ");
        scanf("%s", choice);
        // If the user wants to insert a driver, get the driver details and insert to the list
        if (strcmp(choice, "insert") == 0) {
            printf("Enter the driver name: ");
            scanf("%s", name);
            printf("Enter the driver contact number: ");
            scanf("%s", contact);
            insert_driver(&drivers, name, contact);
            printf("Driver inserted successfully.\n");
        }
        // If the user wants to delete a driver, get the driver name and delete from the list
        else if (strcmp(choice, "delete") == 0) {
            printf("Enter the driver name: ");
            scanf("%s", name);
            delete_driver(&drivers, name);
            printf("Driver deleted successfully.\n");
        }
        // Else, invalid choice
        else {
            printf("Invalid choice.\n");
        }
    }
    // Else, invalid type
    else {
        printf("Invalid type.\n");
    }
    return 0;
}
