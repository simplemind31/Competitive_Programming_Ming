#include <bits/stdc++.h>
using namespace std;
int n,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int nums[n][4]={0};
    for(int i=0;i<n;i++){
        nums[i][3]=0;
        for(int j=0;j<3;j++){
            cin >> nums[i][j];
            nums[i][3]+=nums[i][j];
        }
        for(int j=0;j<i;j++){
            bool xd=abs(nums[i][3]-nums[j][3])<=10;
            for(int k=0;k<3 && xd;k++){
                if(abs(nums[i][k]-nums[j][k])>5)xd=false;
            }
            con+=xd;
        }
    }
    cout << con;
}