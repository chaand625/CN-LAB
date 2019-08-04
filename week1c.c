#include <stdio.h>
#include <string.h>
int main(){
  int i =0, count = 0;
  char data[20];
  printf("Enter bits: ");
  scanf("%s", data);

  printf("\nData bits before stuffing: %s", data);
  printf("\nData bits after stuffing: ");

  for(i = 0; i < strlen(data); i++){
    if (data[i] == '1')
      count++;
    else
      count = 0;

    printf("%c", data[i]);

    if(count == 5){
      printf("0");
      count = 0;
    }
  }

  return 0;
}
/*
 ./week3
 Enter bits: 1000111110111

 Data bits before stuffing: 1000111110111
 Data bits after stuffing: 10001111100111
 */
