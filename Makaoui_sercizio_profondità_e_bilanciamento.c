/*
 * Autore: Makaoui Youness
 * Luogo: 
 * Classe: 4G
 * Data 12/12/2024
 * Description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definizione della struttura del nodo dell'albero
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Funzione per creare un nuovo nodo
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Funzione per calcolare la profondità di un albero
int calculateDepth(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftDepth = calculateDepth(root->left);
    int rightDepth = calculateDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// Funzione per verificare se un albero è bilanciato
bool isBalanced(Node* root) {
    if (root == NULL) {
        return true;
    }

    int leftDepth = calculateDepth(root->left);
    int rightDepth = calculateDepth(root->right);

    if (abs(leftDepth - rightDepth) > 1) {
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}

// Funzione per trovare il nodo minimo (utile per la cancellazione)
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Funzione per cancellare un nodo dall'albero
Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    // Ricerca del nodo da cancellare
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Nodo trovato
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Nodo con due figli
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Funzione di supporto per stampare l'albero (in-order traversal)
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Main per testare le funzioni
int main() {
    Node* root = NULL;

    // Creazione di un albero di esempio
    root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(13);
    root->right->right = createNode(17);

    printf("Albero in-order: ");
    inOrder(root);
    printf("\n");

    // Calcolo della profondità
    printf("Profondità\u00e0 dell'albero: %d\n", calculateDepth(root));

    // Verifica se l'albero è bilanciato
    printf("L'albero %s bilanciato.\n", isBalanced(root) ? "\u00e8" : "non è");

    // Cancellazione di un nodo
    printf("Cancellazione del nodo 15\n");
    root = deleteNode(root, 15);
    printf("Albero in-order dopo cancellazione: ");
    inOrder(root);
    printf("\n");

    return 0;
}
