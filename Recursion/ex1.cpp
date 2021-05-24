#include<iostream>

using namespace std;

void leggi_ric(bool *X, int dim){
    if(dim>0){        
        cin >> X[64-dim];
        leggi_ric(X, dim-1);
    }
}

void print_path_ric(int *X, int r){
    if(r>0){
        cout<<'('<<8-r<<','<<X[8-r]<<')'<<' ';
        print_path_ric(X, r-1);
    }
    
}

bool checkBefore(bool (*Palude)[8], int r){
    //PRE=0<r<=8
    bool result = false;

    for(int i=0; i<8; i++){
        if(Palude[r-1][i]){
            if(i==0){
                if(!Palude[r-2][0] && !Palude[r-2][1]){
                    Palude[r-1][0]=false;
                    result = true;
                }                
            }
            else if(i==7){
                if(!Palude[r-2][6] && !Palude[r-2][7]){
                    Palude[r-1][7]=false;
                    result = true;
                }
                return result; //true sse trovo elementi da eliminare -> riparto da r=8
            }
            else{
                if(!Palude[r-2][i-1] && !Palude[r-2][i] && !Palude[r-2][i+1]){
                    Palude[r-1][i]=false;
                    result = true;
                }
            }
        }
    }
    return false;
}

bool checkAfter(bool (*Palude)[8], int r){
    //PRE=0<=r<=7
    bool result = false;

    for(int i=0; i<8; i++){
        if(Palude[r-1][i]){
            if(i==0){
                if(!Palude[r][0] && !Palude[r][1]){
                    Palude[r-1][0]=false;
                    result = true;
                }                
            }
            else if(i==7){
                if(!Palude[r][6] && !Palude[r][7]){
                    Palude[r-1][7]=false;
                    result = true;
                }
                return result; //true sse trovo elementi da eliminare -> riparto da r=8
            }
            else{
                if(!Palude[r][i-1] && !Palude[r][i] && !Palude[r][i+1]){
                    Palude[r-1][i]=false;
                    result = true;
                }
            }
        }
    }
    return false;
}

bool no_path(bool (*Palude)[8], int r){
    //PRE=Palude bool rx8 completo, r=8

    
            if(r==2)
                int a=r;
    bool last_raw_ok = false;
    if(r>0)
        for(int i=0;i<8;i++){
            if(Palude[r-1][i] || last_raw_ok){
                last_raw_ok = true;
                i=8;
            }
        }
    else
        return true;

    if(last_raw_ok){ //R=true sse almeno un elemento nella riga è 1, 0<r<=8
        if(r==8){
            if(checkBefore(Palude, r))//Verifico riga prec ed elimino path sbagliate
                return no_path(Palude, 8); //riparto dall'inizio 
            else
                return no_path(Palude, r-1); //vado avanti con la ricorsione
        }
        else if(r==1){
            if(checkAfter(Palude, r))//Verifico riga prec ed elimino path sbagliate
                return no_path(Palude, 8); //riparto dall'inizio 
            else
                return no_path(Palude, r-1); //vado avanti con la ricorsione
        }
        else if(1<r<8){
            bool before, after;
            before=checkBefore(Palude, r);
            after = checkAfter(Palude, r);
            if(before||after)//Verifico riga prec ed elimino path sbagliate
                return no_path(Palude, 8); //riparto dall'inizio 
            else
                return no_path(Palude, r-1); //vado avanti con la ricorsione
        }
        return true;       // sse eseguo ogni ricorsione senza trovare righe di false
    }
    else
        return false; //sse una riga piena di false  
}

void make_path(bool (*Palude)[8], int r, int *Path ){
    if(r>0)
        for(int i=0;i<8;i++){
            if(Palude[r-1][i]){
                Path[r-1]=i;
                make_path(Palude, r-1, Path);
            }
        }
}

int main() {
    bool Palude[8][8];
    leggi_ric(*Palude, 64); //da fare

    bool stop = false;
    int Path[8] = {};

    stop = no_path(Palude, 8);
    //definisce stop sse  in Path c'è il cammino più a sinistra 
    make_path(Palude, 8, Path);

    if (stop)
        print_path_ric(Path, 8);
    else
        cout << "nessun cammino" << endl;
}