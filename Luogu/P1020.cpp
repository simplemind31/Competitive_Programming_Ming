#include <bits/stdc++.h>
using namespace std;
int n,nume[100001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> nume[n++]);
    n--;
    multiset<int> lis,lds;
    for(int i=0;i<n;i++){
        auto p=lis.lower_bound(nume[i]);
        if(p!=lis.end()){
            lis.erase(p);
        }
        lis.insert(nume[i]);
    }
    for(int i=n-1;i>=0;i--){
        auto p=lds.upper_bound(nume[i]);
        if(p!=lds.end()){
            lds.erase(p);
        }
        lds.insert(nume[i]);
    }
    cout << lds.size() << '\n' << lis.size();
}