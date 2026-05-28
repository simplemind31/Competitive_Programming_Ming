#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
class Solution {
public:
    int n,q;
    vector<int> resp;
    void solve(vector<pair<string,int>>& wordsContainer, vector<pair<string,int>>& wordsQuery,int pos){
        if(wordsQuery.empty() || wordsContainer.empty())return;
        // checkear las posiciones pos
        vector<pair<string,int>> nexcontain[26],nexque[26];
        int minilen[26];
        memset(minilen,-1,sizeof(minilen));
        for(int i=0;i<wordsContainer.size();i++){
            if(wordsContainer[i].first.size()==pos)continue;
            int posi=wordsContainer[i].first[pos]-'a';
            nexcontain[posi].push_back(wordsContainer[i]);
            if(minilen[posi]==-1 || wordsContainer[i].first.size()<wordsContainer[minilen[posi]].first.size())minilen[posi]=i;
        }
        for(auto& u:wordsQuery){
            if(u.first.size()==pos)continue;
            int posi=u.first[pos]-'a';
            if(minilen[posi]==-1)continue;
            nexque[posi].push_back(u);
            resp[u.second]=wordsContainer[minilen[posi]].second;
        }
        for(int i=0;i<26;i++)solve(nexcontain[i],nexque[i],pos+1);
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery){
        n=wordsContainer.size();
        q=wordsQuery.size();
        resp.clear();
        resp.resize(q);
        vector<pair<string,int>> re(n),pregunta(q);
        int minilen=0;
        for(int i=0;i<n;i++){
            if(wordsContainer[i].size()<wordsContainer[minilen].size())minilen=i;
            re[i]={wordsContainer[i],i};
            reverse(ALL(re[i].first));
        }
        for(int i=0;i<q;i++){
            resp[i]=minilen;
            pregunta[i]={wordsQuery[i],i};
            reverse(ALL(pregunta[i].first));
        }
        solve(re,pregunta,0);
        return resp;
    }
};