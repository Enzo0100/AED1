#include <stdio.h>
#include <string.h>

int main (){

  int letras, tam;
  char palavra[30];
  
  scanf("%i", &letras);

  for (int i = 0; i < letras; i++){

    scanf("%s", palavra);

    tam = strlen(palavra);

    if (i != 0)
      printf(" ");
    if (tam == 3 && palavra[0] == 'O' && palavra[1] == 'B')
      printf("OBI");
    else if (tam == 3 && palavra[0] == 'U' && palavra[1] == 'R')
      printf("URI");
    else
      printf("%s", palavra);

  }
  printf("\n");
}