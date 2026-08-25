#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int con[10],cop[10];
    pair<string,int> construir(int x[10],int need,bool val){
        int a[10];
        for(int i=0;i<10;i++)a[i]=max(x[i],0);
        string res="";
        a[1]=need;
        a[8]=a[2]/3;
        a[2]%=3;
        a[9]=a[3]/2;
        a[3]%=2;
        a[6]=min(a[2],a[3]);
        a[2]-=a[6];
        a[3]-=a[6];
        a[4]=a[2]/2;
        a[2]%=2;
        for(int i=2;i<10;i++)a[1]-=a[i];
        if(val)return {"",need-a[1]};
        for(int i=1;i<10;i++)for(int j=0;j<a[i];j++)res.push_back(char(i)+'0');
        return {res,0};
    }
    string smallestNumber(string num,long long t){
        // res=multiple de t no necesariamente exactamente t
        bool xd=true;
        int n=num.size();
        memset(con,0,sizeof(con));
        memset(cop,0,sizeof(cop));
        for(int i=2;i<10;i++){
            while(t%i==0){
                t/=i;
                con[i]++;
                cop[i]++;
            }
        }
        if(t>1)return "-1";
        int mini=construir(con,0,1).second;
        string res="";
        if(mini>n)return construir(con,mini,0).first;
        int last=-1,corr=-1;
        for(int i=0;i<n && xd;i++){
            for(int j=num[i]-'0'+1;j<10 && last!=i;j++){
                int temp=j;
                for(int k=2;k<10 && temp>1;k++){
                    while(temp%k==0){
                        con[k]--;
                        temp/=k;
                    }
                }
                if(construir(con,0,1).second<=n-i-1)last=i,corr=j;
                temp=j;
                for(int k=2;k<10 && temp>1;k++){
                    while(temp%k==0){
                        con[k]++;
                        temp/=k;
                    }
                }
            }
            if(num[i]=='0')xd=false;
            int temp=num[i]-'0';
            for(int k=2;k<10 && temp>1;k++){
                while(temp%k==0){
                    con[k]--;
                    temp/=k;
                }
            }
        }
        for(int i=0;i<10 && xd;i++)if(con[i]>0)xd=false;
        if(xd)return num;
        // aumentamos un digito más
        // todo igual hasta last
        for(int i=0;i<10;i++)con[i]=cop[i];
        if(last==-1)return construir(con,n+1,0).first;
        for(int i=0;i<last;i++){
            res.push_back(num[i]);
            int temp=num[i]-'0';
            for(int k=2;k<10 && temp>1;k++){
                while(temp%k==0){
                    con[k]--;
                    temp/=k;
                }
            }
        }
        // el last es corr
        res.push_back(char(corr)+'0');
        int temp=corr;
        for(int k=2;k<10 && temp>1;k++){
            while(temp%k==0){
                con[k]--;
                temp/=k;
            }
        }
        // el resto como quiera
        res.append(construir(con,n-last-1,0).first);
        return res;
    }
};