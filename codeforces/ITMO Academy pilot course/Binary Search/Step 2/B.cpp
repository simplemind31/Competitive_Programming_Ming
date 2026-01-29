#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,con;
double l,r=1e7;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    int nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    while(con++<64){
        double mid=(l+r)/2;
        int can=0;
        for(int i=0;i<n && can<k;i++){
            can+=(int)(nums[i]/mid);
        }
        if(can>=k)l=mid;
        else r=mid;
    }
    cout << fixed << setprecision(12) << l;
}