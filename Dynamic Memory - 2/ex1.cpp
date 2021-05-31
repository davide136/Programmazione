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
struct doppiaL{nodo*L,*S; doppiaL(nodo*a=0,nodo*b=0){L=a; S=b;}};
nodo* build1(int m)
{
   if(m==0) return 0;
   int s;
   cin >>s;
   return new nodo(s,build1(m-1));
}

//PRE= (T e P sono liste ben definite)
doppiaL match1(nodo*T, nodo*P){  
  if(T && P){
    if(T->info==P->info){
      doppiaL q = match1(T->next,P->next);
      if(!q.L)
        q.L = T->next;
      if(!q.S)
        T->next=0;
      else
        T->next = q.S;
      q.S = T;
      return q;
    }
    else{
      doppiaL q = match1(T->next,P);
      q.L = new nodo(T->info,q.L);     
      T->next=q.L;
      return q;
    }
  }
  return doppiaL();
}
//POST=(se in T c’è un match P’ di P, la funzione restituisce un valore doppiaL q, 
// con q.S=P’ e q.L=quello che resta di T una volta tolto P’,
// si considera il match P’ che inizia più a sinistra in T)&&( se in T non c’è match di P,
//allora la funzionerestituisce un valore doppiaL q con q.L=T e q.s=0)

//PRE=(T e P sono ben formate)
nodo* match3(nodo*&T, nodo*P){
  if(T && P){
    if(T->info==P->info){
      nodo* q = new nodo(); 
      q->next = match3(T->next,P->next);
      q->info = T->info;
      T=T->next;
      return q;
    }
    else{
      return match3(T->next,P);
    }
  }
  return 0;
}
//POST=(se c’è match restituisce il primo match P’ col return e quello che resta 
//di T nel parametro T) &&(se non c’è match T resta invariata e ritorna 0 col return)

nodo*clone(nodo*L)
{
	if(!L) return 0;
	return new nodo(L->info,clone(L->next));
}

main()
{
  int m,z;
  cin >> m>>z;
  nodo*L=build1(m);
  stampa_LR_iter(L);
  nodo*P=build1(z);
  stampa_LR_iter(P);
  nodo*L1=clone(L);
  nodo* P1=clone(P);
  doppiaL D= match1(L,P);  
  stampa_LR_iter(D.L);
  stampa_LR_iter(D.S);
  nodo* q= match3(L1,P1);  
  stampa_LR_iter(L1);
  stampa_LR_iter(q);
}

      /*
15 5
1 0 1 0 2 0 3 4 0 1 2 0 4 1 0
3 4 0 1 2
      */