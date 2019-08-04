#include <stdio.h>
#include <string.h>

int main(){
  int i = 0, c = 0;
  char data[30], flag, esc;

  printf("Enter flag and esc: ");
  scanf("%c %c", &flag, &esc);

  printf("Enter data: ");
  scanf("%s",data);

  printf("Data after stuffing: ");
  printf("%c", flag);
  for(i = 0; i != strlen(data); i++){
    if(data[i] == flag){
      printf("%c%c", esc, flag);
    }
    else if (data[i] == esc){
      printf("%c%c%c", esc, esc, esc);
    }
    else{
      printf("%c", data[i]);
    }
  }
  printf("%c", flag);
}

/* output
Enter flag and esc: $ #
Enter data: chand$$321#
Data after stuffing: $chand#$#$321###$
*/

