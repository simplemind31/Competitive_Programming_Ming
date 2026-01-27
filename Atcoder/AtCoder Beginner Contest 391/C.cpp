#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int n,q,con,nest[1000000],pig[1000000],a,b;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q;
    for(int i=0;i<n;i++){
        nest[i]=1;
        pig[i]=i;
    }
    while(q--){
        cin >> a;
        if(a==2)cout << con << '\n';
        else{
            cin >> a >> b;
            a--;b--;
            if(--nest[pig[a]]==1)con--;
            pig[a]=b;
            if(++nest[pig[a]]==2)con++;
        }
    }
}