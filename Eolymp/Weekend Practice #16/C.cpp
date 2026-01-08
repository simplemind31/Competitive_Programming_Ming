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
int t=1,n,con,now,res,tt;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> nums(n),visit(n);
        for(int i=0;i<n;i++){
            cin >> nums[i];
            nums[i]--;
        }
        for(int i=res=tt=0;(con=2)&&i<n;i++){
            if(visit[i])continue;
            tt++;
            visit[i]=visit[now=nums[i]]=true;
            while(now!=i){
                visit[now=nums[now]]=true;
                con++;
            }
            res+=(con-1)/2;
        }
        if((n-tt)%2)cout << "-1\n";
        else cout << res << '\n';
    }
}