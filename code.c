#include<stdio.h>
#include<stdlib.h>

void Union(int H[], int i, int j, int P[])
{

  if(H[i] > H[j])
    P[j] = i;
  else
    P[i] = j;
  if(H[i] == H[j])
    H[i]++;
}

int find(int i, int P[])
{
  if(P[i] == -1)
    return i;
  else{
  P[i] = find(P[i], P);
  printf("P[%d] : %d\n",i, P[i]);
    return P[i];}
}



int minSwapsCouples(int* row, int rowSize){
  int j, i, swaps = 0, a, b;
  int *H = (int *)malloc(sizeof(int)*rowSize);
  int *P = (int *)malloc(sizeof(int)*rowSize);
  for(i=0;i<rowSize;i++)
  {
    H[i] = 0;
    P[i] = -1;
  }
  for(i=0;i<rowSize-1;i+=2)
  {
    Union(H, row[i], row[i + 1], P);
  }
  for(i=0;i<rowSize-1;i+=2)
  {
    a = find(i, P);
    b = find(i + 1, P);
  // printf("P : %d %d\n",P[i], P[i+1]);
    if(a == b)
    {
      continue;
    }
    else
    {
      Union(H, a, b, P);
      swaps++;
    }
  }
  return swaps;
  free(H);//deleting the allocated memmory which can result into memory leak
  free(P);
}
