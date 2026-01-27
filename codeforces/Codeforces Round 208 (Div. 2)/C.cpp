#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,a,t;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    vector<vector<int>> nums;
    nums.push_back({});
    for(int i=0;i<n;i++){
        cin >> a;
        if(a==0)nums.push_back({});
        else nums.back().push_back(a);
    }
    t=nums.size();
    // el ultimo es vacio
    for(int i=0;i<t-1;i++){
        if(nums[i].size()==0)cout << 0 << '\n';
        else if(nums[i].size()==1)cout << "pushStack\n1 popStack\n";
        else if(nums[i].size()==2)cout << "pushStack\npushQueue\n2 popStack popQueue\n";
        else if(nums[i].size()==3)cout << "pushStack\npushQueue\npushFront\n3 popStack popQueue popFront\n";
        else{
            n=nums[i].size();
            string res[n];
            bool que=false,sta=false;
            int m1=0,m2=0,m3=0;
            for(int j=0;j<n;j++)if(nums[i][j]>nums[i][m1])m1=j;
            for(int j=0;j<n;j++)if((nums[i][j]>nums[i][m2]&&j!=m1)||m1==m2)m2=j;
            for(int j=0;j<n;j++)if((nums[i][j]>nums[i][m3]&&j!=m1&&j!=m2)||m1==m3||m2==m3)m3=j;
            for(int j=0;j<n;j++){
                if(!que){
                    if(j==m1 || j==m2 || j==m3){
                        que=true;
                        cout << "pushQueue\n";
                    }else{
                        cout << "pushStack\n";
                    }
                }else{
                    if(j==m1 || j==m2 || j==m3){
                        if(!sta){
                            cout << "pushStack\n";
                            sta=true;
                        }else{
                            cout << "pushFront\n";
                        }
                    }else{
                        cout << "pushQueue\n";
                    }
                }
            }
            cout << "3 popStack popQueue popFront\n";
        }
    }
    for(auto u:nums.back())cout << "pushQueue\n";
}