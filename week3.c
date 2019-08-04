#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string.h>

char XOR(char a, char b){
  return '0' + (( a - '0') ^ (b - '0'));
}

int main(int argc, char ** argv){
  char frame[100] = "",
       divFrame[100] = "" ,
       dividend[100] = "",
       quotient[100] = "";

  int frame_size, div_size, i, j;

  scanf("%s %s", frame, divFrame);

  frame_size = strlen(frame);
  div_size = strlen(divFrame);

  strcpy(dividend, frame);

  for(i = 0; i < 4; i++)
    dividend[frame_size + i] = '0';

  for(i = 0; i <= frame_size - div_size + 4 ;  i++){

    if ( dividend[i] == '0' ){
      quotient[i] = '0';
      continue;
    }

    quotient[i] = '1';
    for(j = 0; j < div_size; j++){
      dividend[i + j] = XOR(dividend[i + j], divFrame[j]);
    }
  }

    printf("Quotient: %s\n", quotient);
    printf("Remainder: %s\n", dividend + frame_size + 5 - div_size);

  return 0;
}
/*
11101111 11011
Quotient: 10100001
Remainder: 1011
*/
