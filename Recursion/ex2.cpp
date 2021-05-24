#include<iostream>
using namespace std;

void leggi_ric(int *X, int dim){
    //PRE=X array di 50 elementi vuoto, dim>0
    if(dim>0){
        cin>>X[dim-1]; //Gli elementi sono salvati in ordine inverso rispetto all'inserimento
        leggi_ric(X, dim-1); //ricorsione
    }
}

int match_ric(int *Text, int TextLength, int *Pattern, int PatternLength){
    //PRE=0<=TextLenth<50, 0<=PatternLength<10
    int result = -1;
    if(TextLength==0)
        return result;
    else if (PatternLength==0)
        result = TextLength;
    else if(Text[TextLength-1]==Pattern[PatternLength-1]){
        result = match_ric(Text, TextLength-1, Pattern, PatternLength-1);
    }
    else{
        result = match_ric(Text,TextLength-1, Pattern, PatternLength);
    }
    return TextLength - result;
}

main()
{
  int T[50], P[10], LT, LP;
  cin >> LT >> LP;
  leggi_ric(T,LT);
  leggi_ric(P,LP);
  cout << " inizio match="<<match_ric(T,LT,P,LP)<<endl;  
}   