 #include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 2

struct n_complesso {
	double a;
	double b;
};
struct polari{
	double r;
	double th;
};

typedef struct n_complesso cmpl;

cmpl somma (cmpl a, cmpl b)
{
  	cmpl z;
	z.a=a.a+b.a;
	z.b=a.b+b.b;
	return z;
}


cmpl prodotto (cmpl a, cmpl b)
{

	cmpl z;
	z.a=a.a*b.a-a.b*b.b;
	z.b=a.a*b.b+a.b*b.a;
	return z;
}
struct polari converti(cmpl a){
	struct polari z;
	z.r=sqrt(pow(a.a,2)+pow(a.b,2));
	z.th=atan(a.b/a.a)*180/3.1415;
	return z;
}

double norma(cmpl a){

}
int main ()
{
  int  i;
  cmpl beta;
  cmpl v[N];


  for ( i=0; i < N; i++ ) {
    scanf("%lf", &v[i].a);
    scanf("%lf", &v[i].b);
  }

  beta = somma(v[0], v[1]);
  printf ("[%lf, %lf]\n", beta.a, beta.b);

  beta = prodotto(v[0], v[1]);
  printf ("[%lf, %lf]\n", beta.a, beta.b);
	
	struct polari c;
	c=converti(beta);
	printf("[%lf, %lf]\n", c.r, c.th);


  exit(EXIT_SUCCESS);
}
