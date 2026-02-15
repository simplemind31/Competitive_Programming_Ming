#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int t,n,k,a;
bool cmp(pair<pair<int,int>,int> x, pair<pair<int,int>,int> y){
    if(x.first.second==y.first.second)return x.first.first<y.first.first;
    return x.first.second<y.first.second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        intset nums;
        vector<int> origi(n);
        pair<pair<int,int>,int> restric[k];
        for(int i=0;i<n;i++){
            cin >> origi[i];
            nums.insert(origi[i]);
        }
        nums.insert(-1e9-7);
        nums.insert(1e9+7);
        sort(ALL(origi));
        int canplant=0;
        for(int i=0;i<k;i++)cin >> restric[i].first.first >> restric[i].first.second >> restric[i].second;
        sort(restric,restric+k,cmp);
        for(int i=0;i<k;i++){
            //restric[i].first.first , restric[i].f.s
            int origiposprimer=lower_bound(ALL(origi),restric[i].first.first)-origi.begin();
            int origiposulti=upper_bound(ALL(origi),restric[i].first.second)-origi.begin()-1;
            int origicanti=origiposulti-origiposprimer+1;
            int prime=*nums.lower_bound(restric[i].first.first);
            int ulti=*(--nums.upper_bound(restric[i].first.second));
            int posulti=nums.order_of_key(ulti);
            int posprimer=nums.order_of_key(prime);
            int cantinow=posulti-posprimer+1;
            int plantado=origicanti-cantinow;
            while(plantado<restric[i].second){
                plantado++;
                // quitar el mayor;
                nums.erase(--nums.upper_bound(restric[i].first.second));
                canplant++;
            }
        }
        cout << n-canplant << '\n';
    }
}