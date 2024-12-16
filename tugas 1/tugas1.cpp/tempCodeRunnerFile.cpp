#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

void tambahAwal(node **head);
void tambahData(node **head);
void tambahAkhir(node **head);
void tranverse(node *head);
void insertNode(node **head, node *pPre, node *pNew);
void hapusAwal(node **head);
void hapusData(node **head);
void hapusAkhir(node **head);
void cariData(node *head);
void jumlahData(node *head);
void jumlahanData(node *head);

int main()
{
    node *head;
    char pilih;

    head = NULL;
    do{
        system("cls");
        printf("masukkan pilihan\n");
        printf("1. tambah data di awal list\n");
        printf("2. tambah data di tengah list\n");
        printf("3. tambah data di akhir list\n");
        printf("4. cetak isi list\n");
        printf("5. hapus data di awal list\n");
        printf("6. hapus data di tengah list\n");
        printf("7. hapus data di akhir list\n");
        printf("8. cari data list\n");
        printf("9. jumlah data list\n");
        printf("10. Total semua data di list\n");
        printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
        fflush(stdin);
        scanf("%c", &pilih);
        if (pilih == '1')
            tambahAwal(&head);
        else if (pilih == '2')
            tambahData(&head);
        else if (pilih == '3')
            tambahAkhir(&head);
        else if (pilih == '4'){
            tranverse(head);
            getch();
        }
        else if (pilih == '5')
            hapusAwal(&head);
        else if (pilih == '6')
            hapusData(&head);
        else if (pilih == '7')
            hapusAkhir(&head);
        else if (pilih == '8')
            cariData(head);
        else if (pilih == '9')
            jumlahData(head);
        else if (pilih == '10')
            jumlahanData(head);
    } while (pilih != 'q');

    return 0;
}

void tambahAwal(node **head){
    int bil;
    node *pNew;

    system("cls");
    fflush(stdin);
    printf("masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL){
        pNew->data = bil;
        pNew->next = NULL;
        //add before first logical node or to an empty list
        pNew -> next = *head;
        *head = pNew;
    }
    else{
        printf("Alokasi memori gagal");
        getch();
    }
}

void tambahData(node **head){
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nposisi penyisipan setelah data bernilai : ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nbilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = *head;
    while (pCur != NULL && pCur -> data != pos) {
        pCur = pCur -> next;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pCur == NULL){
        printf("\nnode tidak ditemukan");
        getch();
    }
    else if (pNew == NULL){
        printf("\nalokasi memeori gagal");
        getch();
    }
    else{
        pNew->data = bil;
        pNew->next = NULL;
        pNew -> next = pCur -> next;
        pCur -> next = pNew;
    }
}

void tambahAkhir(node **head){
    int bil;
    node *pNew, *pCur;

    system("cls");
    fflush(stdin);
    printf("masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    pNew->data = bil;
    pNew->next = NULL;

    if (*head == NULL){
        *head = pNew;
    }
    else{
        pCur = *head;
        while (pCur -> next != NULL) {
            pCur = pCur -> next;
        }
        pCur -> next = pNew;
       }
}

void tambahAkhir(node **head){
    int bil;
    node *pNew, *pCur;

    system("cls");
    fflush(stdin);
    printf("masukkan bilangan : ");