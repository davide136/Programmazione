#include<iostream>
using namespace std;

void leggi_ric(int *X, int dim){
    //PRE=X array di 50 elementi vuoto, dim>0
    if(dim>0){
        cin>>X[0]; //Gli elementi sono salvati in ordine inverso rispetto all'inserimento
        leggi_ric(X+1, dim-1); //ricorsione
    }
}

int match_ric(int *Text, int TextLength, int *Pattern, int PatternLength){
    //PRE=0<=TextLenth<50, 0<=PatternLength<10
    //caso base 0: text_length==0 ma PatternLength > 0   -> fallimento ritorno -1
    //caso base 1: text_length>0 ma PatternLength == 0   ->  successo  ritorno TextLength
    //caso base 2: text[n]==pattern[0] -> text[n+1]==pattern[1] (incremento gli zeri e diminuisco lunghezze)

    if(TextLength==0 && PatternLength>0)
        return -1;
    else if(TextLength>0 && PatternLength==0)
        return TextLength;
    else if(Text[0]==Pattern[0])
        return match_ric(Text+1,TextLength-1,Pattern+1,PatternLength-1);
    else 
        return match_ric(Text+1,TextLength-1,Pattern,PatternLength);
}

int main()
{
  int T[50], P[10], LT, LP;
  cin >> LT >> LP;
  leggi_ric(T,LT);
  leggi_ric(P,LP);
  cout << " inizio match="<<match_ric(T,LT,P,LP)<<endl;  
}   