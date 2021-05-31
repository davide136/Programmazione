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
 

struct doppiaL{nodo*L,*S; doppiaL(nodo*a=0,nodo*b=0){L=a; S=b;}};

/*PRE=(Lista(P) e Lista(T) sono ben formate, vT=T)*/
doppiaL matchX1(nodo*T,nodo*P){
    doppiaL R = doppiaL(0,T);
    if(T->next){
        if(P->next){
            if(P->info==T->info){ //nodo uguale, metto il nodo in D.S
                R = matchX1(T->next,P->next);
                if(R.S){ 
                    nodo* temp = R.S;
                    R.S = new nodo(T->info,temp);
                    return R;
                }
            }
            else{ //nodo diverso, salvo in D.L
                R = matchX1(T->next,P);
                if(R.S){
                    nodo* temp = R.L;
                    R.L = new nodo(T->info,temp);
                    return R;
                }
            }
        }
        else{ //Finito il pattern
            if(P->info==T->info){ //nodo uguale alla fine quindi salvo in D.S
                R.S = new nodo(T->info,0);
                R.L = new nodo(T->next->info,T->next->next);
                return R;
            }
            else{ //finito il pattern ma non tutti i nodi sono presenti!!
                return R;
            }
        }
    }
    return R;
}
/*POST=(La funzione restituisce sempre un valore doppiaL D come segue: 
se vT contiene m0,..,mk allora D.S=m0,..,mk e D.L contiene vTsenza i nodi m0...mk, 
mentre se vT non contiene m0,..mk allora la funzione restituisce D.S=0 e D.L=vT)*/

main()
{
  int m,z;
  cin >> m>>z;
  nodo*L=build1(m);
  stampa_LR_iter(L);
  nodo*P=build1(z);
  stampa_LR_iter(P);
  
  doppiaL D= matchX1(L,P);  
  stampa_LR_iter(D.L);
  stampa_LR_iter(D.S);
  
}
