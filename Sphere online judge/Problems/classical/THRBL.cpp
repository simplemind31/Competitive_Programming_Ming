#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int q,n,a,b,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    int nums[n];
    int may[n][20];
    for(int i=0;i<n;i++){
        cin >> nums[i];
        may[i][0]=nums[i];
    }
    for(int j=1;j<20;j++){
        for(int i=0;i<n;i++){
            may[i][j]=may[i][j-1];
            if(i+(1<<(j-1))<n && may[i+(1<<(j-1))][j-1]>may[i][j]){
                may[i][j]=may[i+(1<<(j-1))][j-1];
            }
        }
    }
    while(q--){
        cin >> a >> b;
        a--;b--;
        int val=nums[a];
        if(a>b)swap(a,b);
        int maxi=0;
        for(int i=19;i>=0;i--){
            if(a+(1<<i)<=b){
                maxi=max(maxi,may[a][i]);
                a=a+(1<<i);
            }
        }
        if(maxi<=val){
            con++;
        }
    }
    cout << con;
}
