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
    root=(Bliste*)malloc(sizeof(Bliste));//rootun gosterdigi bir kutu olusturdum-bu alaný node olarak kullanacagým-
                                     //bir tane nodeun hafýzada kapladýgý kadar yeri bana ayýr-memory allocation-
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
