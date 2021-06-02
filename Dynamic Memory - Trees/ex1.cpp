#include<iostream>
using namespace std;
struct nodo{int info; nodo* next; nodo(int a=0, nodo*b=0){info=a; next=b;}};

nodo* faiL(int n)
{
  if(n)
    {
      int x;
      cin >> x;
      return new nodo(x,faiL(n-1));
    }
  return 0;

}
void stampa(nodo*L)
{
  if(L)
    {
      cout << L->info<<' ';
      stampa(L->next);
    }

  else
    cout<<endl;
}
nodo* clone(nodo*L)
{
  if(L)
    return new nodo(L->info,clone(L->next));
  return 0;
}
int length(nodo*L)
{
  if(L) return 1 + length(L->next);
  return 0;
}

/*PRE=(Lista(L) ben formata e ordinata, x punta ad un nodo) */
nodo* insOrd_ric(nodo*L, nodo*x) {
  nodo* R = new nodo();
  if(!L)
    return x;
  if(L->next){
    if(L->info<x->info){
      L = new nodo(L->info, insOrd_ric(L->next,x));
    }
    else{
      x->next = L;
      return x;
    }
  }
  else{ L->next=x; return L;}
  return L;
}
nodo* insOrd_iter(nodo* L, nodo*x) {
  int dimL = length(L);
  bool first = true;
  nodo* R[dimL+1];
  for(int i=0;i<dimL+1;i++){
    R[i]=L;
    if(L && L->info > x->info && first){
      R[i+1]=L;
      R[i]=x;
      i++; 
      first = false;
      L=L->next;
    }
    else
      if(L) L=L->next;
      else R[i]=x;
  }
  for(int i=0;i<dimL;i++){
    R[i]->next=R[i+1];
  }
  return R[0];
}
/*POST=(restituisce vL(L) con x aggiunto in modo che la nuova lista sia ancora ordinata)*/
/*
5 15
2  10  12  20  30
*/
main()
{
  int m, x;
  cin >> m >> x;
  nodo*L=faiL(m);
  nodo*L1=clone(L);
  
  L=insOrd_ric(L,new nodo(x));
  L1=insOrd_iter(L1, new nodo(x));
  stampa(L);
  stampa(L1);
}
