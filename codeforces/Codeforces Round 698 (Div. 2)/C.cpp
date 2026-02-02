#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll t,n,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        map<ll,ll> con;
        for(ll i=0;i<2*n;i++){
            cin >> a;
            con[a]++;
        }
        if(con.size()!=n){
            cout << "NO\n";
            continue;
        }
        bool xd=true;
        for(auto u:con){
            if(u.second!=2){
                xd=false;
                break;
            }
        }
        if(!xd){
            cout << "NO\n";
            continue;
        }
        vector<ll> nums;
        for(auto u:con){
            nums.push_back(u.first);
        }
        vector<ll> deb;
        ll suma=0;
        for(int i=n-1;i>=0 && xd;i--){
            if((nums[i]-suma)%(i+1)!=0 || ((nums[i]-suma)/(i+1))%2!=0){
                xd=false;
            }else{
                deb.push_back((nums[i]-suma)/(i+1)/2);
                suma+=2*deb.back();
            }
        }
        if(!xd){
            cout << "NO\n";
            continue;
        }
        set<ll> fina=set(deb.begin(),deb.end());
        if(fina.size()!=n || *fina.begin()<=0){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
    }
}