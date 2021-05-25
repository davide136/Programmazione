#include<iostream>
using namespace std;

struct stringa{
    int lung; char S[20]; 
    stringa(int a =0, char* b=0){
        lung=a; 
        for(int i=0; i<lung; i++) S[i]=b[i];
    } 
    bool operator <= ( const stringa &s){
        int min=s.lung;
        if(lung<s.lung)
            min = lung;
        for(int i=0;i<min;i++)
            if(S[i]>s.S[i])
                return false;
        return true;
    }
};

ostream & operator << ( ostream  &output, const stringa s ){
    output << "La stringa e':" << endl;
    for(int i=0;i<s.lung;i++)
        output << s.S[i];
    output << endl;
    return output;
}
istream & operator >> (istream  &input, stringa &s){
    input >> s.lung;
    for(int i=0;i<s.lung;i++)
        input >> s.S[i];
    return input;
}

main()
{
  stringa X, Y, Z, W;
  cin >> X >> Y >> Z >> W;
  if(X <= Y)
    cout << X;
  else
    cout<< Y;
 if(Y <= X)
    cout << Y;
  else
    cout<< X;
  if(X <= Z)
    cout<< X;
  else
    cout << Z;
  if(X <= W)
    cout << X;
  else
    cout<< W;
  if(!(Z<=W))
    cout<< Z;
  else
    cout<<W;
}