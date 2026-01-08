#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m,n,q,p,a,b;
char c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> q;
    vector<vector<int>> nums(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> nums[i][j];
            if(i>0){
                nums[i][j]|=nums[i-1][j];
            }
        }
    }
    while(q--){
        cin >> p;
        int iz=0,de=n-1;
        while(p--){
            cin >> a >> c >> b;
            if(iz>de)continue;
            if(c=='>'){
                int l=0,r=n;
                while(l<r){
                    int mid=(l+r)>>1;
                    if(nums[mid][a-1]>b){
                        r=mid;
                    }else{
                        l=mid+1;
                    }
                }
                // unir iz,de con l,n-1
                int nueiz=max(iz,l);
                int nuede=min(de,n-1);
                iz=nueiz;
                de=nuede;
            }else{
                int l=-1,r=n-1;
                while(l<r){
                    int mid=(l+r+1)>>1;
                    if(nums[mid][a-1]<b){
                        l=mid;
                    }else{
                        r=mid-1;
                    }
                }
                // unir iz,de con 0,l
                int nueiz=max(iz,0);
                int nuede=min(de,l);
                iz=nueiz;
                de=nuede;
            }
        }
        if(iz>de){
            cout << "-1\n";
        }else{
            cout << iz+1 << '\n';
        }
    }
}