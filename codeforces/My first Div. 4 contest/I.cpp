#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int t=1,n,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<int> nums(n);
        for(int i=0;i<n;i++)cin >> nums[i];
        vector<int> posicion[11];
        for(int i=0;i<n;i++){
            for(int j=10;j>0;j--){
                if(nums[i]%j==0)posicion[j].push_back(i);
            }
        }
        bool xd=false;
        for(int i=10;i>0 && !xd;i--){
            for(auto u:posicion[i]){
                for(int j=i;j>0 && !xd;j--){
                    for(auto v:posicion[j]){
                        if(u==v)continue;
                        if((ll)nums[u]*nums[v]%m==0){
                            xd=true;
                            cout << nums[min(u,v)] << ' ' << nums[max(u,v)] << '\n';
                            break;
                        }
                    }
                }
                if(xd)break;
            }
        }
        if(!xd)cout << "-1\n";
    }
}