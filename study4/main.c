#include <stdio.h>
#include <stdlib.h>
//STACK
int *dizi;
int boyut=2;
int tepe=0;
int pop(){
    if (tepe<=boyut/4)
    {
        int *dizi2 =(int*)malloc(sizeof(int)*(boyut/2));
        for (int i=0;i<boyut;i++)
        {
            dizi2[i]=dizi[i];
        }
        free(dizi);
        dizi=dizi2;
        boyut/=2;
    }
    return dizi[--tepe];
}
void push(int a){
    if (tepe>=boyut)
    {
        int *dizi2 =(int*)malloc(sizeof(int)*boyut*2);
        for (int i=0;i<boyut;i++)
        {
            dizi2[i]=dizi[i];
        }
        free(dizi);
        dizi=dizi2;
        boyut*=2;
        //int dizi2[boyut*2];
    }
    dizi[tepe++]=a;
}
void bastir(){
    printf("boyut=%d\n",boyut);
    for(int i=0;i<tepe;i++)
    {
        printf("%d\n",dizi[i]);
    }
}
int main()
{
    dizi=(int*)malloc(sizeof(int)*2);
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    bastir();
    printf("popped %d\n",pop());
    printf("popped %d\n",pop());
    printf("popped %d\n",pop());
    printf("popped %d\n",pop());
    //printf("popped %d\n",pop());
    bastir();
    /*for(int i=10;i<200;i++)
    {
        push(i*2);
    }*/
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    push(70);
    push(80);
    push(90);
    push(100);
    return 0;
}
