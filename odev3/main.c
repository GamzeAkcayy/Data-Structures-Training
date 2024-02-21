//20010011039 Gamze Akçay
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 120

typedef struct {
    char items[max];
    int top;
} Stack;

int dolu(Stack* stack) {
    return stack->top == max - 1;
}
int bos(Stack* stack) {
    return stack->top == -1;
}
int push(Stack* stack, char item) {
    if (!dolu(stack)) {
        stack->items[++stack->top] = item;
    } else {
        printf("Stack dolu. %c\n", item);
    }
}

char pop(Stack* stack) {
    if (!bos(stack)) {
        return stack->items[stack->top--];
    } else {
        printf("Stack bos.\n");
        return '\0';
    }
}
void infixToPostfix(const char* infix, FILE* sonhali) {
    char yeni_ifade=" ";
    Stack yiginsembol;
    donusum(&yiginsembol);
    char sayi;
    int uzunluk = strlen(infix);
    for (int i = 0; i < uzunluk; i++) {
        char degisken = infix[i];
        if (isalnum(degisken)) {
            fprintf(sonhali, "%c", degisken);
        } else if (degisken == '(') {
            push(&yiginsembol, degisken);
        }
        else if (degisken == ')') {
            while (!bos(&yiginsembol) && yiginsembol.items[yiginsembol.top] != '(') {
                fprintf(sonhali, "%c", pop(&yiginsembol));
            }
            if (!bos(&yiginsembol) && yiginsembol.items[yiginsembol.top] != '(') {
                fprintf(sonhali, "Gecersiz ifade girdiniz!!\n");
                return;
            }
            else {
                pop(&yiginsembol);
            }
        }
        else {

            while (!bos(&yiginsembol) && hangisi(degisken) <= hangisi(yiginsembol.items[yiginsembol.top])) {
                fprintf(sonhali, "%c", pop(&yiginsembol));
            }
            push(&yiginsembol, degisken);
        }
          while (!sayi.empty())
    {
        postfix+=sayi.top();
        postfix+=" ";
        sayi.pop();
    }
    return postfix;
    }

    while (!bos(&yiginsembol)) {
        if (yiginsembol.items[yiginsembol.top] == '(') {
            fprintf(sonhali, "Gecersiz ifade girdiniz!!\n");
            return;
        }
        fprintf(sonhali,"%c/n");
        fprintf(sonhali, "%c", pop(&yiginsembol));
    }
    fprintf(sonhali, "\n");
}
void PostfixtoYigin(const char* postfix, FILE* sonhali)
{
    char yeni_yigin=" ";
    Stack yiginsembol;
    donusum(&yiginsembol);
    char sayi;
    int Yigin=0;
    int uzunluk = strlen(postfix);
    for (int i = 0; i < uzunluk; i++) {
        char degisken = postfix[i];
        if (isalnum(degisken)) {
            fprintf(sonhali, "%c", degisken);
        }
        else if (degisken=='*')
        {
            printf("Son sayi=%d",degisken*Yigin);
            pop(&yiginsembol, degisken);
        }
        else if (degisken=='/')
        {
            printf("Son sayi=%d",degisken/Yigin);
            pop(&yiginsembol, degisken);
        }
        else if (degisken=='+')
        {
            printf("Son sayi=%d",degisken+Yigin);
            pop(&yiginsembol, degisken);
        }
        else if (degisken=='-')
        {
            printf("Son sayi=%d",degisken-Yigin);
            pop(&yiginsembol, degisken);
        }
        else if (degisken == ')') {
            while (!bos(&yiginsembol) && yiginsembol.items[yiginsembol.top] != '(') {
                fprintf(sonhali, "%c", pop(&yiginsembol));
            }
        }
        else if (degisken == '(') {
            push(&yiginsembol, degisken);
        }
        else{
        while (!sayi.empty())
    {
        postfix+=sayi.top();
        postfix+=" ";
        sayi.pop();
    }
        }
    return Yigin;
    }
        fprintf(sonhali,"%c/n");
        fprintf(sonhali, "%c", pop(&yiginsembol));
    }
    fprintf(sonhali, "\n");
}
int hangisi(char operator) {
    if (operator == '-' || operator == '+') {
        return 1;
    } else if (operator == '/' || operator == '*') {
        return 2;
    }
    return 0;
}

int main() {
    char infixifade[max];
    char dosyaismi[20];

    printf("Infix ifade giriniz: ");
    fgets(infixifade, max);

    printf("Dosya adi giriniz: ");
    fgets(dosyaismi, 20);

    FILE* sondosya = fopen(dosyaismi, "w");
    if (sondosya == NULL) {
        printf("Dosya acilamadi.\n");
        return 1;
    }
    infixToPostfix(infixifade, sondosya);
    PostfixtoYigin(infixifade,sondosya);

    fclose(sondosya);
    printf("Dosya olusturuldu ve kapatildi.");
    printf("Son hali:%c",&yeni_ifade);
    printf("Son hali:%c",&yeni_yigin);
    return 0;
}


