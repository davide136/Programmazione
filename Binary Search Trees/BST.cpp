#include<iostream>
#include "BST.h"
using namespace std;
using namespace BST;

//PRE=vr=r albero ben formato
void BST::stampa_l(nodo* r){
    if(r){
        cout<<r->info<<'(';
        stampa_l(r->left);
        cout<<',';
        stampa_l(r->right);
        cout<<')';
    }
    else cout<<'_';
}
//POST=viene stampato in console la forma lineare dell'albero r.

//PRE=vr=r ben formato BST
nodo* BST::insert(nodo* r, int val){
    if(r){
        if(val<r->info)
            r->left = insert(r->left, val);
        else
            r->right = insert(r->right, val);
    }
    else{
        r=new nodo(val,0,0);
        return r;
    }
    return r;
}
//POST=viene restituito r con aggiunto un nodo seguendo pr BST

//PRE=vr=r ben formato
bool BST::search (nodo* r, int val){
    bool found = false;
    if(r){
        if(r->info==val) return true;
        found = search(r->left, val);
        if(!found) found = search(r->right, val);
        
    }
    return found;
}
//POST=true sse esiste almeno un nodo con info=val

//PRE=vr=r ben formato BST
nodo* BST::max(nodo* r){
    if(r){
        if(r->right){
            if(r->right->info>r->info)
                return max(r->right);
            else
                return r;
        }
    }
    return r;
}
//POST=ritorna nodo con max campo info in vr

//PRE=vr=r ben formato BST
nodo* BST::min(nodo* r){
    if(r){
        if(r->left){
            if(r->left->info<r->info)
                return min(r->left);
            else
                return r;
        }
    }
    return r;
}
//ritorna nodo con minimo campo info in vr

//PRE=vr=r ben formato
int BST::altezza(nodo* r){
    if(r){
        int left = altezza(r->left);
        int right = altezza(r->right);
        if(left>right) return left+1;
        else return right+1;
    }else return -1; //albero vuoto
}
//POST=ritorna altezza max tra i cammini dell'albero

//PRE=vr=r ben formato
int BST::altMin(nodo* r){
    if(r){
        int a=altMin(r->left);
        int b=altMin(r->right);
        if(a<b) return a+1;
        else return b+1;
    }
    else return 0;
}
//POST=ritorna altezza minima tra i cammini dell'albero