#include<iostream>
using namespace std;

void leggi(int*X, int nelem)
{
  for(int i=0; i < nelem; i++)
    cin >> X[i];
}

int& FETTE(int (*T)[6][5], int s, char F, int indf, int k){
    //PRE=T ha s strati ed è completamente definito, F e indf 
    //specificano una fetta esistente in T, k >=0è un elemento 
    //esistente della fetta richiesta
    
    switch(F){
        case 'V': 
            // k/6 trova strato
            // k%6 trova riga
            // indf + (k/s) trova colonna
                    
            return T[k/6][k%6][indf];
        case 'H': 
            // indf trova riga 
            // k/5 trova strato
            // k%5 trova colonna
            return T[k/5][indf][k%5];
        default: return ***T;
    }
    //POST=(restituisce l’elemento k-esimo della fetta di T 
    //specificata da F e indf)
}

int main()
{
  int A[3][6][5], nelem;
  leggi(**A,90);
  bool stop=false;
  while(!stop)
    {
      char c;
      cin >> c;
      if(c =='S')
	    stop=true;
      else
    	{
	        int f,k;
	        cin>>f>>k;
            
	        cout << FETTE(A,3,c,f,k) << endl;
	    }
    }
}