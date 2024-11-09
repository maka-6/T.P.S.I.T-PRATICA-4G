/*
 * Autore: Makaoui Youness
 * Luogo: Home
 * Classe: 4G
 * Data 08/11/2024
 * Description:
    - Inserimento in testa
    - Visualizzazione
    - Cancellazione in testa
    - Cancellazione in coda
    - Cancellazione di tutta la lista
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct money{

    int number;
    double cash$$;
    struct money *pointNext;

}Money;

int addMoreMoney(Money **soldi);

void seeMoney(Money *soldi);

int removeMoneyDown(Money **soldi);

int removeMoneyUp(Money **soldi);

int becomePoor(Money **soldi);

int main() {

    srand(time(NULL));
    Money *soldi = NULL;
    int c;
    do {
        printf("\nHello");
        printf("\n1 - Aggiungi");
        printf("\n2 - Vedi i tuoi conti");
        printf("\n3 - Cancella portafoglio in testa");
        printf("\n4 - Cancella portafoglio in coda");
        printf("\n5 - Cancella i tuoi conti e torna povero");
        printf("\n6 - Esci\n->");
        scanf("%d",&c);
        fflush(stdin);
        switch (c) {

            case 1:
                if (addMoreMoney(&soldi)){
                    printf("\bAccredito riuscito");
                } else {
                    printf("\nErrore, hai perso i soldi vai via");
                }
                break;

            case 2:
                seeMoney(soldi);
                break;

            case 3:
                if (removeMoneyUp(&soldi)) {
                    printf("\nRimozione in testa riuscita");
                } else {
                    printf("\nNon hai soldi");
                }
                break;

            case 4:
                if (removeMoneyDown(&soldi)){
                    printf("\nSoldi rimossi");
                } else {
                    printf("\nNon hai soldi");
                }
                break;

            case 5:
                if (becomePoor(&soldi)){
                    printf("\nCongratulazioni, ora sei povero");
                } else {
                    printf("\nSei gia povero");
                }
                break;

            case 6:
                printf("\nVattene");
                break;

            default:
                break;
        }
    }while(c!=6);
}

int addMoreMoney(Money **soldi){

    Money *newPortfolio = (Money*) malloc(sizeof(Money));
    if (newPortfolio==NULL)
        return 0;

    newPortfolio->pointNext = NULL;
    newPortfolio->cash$$ = (rand()%100)-50;
    Money *temp = *soldi;

    if (*soldi==NULL){
        *soldi = newPortfolio;
        newPortfolio->number = 1;
    } else {
        int maxPortfolio = 1;
        while (temp->pointNext!=NULL){
            temp = temp->pointNext;
            maxPortfolio++;
        }
        temp->pointNext = newPortfolio;
        newPortfolio->number = maxPortfolio + 1;
    }

    return 1;
}

void seeMoney(Money *soldi){

    if (soldi==NULL){
        printf("\nSei povero vai via");
        return;
    }

    double credit = 0;
    while (soldi!=NULL){
        credit += soldi->cash$$;
        printf("\n\nConto N: %d\nSoldi: $%0.2f", soldi->number,soldi->cash$$);
        soldi = soldi->pointNext;
    }

    printf("\n\nTotale: $%.2f", credit);
    if (credit < 0) {
        printf("\nSei pure in debito");
    }
}

int removeMoneyDown(Money **soldi) {

    if (*soldi==NULL)
        return 0;

    Money *temp = *soldi;

    if (temp->pointNext==NULL) {
        free(temp);
        *soldi = NULL;
        return 1;
    }

    while (temp->pointNext->pointNext!=NULL) {
        temp = temp->pointNext;
    }

    free(temp->pointNext);
    temp->pointNext = NULL;

    return 1;
}

int removeMoneyUp(Money **soldi){

    if (*soldi==NULL)
        return 0;

    Money *temp = *soldi;
    *soldi = temp->pointNext;
    free(temp);

    return 1;
}

int becomePoor(Money **soldi) {

    if (*soldi==NULL)
        return 0;

    Money *temp = *soldi;
    Money *nextNode;

    while (temp!=NULL) {
        nextNode = temp->pointNext;
        free(temp);
        temp = nextNode;
    }

    *soldi = NULL;
    return 1;
}