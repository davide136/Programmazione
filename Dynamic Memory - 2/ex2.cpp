#include<iostream>
using namespace std;
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=NULL){info=a; next=b;}};
int length(nodo*L)
{
  if(L) return 1 + length(L->next);
  return 0;
}
void stampa_LR_iter(nodo*L)
{       int k=length(L);
  
	for(int i=0; i<k; i++)
	  {cout<<L->info<<' '; L=L->next;}
	cout<<endl;
}

nodo* build1(int m)
{
   if(m==0) return 0;
   int s;
   cin >>s;
   return new nodo(s,build1(m-1));
}
 

//PRE=(T e P sono ben formate)
nodo* match3b(nodo*&T, nodo*P){
  if(T){
    if(P){
      if(T->info==P->info){               
        T->next = match3b(T->next,P->next);
        return T;
      }
      else if(!P->next){
        
      }
      else{       
        nodo* q = new nodo(); 
        q->next = match3b(T->next,P);
        q->info = T->info;
        return q;
      }
    }
  }
  return T;
}
//POST=(se c’è match restituisce il primo match P’ con il parametro T per riferimento 
// e quello che resta come ritorno) &&(se non c’è match T diventa 0 e viene 
//tornato il valore iniziale di T)





main()
{
  int m,z;
  cin >> m>>z;
  nodo*L=build1(m);
  stampa_LR_iter(L);
  nodo*P=build1(z);
  stampa_LR_iter(P);
  
  nodo* q= match3b(L,P);  
  stampa_LR_iter(q);
  stampa_LR_iter(L);
}

