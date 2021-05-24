#include<iostream>
using namespace std;



void leggi(int* X, int & nelem)
{
    bool ok=false;
    while(!ok)
    {
        cin >>nelem;
        if(nelem>0 && nelem <=49)
        ok=true;
    }
    
  for(int i=0; i < nelem; i++)
    cin >> X[i];
}

void stampa(bool (*X)[7], int nelem){
    int righe = nelem / 7;
    bool eccesso = false;
    if( nelem %7 >0 )
        eccesso = true;

    for(int i=0; i < righe + eccesso; i++)
    {
        for(int j=0; j<7; j++)
            cout<<X[i][j]<<' ';
        cout << endl;
        
    }
}

bool check( int riga[7], int dim_riga, 
            int colonna[8], int dim_colonna ){
    for(int r=0;r<dim_riga;r++){
        for(int c=0;c<dim_colonna; c++){
            if(riga[r]==colonna[c])
                c=dim_colonna+1;                 //Per uscire dal ciclo
            else{
                if(c==dim_colonna-1)
                    return false;
            }            
        }
    }
    return true;
}

void calcB(int (*A)[7], bool (*B)[7], int nelem){
    int righe_intere = nelem / 7;
    int resto = nelem % 7;
    bool eccesso = false;
    if(resto>0)
        eccesso = true;
        
//check riga i esima con colonna j esima
    for(int j=0; j<7; j++){        
        for(int i=0;i<7;i++){
            int dim_colonna,dim_riga;
            if(eccesso)
                dim_colonna = righe_intere+1;
            else
                dim_colonna = righe_intere;
            if(eccesso && i==righe_intere)
                dim_riga = resto;
            else if (i>righe_intere+1)
                dim_riga = 0;
            else 
                dim_riga = 7;
            


            int colonna[dim_colonna];
            for(int k=0;k<dim_colonna;k++){
                colonna[k]=A[k][j];                
            }
            B[i][j] = check( 
                A[i], dim_riga,
                colonna, dim_colonna 
                );
        }
    }
}

int main()
{
  int A[7][7], nelem;
  bool B[7][7], finitoR=false;
  leggi(*A,nelem);
 
 //calcolo di B da fare
    calcB(A, B, nelem);

  stampa(B,nelem);
}
