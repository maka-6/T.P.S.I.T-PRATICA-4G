/*
 * Autore: Makaoui Youness
 * Luogo: 
 * Classe: 4G
 * Data 06/03/2025
 * Description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

// struct
typedef struct book{

    int Id;
    char title[MAX];
    char author[MAX];
    char genre[MAX];
    int copies;
    int published;

    struct book *pointNext;

}Book;

// aggiunge i libri alla lista in ordine alfabetico
Book *saveNewBook( Book *pointHead );

// lista di libri pubblicati prima degli anni 2000
void The2000s(Book *pointHead2000);

// lista di libri genere fantascientifico
void Fiction(Book *pointHeadFantasy);

// stampa la lista di libri
void printLibrary(Book *pointHead);

// salva sul file la lista
// alla chiusura del programma!
void saveOnFile(FILE *pointFile,  Book *pointHead);

//
int main() {

    Book *pointHead = NULL;
    Book *pointHead2000 = NULL;
    Book *pointHeadFantasy = NULL;

    FILE *pointFile = fopen("Books.txt","w+");

    int choice;
    do {
        printf("\n1 - Inserisci un libro");
        printf("\n2 - Fiction-science");
        printf("\n3 - The 2000s Books");
        printf("\n4 - See all");
        printf("\n5 - Get Out!!");
        printf("\n->");
        scanf("%d",&choice);
        fflush(stdin);
        switch (choice) {

            case 1:
                pointHead = saveNewBook(pointHead);
                saveOnFile(pointFile,pointHead);
                break;
            case 2:
                Fiction(pointHeadFantasy);
                break;
            case 3:
                The2000s(pointHead2000);
                break;
            case 4:
                printLibrary(pointHead);
                break;
            case 5:
                printf("VA FUORII!!");
                break;
            default:
                printf("\nErrore");
                break;
        }
    } while (choice!=5);
    fclose(pointFile);
}

//
Book *saveNewBook( Book *pointHead ) {

    char title[MAX];
    char author[MAX];
    char genre[MAX];
    int published;

    printf("\nInserisci il titolo:\n->");
    scanf("%s",title);
    fflush(stdin);

    printf("\nInserisci l'autore:\n->");
    scanf("%s",author);
    fflush(stdin);

    printf("\nInserisci l'anno di pubblicazione:\n->");
    scanf("%d",&published);
    fflush(stdin);

    int choice;
    printf("\nInserisci il genere");
    printf("\n1 - Fantascienza");
    printf("\n2 - Fantastico");
    printf("\n3 - Avventura");
    printf("\n4 - Noiosi");
    printf("\n5 - Horror");
    printf("\n->");
    scanf("%d",&choice);
    fflush(stdin);
    switch (choice) {
        case 1: strcpy(genre, "Fantascienza"); break;
        case 2: strcpy(genre, "Fantastico"); break;
        case 3: strcpy(genre, "Avventura"); break;
        case 4: strcpy(genre, "Noiosi"); break;
        case 5: strcpy(genre, "Horror"); break;
        default: strcpy(genre, "Non Inserito"); break;
    }

    Book *pointNew = (Book*) malloc(sizeof(Book));
    strcpy(pointNew->title, title);
    strcpy(pointNew->author, author);
    strcpy(pointNew->genre, genre);
    pointNew->published = published;
    pointNew->copies = 1;
    pointNew->Id = 0;
    pointNew->pointNext = NULL;

    // lista vuota
    if ( pointHead == NULL ){

        pointHead = pointNew;
        return pointHead;

    } else {

        Book *pointTemp = pointHead;

        // in caso il libro esista gia
        while ( pointTemp != NULL ){
            if ( strcmp(pointTemp->title, pointNew->title) == 0 ) {
                pointTemp->copies++;
                return pointHead;
            }
            pointTemp = pointTemp->pointNext;
        }

        pointTemp = pointHead;
        Book *pointPrev = pointHead;

        // parte corretta
        // riordino il libro
        while ( pointTemp != NULL ) {
            printf("\nCrash nella comparazione strcmp(pointTemp->title, pointNew->title) < 0");
            if ( strcmp(pointTemp->title, pointNew->title) < 0 ){
                if ( pointTemp->pointNext != NULL ) {
                    pointNew->Id = pointTemp->pointNext->Id+1;
                }

                // aggiorno gli id dei libri
                Book *pointTempTwo = pointTemp;
                while ( pointTempTwo != NULL){
                    pointTempTwo->Id++;
                    pointTempTwo = pointTempTwo->pointNext;
                }

                pointNew->pointNext = pointTemp->pointNext;
                pointTemp->pointNext = pointNew;
                return pointHead;

            }
            printf("\nCrash dopo if");
            // Se il libro è l'ultimo
            pointPrev->pointNext = pointNew;
            pointNew->Id = pointPrev->Id + 1;

            // Aggiorno gli ID dei libri successivi
            Book *pointTempTwo = pointNew->pointNext;
            while ( pointTempTwo != NULL ) {
                pointTempTwo->Id++;
                pointTempTwo = pointTempTwo->pointNext;
            }
        }
        return pointHead;
    }
}

//
void The2000s(Book *pointHead2000) {
    if ( pointHead2000 == NULL ) {
        return;
    } else {
        Book *pointTemp = pointHead2000;
        while ( pointTemp != NULL ){
            printf("\nTitolo: %s", pointTemp->title);
            printf("\nGenere: %s", pointTemp->genre);
            printf("\nAutore: %s", pointTemp->author);
            printf("\nCopie: %d", pointTemp->copies);
            printf("\nAnno di pubblicazione: %d", pointTemp->published);
            printf("\nId: %d\n", pointTemp->Id);
            pointTemp = pointTemp->pointNext;
        }
    }
}

//
void Fiction(Book *pointHeadFantasy) {
    if ( pointHeadFantasy == NULL ) {
        return;
    } else {
        Book *pointTemp = pointHeadFantasy;
        while ( pointTemp != NULL ){
            printf("\nTitolo: %s", pointTemp->title);
            printf("\nGenere: %s", pointTemp->genre);
            printf("\nAutore: %s", pointTemp->author);
            printf("\nCopie: %d", pointTemp->copies);
            printf("\nAnno di pubblicazione: %d", pointTemp->published);
            printf("\nId: %d\n", pointTemp->Id);
            pointTemp = pointTemp->pointNext;
        }
        free(pointTemp);
    }
}

//
void printLibrary(Book *pointHead) {

    if ( pointHead == NULL ) {
        return;
    } else {
        Book *pointTemp = pointHead;
        while ( pointTemp != NULL ){
            printf("\nTitolo: %s", pointTemp->title);
            printf("\nGenere: %s", pointTemp->genre);
            printf("\nAutore: %s", pointTemp->author);
            printf("\nCopie: %d", pointTemp->copies);
            printf("\nAnno di pubblicazione: %d", pointTemp->published);
            printf("\nId: %d\n", pointTemp->Id);
            pointTemp = pointTemp->pointNext;
        }
        free(pointTemp);
    }
}

//
void saveOnFile(FILE *pointFile, Book *pointHead){

    if ( pointHead == NULL)
        return;
    Book *pointTemp = pointHead;
    while (pointTemp != NULL ){
        fprintf(pointFile, "%s", pointTemp->title);
        fprintf(pointFile, "\n%s", pointTemp->author);
        fprintf(pointFile, "\n%s", pointTemp->genre);
        fprintf(pointFile, "\n%d", pointTemp->copies);
        fprintf(pointFile, "\n%d", pointTemp->published);
        fprintf(pointFile, "\n%d\n", pointTemp->Id);
        pointTemp = pointTemp->pointNext;
    }
}