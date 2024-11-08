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

typedef struct money{

    double cash$$;
    struct money *pointNext;

}Money;

int addMoreMoney(Money *soldi);

void seeMoney(Money *soldi);

int removeMoneyDown(Money *soldi);

int removeMoneyUp(Money *soldi);

int becomePoor(Money *soldi);

int main() {

    Money *soldi = NULL;
    int c;
    do {
        printf("\nHello");
        scanf("%d",&c);
        fflush(stdin);
        switch (c) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                break;
        }
    }while(c!=4);
}