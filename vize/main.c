#include <stdio.h>
#include <stdlib.h>

/*void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Diziyi tarayarak uygun konuma yerle�tirme
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

    // Insertion sort'u kullanarak s�rala
    insertionSort(numbers, n);

    // Sonucu yazd�r
    printf("Azalan siralama: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}*/

// Y���n veri yap�s� tan�m�
typedef struct {
    int data;
    struct Node* next;
} Node;

// Y���na eleman ekleme
void push(Node** stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *stack;
    *stack = newNode;
}

// Y���ndan eleman ��karma
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

// Y���n�n tepesindeki eleman� alma
int peek(Node* stack) {
    if (stack == NULL) {
        printf("Yigin bos, eleman okunamaz.\n");
        exit(EXIT_FAILURE);
    }
    return stack->data;
}

// Y���n�n bo� olup olmad���n� kontrol etme
int isEmpty(Node* stack) {
    return (stack == NULL);
}

// ��lem �nceli�i kontrol�
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// ��lem �nceli�i de�erini d�nd�rme
int getPriority(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    }
    return 0;
}

// �nfix ifadeyi postfixe d�n��t�rme
void infixToPostfix(char infix[], char postfix[]) {
    Node* stack = NULL;
    int i, j;
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        // Operandlar� direkt postfix ifadeye ekle
        if (isdigit(infix[i]) || isalpha(infix[i])) {
            postfix[j++] = infix[i];
        }
        // ��lem operat�rleri i�in
        else if (isOperator(infix[i])) {
            while (!isEmpty(stack) && getPriority(infix[i]) <= getPriority(peek(stack))) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
        // A�ma parantezi i�in
        else if (infix[i] == '(') {
            push(&stack, infix[i]);
        }
        // Kapanma parantezi i�in
        else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // '(' karakterini y���ndan ��kar
        }
    }
    // Y���nda kalan elemanlar� postfix ifadeye ekle
    while (!isEmpty(stack)) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0'; // Sonland�rma karakteri ekle
}

// Postfix ifadeyi de�erlendirme
int evaluatePostfix(char postfix[]) {
    Node* stack = NULL;
    int i, operand1, operand2, result;
    for (i = 0; postfix[i] != '\0'; i++) {
        // Operandlar� y���na ekle
        if (isdigit(postfix[i])) {
            push(&stack, postfix[i] - '0');
        }
        // Operat�rleri kullanarak i�lem yap
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
    // Y���nda kalan tek eleman sonucu i�erir
    result = pop(&stack);
    return result;
}

int main() {
    char infix[] = "(5+(3-(2*(4+(1)))))";
    char postfix[50];

    // �nfix ifadeyi postfixe d�n��t�rme
    infixToPostfix(infix, postfix);
    printf("Postfix ifade: %s\n", postfix);

    // Postfix ifadeyi de�erlendirme
    int result = evaluatePostfix(postfix);
    printf("Sonuc: %d\n", result);

    return 0;
}


