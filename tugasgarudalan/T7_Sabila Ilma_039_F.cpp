#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char items[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char c) {
    if (!isFull(s)) {
        s->items[++(s->top)] = c;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return '\0';
}

char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return '\0';
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']') ||
           (open == '<' && close == '>');
}

int isValid(char *code) {
    Stack s;
    init(&s);
    
    for (int i = 0; i < strlen(code); i++) {
        char c = code[i];
        
        if (c == '(' || c == '{' || c == '[' || c == '<') {
            push(&s, c);
        }
        else if (c == ')' || c == '}' || c == ']' || c == '>') {
            if (isEmpty(&s)) {
                printf("Error: Tidak ada pasangan untuk '%c' di posisi %d\n", c, i);
                return 0;
            } else {
                char top = pop(&s);
                if (!isMatchingPair(top, c)) {
                    printf("Error: Pasangan tidak cocok untuk '%c' di posisi %d, ditemukan '%c'\n", top, i, c);
                    return 0;
                }
            }
        }
    }
    
    if (!isEmpty(&s)) {
        printf("Error: Tanda kurung '%c' tidak memiliki pasangan\n", peek(&s));
        return 0;
    }

    return 1;
}

int main() {
    char code[MAX] = "";  // Awal buffer kosong
    char line[256];       // Buffer sementara untuk setiap baris input

    printf("Masukkan kode untuk validasi tanda kurung (enter baris kosong untuk selesai):\n");

    while (1) {
        fgets(line, sizeof(line), stdin);
        
        // Jika baris kosong, hentikan input
        if (strcmp(line, "\n") == 0) {
            break;
        }

        // Gabungkan baris ke buffer utama
        if (strlen(code) + strlen(line) < MAX) {
            strcat(code, line);
        } else {
            printf("Error: Kode terlalu panjang untuk divalidasi!\n");
            return 1;
        }
    }

    if (isValid(code)) {
        printf("Kode valid!\n");
    } else {
        printf("Kode tidak valid!\n");
    }
    
    return 0;
}