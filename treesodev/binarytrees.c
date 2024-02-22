
#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
    int data;
    struct tree * left;
    struct tree * right;
    char isim[20];
    int num;
} tree;

struct tree* ekle(tree* root,int num) {

    tree* yeni_dugum = (tree*)malloc(sizeof(tree));
    yeni_dugum->data = num;
    yeni_dugum->left = yeni_dugum->right = NULL;
    return yeni_dugum;
}

struct tree* node_ekle(tree* root, int num) {
    if (root == NULL) {
        return ekle(root,num);
    }

    if (num < root->data) {
        root->left = node_ekle(root->left, num);
    } else if (num > root->data) {
        root->right = node_ekle(root->right, num);
    }

    return root;
}

struct tree* silme(tree* root, char isim) {
    if (root == NULL) {
        return root;
    }

    if (num < root->data) {
        root->left = silme(root->left, isim);
    } else if (num > root->data) {
        root->right = silme(root->right, isim);
    } else {

        if (root->left == NULL) {
            struct tree* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct tree* temp = root->left;
            free(root);
            return temp;
        }

        tree* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = sil(root->right, temp->data);
    }

    return root;
}

void dosyaya_yaz(tree* root, FILE* file) {
    if (root != NULL) {
        dosyaya_yaz(root->left, file);
        fprintf(file, "%d ", root->data);
        dosyaya_yaz(root->right, file);
    }
}

int yukseklik_bul(tree * root)
{
    if (root == NULL)
        return 0;
    else
    {
        int left_yukseklik = yukseklik_bul(root->left);
        int right_yukseklik = yukseklik_bul(root->right);

        if (left_yukseklik > right_yukseklik)
            return (left_yukseklik + 1);
        else
            return (right_yukseklik + 1);
    }
}
void listele(root)
{
    if (root != NULL) {
        listele(root->left);
        printf("%d ", root->data);
        listele(root->right);
    }
}
void ayni_listele(tree *root)
{
    if(tree* ad==baska_ad)
    {
        if (root != NULL) {
        listele(root->left);
        printf("%d ", root->data);
        listele(root->right);
    }
    }

}
int main() {

    tree *root = NULL;
    int secim;
    int num;
    char isim[20];
     FILE* outFile = fopen("bst_data.txt", "w");
    if (outFile == NULL) {
        fprintf(stderr, "Dosya oluþturma hatasý\n");
        return 1;
    }
    dosyaya_yaz(root, outFile);

    fclose(outFile);

    FILE* inFile = fopen("bst_data.txt", "r");
    if (inFile == NULL) {
        fprintf(stderr, "Dosya açma hatasý\n");
        return 1;
    }

    printf("Yapmak istediginiz islemi seciniz:");
    while(1)
    {
        printf("\n1-Ekle");
        printf("\n2-Sil");
        printf("\n3-Ortalama Bul");
        printf("\n4-Yukseklik Bul");
        printf("\n5-Listele");
        printf("\n6-Ayni olanlari listele");
        printf("\n7-Cikis\n\n");
        scanf("%d",&secim);

        switch(secim)
        {
        case 1:
            printf("Eklenecek NO'yu giriniz:");
            scanf("%d",&num);
            ekle(root,num);
            break;
        case 2:
            printf("Silinecek ismi giriniz:");
            scanf("%d",&isim);
            root = silme(root,isim);
            break;
        case 3:
            ortalama_hesapla(root);
            break;
        case 4:
            printf("Agacin yuksekligi: %d", yukseklik_bul(root));
            break;
        case 5:
            printf("Listeleniyor...\n");
            listele(root);
        case 6:
            printf("Ayni ada sahip olanlar listeleniyor...\n");
            ayni_listele(root);
        case 7:
            exit(0);
            break;
        default:
            printf("\nHatali Secim Yaptiniz\n");
            break;
        }
    }

    fclose(inFile);

    free(root);

    return 0;
}


