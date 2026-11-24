#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE 256

// Each node stores one feedback message and a link to the next node.
typedef struct Feedback {
    char message[MAX_MESSAGE];
    struct Feedback *next;
} Feedback;

// Queue maintains front and rear pointers.
typedef struct {
    Feedback *front;
    Feedback *rear;
} Queue;

// Initialize an empty queue.
void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

// Add a feedback message at the rear (enqueue).
void enqueue(Queue *q, const char *msg) {
    Feedback *newNode = malloc(sizeof(Feedback));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    snprintf(newNode->message, MAX_MESSAGE, "%s", msg);
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("Feedback added.\n");
}

// Process and remove the oldest feedback (dequeue).
void dequeue(Queue *q) {
    if (q->front == NULL) {
        printf("No feedback to process.\n");
        return;
    }

    Feedback *temp = q->front;
    printf("Processing feedback: %s\n", temp->message);

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}

// Delete the first feedback message matching the entered text.
void deleteFeedback(Queue *q, const char *msg) {
    Feedback *current = q->front;
    Feedback *previous = NULL;

    while (current != NULL && strcmp(current->message, msg) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Feedback not found.\n");
        return;
    }

    if (previous == NULL) {
        q->front = current->next;
    } else {
        previous->next = current->next;
    }

    if (current == q->rear) {
        q->rear = previous;
    }

    free(current);
    printf("Feedback deleted.\n");
}

// Display all feedback from front to rear.
void displayQueue(const Queue *q) {
    if (q->front == NULL) {
        printf("No feedback available.\n");
        return;
    }

    const Feedback *current = q->front;
    printf("\n--- Feedback List ---\n");

    while (current != NULL) {
        printf("- %s\n", current->message);
        current = current->next;
    }

    printf("----------------------\n");
}

// Release all dynamically allocated nodes.
void freeQueue(Queue *q) {
    while (q->front != NULL) {
        Feedback *temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    q->rear = NULL;
}

// Read a full line safely, including spaces.
int readLine(const char *prompt, char *buffer, size_t size) {
    printf("%s", prompt);

    if (fgets(buffer, (int)size, stdin) == NULL) {
        return 0;
    }

    buffer[strcspn(buffer, "\n")] = '\0';
    return 1;
}

int main(void) {
    Queue feedbackQueue;
    char input[MAX_MESSAGE];
    char choiceText[32];
    int choice;

    initQueue(&feedbackQueue);

    do {
        printf("\n--- Online Feedback Collection System ---\n");
        printf("1. Add Feedback\n");
        printf("2. Process Feedback\n");
        printf("3. Delete Specific Feedback\n");
        printf("4. View All Feedback\n");
        printf("5. Exit\n");

        if (!readLine("Enter your choice: ", choiceText, sizeof(choiceText))) {
            break;
        }

        char *endPtr;
        choice = (int)strtol(choiceText, &endPtr, 10);

        if (endPtr == choiceText || *endPtr != '\0') {
            printf("Invalid choice. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                if (readLine("Enter your feedback: ", input, sizeof(input))) {
                    if (input[0] == '\0') {
                        printf("Feedback cannot be empty.\n");
                    } else {
                        enqueue(&feedbackQueue, input);
                    }
                }
                break;

            case 2:
                dequeue(&feedbackQueue);
                break;

            case 3:
                if (readLine("Enter the exact feedback to delete: ",
                             input, sizeof(input))) {
                    deleteFeedback(&feedbackQueue, input);
                }
                break;

            case 4:
                displayQueue(&feedbackQueue);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    freeQueue(&feedbackQueue);
    return 0;
}
