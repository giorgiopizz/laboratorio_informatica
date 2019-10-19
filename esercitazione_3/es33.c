#include <stdio.h>
#define M 3
#define N 2
int main(){
        double mat[M][N];
        int x, y;
        double somma=0, sommadue=0,sommatre=0;
        for (y=0;y<N;++y){
                for (x=0;x<M;++x){
                        //scrivo il valore della riga x e colonna y
                        printf("Inserisci il valore in posizione(%i,%i): ", x,y);
                        scanf("%lf", &mat[x][y]);
                        somma=somma+mat[x][y];
                        if(x==2){
                                //se è un valore della terza riga lo sommo
                                sommatre=sommatre+mat[x][y];
                        }
                        if(y==1){
                                //se è un valore della seconda colonna lo sommo
                                sommadue=sommadue+mat[x][y];
                        }
                }
        }
        printf("La somma di tutti i valori è: %lf\nLa somma dei valori sulla seconda colonna è: %lf\nLa somma dei valori sulla terza riga è: %lf",somma, sommadue, sommatre);
}