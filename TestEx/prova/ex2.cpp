#include<iostream>
using namespace std;

struct nodo{
	int info;
	nodo* left;
	nodo* right;

	nodo(int x=0, nodo* l=0, nodo* r=0){
		info = x;
		left = l;
		right = r;
	}
};

// FUNZIONI AUSILIARIE FORNITE
nodo* buildTree(int arr[], int i, int n)  {

    if (i >= n) {
    	return NULL;
    }
    nodo* root = new nodo(arr[i]);
    // insert left child
    root->left = buildTree(arr, 2 * i + 1, n);
    // insert right child
    root->right = buildTree(arr, 2 * i + 2, n);

    return root;

}

int height(nodo* root) {
	if(!root) {
		return -1;
	}
	return 1 + max(height(root->left), height(root->right));
}

void stampa_l(nodo *r)
{
  if(r)
    {
      cout<<r->info<<'(';
      stampa_l(r->left);
      cout<<',';
      stampa_l(r->right);
      cout<<')';
    }
  else
    cout<< '_';
}

void sc(int*C)
{
    cout<<*C<<' ';    
    if(*C!=-1)
    sc(C+1);
}

struct nodoE{nodo*info; nodoE* next; nodoE(nodo*a=0, nodoE*b=0){info=a; next=b;}};

void stampaE(nodoE*x)
{
  if(x)
    {cout << x->info->info<<' ';stampaE(x->next);}
  else
    cout << endl;

}

//PRE=T ha nodo info = a *(P-1) 
nodoE* checkPattern(nodo*T,int*P, int dimP){
  nodoE* result;
  if(!dimP)
    return new nodoE(T,0);
  if(T->left)
    if(T->left->info == *P){
      result = checkPattern(T->left,P+1, dimP-1);
      if(!result)
       return 0;
      else
       return new nodoE(T, result);
    }
      
  else if(T->right)
    if(T->right->info == *P){
      result = checkPattern(T->right,P+1, dimP-1);
      if(!result)
       return 0;
      else
       return new nodoE(T, result);
    }
  return 0;
}
//POST=nodoE costruito con nodi trovati, altrimenti 0

//PRE=(albero(T) ben formato, P >=0 elementi)
nodoE* PM1(nodo*T, int*P, int dimP){
  if(!T) return 0;
  nodoE* result = 0; 
  result = PM1(T->left,P, dimP);
  if(!result)
    result = PM1(T->right,P, dimP);
  if(T->info==*P){
    result = checkPattern(T,P+1, dimP-1);
    if(result)      
      return result;
  }
  return result;
}
/*POST=(se in T esiste un cammino che contiene un match di P completo e contiguo, allora PM1 restituisce
una lista di dimP nodi di tipo nodoE che puntano ai nodi del cammino più a sinistra su cui esiste un tale
match di P, altrimenti PM1 restituisce 0 ).*/

//idea=se trovo match con P[0] uso funzione ausialiaria che se trova match completo mi torna true
//caso base=T è vuoto

int main()
{
  int dim,dimP;
  cin >>dim>>dimP;
    nodo*r=0;
    int*A=new int[dim];
    for(int i=0; i<dim;i++)
     {
    	cin >> A[i];
    	r=buildTree(A,0,dim);
     }
    stampa_l(r);
    cout<<endl;
   
    int*P=new int[dimP];
    for(int i=0; i < dimP; i++)
      cin>>P[i];
    nodoE*z= PM1(r,P,dimP);
    if(z)
      {
	    cout<<"trovato match: ";
	    stampaE(z);
      }
    else
        cout<<"nessun match"<<endl;
}
