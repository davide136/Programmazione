#include<iostream>
using namespace std;

int leggi(int*X, int dimX)
{
  int k,i=0;
  bool ok=false;
  while(!ok)
    {
      cout<<"dai intero k, 0 < k <"<<dimX<<endl;
      cin >> k;
      if(0<k && k<dimX)
	    ok=true;
    }
  
  while(i<k)
    {
      cin >>X[i];
      i=i+1;
    }
  return k;
}

void stampa(int*X, int lim)
{
  int i=0;
  while(i < lim)
    {
      cout<<X[i]<<' ';
      i=i+1;
    }
  cout<<endl;
}

int K(int *A, int dim){
    int finalSize = dim;
    for(int slow=0;slow<dim;slow++){
        for(int fast=slow+1;fast<finalSize;fast++){
            if(A[slow]==A[fast]){
                for(
                    int temp=0;
                    temp<(finalSize-fast);    //quantità celle da traslare a sinistra 
                    temp++){
                        A[fast+temp]=A[fast+temp+1];
                    }
                finalSize--;                //Sezione finale traslata, diminuiamo dimensione
                slow--;                     //Altrimenti esegue il check solo una volta.
            }
        }
    }
    return finalSize;
}

int main()
{
  int A[30];
  int elemA=leggi(A,30);
  //PRE= A ha elemA elem definiti con 0 < elemA < 30
  int ok = K(A, elemA);        //A viene direttamente modificato
  //POST= ok è la nuova dim dell'array semplificao come da istruzioni, A 
  stampa(A,ok);
}