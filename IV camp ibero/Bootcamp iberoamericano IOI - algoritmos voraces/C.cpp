#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n;
int main()
{
    scanf("%d",&n);
    vector<pair<int,int>> time(n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&time[i].second,&time[i].first);
    }
    sort(ALL(time));
    int last=0,con=0;
    for(int i=0;i<n;i++){
        if(time[i].second>=last){
            con++;
            last=time[i].first;
        }
    }
    printf("%d",con);
}