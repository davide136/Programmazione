#include<iostream>
using namespace std;



void leggi(int*X, int& nelem)
{
  cin >>nelem;
  for(int i=0; i < nelem; i++)
    cin >> X[i];
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

void CONVERTI(int (*T)[6][5], int s,int nelem, bool (*DEST)[5]){
    //assegnazioni variabili ausiliarie per calcolare grandezza array verità   
    int strati_interi = nelem / (6*5);
    int avanzo_ultimo_strato = nelem % (6*5); 
    int avanzo_ultima_riga = avanzo_ultimo_strato%5;
    int righe_intere = avanzo_ultimo_strato / 5;
    int righe_DEST = righe_intere;
    bool esiste_avanzo_ultimo_strato = false;
    bool esiste_avanzo_ultima_riga = false;
    if(avanzo_ultimo_strato>0)
        esiste_avanzo_ultimo_strato = true;
    if(avanzo_ultima_riga>0)
        esiste_avanzo_ultima_riga = true;
    if(righe_intere>0)
        righe_DEST = 7;
    if(esiste_avanzo_ultimo_strato && strati_interi==0)
        righe_DEST = (nelem / 5)+esiste_avanzo_ultima_riga;
    int col_DEST = 5;
    if(nelem<5)
        col_DEST=nelem;

  //ciclo iterativo su array verità 
  for(int indRig=0; indRig<righe_DEST; indRig++){
    for(int indCol=0; indCol<col_DEST; indCol++){
        //creazione array colonna
        int dim_colonna = 0;
        if(indCol<avanzo_ultimo_strato%5)
            dim_colonna = (strati_interi)*6
                +(esiste_avanzo_ultimo_strato*(
                    avanzo_ultimo_strato/5 
                    + esiste_avanzo_ultima_riga
                ));
        else
            dim_colonna = (strati_interi)*6
                +(esiste_avanzo_ultimo_strato*(
                    avanzo_ultimo_strato/5 
                    + esiste_avanzo_ultima_riga
                )) -1;
        int C[dim_colonna];
        for(int i=0;i<dim_colonna;i++)
          C[i]=T[i/6][i%6][indCol];
        

        //creazione array riga
        int dim_riga = 0;
        if(indRig<righe_intere)
            dim_riga = (strati_interi*5)+(esiste_avanzo_ultimo_strato*5); 
        else if (indRig==righe_intere && esiste_avanzo_ultimo_strato)
            dim_riga = (strati_interi*5)+(avanzo_ultimo_strato%5);
        else if (indRig>righe_intere)
            dim_riga = strati_interi*5;
        int R[dim_riga];
        for(int i=0;i<dim_riga;i++)
          R[i]=T[i/5][indRig][i%5];
        
        if(indRig==4)
         bool a = true;
        DEST[indRig][indCol] = CONTROLLA(R,dim_riga,C,dim_colonna);
    }
  }
}

void stampaB(bool (*B)[5], int nelem, int s){
    //Calcolo quante rige mostrare
    int strati_interi = nelem / (s*5);
    int avanzo_ultimo_strato = nelem % (s*5);
    int righe_DEST = avanzo_ultimo_strato / 5;
    if (strati_interi > 0)
        righe_DEST = 6;
    if(avanzo_ultimo_strato>0 && strati_interi==0)
        righe_DEST = 1;
    int col_DEST = 5;
    if(nelem<5)
        col_DEST=nelem;

    //Itero B per mostrarne gli elementi
    for(int indRig=0; indRig<righe_DEST; indRig++){
        for(int indCol=0; indCol< col_DEST; indCol++)
            cout<<B[indRig][indCol]<<' ';
        cout<<endl;
    }   
}

int main()
{
  int A[3][6][5], nelem;
  bool B[6][5];
  leggi(**A,nelem);
  
  //PRE=T ha s strati ed è non completamente definito, s rappresenta gli strati, potrebbero 
  // anche essere più di 3 per come è scritto il programma, invece rige e colonne devono essere 
  // 6 e 5, a meno che non le spostiamo a variabili di classe.
  
  //INVARIANTE= ogni colonna avrà sempre elementi e sarà sempre confrontabile con una riga,
  // le righe invece ad un certo punto termineranno con un avanzo_ultimo_strato.
  // righe intere = nelem / 5 elem per riga
  // avanzo_ultimo_strato = nelem % 5 elem per riga
  //indice prima riga vuota = righe intere + 1
  CONVERTI(A,3,nelem,B);
  //POST = B[i][j]=true sse H(A[i]) è contenuto in V(A[j]) non definito per righe vuote di A
  stampaB(B,nelem,6); //da fare
}