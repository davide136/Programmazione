#include<iostream>
using namespace std;
void leggi(bool*B, int nelem)
{
  for(int i=0; i<nelem; i++)
    cin >> B[i];
}


void print_path(int*X, int righe)
{
  for(int i=0; i<righe; i++)
    {
      cout<<'('<<i<<','<<X[i]<<')'<<' ';
    }
  cout <<endl;
}

//PRE=(Palude rx8 di bool, 0<=index<8, 0<=r<8)
bool search_path(bool (*Palude)[8], int index, int r, int *Path){
  if(r<0)
    return true;
  if(index==0){
    if(Palude[r-1][index]){
      Path[r]=index;
      Palude[r][index]=search_path(Palude,index,r-1,Path);
    }
    else if(Palude[r-1][index+1]){
      Path[r]=index;
      Palude[r][index]=search_path(Palude,index+1,r-1,Path);
    }
    else return false;
  }
  else if(index==7){
    if(Palude[r-1][index-1]){
      Path[r]=index;
      Palude[r][index]=search_path(Palude,index-1,r-1,Path);
    }
    else if(Palude[r-1][index]){
      Path[r]=index;
      Palude[r][index]=search_path(Palude,index,r-1,Path);
    }
    else return false;
  }
  else{
    if(Palude[r-1][index-1]){
      Path[r]=index;
      Palude[r][index]=search_path(Palude,index-1,r-1,Path);
    }
    else if(Palude[r-1][index]){
      Path[r]=index;
      Palude[r][index]=search_path(Palude,index,r-1,Path);
    }
    else if(Palude[r-1][index+1]){
      Path[r]=index;
      Palude[r][index]=search_path(Palude,index+1,r-1,Path);
    }
    else return false;
  }
  return Palude[r][index];
}
//POST=(ritorno true sse ho un percorso)

/*PRE=Palude è un array 8x8 di bool, pieno. Path vuoto.*/
bool build_path(bool (*Palude)[8], int r, int*Path){
  for(int i=0;i<8;i++){
    if(Palude[r-1][i])
      Palude[r-1][i] = search_path(Palude, i, r-1, Path);       
    if(Palude[r-1][i])
      i=8; //rompe il ciclo
  }
  for(int i=0;i<8;i++){
    if(Palude[7][i]) return true;
  }
  return false;
}
/*POST=Path contiene cammino che collega 0 a 7 in Palude */
/*
funzione ausiliaria che viene provata, nel momento in cui trova che i vlaori davanti, 
a sinistra e a destra sono falsi torna falso e in ricorrenza porta tutto a falso. Mentre scorre
salva in Path. Rimane l'unica strada possibile.
*/

main()
{
  bool Palude[8][8];
  leggi(*Palude,64);
  bool stop=false;

  int Path[8];
  if(build_path(Palude,8,Path))
    print_path(Path,8);
  else
    cout<<"nessun cammino"<<endl;
}