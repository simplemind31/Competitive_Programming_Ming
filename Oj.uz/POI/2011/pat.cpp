#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int c,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c;
    vector<int> stick[c];
    for(int i=0;i<c;i++){
        cin >> a;
        stick[i].resize(a);
        for(int j=0;j<a;j++)cin >> stick[i][j];
        sort(ALL(stick[i]));
    }
    for(int i=0;i<c;i++){
        for(int j=i+1;j<c;j++){
            if(i==j)continue;
            for(int k=0;k<c;k++){
                if(k==i || k==j)continue;
                // buscar siempre mayor, entre max(p1,p2),p1+p2-1
                int p1=0,p2=0,p3=0;
                while(p1<stick[i].size() && p2<stick[j].size()){
                    while(p3<stick[k].size() && stick[k][p3]<max(stick[i][p1],stick[j][p2]))p3++;
                    if(p3==stick[k].size())break;
                    if(stick[i][p1]+stick[j][p2]>stick[k][p3]){
                        cout << i+1 << ' ' << stick[i][p1] << ' ' << j+1 << ' ' << stick[j][p2] << ' ' << k+1 << ' ' << stick[k][p3];
                        return 0;
                    }
                    if(p1+1<stick[i].size() && p2+1<stick[j].size()){
                        if(stick[i][p1+1]<stick[j][p2+1])p1++;
                        else p2++;
                    }else if(p1+1<stick[i].size())p1++;
                    else p2++;
                }
            }
        }
    }
    cout << "NIE";
}