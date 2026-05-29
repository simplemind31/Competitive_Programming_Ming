#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> matriz;
    // 7 1 2 3 4 5 6
    // 0 1 3 5 7 8 9
    // -1 20 1 3 4 5 6
    while(1<2){
        vector<int> nums(n);
        bool existenegativo=false;
        for(int i=0;i<n;i++){
            cin >> nums[i];
            if(nums[i]<0){
                existenegativo=true;
            }
        }
        if(existenegativo){
            break;
        }
        matriz.push_back(nums);
    }
    n=matriz.size();
    int m=matriz[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << matriz[i][j] << ' ';
        }
        cout << endl;
    }
}
/*
#.... 0
##... 1
###.. 2
####. 3
##### 4
01234

10000 0
01000 1
00100 2
00010 3
00001 4
01234


*/