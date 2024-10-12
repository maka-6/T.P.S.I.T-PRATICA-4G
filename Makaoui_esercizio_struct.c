/*
 * Autore: Makaoui Youness
 * Luogo: Lab 53 bis
 * Classe: 4G
 * Data 09/10/2024
 * Description: ${DESCRIPTION}
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Data{
    int day;
    int month;
    // l'anno è fisso per tutti i voti
    int anno;
};

typedef struct {
    float voto;
    struct Data data;
    char materia[64];
}Valutazione;

void CreaRegistro ( Valutazione registro[], int sizeVoti ) {

    const int anno;
    printf("\nInserisci l'anno:\n->");
    scanf("%d",&anno);

    int i;
    for (i = 0; i < sizeVoti; ++i) {

        registro[i].data.month = (rand()%12)+1;
        registro[i].data.day = i + 2;
        registro[i].data.anno = anno;
        registro[i].voto = (float) (rand() % 9) + 2;
        int r = (rand() % 7) + 1;
        switch (r) {
            case 1:
                strcpy( registro[i].materia, "italiano" );
                break;
            case 2:
                strcpy( registro[i].materia, "matematica" );
                break;
            case 3:
                strcpy( registro[i].materia, "inglese" );
                break;
            case 4:
                strcpy( registro[i].materia, "motoria" );
                break;
            case 5:
                strcpy( registro[i].materia, "storia" );
                break;
            case 6:
                strcpy( registro[i].materia, "motoria" );
                break;
            case 7:
                strcpy( registro[i].materia, "informatica" );
        }

        printf("\nMateria: %s\nVoto: %.2f\nData: %d\\%d\\%d\n",registro[i].materia, registro[i].voto, registro[i].data.day, registro[i].data.month, registro[i].data.anno);
    }
}

float media ( Valutazione registro[], char materia[], int votiSize ) {

    int i;
    float media = 0;
    float n = 0;
    for (i = 0; i < votiSize; ++i) {

        if ( strcmp( registro[i].materia, materia ) == 0 ) {
            media += registro[i].voto;
            n++;
        }
    }
    if ( n > 0 )
        return media / n;

    return -1;
}

int main () {

    srand(time(NULL));
    printf("\nBenvenuto nel registro");
    Valutazione registro[20];

    CreaRegistro( registro, 20 );
    char materia[64];
    printf("\nInserisci la materia per la media voti\n->");
    scanf("%s",materia);
    if ( media( registro, materia, 20 ) == -1 ) {
        printf("\nNessuna materia trovata");
    } else {
        printf("\nMedia: %.2f", media( registro, materia, 20 ));
    }
}