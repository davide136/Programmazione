#include<iostream>
using namespace std;



void leggi(int*X, int& nelem)
{
  cin >>nelem;
  for(int i=0; i < nelem; i++)
    cin >> X[i];
}

/*
Questo esercizio è una variazione dell’esercizio 3 di questa settimana. 
In questo esercizio l’array a 3 dimensioni int A[3][6][5]non è, in generale, 
completamente definito, come si può capire dalla funzione leggi che è data.

Come per l’esercizio 3, vogliamo un programma che calcoli un array bool B[6][5] 
tale che B[i][j] è vero sse la H-fetta i è contenuta nella V-fetta j. 
Naturalmente però si devono considerare solamente gli elementi di A che sono definiti.
 Questo fatto può causare il fatto che B non sia tutta definita e questo 
 va considerato nella funzione stampaB che viene richiesta. 

 Questa funzione deve stampare solo gli elementi definiti di B.

 Nello scrivere stampaB sideve avere cura di considerare i casi particolari 
 in cui in A non tutta la prima riga del primo strato siadefinita e anche
  il caso in cui in A non sia definitainteramente il primo strato. 

  Solo in questi casi infatti si verificherà Che B non sia tutta riempita.
  Viene dato un main parziale chesi occupa della lettura di A
*/

bool compara(int*A,int dim_A, int*B, int dim_B){
  for(int i=0;i<dim_A; i++){
    int count=0;
    for(int j=0; j<dim_B;j++){
      if(A[i]==B[j])
        count++;
    }
    if(!count) 
      return false;
  }
  return true;
}

/*
PRE=(A[s][6][5] rimepito con nelem elementi. nelem>=0. B vuoto)
*/
int controlla(int (*A)[6][5], bool (*B)[5], int nelem, int s, int r){
  int full_sets = nelem/(6*5);
  int B_dim=0, resto=0, colonne=0, righe=0;
  if(nelem%5) resto =1;
  if(!full_sets){
    righe=nelem/5+resto;
    if(righe>1)
      colonne=5;
    else
      colonne=nelem%6; 
  } 
  else{
    righe=full_sets*6;
    colonne=full_sets*5;
  }
  for(int i=0;i<righe;i++){
    for(int j=0;j<colonne;j++, B_dim++){
      int H_size, V_size;
      if(i<(nelem%(6*5))%5) 
        H_size=full_sets*5+5;
      else if(i==(nelem%(6*5))%5) 
        H_size=full_sets*5+nelem%5;
      else 
        H_size=full_sets*5;

      if(j<=(nelem%(5*6)%5)) 
        V_size=full_sets*6+nelem/5+resto;
      else 
        V_size=full_sets*6+(nelem%(6*5))%5;

      int H[H_size];
      for(int k=0;k<H_size;k++) //estraggo la H fetta i esima
        H[k]=A[k/5][i][k%5];
      int V[V_size];
      for(int k=0;k<V_size;k++) //estraggo la V fetta j esima
        V[k]=A[k/6][k%6][j];//sistemare
      B[i][j]=compara(H,H_size,V,V_size);
    }
  }
  return B_dim;
}
/*
POST=(B[i][j]=true sse H-fetta i è contenuta in V-fetta j)&&(restituisce num iterazioni)
*/
/*IDEA=(estraggo h fetta j e v fetta i e le verifico in funzione secondaria salvando
il return di tale funzione in B[i][j])*/

void stampaB(bool (*B)[5], int nelem, int r){
  int righe=6;
  int colonne=5;
  if(nelem<5) {
    colonne = nelem;
    righe=1;
  }
  else righe = 6*nelem/(5*6);
  for(int i=0;i<righe;i++){
    for(int j=0; j<colonne; j++)
      cout<<B[i][j]<<' ';
    cout<<endl;
  }
}

main()
{
  int A[3][6][5], nelem;
  bool B[6][5];
  leggi(**A,nelem);
  
  int nbool = controlla(A,B,nelem,3,6);
  
  stampaB(B,nbool,6); //da fare
}