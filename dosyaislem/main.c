#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int x;
    struct node *next;
}Bliste;
//typedef n node;
int main()
{
    Bliste * root;//bir root olusturdum
    root=(Bliste*)malloc(sizeof(Bliste));//rootun gosterdigi bir kutu olusturdum-bu alan� node olarak kullanacag�m-
                                     //bir tane nodeun haf�zada kaplad�g� kadar yeri bana ay�r-memory allocation-
    root->x=10;
    root->next=(Bliste*)malloc(sizeof(Bliste));
    root->next->x=20;
    Bliste*iter;
    iter=root;
    printf("%d",iter->x);
    iter=root->next;
    printf("%d",iter->x);
    //FILE *filep=fopen("deneme.txt","a");
    //fclose(filep);
    return 0;
}
