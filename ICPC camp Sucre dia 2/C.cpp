#include <bits/stdc++.h>
using namespace std;
int n,a,res;
vector<int> con(5);
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> a;
        con[a%5]++;
    }
    res+=con[0];
    con[0]=0;
    int mini=min(con[1],con[4]);
    con[1]-=mini;
    con[4]-=mini;
    res+=mini;
    mini=min(con[2],con[3]);
    con[2]-=mini;
    con[3]-=mini;
    res+=mini;
    vector<int> cop=con;
    if(con[1]&&con[2]){
        // 1,2
        vector<pair<int,int>> posi={{3,1},{1,2}};
        int p1=0,p2=0;
        while(con[1]>=3 && con[2]>=1){
            con[1]-=3;
            con[2]-=1;
            p1++;
        }
        while(con[1]>=1 && con[2]>=2){
            con[1]-=1;
            con[2]-=2;
            p1++;
        }
        p1+=con[1]/5+con[2]/5;
        while(cop[1]>=1 && cop[2]>=2){
            cop[1]-=1;
            cop[2]-=2;
            p2++;
        }
        while(cop[1]>=3 && cop[2]>=1){
            cop[1]-=3;
            cop[2]-=1;
            p2++;
        }
        p2+=cop[1]/5+cop[2]/5;
        res+=max(p1,p2);
    }else if(con[1]&&con[3]){
        //1,3
        vector<pair<int,int>> posi={{2,1},{1,3}};
        int p1=0,p2=0;
        while(con[1]>=2 && con[3]>=1){
            con[1]-=2;
            con[3]-=1;
            p1++;
        }
        while(con[1]>=1 && con[3]>=3){
            con[1]-=1;
            con[3]-=3;
            p1++;
        }
        p1+=con[1]/5+con[3]/5;
        while(cop[1]>=1 && cop[3]>=3){
            cop[1]-=1;
            cop[3]-=3;
            p2++;
        }
        while(cop[1]>=2 && cop[3]>=1){
            cop[1]-=2;
            cop[3]-=1;
            p2++;
        }
        p2+=cop[1]/5+cop[3]/5;
        res+=max(p1,p2);
    }else if(con[2]&&con[4]){
        //4,2
        vector<pair<int,int>> posi={{2,1},{1,3}};
        int p1=0,p2=0;
        while(con[4]>=2 && con[2]>=1){
            con[4]-=2;
            con[2]-=1;
            p1++;
        }
        while(con[4]>=1 && con[2]>=3){
            con[4]-=1;
            con[2]-=3;
            p1++;
        }
        p1+=con[4]/5+con[2]/5;
        while(cop[4]>=1 && cop[2]>=3){
            cop[4]-=1;
            cop[2]-=3;
            p2++;
        }
        while(cop[4]>=2 && cop[2]>=1){
            cop[4]-=2;
            cop[2]-=1;
            p2++;
        }
        p2+=cop[4]/5+cop[2]/5;
        res+=max(p1,p2);
    }else if(con[4]&&con[3]){
        //4,3
        vector<pair<int,int>> posi={{3,1},{1,2}};
        int p1=0,p2=0;
        while(con[4]>=3 && con[3]>=1){
            con[4]-=3;
            con[3]-=1;
            p1++;
        }
        while(con[4]>=1 && con[3]>=2){
            con[4]-=1;
            con[3]-=2;
            p1++;
        }
        p1+=con[4]/5+con[3]/5;
        while(cop[4]>=1 && cop[3]>=2){
            cop[4]-=1;
            cop[3]-=2;
            p2++;
        }
        while(cop[4]>=3 && cop[3]>=1){
            cop[4]-=3;
            cop[3]-=1;
            p2++;
        }
        p2+=cop[4]/5+cop[3]/5;
        res+=max(p1,p2);
    }else{
        for(int i=1;i<=4;i++)res+=con[i]/5;
    }
    cout << res;
}