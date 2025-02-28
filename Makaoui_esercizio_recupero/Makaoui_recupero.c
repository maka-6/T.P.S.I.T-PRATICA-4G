/*
 * Autore: Makaoui Youness
 * Luogo: Lab 53bis
 * Classe: 4G
 * Data 27/02/2025
 * Description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

typedef struct {

    char name[MAX];
    float price;

}Product;

typedef struct node{

    Product payload;
    struct node *pointNext;

}Node;

Node *pointHead = NULL;

int addProduct();

int seePurchase();

int seeLastPurchase();

int addTailProduct();

int main(){

    int c;
    pointHead = (Node*) malloc(sizeof(Node));
    pointHead->pointNext = NULL;

    do {
        printf("\n\nHello");
        printf("\n1 - Aggiungi");
        printf("\n2 - Aggiungi in fondo alla lista");
        printf("\n3 - Vedi i tuoi prodotti");
        printf("\n4 - Vedi l'ultimo prodotto");
        printf("\n5 - Esci\n->");
        scanf("%d",&c);
        fflush(stdin);
        switch (c) {

            case 1:
                addProduct();
                break;

            case 2:
                addTailProduct();
                break;

            case 3:
                seePurchase();
                break;

            case 4:
                seeLastPurchase();
                break;

            case 5:
                printf("\nVattene");
                break;

            default:
                break;
        }
    }while(c != 5);
}

int addProduct(){

    char name[MAX];
    float price;

    printf("\nInserisci nome prodotto:\n->");
    scanf("%s",name);
    fflush(stdin);
    printf("\nInserisci prezzo:\n-");
    scanf("%f",&price);
    fflush(stdin);

    Node *pointNew = (Node*) malloc(sizeof(Node));

    pointNew->payload.price = price;
    strcpy( pointNew->payload.name, name);
    pointNew->pointNext = NULL;

    if ( pointHead->pointNext == NULL ){

        pointHead->pointNext = pointNew;

    } else {

        pointNew->pointNext = pointHead->pointNext;
        pointHead->pointNext = pointNew;

    }

    return 1;
}

int seePurchase(){

    if ( pointHead->pointNext == NULL ){
        return 0;

    } else {

        Node *pointTemp = pointHead->pointNext;
        while ( pointTemp != NULL ){

            printf("\nName: %s",pointTemp->payload.name);
            printf("\nPrezzo: %.2f",pointTemp->payload.price);
            pointTemp = pointTemp->pointNext;
        }
    }
    return 1;
}

int seeLastPurchase(){

    if ( pointHead == NULL ){
        return 0;

    } else {
        Node *pointTemp = pointHead->pointNext;
        while ( pointTemp->pointNext != NULL ){

            pointTemp = pointTemp->pointNext;
        }
        printf("\nName: %s",pointTemp->payload.name);
        printf("\nPrezzo: %.2f",pointTemp->payload.price);
    }
    return 1;
}

int addTailProduct(){

    char name[MAX];
    float price;

    printf("\nInserisci nome prodotto:\n->");
    scanf("%s",name);
    fflush(stdin);
    printf("\nInserisci prezzo:\n-");
    scanf("%f",&price);
    fflush(stdin);

    Node *pointNew = (Node*) malloc(sizeof(Node));

    pointNew->payload.price = price;
    strcpy( pointNew->payload.name, name);
    pointNew->pointNext = NULL;

    if ( pointHead->pointNext == NULL ){

        pointHead->pointNext = pointNew;

    } else {

        Node *pointTemp = pointHead->pointNext;
        while ( pointTemp->pointNext != NULL ){

            pointTemp = pointTemp->pointNext;

        }
        pointTemp->pointNext = pointNew;
    }
    return 1;
}