#include<iostream>
using std::ostream;
using std::cout;
using std::cin;
using std::string;

enum colore{rosso, giallo, blu};

struct forma{
    int vertici, archi; colore col; 
    forma(int a, int b, colore c){vertici=a;archi=b;col=c;}
};

//tipo ritorno - nome funzione ( tipi necessari a funzione ) { implementazione } 
    ostream&      operator<<       (ostream& o,const forma& x)    {
        string nome = "non regolare";
        switch(x.vertici){
            case 4:
            if(x.archi==4) nome="quadrato";
            break;
            case 3:
            if(x.archi==3) nome="triangolo";
            break;
            case 2:
            if(x.archi==1) nome="tratto";
            break;
            case 1:
            if(x.archi==0) nome="punto";
            break;
            default: return o<<"Non implementato\n";
        }
        string col = "";
        if(nome!="non regolare"){
            switch (x.col)
            {
            case rosso:
                col="rosso";
                break;
            case giallo:
                col="giallo";
                break;
            case blu:
                col="blu";
                break;
            default: return o<<"Non implementato\n";
            }
        }
        return o<<"Forma: "<<nome<<" "<<col<<".\n";
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    colore d;
    switch (c)
    {
    case 0:
        d=rosso;
        break;
    case 1:
        d=giallo;
        break;
    case 2:
        d=blu;
        break;
    
    default:
        break;
    }
    forma f = forma(a,b,d);
    cout << f;
}
