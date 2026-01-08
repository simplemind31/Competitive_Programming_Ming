#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int g,b,k,punt;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> b >> g >> k;
    intset clave;
    vector<int> orden;
    for(int i=0;i<g+b;i++){
        clave.insert(i);
    }
    while(clave.size()>0){
        punt+=k-1;
        punt%=clave.size();
        orden.push_back(*clave.find_by_order(punt));
        clave.erase(clave.find_by_order(punt));
    }
    string res(g+b,'B');
    for(int i=0;i<g;i++){
        res[orden[i]]='G';
    }
    cout << res;
}