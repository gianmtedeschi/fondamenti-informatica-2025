#include<stdio.h>
#define N 6

void read_array(int []);
int sequenze(int [], int);

int main(){
  int v[N];
  int k,res;

  read_array(v);
  printf("Introdurre k:\n");
  scanf("%d",&k);

  res = sequenze(v,k);
  printf("numero di seq= %d\n",res);

  return 0;
}

void read_array(int v[]){
  int i;
  printf("Introdurre array di dimensione %d:\n", N);
  for (i=0; i<N; i++){
    scanf("%d",&v[i]);
  }
}

int sequenze(int v[], int k){
  //c: lunghezza della sequenza corrente
  //c_max: lunghezza della sequenza massima incontrata
  int i,c=1,c_max=1;

  for(i=0; i<N-1; i++){
    if(v[i+1]==v[i]+k || v[i+1]==v[i]-k) {
      c++;
      if(c_max < c)
        c_max = c;
    } else {
      c=1;
    }
  }
  
  return c_max;
}
