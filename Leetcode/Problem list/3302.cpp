#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> validSequence(string word1, string word2){
        int n=word1.size(),m=word2.size(),last=n-1;
        vector<int> corres(n+1,m),res;
        for(int i=m-1;i>=0;i--){
            while(last>=0 && word1[last]!=word2[i]){
                corres[last]=corres[last+1];
                last--;
            }
            if(last<0)break;
            corres[last--]=i;
        }
        while(last>=0){
            corres[last]=corres[last+1];
            last--;
        }
        last=0;
        for(int i=0;i<m && last<n;i++){
            // puedo usar poder?
            if(word1[last]==word2[i]){
                res.push_back(last++);
                if(i==m-1)return res;
            }else if(corres[last+1]<=i+1){
                // si puedo usar poder
                res.push_back(last++);
                for(int j=i+1;j<m;j++){
                    while(word1[last]!=word2[j])last++;
                    res.push_back(last++);
                }
                return res;
            }else{
                while(last<n && word1[last]!=word2[i])last++;
                res.push_back(last++);
            }
        }
        return {};
    }
};