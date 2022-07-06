#include "hashFechado.h"

void CreateHashClose(HashClose *h, int size) {
    size = size*2;
    h->H = (Lista*)malloc(size * sizeof(Lista));
    h->S = FindNextPrime(size);
    h->colision = 0;
    
    for(int i=0; i<h->S; i++)
        FLVazia(&h->H[i]);
}

void InsertHashClose(HashClose *h, int value) {
    int key = hash(value, h->S);

    if(!LVazia(&h->H[key]))
        h->colision++;

    Item aux;
    aux.val =value;
    LInsert(&h->H[key], aux);
}

void RemoveHashClose(HashClose *h, int value) {
    if(!SearchHashClose(h, value))
        return;
    
    int key = hash(value, h->S);

    Item aux;
    aux.val = value;
    LRemove(&h->H[key], aux);
}

bool SearchHashClose(HashClose *h, int value) {
    int key = hash(value, h->S);

    if(!LVazia(&h->H[key])) {
        Block *aux;
        aux = h->H[key].first;
        while(aux->prox != NULL) {
            if(aux->prox->data.val == value)
                return true;
        }
    }

    return false;
}

void PrintHashClose(HashClose *h) {
    for(int i=0; i<h->S; i++) {
        printf("%d ", i);
        LImprime(&h->H[i]);
        printf("\n");
    }
    printf("\n");
}

int FindNextPrime(int number) {
    int next = number;
    bool found = false;

    while (!found)
    {
        next++;
        if(IsPrime(next))
            found = true;
    }

    return next;    
}

bool IsPrime(unsigned int number) {
    if (number <= 1) 
        return false; // zero and one are not prime
    for (unsigned int i=2; i*i<=number; i++) {
        if (number % i == 0) 
            return false;
    }
    return true;
}