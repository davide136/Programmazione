#include<iostream>
#include<sstream>
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


string tree_to_string_PRE(nodo* root){
  string result = "";
  if(root){
    result = result + to_string(root->info) + " ";
    result += tree_to_string_PRE(root->left);
    result += tree_to_string_PRE(root->right);
  }
  return result;
}

string tree_to_string_INF(nodo* root){
  string result = "";
  if(root){
    result += tree_to_string_PRE(root->left);
    result = result + to_string(root->info) + " ";
    result += tree_to_string_PRE(root->right);
  }
  return result;
}

/*PRE=(albero(r) ben formato,0<= n<=k, k>0)*/
int stampaASPre(nodo*r, int n){
  string r_prefisso = tree_to_string_PRE(r);
  for(int i=2;i<r_prefisso.length();i=i+2){
    if(i%(2*n) == 0){
      cout << r_prefisso[i-2]<<' ';
    }
  }
  int resto = r_prefisso.length()%(2*n)-1;
  return resto;
}
/*POST=(considerando I nodi di albero(r) in ordine prefisso, salta n nodi e poi 
stampa quello successivo e dopo ne salta k-1 e poi stampa il successivo, restituisce
 col return un intero m tale che (k-1)-m è il numero di nodi che sono stati saltati 
 dopo l’ultimo stampato)*/

 /*PRE=(albero(r) ben formato,0<= n<=k, k>0)*/
int stampaASInf(nodo*r, int n){

  string infisso = tree_to_string_INF(r);
  for(int i=2;i<infisso.length();i=i+2){
    if(i%(2*n) == 0){
      cout << infisso[i-2]<<' ';
    }
  }
  int resto = infisso.length()%(2*n)-1;
  return resto;
    
}
/*POST=(considerando I nodi di albero(r) in ordine infisso, salta n nodi e poi 
stampa quello successivo e dopo ne salta k-1 e poi stampa il successivo, restituisce
 col return un intero m tale che (k-1)-m è il numero di nodi che sono stati saltati 
 dopo l’ultimo stampato)*/

int main() {
  int dim;
    cin >>dim;
    int* a= new int[dim];
    for (int i=0; i<dim; i++)
      cin >> a[i];
      
    nodo* root = NULL;
    root = buildTree(a, 0, dim);
    //stampa_l(root);
   
    int k;  
    cin>>k;    
    
   int a1 = stampaASPre(root, k);
   cout << "con avanzo "<< a1<<endl;
   int b1=  stampaASInf(root, k);
   cout << "con avanzo "<< b1 <<endl;
   
}
