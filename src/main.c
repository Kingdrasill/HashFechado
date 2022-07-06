#include "hashFechado.h"

int main() {
    HashClose h;
    int vec[20] = {14, 38, 8, 14, 9, 28, 37, 43, 6, 22, 21, 39, 42, 43, 12, 7, 22, 50, 38, 4};
    int size = 20;

    CreateHashClose(&h, size);
    
    for(int i=0; i<20; i++) {
        InsertHashClose(&h, vec[i]);
    }
    printf("\n");
    PrintHashClose(&h);

    printf("\nNumero de colisoes: %d\n\n", h.colision);

    return 0;
}