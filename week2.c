#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

char frames[100][100];

void PrintSort(int totalFrames ){
  int arr[100];
  int i, j;
  char temp[100], key[100];
  int itemp, ikey;

  for( i = 0; i < totalFrames; i++)
    arr[i] = i;

  for(i = 1; i < totalFrames; i++){
    ikey = arr[i];
    strcpy(key, frames[i]);
    j = i - 1;
    while(j >= 0 && (strcmp(key, frames[j]) < 0) ){
      arr[j + 1] = arr[j];
      strcpy(frames[j + 1], frames[j]);
      j--;
    }
    arr[j + 1] = ikey;
    strcpy(frames[j+1], key);
  }

  for(i = 0; i < totalFrames; i++){
    printf("Frame %d: %s\n", arr[i] + 1, frames[i]);
  }
}

int main(int argc, char** argv){
  char data[1000];
  int i, j, frame_size, total_no_frames, length;

  scanf("%[^\n]s", data);
  scanf("%d", &frame_size);
  length = strlen(data);

  total_no_frames = length % frame_size == 0 ? length / frame_size : length / frame_size + 1;
  for(i = 0; i < total_no_frames; i++){
    for(j = 0; j < frame_size && (i * frame_size + j < length); j++){
      frames[i][j] = data[i * frame_size + j];
    }
    frames[i][j] = '\0';
  }

  PrintSort(total_no_frames);

  return 0;
}

/*
shaik chand basha
3
Frame 5: bas
Frame 3: cha
Frame 6: ha
Frame 2: ik
Frame 4: nd
Frame 1: sha
*/
