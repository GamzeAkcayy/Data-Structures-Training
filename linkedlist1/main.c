#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int x;
    struct node *next;
}Bliste;
//typedef n node;
void bastir(Bliste *r)
{
    while(r!=NULL)
    {
        printf("%d\n",r->x);
        r=r->next;
    }
}
void ekle(Bliste *r,int x)
{
    while(r->next!=NULL)
    {
        r=r->next;
    }
    r->next=(Bliste*)malloc(sizeof(Bliste));
    r->next->x=x;
    r->next->next=NULL;
}
int main()
{
    Bliste * root;//bir root olusturdum
    root=(Bliste*)malloc(sizeof(Bliste));//rootun gosterdigi bir kutu olusturdum-bu alaný node olarak kullanacagým-
                                     //bir tane nodeun hafýzada kapladýgý kadar yeri bana ayýr-memory allocation-
    root->next=NULL;
    root->x=500;
    /*root->next=(Bliste*)malloc(sizeof(Bliste));
    root->next->x=20;
    root->next->next=NULL;
    Bliste*iter;
    iter=root;
    printf("%d\n",iter->x);
    iter=root->next;
    printf("%d\n ",iter->x);
    iter=root;
    int i=0;
    while(iter->next != NULL)
    {
        i++;
        printf("%dinci eleman :%d \n",i,iter->x);
        iter=iter->next;
    }*/
    for (int i=0;i<10;i++)
    {
        ekle(root,i*10);
        /*iter->next=(Bliste*)malloc(sizeof (Bliste));
        iter=iter->next;
        iter->x=i*10;
        iter->next=NULL;*/
    }
    bastir(root);
    return 0;
}
