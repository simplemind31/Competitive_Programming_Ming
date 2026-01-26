#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend();
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int n,nums[101],iz,de;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> nums[i];
    }
    de=n;
    while(iz<n){
        if(!nums[iz+1])iz++;
        else break;
    }
    while(de>0){
        if(!nums[de])de--;
        else break;
    }
    if(de<=iz){
        cout << 0;
    }else{
        cout << n+1-(iz+1+n-de+1);
    }
}