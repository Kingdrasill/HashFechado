#ifndef HASHFECHADO_H
#define HASHFECHADO_H

#include "lista.h"

#define hash(v, S) (v % S)

typedef struct HashClose HashClose;

struct HashClose{
    Lista *H;
    int S;
    int colision;
};

void CreateHashClose(HashClose *h, int size);
void InsertHashClose(HashClose *h, int value);
void RemoveHashClose(HashClose *h, int value);
bool SearchHashClose(HashClose *h, int value);
void PrintHashClose(HashClose *h);
int FindNextPrime(int number);
int FindPreviousPrime(int number);
bool IsPrime(unsigned int number);

#endif