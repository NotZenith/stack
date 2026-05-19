#include <stdio.h>     // For printf and scanf functions

#define MAX 100        // Maximum size of queue

int queue[MAX];        // Array to store queue elements

int front = -1;        // Front points to first element
int rear = -1;         // Rear points to last element

// ENQUEUE FUNCTION
// Adds element at the rear/end
void enqueue() {

    int value; // Variable to store user input

    // Check if queue is full
    if (rear == MAX - 1) {

        printf("Queue Overflow! Can't insert more elements.\n");

    } else {

        // If first element is being inserted
        if (front == -1) {
            front = 0; // Set front to first index
        }

        // Ask user for value
        printf("Enter value to enqueue: ");
        scanf("%d", &value);

        // Move rear one step ahead
        rear++;

        // Store value at rear position
        queue[rear] = value;

        // Show success message
        printf("%d inserted into queue.\n", value);
    }
}

// DEQUEUE FUNCTION
// Removes element from front
void dequeue() {

    // Check if queue is empty
    if (front == -1 || front > rear) {

        printf("Queue Underflow! Nothing to remove.\n");

    } else {

        // Print removed element
        printf("%d removed from queue.\n", queue[front]);

        // Move front ahead
        front++;

        // Reset queue if all elements removed
        if (front > rear) {
            front = rear = -1;
        }
    }
}

// PEEK FUNCTION
// Shows front element
void peek() {

    // Check if queue is empty
    if (front == -1) {

        printf("Queue is empty.\n");

    } else {

        // Display front element
        printf("Front element is: %d\n", queue[front]);
    }
}

// DISPLAY FUNCTION
// Displays all queue elements
void display() {

    // Check if queue is empty
    if (front == -1) {

        printf("Queue is empty.\n");

    } else {

        printf("Queue elements are:\n");

        // Print elements from front to rear
        for (int i = front; i <= rear; i++) {

            printf("%d\n", queue[i]);
        }
    }
}

// MAIN FUNCTION
int main() {

    int choice; // Variable for menu choice

    // Infinite loop for menu
    while (1) {

        // Menu display
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        // Ask user choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on choice
        switch (choice) {

            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid input! Try again.\n");
        }
    }

    return 0;
}
