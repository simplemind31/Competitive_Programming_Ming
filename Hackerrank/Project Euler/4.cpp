#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int t,n;
vector<int> pal;
string s,rever;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    for(int i=100;i<1000;i++){
        for(int j=999;j>99;j--){
            n=i*j;
            if(n<1e5)break;
            s="";
            while(n){
                s.push_back(n%10);
                n/=10;
            }
            rever=s;
            reverse(ALL(s));
            if(s==rever)pal.push_back(i*j);
        }
    }
    sort(ALL(pal));
    while(t--){
        cin >> n;
        cout << *(--lower_bound(ALL(pal),n)) << '\n';
    }
}