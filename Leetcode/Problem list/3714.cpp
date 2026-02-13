#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    int longestBalanced(string s){
        map<ll,int> con;
        con[0]=0;
        int a=0,b=0,c=0,res=0;
        for(int i=0,n=s.size();i<n;i++){
            if(s[i]=='a')a++;
            else if(s[i]=='b')b++;
            else c++;
            // usar a,b,c
            int nuea=a,nueb=b,nuec=c;
            int temp=min({nuea,nueb,nuec});
            nuea-=temp;
            nueb-=temp;
            nuec-=temp;
            if(!con.count(nuea*1e12+nueb*1e6+nuec))con[nuea*1e12+nueb*1e6+nuec]=i+1;
            res=max(res,i+1-con[nuea*1e12+nueb*1e6+nuec]);
        }
        a=b=c=0;
        con.clear();
        con[0]=0;
        for(int i=0,n=s.size();i<n;i++){
            // usar a y b
            if(s[i]=='a'){a++;}
            else if(s[i]=='b'){b++;}
            else{
                a=b=c=0;
                con.clear();
                con[0]=i+1;
                continue;
            }
            // usar a,b,c
            int nuea=a,nueb=b;
            int temp=min(nuea,nueb);
            nuea-=temp;
            nueb-=temp;
            if(!con.count(nuea*1e6+nueb))con[nuea*1e6+nueb]=i+1;
            res=max(res,i+1-con[nuea*1e6+nueb]);
        }
        a=b=c=0;
        con.clear();
        con[0]=0;
        for(int i=0,n=s.size();i<n;i++){
            // usar a y c
            if(s[i]=='a'){a++;}
            else if(s[i]=='b'){
                a=b=c=0;
                con.clear();
                con[0]=i+1;
                continue;
            }
            else{c++;}
            // usar a,b,c
            int nuea=a,nueb=c;
            int temp=min(nuea,nueb);
            nuea-=temp;
            nueb-=temp;
            if(!con.count(nuea*1e6+nueb))con[nuea*1e6+nueb]=i+1;
            res=max(res,i+1-con[nuea*1e6+nueb]);
        }
        a=b=c=0;
        con.clear();
        con[0]=0;
        for(int i=0,n=s.size();i<n;i++){
            // usar b y c
            if(s[i]=='a'){
                a=b=c=0;
                con.clear();
                con[0]=i+1;
                continue;
            }
            else if(s[i]=='b'){b++;}
            else{c++;}
            // usar a,b,c
            int nuea=b,nueb=c;
            int temp=min(nuea,nueb);
            nuea-=temp;
            nueb-=temp;
            if(!con.count(nuea*1e6+nueb))con[nuea*1e6+nueb]=i+1;
            res=max(res,i+1-con[nuea*1e6+nueb]);
        }
        int conta=1;
        for(int i=1,n=s.size();i<n;i++){
            if(s[i]==s[i-1])conta++;
            else{
                res=max(res,conta);
                conta=1;
            }
        }
        res=max(res,conta);
        return res;
    }
};