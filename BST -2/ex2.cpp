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

void buildBST(nodo*&r,int x)
{
  //cout << "inserisco "<<x<<endl;
  if(!r) {r=new nodo(x);return;}
  if(r->info>= x)
    buildBST(r->left,x);
  else
    buildBST(r->right,x);
}

//PRE=(r è albero ben formato && m1<=y<=m2 )
void calcIntMin(nodo* r, int *m1, int* m2, int y){
    if(r){
        if(r->info >= *m1 && r->info <= y )
          *m1 = r->info;
        if(r->info <= *m2 && r->info >= y )
          *m2 = r->info;
        calcIntMin(r->left, m1, m2, y);
        calcIntMin(r->right, m1, m2, y);
    }
    return;
}
/*POST=(vengono restituiti in m1 e m2 i valori di x1 e x2 t.c.
 x1<=y<=x2 e sono il minore intervallo possibile tra gli info dell'albero) */

//CORRETTEZZA_calcintmin=(scrorro albero, se trovo info maggiore 
//di m1 e minore di y, salvo tale valore in m1.
//se trovo info minore di m2 e maggiore di y salvo in m2.
//quando ho finito il giro ritorno.)

//PRE=(r è albero ben formato BST && m1<=y<=m2 )
void calcIntMinBST(nodo* r, int *m1, int* m2, int y){
    
    if(!r) *m1=*m2=0;
    else{
      bool ok = true;
      while(ok){
        if(!r) 
          ok = false;
        else{
          if(r->info==y){*m1=*m2=y; ok=false;}
          else if(y <= r->info && *m2 >= r->info){
            *m2 = r->info;
            r = r->left;
          }
          else if(y >= r->info && *m1 <= r->info){
            *m1 = r->info;
            r = r->right;
          }
        }
        
      }
    }
}
/*POST=(viene restituito tramite m1 e m2 la coppia di valori x1 e x2 t.c. 
x1 <= y <= x2 e sono il minore intervallo possibile tra gli info dell'albero)*/

/* CORRETTEZZA_calcintminBST=(scorro l'albero in base al valore di y:
Se y < info, devo spostarmi a sinistra, pongo m2 uguale all'info attuale
Se y > info devo spostarmi a destra e pongo m1 uguale all'info attuale)
*/


int main()
{
  int dim;
    cin >>dim;
    nodo*r=0;
    int*A=new int[dim];
    for(int i=0; i<dim;i++)
      {
	cin >> A[i];
	r=buildTree(A,0,dim);
      }
    nodo*r1=0;    
    for (int i=0; i<dim; i++)
      buildBST(r1,A[i]);
    
    
    stampa_l(r);
    cout<<endl;
    stampa_l(r1);
       
    bool basta=false;
    int l1,l2,y;
    while(!basta)
      {
        cin>> l1>>l2>>y;
        int z1=l1, z2=l2;
        if(y==-1)
          basta=true;
        else
          {
            calcIntMin(r,&l1,&l2,y);
            cout <<"l1="<<l1<<" l2="<<l2<<endl;
            
            calcIntMinBST(r1,&z1,&z2,y);
            cout <<"l1="<<z1<<" l2="<<z2<<endl;
          }
      }
}
