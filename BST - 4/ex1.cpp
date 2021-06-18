#include<iostream>
using namespace std;

struct nodo{int info; nodo*next; nodo(int a =0, nodo*b=0){info=a; next=b;}};

nodo* faiL(int arr[],int dim)
{
  if(dim)
    {return new nodo(*arr, faiL(arr+1,dim-1));}
  else
    return 0;
}

nodo* clone(nodo*L)
{
  if(!L) return 0;
  return new nodo(L->info,clone(L->next));
}

void stampaL(nodo*L)
{
  if(!L) cout <<endl;
  else
    {
      cout << L->info<<' ';
      stampaL(L->next);
    }
}

//PRE=(L(L) ben formata, k>=y, vL=L)
bool checkL(nodo*&L,int k, int y){
    if(k==0) return true;
    if(!L) return false;
    if(L->info==y) return checkL(L->next, k-1, y);
    return checkL(L->next, k, y);
}
//POST=(VERO sse trovo k occorrenze di y in L(L))

/*PRE=(L(L) ben formata, k>=y),vL=L)*/
nodo* elimI(nodo*L, int &n, int k, int y){
  if(!L) return 0; 
  if(!L->next) return L;
  if(checkL(L,k,y)){
    if(L->info==y){ //y è il primo elemento di L
      L = L->next;
    }
    if(L->next->info==y && n<=k){
      nodo *temp = L->next;
      if(!temp->next)
        L->next = 0;
      else
        L->next=temp->next;
      delete temp;
      n++;
    }
    L->next = elimI(L->next,n,k,y);
  }
  return L;
}
/*POST=(se vL contiene almeno k nodi con info=y, allora L è ottenuta
 da vL eliminando i primi k nodi con info=y di vL, altrimenti, L=vL)&&
 ( se nodi di vL vengono cancellati, essi vanno deallocati)*/

 /*
 IDEA=(scorro in in maniera prefissa la lista, quando il prossimo elemento
 corrisponde a y, vL diventa vL@L->next ed elimino il nodo L)&&(2 casi base,
 1 - lista vuota, 2 - sono sull'ultimo nodo)
 */

 /*PRE=(L(L) ben formata, k>=y),vL=L)*/
nodo* elimF(nodo*L, int &n, int k, int y){
    if(!L) return 0;
    if(k==0) return L;
    if(checkL(L,k,y)){
        if(L->info==y && k!=n){
            nodo* temp = L;
            return L->next;
            delete temp;
            k--;
            n++;
        }
        return elimI(L->next,n,k,y);
    }
    return L;
}
/*POST=(se vL contiene almeno k nodi con info=y, allora L è ottenuta
 da vL eliminando i primi k nodi con info=y di vL, altrimenti, L=vL)&&
 ( se nodi di vL vengono cancellati, essi vanno deallocati)*/

main()
{
  int dim;
  cin >> dim;
  int*arr= new int [dim];
  for(int i=0; i<dim; i++)
    cin >>arr[i];
  nodo*L=faiL(arr, dim);
  nodo*L1=clone(L);

  int n=0, k, y;
  cin >> k >> y;
  L=elimI(L,n,k,y);
  n=0;
  L1=elimF(L1,n,k,y);
  stampaL(L);
  stampaL(L1);



}
