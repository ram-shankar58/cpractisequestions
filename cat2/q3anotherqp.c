/* 
Write a C program to manage a parking lot for the following scenario. You want to keep track of number of available
parking slots as wells as the license plates of the cars parked in each spot. 
You decide to represent the paring lot as an array of strings where each string corresponds to a parking spot and 
contains either the licenxe plate of the car parked there or an empty string if the spot is available

To keep track of the number of available parking spots, you decide to use a pointer to the first empty spot in the array
Whenever a car leaves the parking lot, you update the array to remove its license plate and increment the ppointer to point
to the next empty spot. Suppose the parking lot is initially empty and you have a pointer p that points to the first element.

What happens if you try to insert a car into the parking lot when p is pointing to the last element of the array?
How would you handle this situtation?
*/
#include <stdio.h>
#include <string.h>

int main() {
    char parkingLot[10][10];
    for (int i = 0; i < sizeof(parkingLot)/sizeof(parkingLot[0]); i++) {
        parkingLot[i][0] = '\0';  // initialize each slot to empty string
    }
    char* p = (char*)parkingLot;

    // main loop
    while (1) {
        // print current state of parking lot
        printf("Parking Lot:\n");
        for (int i = 0; i < sizeof(parkingLot)/sizeof(parkingLot[0]); i++) {
            if (parkingLot[i][0] == '\0') {
                printf("%d: empty\n", i);
            } else {
                printf("%d: %s\n", i, parkingLot[i]);
            }
        }

        // ask user what to do
        printf("Enter 'park' to park a car or 'leave' to remove a car: ");
        char action[10];
        scanf("%s", action);

        if (strcmp(action, "park") == 0) {
            // park a car
            if (p == (char*)parkingLot + sizeof(parkingLot)) {
                printf(" parking lot is full.\n");
                continue;
            }
            printf("Enter license plate: ");
            char plate[10];
            scanf("%s", plate);
            strcpy(p, plate);
            p += 10;
        } else if (strcmp(action, "leave") == 0) {
            // remove a car
            printf("Enter slot number to vacate: ");
            int slot;
            scanf("%d", &slot);
            if (slot < 0 || slot >= sizeof(parkingLot)/sizeof(parkingLot[0])) {
                printf("Invalid slot number.\n");
                continue;
            }
            if (parkingLot[slot][0] == '\0') {
                printf("Slot is already empty.\n");
                continue;
            }
            parkingLot[slot][0] = '\0';
            if (p > (char*)&parkingLot[slot][0]) {
                p = (char*)&parkingLot[slot][0];
            }
        } else {
            // invalid action
            printf("Invalid action.\n");
        }
    }
}
/*CHATGPT CODE:
#include <stdio.h>
#include <string.h>

#define MAX_SLOTS 10
#define MAX_PLATE_LEN 9

typedef struct {
    char plate[MAX_PLATE_LEN+1];
} Car;

typedef struct {
    Car slots[MAX_SLOTS];
    int num_slots;
} ParkingLot;

void initParkingLot(ParkingLot* lot) {
    for (int i = 0; i < MAX_SLOTS; i++) {
        lot->slots[i].plate[0] = '\0';  // initialize each slot to empty string
    }
    lot->num_slots = 0;
}

void printParkingLot(ParkingLot* lot) {
    printf("Parking Lot (%d slots):\n", MAX_SLOTS);
    for (int i = 0; i < lot->num_slots; i++) {
        printf("%d: %s\n", i, lot->slots[i].plate);
    }
}

void parkCar(ParkingLot* lot) {
    if (lot->num_slots == MAX_SLOTS) {
        printf("Sorry, parking lot is full.\n");
        return;
    }
    printf("Enter license plate: ");
    char plate[MAX_PLATE_LEN+1];
    scanf("%s", plate);
    strcpy(lot->slots[lot->num_slots].plate, plate);
    lot->num_slots++;
}

void leaveCar(ParkingLot* lot) {
    printf("Enter slot number to vacate: ");
    int slot;
    scanf("%d", &slot);
    if (slot < 0 || slot >= lot->num_slots) {
        printf("Invalid slot number.\n");
        return;
    }
    if (lot->slots[slot].plate[0] == '\0') {
        printf("Slot is already empty.\n");
        return;
    }
    for (int i = slot; i < lot->num_slots-1; i++) {
        strcpy(lot->slots[i].plate, lot->slots[i+1].plate);
    }
    lot->slots[lot->num_slots-1].plate[0] = '\0';
    lot->num_slots--;
}

int main() {
    ParkingLot parkingLot;
    initParkingLot(&parkingLot);

    // main loop
    while (1) {
        printParkingLot(&parkingLot);

        // display menu and ask user what to do
        printf("Menu:\n");
        printf("1. Park a car\n");
        printf("2. Leave a car\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // park a car
                parkCar(&parkingLot);
                break;
            case 2:
                // remove a car
                leaveCar(&parkingLot);
                break;
            case 3:
                // exit program
                return 0;
            default:
                // invalid choice
                printf("Invalid choice.\n");
                break;
        }
    }
}

*/
