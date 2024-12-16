#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Fungsi untuk membuat antrian
void createQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Fungsi untuk memeriksa apakah antrian kosong
bool isEmpty(Queue *q) {
    return q->front == -1;
}

// Fungsi untuk memeriksa apakah antrian penuh
bool isFull(Queue *q) {
    return q->rear == MAX - 1;
}

// Fungsi untuk menambahkan elemen ke antrian (enqueue)
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d\n", value);
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

// Fungsi untuk menghapus elemen dari antrian (dequeue)
void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        printf("Dequeued: %d\n", q->items[q->front]);
        if (q->front == q->rear) { // Jika hanya ada satu elemen
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
    }
}

// Fungsi untuk mendapatkan elemen di depan antrian
void queueFront(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Front: %d\n", q->items[q->front]);
    }
}

// Fungsi untuk mendapatkan elemen di belakang antrian
void queueRear(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Rear: %d\n", q->items[q->rear]);
    }
}

// Fungsi untuk menghitung jumlah elemen dalam antrian
int queueCount(Queue *q) {
    if (isEmpty(q)) {
        return 0;
    }
    return q->rear - q->front + 1;
}

// Fungsi untuk menghancurkan (menghapus) antrian
void destroyQueue(Queue *q) {
    createQueue(q);
    printf("Queue destroyed.\n");
}

// Program utama
int main() {
    Queue q;
    createQueue(&q);

    int choice, value;

    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Queue Front\n");
        printf("4. Queue Rear\n");
        printf("5. Queue Count\n");
        printf("6. Destroy Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(&q, value);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            queueFront(&q);
            break;
        case 4:
            queueRear(&q);
            break;
        case 5:
            printf("Queue count: %d\n", queueCount(&q));
            break;
        case 6:
            destroyQueue(&q);
            break;
        case 7:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
