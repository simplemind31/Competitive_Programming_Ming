#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,puntocamb,suma,mini=1e18;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    pair<ll,ll> nums[n],aba[n],arr[n];
    for(int i=0;i<n;i++){
        cin >> nums[i].first;
        puntocamb=max(puntocamb,nums[i].first);
        aba[i]={nums[i].first,i};
    }
    for(int i=0;i<n;i++){
        cin >> nums[i].second;
        suma+=nums[i].second-nums[i].first;
        arr[i]={nums[i].second,i};
    }
    if(n==1){
        cout << nums[0].second;
        return 0;
    }
    for(int i=0;i<n;i++){
        suma+=puntocamb-nums[i].first;
        suma+=nums[i].second-puntocamb;
    }
    sort(aba,aba+n);
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        // inicio en i, tengo que bajar si o si de i y llegar todo menos i
        ll temp=nums[i].first+suma;
        // no bajar hasta i
        temp-=puntocamb-nums[i].first;
        if(arr[n-1].second==i){
            //no bajar de penultimo
            temp-=arr[n-2].first-puntocamb;
        }else{
            //no bajar del ultimo
            temp-=arr[n-1].first-puntocamb;
        }
        mini=min(mini,temp);
    }
    cout << mini;
}
//3:15