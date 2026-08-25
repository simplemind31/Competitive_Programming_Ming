#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string smallestPalindrome(string s, int k) {
        // log para ver cuantos digitos tiene el numero 
        int n=s.size();
        long double loga=0;
        vector<int> con(26);
        for(int i=0;i<n/2;i++)con[s[i]-'a']++;
        n=n/2;
        for(int i=1;i<=n;i++)loga+=log10l(i);
        for(int i=0;i<26;i++)for(int j=1;j<=con[i];j++)loga-=log10l(j);
        string res="";
        // si cantidad total de permutaciones<k
        if(loga<7){
            int x=roundl(powl(10,loga));
            if(x<k)return "";
        }
        for(int i=n;i>0;i--){
            for(int j=0;j<26;j++){
                if(!con[j])continue;
                // que pasa si este pongo j
                long double nue=loga;
                nue-=log10l(i);
                nue+=log10l(con[j]);
                //10^nue=original
                // si nue es muy grande seguramente funciona
                if(nue>=7){
                    // entonces usamos j
                    res.push_back(char('a'+j));
                    con[j]--;
                    loga=nue;
                    break;
                }
                int x=roundl(powl(10,nue));
                if(x>=k){
                    res.push_back(char('a'+j));
                    con[j]--;
                    loga=nue;
                    break;
                }
                k-=x;
            }
            //fact[i]/fact de cada con
        }
        string fina=res;
        reverse(fina.begin(),fina.end());
        if(s.size()&1)res.push_back(s[s.size()/2]);
        res+=fina;
        return res;
    }
};