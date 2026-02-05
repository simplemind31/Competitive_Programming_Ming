#include <bits/stdc++.h>
using namespace std;
int n,a,con;
bitset<100000> usado;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("highcard.in","r",stdin);
    freopen("highcard.out","w",stdout);
    cin >> n;
    vector<int> Elsie,Basie;
    for(int i=0;i<n;i++){
        cin >> a;
        usado[--a]=true;
    }
    for(int i=0;i<2*n;i++){
        if(usado[i])Elsie.push_back(i);
        else Basie.push_back(i);
    }
    int i=0;
    for(int j=0;j<n;j++){
        if(Elsie[i]<Basie[j]){
            con++;
            i++;
        }
    }
    cout << con;
}