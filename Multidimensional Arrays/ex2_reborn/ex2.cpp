#include<iostream>
using namespace std;

int leggi(int*X, int dimX)
{
  int k,i=0;
  bool ok=false;
  while(!ok)
    {
      //cout<<"dai intero k, 0 < k <"<<dimX<<endl;
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


/*PRE=(vA=A[dim], index>0)*/
void deleteElem(int *A, int index, int dim){
    for(int i=index;i<dim;i++)
        A[i]=A[i+1];
}
/*POST=(A[index] è sostituito dai successivi A[i])*/

/*
PRE=(A ha dim elementi definiti, sia A_orig=A)*/
int K(int * A, int dim) {
    for(int slow=0; slow<dim; slow++){
        for(int fast=slow+1; fast<dim;fast++){
            if(A[slow]==A[fast]){
                deleteElem(A,fast,dim);
                dim--;
                fast--;
            }
        }
    }
    return dim;
}
/*
POST=(restituisce un intero n tale che A[0..n-1] è ottenuto da A_orig
 mantenendo per ogni valore solo l’istanza più a sinistra, come descritto nell’esempio, 
 quindi torna la dimensione dell'array finale e modifica A)
*/

/*
IDEA=(2 cicli, il primo lento verifica per ogni elemento se ne esistono altri
nell'array e li elimina sfruttando un ciclo più veloce di ricerca))
*/

/*
Esempio:sia A=[1,2,3,0,1,5,4,3,5,6,0,1], dopo l’operazione richiesta A 
deve diventare [1,2,3,0,5,4,6] che per ogni valore che appare nell’array
 originale mantiene solo la prima istanza e cancella le successive
*/


main()
{
  int A[30];
  int elemA=leggi(A,30);
  //da fare
  int ok = K(A,elemA);
  stampa(A,ok);
}