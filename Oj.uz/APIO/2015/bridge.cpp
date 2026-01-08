#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree<pair<ll,pair<ll,ll>>,null_type,less<pair<ll,pair<ll,ll>>>,rb_tree_tag,tree_order_statistics_node_update> llset;
char t1,t2;
ll k,n,a,b;
ll lad,res,sumade,sumaiz;
bool cmp(pair<ll,ll> a,pair<ll,ll> b){return a.first+a.second<b.first+b.second;};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> k >> n;
    vector<pair<ll,ll>> nums;
    vector<ll> dif;
    for(ll i=0;i<n;i++){
        cin >> t1 >> a >> t2 >> b;
        if(t1==t2)lad+=abs(a-b);
        else{
            dif.push_back(a);
            dif.push_back(b);
            nums.push_back({min(a,b),max(a,b)});
        }
    }
    n=nums.size();
    sort(ALL(dif));
    for(ll i=0;i<dif.size();i++){
        res+=abs(dif[i]-dif[dif.size()/2]);
    }
    res+=n;
    if(k==1){
        cout << lad+res;
        return 0;
    }
    sort(ALL(nums),cmp);
    llset de;
    vector<ll> sumaaaa(n);
    for(ll i=0;i<n;i++){
        if(de.empty()){
            de.insert({nums[i].first,{i,0}});
        }else{
            ll valmedante=de.find_by_order(de.size()/2)->first;
            sumade+=abs(valmedante-nums[i].first);
            de.insert({nums[i].first,{i,0}});
            if(nums[i].first<=valmedante){
                ll valmednow=de.find_by_order(de.size()/2)->first;
                sumade-=(valmedante-valmednow);
            }
        }
        ll valmedante=de.find_by_order(de.size()/2)->first;
        sumade+=abs(valmedante-nums[i].second);
        de.insert({nums[i].second,{i,1}});
        sumaaaa[i]=sumade;
    }
    for(ll i=0;i<n-1;i++){
        //de 0 a i pref, de i+1 a n-1 suf
        //quitar nums[i] del de
        ll valmedante=de.find_by_order(de.size()/2)->first;
        sumade-=abs(valmedante-nums[i].first);
        de.erase(make_pair(nums[i].first,make_pair(i,0)));
        if(nums[i].first>=valmedante){
            ll valmednow=de.find_by_order(de.size()/2)->first;
            sumade-=valmedante-valmednow;
        }
        valmedante=de.find_by_order(de.size()/2)->first;
        sumade-=abs(valmedante-nums[i].second);
        de.erase(make_pair(nums[i].second,make_pair(i,1)));
        res=min(res,sumade+sumaaaa[i]+n);
    }
    cout << lad+res;
}