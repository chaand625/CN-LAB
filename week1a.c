#include <stdio.h>
#include <stdlib.h>

int main(){
  int n, i, j,
      no_frames,
      frames[100];

  int data[100][100];

  printf("Enter the no.of frames: ");
  scanf("%d", &no_frames);

  printf("Enter the size of each frame: " );
  for(i = 0; i < no_frames; i++)
    scanf("%d", frames + i );

  printf("Enter the elements of each frame: " );
  for(i = 0; i < no_frames; i++)
    for(j = 0; j < frames[i]; j++)
      scanf("%d", &data[i][j]);

  printf("::The resultant array::\n");
  for(i = 0; i < no_frames; i++){
    printf("%d ", frames[i]);
    for(j = 0; j < frames[i]; j++)
      printf("%d ", data[i][j]);
  }

  return 0;
}
/*
./myweek1
Enter the no.of frames: 2
Enter the size of each frame: 3 4
Enter the elements of each frame: 1 2 3 4 4 4 5
::The resultant array::
3 1 2 3 4 4 4 4 5
*/
