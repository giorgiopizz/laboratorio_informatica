#include <stdio.h>
#define CHIAVE 5
int main(){
	char c;
	while(c!='*'){
		c=getchar();
		//nel caso in cui il carattere inserito sia una lettera tra a/A e numero di caratteri pari alla CHIAVE prima della z/Z 
		if((c>='a' && c<='z'-CHIAVE) || (c>='A' && c<='Z'-CHIAVE)){
			putchar(c+CHIAVE);
		}
		/*nel caso in cui invece il carattere sia nell'ultima parte dell'alfabeto compreso tra z/Z-chiave e z/Z è necessario portare all'inizio
		dell'alfabeto la lettera*/
		else if(c<='z' && c>'z'-CHIAVE){
			putchar('a'+CHIAVE-('z'-c)-1);	
		}
		else if(c<='Z' && c>'Z'-CHIAVE){			
			putchar('A'+CHIAVE-('Z'-c)-1);	
		}
		else{
			putchar(c);
		}
	}

}
