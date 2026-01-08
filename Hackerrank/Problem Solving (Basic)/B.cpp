#include <bits/stdc++.h>
using namespace std;
string decryptPassword(string s){
    int n=s.size(),last=-1;
    string ori="";
    vector<int> nums;
    for(int i=0;i<n;i++){
        if(s[i]>='1' && s[i]<='9'){
            nums.push_back(s[i]-48);
            last=nums.size()-1;
        }else{
            if(s[i]=='0'){
                ori.push_back(nums[last--]+48);
            }else{
                if(i<=n-3){
                    if(s[i]>='A' && s[i]<='Z' && s[i+1]>='a' && s[i+1]<='z' && s[i+2]=='*'){
                        ori.push_back(s[i+1]);
                        ori.push_back(s[i]);
                        i+=2;
                    }else{
                        ori.push_back(s[i]);
                    }
                }else{
                    ori.push_back(s[i]);
                }
            }
        }
    }
    return ori;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    string s;
    getline(cin, s);
    string result = decryptPassword(s);
    fout << result << "\n";
    fout.close();
    return 0;
}
