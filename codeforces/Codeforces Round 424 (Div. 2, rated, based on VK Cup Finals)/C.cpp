#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k,n,a,conta,nums[2000];
map<ll,bool> con,cop;
set<ll> posi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> k >> n;
    for(int i=0;i<k;i++)cin >> nums[i];
    for(int i=1;i<k;i++)nums[i]+=nums[i-1];
    for(int i=0;i<n;i++){
        cin >> a;
        con[a]=true;
    }
    for(int i=0;i<k;i++){
        //si despues de esta calificacion i tengo a de score
        //entonces originalmente tenía a-psum[i]
        ll ori=a-nums[i];
        if(posi.find(ori)!=posi.end())continue;
        //checkear si cada elemento de con aparece en ori+psum[j]
        cop=con;
        for(int j=conta=0;j<k;j++){
            if(cop[ori+nums[j]]){
                cop[ori+nums[j]]=false;
                conta++;
            }
        }
        if(conta==n)posi.insert(ori);
    }
    cout << posi.size();
}