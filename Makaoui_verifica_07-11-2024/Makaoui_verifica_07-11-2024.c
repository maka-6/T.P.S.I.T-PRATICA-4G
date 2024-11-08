/*
 * Autore: Makaoui Youness
 * Luogo: Lab 53bis
 * Classe: 4G
 * Data 07/11/2024
 * Description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book{

    char name[30];
    char author[30];
    int available;
    struct book *pointNext;

}Book;

int AddBook(Book **library);

Book *SearchBook(Book *library, char name[]);

int LeaseBook(Book *library);

int TakeBook(Book *library);

void ViewLibrary(Book *library);

int main() {

    int n;
    char name[30];

    // creo la libreria vuota
    Book *library = NULL;
    do {
        printf("\nBenvenuto nella libreria");
        printf("\n1 - Inserisci un libro");
        printf("\n2 - Cerca un libro");
        printf("\n3 - Prendi in prestito");
        printf("\n4 - Restituisci un libro");
        printf("\n5 - Visualizza libreria");
        printf("\n6 - Esci");
        printf("\nScegli l'opzione\n->");
        scanf("%d",&n);
        fflush(stdin);
        switch (n) {

            case 1:
                if ( AddBook(&library) ){
                    printf("\nLibro aggiunto");
                } else {
                    printf("Libreria vuota");
                }
                break;

            case 2:
                printf("\nInserisci nome libro\n->");
                scanf("%s",name);
                // trasformo in minuscolo il testo
                strlwr(name);
                fflush(stdin);
                if ( SearchBook(library, name) ){
                    printf("\nLibro trovato ma non te lo diamo");
                } else {
                    printf("\nNon l'abbiamo trovato il libro, godo");
                }
                break;

            case 3:
                if ( LeaseBook(library) ){
                    printf("\nRicorda di riportarcelo o c'e l'ho riprendiamo noi :)");
                } else {
                    printf("\nLibro non trovato arrangiati");
                }
                break;

            case 4:
                if ( TakeBook(library) ){
                    printf("\nFaremo finta che lai letto davvero esci");
                } else {
                    printf("\nNon trovato");
                }
                break;

            case 5:
                ViewLibrary(library);
                break;

            case 6:
                printf("\nArrivederci");
                break;

            default:
                printf("\nSelezione non valida");
                break;
        }
    } while (n!=6);
}

int AddBook(Book **library){
    char string[30];
    Book *newBook = (Book *)malloc(sizeof(Book));
    if (newBook == NULL) return 0;
    newBook->pointNext = NULL;

    printf("\nInserisci titolo libro\n->");
    scanf("%s", string);
    strlwr(string);
    fflush(stdin);
    strcpy(newBook->name, string);

    printf("\nInserisci autore\n->");
    scanf("%s", string);
    strlwr(string);
    fflush(stdin);
    strcpy(newBook->author, string);

    newBook->available = 1;

    if (*library == NULL) {
        *library = newBook;
    } else {
        Book *temp = *library;
        while (temp->pointNext != NULL) {
            temp = temp->pointNext;
        }
        temp->pointNext = newBook;
    }
    return 1;
}

Book *SearchBook(Book *library, char name[]){
    Book *book = library;
    // trasformo in minuscolo il testo
    strlwr(name);
    // controllo che la libreria non sia vuota
    if ( book == NULL )
        return 0;

    while (book != NULL){
        if (strcmp( name, book->name) == 0)
            return book;
        book = book->pointNext;
    }
    return NULL;
}

int LeaseBook(Book *library){

    char name[30];
    printf("\nInserisci nome libro\n->");
    scanf("%s",name);
    // trasformo in minuscolo il testo
    strlwr(name);
    fflush(stdin);

    Book *book = SearchBook( library, name );
    // cerco se il libro è presente
    if ( book == NULL )
        return 0;

    if ( book->available == 0 ){
        printf("\nLibro gia preso vai via");
        return 1;
    }
    book->available=0;
    return 1;
}

int TakeBook(Book *library){

    char name[30];
    printf("\nInserisci nome libro\n->");
    scanf("%s",name);
    // trasformo in minuscolo il testo
    strlwr(name);
    fflush(stdin);

    Book *book = SearchBook( library, name );
    // cerco se il libro è presente
    if ( book == NULL )
        return 0;

    if ( book->available == 1 ){
        printf("\nLibro gia presente, non è nostro deficiente");
        return 1;
    }

    book->available=1;
    return 1;
}

void ViewLibrary(Book *library){

    if ( library == NULL ){
        printf("Libreria vuota");
        return;
    }

    Book *temp = library;
    while (temp!=NULL){
        printf("\n\nTitolo: %s\nAutore: %s",temp->name,temp->author);
        temp=temp->pointNext;
    }
}