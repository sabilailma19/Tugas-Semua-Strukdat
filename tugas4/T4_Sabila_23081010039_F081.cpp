#include <stdio.h>
#include <stdbool.h>

#define MAX 5

struct Stack {
    int data[MAX];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

bool isFull(struct Stack *stack) {
    return stack->top == MAX - 1;
}

void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack penuh! Tidak bisa menambah data.\n");
    } else {
        stack->data[++stack->top] = value;
        printf("Elemen %d berhasil ditambahkan ke stack.\n", value);
    }
}

void pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong! Tidak ada elemen yang bisa dihapus.\n");
    } else {
        printf("Elemen %d berhasil dihapus dari stack.\n", stack->data[stack->top--]);
    }
}

void stackTop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong! Tidak ada elemen di puncak.\n");
    } else {
        printf("Elemen teratas: %d\n", stack->data[stack->top]);
    }
}

int stackCount(struct Stack *stack) {
    return stack->top + 1;
}

void destroy(struct Stack *stack) {
    stack->top = -1;
    printf("Stack berhasil dikosongkan.\n");
}

int main() {
    struct Stack stack;
    initialize(&stack);
    int pilihan, nilai;

    do {
        printf("\nMenu Stack:\n");
        printf("1. Push (tambah elemen)\n");
        printf("2. Pop (hapus elemen)\n");
        printf("3. Top (lihat elemen teratas)\n");
        printf("4. Cek apakah kosong\n");
        printf("5. Cek apakah penuh\n");
        printf("6. Hitung jumlah elemen\n");
        printf("7. Destroy (kosongkan stack)\n");
        printf("8. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan nilai: ");
                scanf("%d", &nilai);
                push(&stack, nilai);
                break;
            
            case 2:
                pop(&stack);
                break;

            case 3:
                stackTop(&stack);
                break;

            case 4:
                printf(isEmpty(&stack) ? "Stack kosong.\n" : "Stack tidak kosong.\n");
                break;

            case 5:
                printf(isFull(&stack) ? "Stack penuh.\n" : "Stack tidak penuh.\n");
                break;

            case 6:
                printf("Jumlah elemen dalam stack: %d\n", stackCount(&stack));
                break;

            case 7:
                destroy(&stack);
                break;

            case 8:
                printf("Program selesai.\n");
                break;

            default:
                printf("Pilihan tidak valid! Coba lagi.\n");
        }
    } while (pilihan != 8);

    return 0;
}
