#include <bits/stdc++.h>
using namespace std;
int t,n,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int nums[n+1][31];
        for(int i=0;i<31;i++){
            nums[0][31]=0;
        }
        // mientras mas grande sea r-l+1, menos va a ser &
        for(int i=1;i<=n;i++){
            cin >> a;
            for(int j=0;j<31;j++){
                if(a&(1<<j)){
                    nums[i][j]=nums[i-1][j]+1;
                }else{
                    nums[i][j]=nums[i-1][j];
                }
            }
        }
        int con=0;
        for(int i=1;i<=n;i++){
            int l=1,r=i;
            //buscar el primer res>=dist
            while(l<r){
                int mid=(l+r)>>1;
                // del mid al i
                int dist=i-mid+1;
                int res=0;
                for(int j=0;j<31;j++){
                    if(nums[i][j]-nums[mid-1][j]==dist){
                        res|=(1<<j);
                    }
                    if(res>=dist)break;
                }
                if(res>=dist){
                    // se puede ampliamos la dist
                    r=mid;
                }else{
                    l=mid+1;
                }
            }
            //cout << l << '\n';
            while(l<=i){
                int res=0;
                for(int j=0;j<31;j++){
                    if(nums[i][j]-nums[l-1][j]==i-l+1){
                        res|=(1<<j);
                    }
                    if(res>i-l+1)break;
                }
                if(res==i-l+1)con++;
                else break;
                l++;
            }
        }
        cout << con << '\n';
    }
}