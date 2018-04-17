#include <stdio.h>
int main(){
  char x;
  x = getchar();
  while(x!="*"){
    if(x=="a"){
      printf("e");
    }
    else{
      printf("%c",x);
    }
    x=getchar();
  }
}

