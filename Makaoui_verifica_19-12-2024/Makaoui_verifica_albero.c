/*
Nome e Cognome: Youness Makaoui
Data: 19-12-2024
Luogo: Lab 53bis
Classe: 4G

Scrivi un programma in C che gestisca un dizionario di parole italiane disponendole in una
struttura dati ad albero binario. Il programma deve:
...
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIM 30

typedef struct node{
	
	char string[30];
	
	struct node *left;
	struct node *right;
	
}Node;

int Comp( Node *node1, Node *node2 ){
	return strcmp( node1->string, node2->string );
}

void newNode( Node *root, Node *pNew );

// crea o apre un file
FILE *loadFile( char name[DIM], Node *root ){

	char string[DIM];
	FILE *pFile = fopen(name,"r+");
	
	if ( pFile != NULL ){
		// memorizzo la prima stringa
		fscanf(pFile, "%s", root->string);
		
		while( !feof(pFile) ){
			fscanf(pFile, "%s", string);
			Node *pNew = (Node*) malloc(sizeof(Node));
			strcpy(pNew->string, string );
			newNode(root, pNew );
		}
		return pFile;
	}
	return NULL;
}

// crea o apre un file
int saveFile( FILE *pFile ,Node *root ){

    if (pFile == NULL || root == NULL) {
        return 0; // Errore se il file o il nodo è nullo
    }

    // Scrivi il contenuto del nodo corrente nel file
    fprintf(pFile, "%s\n", root->string);

    // Ricorsivamente salva il sotto albero sinistro
    if (root->left != NULL) {
        saveFile(pFile, root->left);
    }

    // Ricorsivamente salva il sotto albero destro
    if (root->right != NULL) {
        saveFile(pFile, root->right);
    }
    return 1;
}

//
int printTree( Node *root ){

    if ( root == NULL ) {
        return 0; // Errore se il file o il nodo è nullo
    }

    // Scrivi il contenuto del nodo corrente nel file
    printf("%s\n", root->string);

    // Ricorsivamente salva il sotto albero sinistro
    if (root->left != NULL) {
        printTree( root->left );
    }

    // Ricorsivamente salva il sotto albero destro
    if (root->right != NULL) {
        printTree( root->right );
    }

    return 1;
}

// trasforma le lettere in minuscolo
void toLwrCase ( char string[DIM] ) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] += 'a' - 'A';
        }
    }
}


// aggiunge una stringa
// ritorna un flag intero
int addString( Node *root ){

    if ( root == NULL )
        return 0;

	char string[DIM];
	printf("\nInserisci la parola:\n->");
	scanf("%s",string);
	fflush(stdin);
	
	toLwrCase(string);
	
	Node *pNew = (Node*) malloc(sizeof(Node));
    pNew->left = NULL;
    pNew->right = NULL;
	strcpy(pNew->string, string );
	newNode( root, pNew );
    return 1;
}

// main
int main(){
	
	char name[DIM];
	
	Node *root = (Node*) malloc(sizeof(Node));
	root->left = NULL;
	root->right = NULL;
	
	printf("\nInserisci nome del file:\n->");
	scanf("%s",name);
	fflush(stdin);
	
	FILE *pFile = loadFile(name, root );
	
	// entro nel if solo se ho il file
	if (pFile != NULL){
		int choice;
		do{
			printf("\n1 - Inserisci una Parola");
			printf("\n2 - Visualizza Parole");
			printf("\n3 - Salva nel file");
			printf("\n4 - Esci\n->");
			scanf("%d",&choice);
			switch(choice){
                case 1:
                    if (!addString(root))
                        printf("\nErrore");
                    break;
                case 2:
                    if (!printTree(root))
                        printf("\nErrore");
                    break;
                case 3:
                    rewind(pFile); // Riposiziona il puntatore all'inizio del file
                    if (!saveFile(pFile, root))
                        printf("\nErrore");
                    break;
				case 4:
					printf("\nArrivederci");
					break;
				default:
					printf("\nErrore");
					break;
			}
		// esco
		}while(choice!=4);
		return 0;
	}
	return 5;
}

// crea un nuovo nodo
void newNode( Node *root, Node *pNew ){
	
	int result = Comp(root, pNew );

	switch(result){
		case -1:
   			if ( root->left != NULL ){
				// il caso in cui ho raggiunto la fine del ramo
				newNode(root->left, pNew );
			} else {
				root->left = pNew;
			}
			break;
		case 0:
			printf("\nParola gia presente");
            break;
		case 1:
   			if ( root->right != NULL ){
				newNode(root->right, pNew );
			} else {
				root->right = pNew;
			}
			break;
	}
}