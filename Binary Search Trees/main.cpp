#include<iostream>
#include "BST.h"
using namespace std;
using namespace BST;

main()
{
    //prepara un albero iniziale non triviale
  nodo* r=new nodo(15, new nodo(7), new nodo(19));
  r->left->right=new nodo (9, new nodo(8));
  r->right->right=new nodo(25, new nodo(22));
  
  bool stop=false;
  while(!stop)
    {
      //legge le istruzoni e le esegue
      int fun, val;
      cin >> fun;
      if(1 < fun && fun < 5 ) cin>>val;
      switch(fun){
        case 1: stampa_l(r); cout<<endl; break;
        case 2: insert(r,val); stampa_l(r); cout<<endl; break;
        case 3: 
          if(search(r,val))
            cout<<"valore "<<val<<" presente"<<endl;
          else
            cout<<"valore "<<val<<" non presente"<<endl;
          break;
        case 4: 
          if(val==1)
            cout<<max(r)->info<<endl;
          if(val==2)
            cout<<min(r)->info<<endl;
          break;
        case 5: cout<<altezza(r)<<endl; break;
        case 6: cout<<altMin(r)<<endl; break;
        case 0: stop = true; break;
        default: cout<<"Scelta non valida."<<endl; break;
      }
    }
}