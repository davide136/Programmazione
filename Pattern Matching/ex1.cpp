#include<iostream>
using namespace std;

void leggi(int *S, int LS){
    for(int i=0;i<LS;i++)
        cin>>S[i];
}

int match(int*T, int LT, int*P, int LP){
    for(int i=0;i<LT-LP;i++){
        bool match_found = false;
        if(T[i]==P[0]){
            match_found = true;
            for(int k=1;k<LP;k++){                
                if(T[i+k]!=P[k]){
                    match_found = false;
                    k=LP;
                }                    
            }
        }
        if(match_found)
            return i;    
    }
    return -1;
}

int main()
{
  int T[50], P[10], LT, LP;
  cin >> LT >> LP;
  leggi(T,LT);
  leggi(P,LP);
  //PRE =(T ha LT elementi e P ne ha LP, LT e LP sono >0)
  cout << " inizio match="<<match(T,LT,P,LP)<<endl;  
  //POST=(se c’è un match di P in T, allora la funzione restituisce l’indice minimo di un tale match, altrimenti restituisce -1)
}   