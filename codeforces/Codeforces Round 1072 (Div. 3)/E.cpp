#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<long long> vll;
typedef pair<ll,ll> pii;
typedef pair<long long,long long> pll;
ll t=1,n,a,b;
vector<ll> nums,head,tail;
ll resp;
ll findhead(ll a){
    if(head[a]==a)return a;
    return head[a]=findhead(head[a]);
}
ll findtail(ll a){
    if(tail[a]==a)return a;
    return tail[a]=findtail(tail[a]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        resp=0;
        cin >> n >> a;
        nums.resize(n-1);
        head=tail=nums;
        for(ll i=0;i<n-1;i++){
            head[i]=tail[i]=i;
        }
        vector<ll> pos[n];
        for(ll i=1;i<n;i++){
            cin >> b;
            pos[nums[i-1]=abs(a-b)].push_back(i-1);
            a=b;
        }
        vector<ll> res(n);
        map<pair<ll,ll>,bool> visited; 
        for(ll i=n-1;i>=0;i--){
            for(auto u:pos[i]){
                resp++;
                if(u>0 && nums[u-1]>=nums[u] && findhead(u-1)!=findhead(u)){
                    ll anteh=findhead(u-1);
                    ll antet=findtail(u-1);
                    ll longi=antet-anteh+1;
                    resp-=longi*(longi+1)/2;

                    anteh=findhead(u);
                    antet=findtail(u);
                    longi=antet-anteh+1;
                    resp-=longi*(longi+1)/2;

                    head[u]=findhead(u-1);
                    tail[u-1]=findtail(u);

                    anteh=findhead(u);
                    antet=findtail(u);
                    longi=antet-anteh+1;
                    resp+=longi*(longi+1)/2;
                }
                if(u+1<n-1 && nums[u+1]>nums[u] && findhead(u+1)!=findhead(u)){
                    ll anteh=findhead(u+1);
                    ll antet=findtail(u+1);
                    ll longi=antet-anteh+1;
                    resp-=longi*(longi+1)/2;

                    anteh=findhead(u);
                    antet=findtail(u);
                    longi=antet-anteh+1;
                    resp-=longi*(longi+1)/2;

                    head[u+1]=findhead(u);
                    tail[u]=findtail(u+1);

                    anteh=findhead(u);
                    antet=findtail(u);
                    longi=antet-anteh+1;
                    resp+=longi*(longi+1)/2;
                }
            }
            res[i]=resp;
        }
        for(ll i=1;i<n;i++){
            cout << res[i] << ' ';
        }
        cout << '\n';
    }
}