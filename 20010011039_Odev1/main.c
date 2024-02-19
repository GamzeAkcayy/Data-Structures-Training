#include <stdio.h>
#include <stdlib.h>
//20010011039 Gamze AKÇAY

typedef struct ogrencinode{
    int no;
    char ad[20];
    char soyad[20];

    struct ogrencinode *next;

    struct dersnode{
        int dersnot;
        char dersad[25];
        char kod[10];

        struct dersnode *nnext;
     }Blistders;
}Blistogr;

int count=0;

void listele()
{
    FILE *filep=fopen("bilgi.txt","r");
    Blistogr * root;//bir root olusturdum
    root=(Blistogr*)malloc(sizeof(Blistogr));
    Blistogr*iter;
    int i;
    for(i=0; i<3; i++){
        if((iter+i)->no == -1){
            continue;
        }
        printf("ID: %d\n",(iter+i)->no);
        printf("Adi: %s\n",(iter+i)->ad);
        printf("Soyadi: %s\n",(iter+i)->soyad);
    }
     close(filep);
}
void sil()

{   int i;
    FILE *filep=fopen("bilgi.txt","r");
    Blistogr * root;//bir root olusturdum
    root=(Blistogr*)malloc(sizeof(Blistogr));
    Blistogr*iter;
    printf("Soyad giriniz:\n");
    scanf("%s",(&Blistogr)->soyad);
    for(i=0; i<3; i++){
        if((Blistogr+i)->soyad == (Blistogr->soyad){
            (Blistogr+i)-> = -1;
            printf("Basariyla silindi..\n");
            kontrol = 1;
        }
    }
     close(filep);
}
void ara()
{
    int i;
    int kod;
    FILE *filep=fopen("bilgi.txt","r");
    Blistogr * root;//bir root olusturdum
    Blistogr*iter;
    iter=root;
    printf("Ders kodunu giriniz:\n");
    scanf("%d",&(Blistogr->Blistders));
    for (i=0;i<3;i++)
    {
        if((Blistogr->Blistders)+i) == (Blistogr->Blistders->kod){
            for(i=0; i<3; i++){
            printf("ID: %d\n",(iter+i)->no);
            printf("Adi: %s\n",(iter+i)->ad);
            printf("Soyadi: %s\n",(iter+i)->soyad);
            printf("Not: %d\n",Blistogr->Blistders)->not);
            printf("Ders Adý: %s\n",(Blistogr->Blistders)->dersad);
            printf("Dersin Kodu: %s\n",(Blistogr->Blistders)->kod);
       }}}
    close(filep);
}
int main()
{
    int secim;
    printf("1-Listele\n");
    printf("2-Ara\n");
    printf("3-Sil\n");
    scanf("%d",&secim);

    switch(secim)
    {
    case 1:
        listele();
        break;
    case 2:
        sil();
        break;
    case 3:
        ara();
       break;
    }
    return 0;
}
