#include<iostream>
using namespace std;
void leggi(bool*B, int nelem)
{
  for(int i=0; i<nelem; i++)
    cin >> B[i];
}

bool false_pool[8][8] = {
false, false, false, false, false, false, false, false,
false, false, false, false, false, false, false, false,
false, false, false, false, false, false, false, false,
false, false, false, false, false, false, false, false,
false, false, false, false, false, false, false, false,
false, false, false, false, false, false, false, false,
false, false, false, false, false, false, false, false,
false, false, false, false, false, false, false, false};

struct err{
  int raw, col;
  err(int r, int c){ raw=r; col=c;}
};

void print_path(int*X, int righe)
{
  for(int i=0; i<righe; i++)
    {
      cout<<'('<<i<<','<<X[i]<<')'<<' ';
    }
  cout <<endl;

}

void print_palude(bool (*X)[8], int r){
  cout << endl;
  for(int raw=0;raw<r;raw++){
    for(int col=0; col<8; col++){
      cout << X[raw][col] << ' ';
    }
    cout << endl;
  }
}

bool check_before(bool (*Palude)[8], int r, int current_raw, int current_column){
  if(current_column==0){
    if(!Palude[current_raw-1][current_column] && !Palude[current_raw-1][current_column+1]){
      return false;
    }
  }
  else if(current_column==7) {
    if(!Palude[current_raw-1][current_column-1] && !Palude[current_raw-1][current_column]){
      return false;
    }
  }
  else {
    if(!Palude[current_raw-1][current_column-1] && !Palude[current_raw-1][current_column] && !Palude[current_raw-1][current_column+1]){
      return false;
    }
  }
  return true;
}

bool check_after(bool (*Palude)[8], int r, int current_raw, int current_column){
  if(current_column==0){
    if(!Palude[current_raw+1][current_column] && !Palude[current_raw+1][current_column+1]){
       return false;
    }
  }
  else if(current_column==7) {
    if(!Palude[current_raw+1][current_column+1] && !Palude[current_raw+1][current_column]){
      return false;
    }
  }
  else {
    if(!Palude[current_raw+1][current_column-1] && !Palude[current_raw+1][current_column] && !Palude[current_raw+1][current_column+1]){
      return false;
    }
  }
  return true;
}

void build_path(bool (* Palude)[8], int r, int *Path){
  //PRE=Palude bool rx8 pieno, r=8, array comprende solo una path valida
  int current_raw = r-1;  
  int current_column = 0;
  while(current_raw>=0){
    while(current_column<8){
      if(Palude[current_raw][current_column]){
        bool before = true;
        if(current_raw>0)
          before = check_before(Palude, r, current_raw, current_column);
        else
          before = Palude[current_raw][current_column];
        if(before)
          Path[current_raw]=current_column;     
      }
      current_column ++;
    }
    current_column=0;
    current_raw--;
  }
  //POST=Path contiene gli indici colonna del percorso più a sinistra
}

bool no_path(bool (*Palude)[8], int r){
  //PRE=Palude array completo rx8
  int current_raw = r-1;
  try{
        int current_column = 0;

        while(current_raw>=0){
          while(current_column<8){
            if(Palude[current_raw][current_column]){
              bool before = true, after = true;
              if(current_raw>0)
                before = check_before(Palude, r, current_raw, current_column);
              if(current_raw<r-2) 
                after = check_after(Palude, r, current_raw, current_column); 
              bool result = before && after;           
              if( !result )
                throw err(current_raw, current_column);
            }
            current_column ++;
          }
          current_raw--;
          if(current_column==8)
            current_column = 0;
          else 
            current_column=current_column-2;
        }

  }catch(err e){
    Palude[e.raw][e.col]=false;
    no_path(Palude,r);
  }
  for(int i=0;i<r;i++)
    for(int j=0;j<8;j++)
      if(Palude[i][j])
        return false;
  return true;
}


main()
{
  bool Palude[8][8];
  leggi(*Palude,64);
  bool stop=false;
  // parte da fare
  stop = no_path(Palude, 8);
  //POST=(stop sse non c'è cammino) & Palude svuotato di tutti i valori che non completano path
  if(!stop)
    {
      int Path[8];//da riempire
      build_path(Palude,8,Path);//la dovete fare
      print_path(Path,8); //questa è data
    }
  else
    cout<<"nessun cammino"<<endl;
}
