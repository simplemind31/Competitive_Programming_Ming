#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int a[n],b[n];
        for(int i=0;i<n;i++)cin >> a[i];
        for(int i=0;i<n;i++)cin >> b[i];
        int l=1,r=2*n;
        while(l<r){
            int mid=(l+r+1)>>1;
            vector<int> con(n),nue;
            for(int i=0;i<n;i++)con[i]+=(a[i]<mid)+(b[i]<mid);
            for(int i=0;i<n;i++){
                int now=con[i];
                while(!nue.empty() && now+nue.back()>=3){
                    now=2;
                    nue.pop_back();
                }
                nue.push_back(now);
            }
            con=nue;
            nue.clear();
            for(int i=0;i<con.size();i++){
                int now=con[i];
                while(!nue.empty() && now+nue.back()){
                    now=now+nue.back()-1;
                    nue.pop_back();
                }
                nue.push_back(now);
            }
            bool xd=false;
            for(int i=0;i<nue.size();i++)xd=xd||(nue[i]);
            if(xd)r=mid-1;
            else l=mid;
        }
        cout << l << '\n';
    }
}