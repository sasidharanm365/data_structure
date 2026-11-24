# Online Feedback Collection System

A menu-driven C application that collects and manages user feedback using a **queue implemented with a singly linked list**. Feedback is added at the rear and processed from the front, following the First-In-First-Out (FIFO) principle.

## Features

- Add new feedback messages.
- Process the oldest feedback first.
- Delete a specific feedback message by matching its text.
- Display all feedback currently stored in the queue.
- Dynamically allocate memory for feedback nodes.
- Free allocated memory when the program exits.
- Accept feedback messages containing spaces.

## Data Structure Used

The implementation uses a **queue based on a singly linked list**.

Each `Feedback` node contains:
- `message`: a character array that stores the feedback text.
- `next`: a pointer to the next node.

The `Queue` structure contains:
- `front`: points to the oldest feedback.
- `rear`: points to the newest feedback.

### FIFO Workflow

```text
Add feedback (enqueue) at REAR
              |
              v
FRONT -> [Feedback 1] -> [Feedback 2] -> [Feedback 3] <- REAR
              |
              v
Process feedback (dequeue) from FRONT
```

## Operations

| Operation | Description |
|---|---|
| Initialize | Sets `front` and `rear` to `NULL`. |
| Enqueue | Adds a new feedback node at the rear. |
| Dequeue | Processes and removes the front node. |
| Delete specific feedback | Searches for matching text and removes the first match. |
| Display | Traverses and displays feedback from front to rear. |
| Free queue | Releases all remaining dynamically allocated nodes. |

## Technologies Used

- C programming language
- Standard C libraries: `stdio.h`, `stdlib.h`, and `string.h`
- Singly linked list
- Queue (FIFO)

## Project Structure

```text
Online-Feedback-Collection-System/
├── main.c
├── README.md
├── .gitignore
└── screenshots/
```

## How to Compile and Run

### GCC (Windows / Linux / macOS)

Compile:

```bash
gcc main.c -o feedback
```

Run on Windows:

```bash
feedback.exe
```

Run on Linux or macOS:

```bash
./feedback
```

## Sample Output

```text
--- Online Feedback Collection System ---
1. Add Feedback
2. Process Feedback
3. Delete Specific Feedback
4. View All Feedback
5. Exit
Enter your choice: 1
Enter your feedback: Phone - Great battery life
Feedback added.

--- Online Feedback Collection System ---
1. Add Feedback
2. Process Feedback
3. Delete Specific Feedback
4. View All Feedback
5. Exit
Enter your choice: 4

--- Feedback List ---
- Phone - Great battery life
----------------------

--- Online Feedback Collection System ---
1. Add Feedback
2. Process Feedback
3. Delete Specific Feedback
4. View All Feedback
5. Exit
Enter your choice: 2
Processing feedback: Phone - Great battery life
```

## Complexity

For the queue operations in this implementation:

| Operation | Time Complexity |
|---|---:|
| Enqueue at rear | O(1) |
| Dequeue from front | O(1) |
| Display all feedback | O(n) |
| Search and delete specific feedback | O(n) |

Here, `n` is the number of feedback entries in the queue.

## Important Implementation Note

The submitted project report discusses queues, singly linked lists, doubly linked lists, and priority queues in different sections. The source code in this repository implements a **FIFO queue using a singly linked list**. It does not implement a doubly linked list or priority-based processing. The README describes the implemented source code accurately.

## Future Enhancements

The project report suggests the following possible enhancements:

- Categorize feedback as complaints, suggestions, or compliments.
- Store feedback permanently using file handling or a database such as SQLite or MySQL.
- Add timestamps to feedback entries.
- Add search and filter options.
- Generate reports or send email notifications.

These are future-scope ideas and are not included in the current program.

## Author

**Sasi Dharan M**  
B.E. – Electronics and Communication Engineering  
K. Ramakrishnan College of Engineering

## References

- Reema Thareja, *Data Structures Using C*, Oxford University Press.
- E. Balagurusamy, *Programming in ANSI C*, Tata McGraw-Hill Education.
- Thomas H. Cormen et al., *Introduction to Algorithms*, MIT Press.
- Yashavant Kanetkar, *Let Us C*, BPB Publications.

