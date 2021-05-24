#include<iostream>
using namespace std;

void leggi(int*X, int k)
{
  int i=0;
  while(i<k)
    {
      cin >>X[i];
      i=i+1;
    }
}

void stampaMat(bool (*X)[8], int righe)
{
  for(int i=0; i < righe; i++)
    {
      for(int j=0; j<8; j++)
	     cout<<X[i][j]<<' ';
      cout << endl;
    }
  
}

bool check( int riga[7], int colonna[8] ){
    for(int r=0;r<7;r++){
        for(int c=0;c<8; c++){
            int rig=riga[r], col=colonna[c];
            if(riga[r]==colonna[c])
                c=100;
            else{
                if(c==6)
                    return false;
            }            
        }
    }
    return true;
}

void calcB (int A[7][8], bool B[7][8]){
    //check riga i esima con colonna j esima
    for(int j=0; j<8; j++){
        for(int i=0;i<7;i++){
            int colonna[7];
            for(int k=0;k<7;k++){
                colonna[k]=A[k][j];
            }
            B[i][j] = check( A[i], colonna );
        }
    }
}

int main()
{
  int A[7][8];
  bool B[7][8];
  
  leggi(*A,56); //lo leggiamo come se avesse 1 dimensione
  
  //da fare
    calcB(A,B);

  stampaMat(B,7);
}