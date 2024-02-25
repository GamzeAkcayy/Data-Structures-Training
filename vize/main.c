#include <stdio.h>
#include <stdlib.h>

/*void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Diziyi tarayarak uygun konuma yerleþtirme
        while (j >= 0 && key > arr[j]) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int numbers[] = {20, 11, 28, 14, 17, 22};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    // Insertion sort'u kullanarak sýrala
    insertionSort(numbers, n);

    // Sonucu yazdýr
    printf("Azalan siralama: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}*/

// Yýðýn veri yapýsý tanýmý
typedef struct {
    int data;
    struct Node* next;
} Node;

// Yýðýna eleman ekleme
void push(Node** stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *stack;
    *stack = newNode;
}

// Yýðýndan eleman çýkarma
int pop(Node** stack) {
    if (*stack == NULL) {
        printf("Yigin bos, eleman cikartilamiyor.\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = *stack;
    *stack = (*stack)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Yýðýnýn tepesindeki elemaný alma
int peek(Node* stack) {
    if (stack == NULL) {
        printf("Yigin bos, eleman okunamaz.\n");
        exit(EXIT_FAILURE);
    }
    return stack->data;
}

// Yýðýnýn boþ olup olmadýðýný kontrol etme
int isEmpty(Node* stack) {
    return (stack == NULL);
}

// Ýþlem önceliði kontrolü
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Ýþlem önceliði deðerini döndürme
int getPriority(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    }
    return 0;
}

// Ýnfix ifadeyi postfixe dönüþtürme
void infixToPostfix(char infix[], char postfix[]) {
    Node* stack = NULL;
    int i, j;
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        // Operandlarý direkt postfix ifadeye ekle
        if (isdigit(infix[i]) || isalpha(infix[i])) {
            postfix[j++] = infix[i];
        }
        // Ýþlem operatörleri için
        else if (isOperator(infix[i])) {
            while (!isEmpty(stack) && getPriority(infix[i]) <= getPriority(peek(stack))) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
        // Açma parantezi için
        else if (infix[i] == '(') {
            push(&stack, infix[i]);
        }
        // Kapanma parantezi için
        else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // '(' karakterini yýðýndan çýkar
        }
    }
    // Yýðýnda kalan elemanlarý postfix ifadeye ekle
    while (!isEmpty(stack)) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0'; // Sonlandýrma karakteri ekle
}

// Postfix ifadeyi deðerlendirme
int evaluatePostfix(char postfix[]) {
    Node* stack = NULL;
    int i, operand1, operand2, result;
    for (i = 0; postfix[i] != '\0'; i++) {
        // Operandlarý yýðýna ekle
        if (isdigit(postfix[i])) {
            push(&stack, postfix[i] - '0');
        }
        // Operatörleri kullanarak iþlem yap
        else if (isOperator(postfix[i])) {
            operand2 = pop(&stack);
            operand1 = pop(&stack);
            switch (postfix[i]) {
                case '+': push(&stack, operand1 + operand2); break;
                case '-': push(&stack, operand1 - operand2); break;
                case '*': push(&stack, operand1 * operand2); break;
                case '/': push(&stack, operand1 / operand2); break;
            }
        }
    }
    // Yýðýnda kalan tek eleman sonucu içerir
    result = pop(&stack);
    return result;
}

int main() {
    char infix[] = "(5+(3-(2*(4+(1)))))";
    char postfix[50];

    // Ýnfix ifadeyi postfixe dönüþtürme
    infixToPostfix(infix, postfix);
    printf("Postfix ifade: %s\n", postfix);

    // Postfix ifadeyi deðerlendirme
    int result = evaluatePostfix(postfix);
    printf("Sonuc: %d\n", result);

    return 0;
}


