#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
bool xd=1;
int n,con;
vector<bool> bits;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    /*
    0123456789ABCD
    -> DBCA9876543210
    -> 23456789ABCD10 en 2
    -> 456789ABCD3210 en 2 tb
    // check block number need flip number no
    cant reduce if 0,1=G
    01101101100
    GG o HH skip
    GGGHGHHGHHHGHG -> GHGHHGHGHG
    GH=0,HG=1
    -> 00111
    select r and flip 0,...,r
    100011101011011
    */
    cin >> n >> st;
    for(int i=0;i+1<n;i+=2){
        if(st[i]=='H' && st[i+1]=='G')bits.push_back(1);
        else if(st[i]=='G' && st[i+1]=='H')bits.push_back(0);
    }
    n=bits.size();
    for(int i=n-1;i>=0;i--){
        if(xd!=bits[i]){
            con++;
            xd=!xd;
        }
    }
    cout << con;
}