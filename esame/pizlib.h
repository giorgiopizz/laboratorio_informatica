//libreria personale per l'esame
#ifndef libreria
#define libreria
#include <stdio.h>
#include <stdlib.h>
struct elm{
        int n;
        struct elm * prox;
};
typedef struct elm elm;
elm * elemento(int n);
elm * addinfront(elm * t, int n);
elm * addback(elm * t, int n);
elm * delfirst(elm * t);
elm * dellast(elm* t);
//elm * delatpos(elm * t, int x);
void printlist(elm * t);
#endif
