#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,m,a,suma1,suma2;
string mode;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<int> ata,def,b(m);
    for(int i=0;i<n;i++){
        cin >> mode >> a;
        if(mode=="ATK"){
            ata.push_back(a);
        }else{
            def.push_back(a);
        }
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    sort(ALL(ata));
    sort(ALL(def));
    sort(ALL(b));
    int con=0;
    for(int i=m-1;i>=0 && con<ata.size();i--){
        if(b[i]>ata[con]){
            suma1+=b[i]-ata[con++];
        }else{
            break;
        }
    }
    //now def
    con=0;
    vector<int> nue;
    for(int i=0;i<m;i++){
        if(con==def.size()){
            nue.push_back(b[i]);
        }else if(b[i]>def[con]){
            con++;
        }else{
            nue.push_back(b[i]);
        }
    }
    if(con!=def.size()){
        cout << suma1;
        return 0;
    }
    con=0;
    m=nue.size();
    b=nue;
    for(int i=0;i<m;i++){
        if(con==ata.size()){
            suma2+=b[i];
        }else if(b[i]>=ata[con]){
            suma2+=b[i]-ata[con];
            con++;
        }else{
            suma2+=b[i];
        }
    }
    if(con==ata.size()){
        cout << max(suma1,suma2);
    }else{
        cout << suma1;
    }
}