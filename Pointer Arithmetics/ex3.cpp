#include<iostream>
using namespace std;


void leggi(int*X, int nelem)
{
  for(int i=0; i < nelem; i++)
    cin >> X[i];
}

void stampa(bool (*B)[5],int righe)
{
  for(int i=0; i<righe; i++)
    {
      for(int j=0;j<5; j++ )
  cout<<B[i][j]<<' ';
      cout<<endl;
    }
}

bool CONTROLLA(int *R, int dim_rig, int *C, int dim_col){
      for(int r=0;r<dim_rig;r++){
        for(int c=0;c<dim_col; c++){
            if(R[r]==C[c])
                c=dim_col+1;                 //Per uscire dal ciclo
            else{
                if(c==dim_col-1)
                    return false;
            }            
        }
    }
    return true;
}

void CONVERTI(int (*T)[6][5], int s, bool (*DEST)[5]){
  //PRE=T ha s strati ed è completamente definito, s rappresenta gli strati, potrebbero 
  // anche essere più di 3 per come è scritto il programma, invece rige e colonne devono essere 
  // 6 e 5, a meno che non le spostiamo a variabili di classe.
  
  //ciclo iterativo su array verità 
  for(int indRig=0; indRig<6; indRig++){
    for(int indCol=0; indCol<5; indCol++){
        //creazione array colonna
        int C[6*s];
        for(int i=0;i<6*s;i++)
          C[i]=T[i/6][i%6][indCol];
        
        //creazione array riga
        int R[5*s];
        for(int i=0;i<5*s;i++)
          R[i]=T[i/5][indRig][i%5];
        
        DEST[indRig][indCol] = CONTROLLA(R,5*s,C,6*s);
    }
  }
}


main()
{
  int A[3][6][5];
  bool B[6][5];
  leggi(**A,90);
//da fare  
  CONVERTI(A,3,B);
  //POST = B è stato modificato direttamente dalla funzione CONVERTI,  A rimane invariato per tutto il processo.
  // sono creati dei vettori ausiliari che vengono rilasciati nel momento in cui si giunge a questa riga.
  stampa(B,6);
  
}