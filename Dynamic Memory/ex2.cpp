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
    if(!L->next){
        if(L->info==z)
            return 0;
        else
            return new nodo(L->info, 0);
    }
    if(L->info==z)
        return del1(L->next,z);
    return new nodo(L->info, del1(L->next, z));
}
//POST=(restituisce una lista composta dai nodi di vLista(L)che non hanno campo info=z nell’ordine che hanno in vLista(L)) && (dealloca gli altri nodidi vLista(L))

//PRE=(LIsta(L) ben formata, non vuota,e L->info != z, sia vLista(L)=Lista(L))
void del2(nodo*L, int z){
    if(!L->next){   
        if(L->info==z)
            delete L;
        else
            return;
    }
    else{
        if(L->info==z){
            L->info = L->next->info;
            L->next = L->next->next;
        }
        if(L->next->info==z){
            L->next=L->next->next;
            del2(L,z);
        }
        else
            del2(L->next,z);
        
    }
    
}//POST=(Lista(L) è ottenuta da vLista(L) eliminando i nodi con info=z e tenendo gli altri mantenendo il loro ordine) &&(i nodi con info=z sono deallocati)

//PRE=(Lista(L) ben formata, vLista(L)=Lista(L))
void del3(nodo*&L, int z){
    if(!L->next){
        if(L->info==z)
            L=0;
        else   
            return;
    }
    else{
        if(L->info==z){
            L = L->next;
            del3(L,z);
        }
        else
            del3(L->next,z);
    }
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
