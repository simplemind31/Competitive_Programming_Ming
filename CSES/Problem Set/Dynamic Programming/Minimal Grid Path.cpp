#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,nums[3000][3000],con=0;
bool mini[3000][3000];
char c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> c;
            nums[i][j]=c-'A';
        }
    }
    mini[0][0]=true;
    cout << char(nums[0][0]+'A');
    while(++con<2*n-1){
        int minim=25;
        for(int i=0,j=con;i<=con;i++,j--){
            if(i>=n || j>=n)continue;
            if(i-1>=0){
                if(mini[i-1][j]){
                    minim=min(minim,nums[i][j]);
                    continue;
                }
            }
            if(j-1>=0){
                if(mini[i][j-1]){
                    minim=min(minim,nums[i][j]);
                }
            }
        }
        for(int i=0,j=con;i<=con;i++,j--){
            if(i>=n || j>=n)continue;
            if(i-1>=0){
                if(mini[i-1][j] && minim==nums[i][j]){
                    mini[i][j]=true;
                    continue;
                }
            }
            if(j-1>=0){
                if(mini[i][j-1] && minim==nums[i][j]){
                    mini[i][j]=true;
                }
            }
        }
        cout << char(minim+'A');
    }
}