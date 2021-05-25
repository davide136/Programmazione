#include<iostream>
using namespace std;
struct nodo{
    int info; 
    nodo* next; 
    nodo(int a=0, nodo* b=NULL){info=a; next=b;}
};

int length(nodo*L)
{
  if(L) return 1 + length(L->next);
  return 0;
}

void stampa_LR_iter(nodo*L)
{       
    int k=length(L);
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

//PRE=(Lista(L) ben formata, vLista(L)=Lista(L))
nodo* del1(nodo* L, int z){
    if(!L)
        return 0;
    int val = L->info;
    if(length(L)==0)
        return 0;
    else if(length(L)>0 && val != z)
        return new nodo(val, del1(L->next,z));
    else return new nodo(L->next->info, del1(L->next->next, z));
}
//POST=(restituisce una lista composta dai nodi di vLista(L)che non hanno campo info=z nell’ordine che hanno in vLista(L)) && (dealloca gli altri nodidi vLista(L))

//PRE=(LIsta(L) ben formata, non vuota,e L->info != z, sia vLista(L)=Lista(L))
void del2(nodo*L, int z){
    if(!L)
        return;
    else if(length(L)>0 && L->info != z)
        del2(L->next, z);
    else if(L->info==z){
        L->info = L->next->info;
        L->next = L->next->next;
        del2(L,z);
    }
    else{ 
        delete L;
    }

}
//POST=(Lista(L) è ottenuta da vLista(L) eliminando i nodi con info=z e tenendo gli altri mantenendo il loro ordine) &&(i nodi con info=z sono deallocati)

//PRE=(Lista(L) ben formata, vLista(L)=Lista(L))
void del3(nodo*&L, int z){
   

}
//POST=(Lista(L) è ottenuto da vLista(L) eliminando i nodi con info=z e mantenendo gli altri nello stessoordine che avevano in vLista(L) && (i nodi eliminati sono deallocati)

main()
{
  int m,z;
  cin >> m;
  nodo*Y=build1(m);
  stampa_LR_iter(Y);
  cin >> z;
  Y=del1(Y,z);
  stampa_LR_iter(Y);
  cin >> z;
  del2(Y,z);
  stampa_LR_iter(Y);
  cin >> z;
  del3(Y,z);
  stampa_LR_iter(Y);
}
