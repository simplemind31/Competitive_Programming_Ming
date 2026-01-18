#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("balancing.in","r",stdin);
    freopen("balancing.out","w",stdout);
    cin >> n >> m;
    map<int,int> alt,anc;
    pair<int,int> points[n];
    for(int i=0;i<n;i++){
        cin >> points[i].first >> points[i].second;
        alt[points[i].first]++;
        anc[points[i].second]++;
    }
    int horisize=alt.size(),vertsize=anc.size();
    pair<int,int> hori[horisize],vert[vertsize];
    auto p=alt.begin();
    hori[0]={*p};
    for(int i=1;i<horisize;i++){
        p++;
        hori[i]={p->first,hori[i-1].second+p->second};
    }
    p=anc.begin();
    vert[0]={*p};
    for(int i=1;i<vertsize;i++){
        p++;
        vert[i]={p->first,vert[i-1].second+p->second};
    }
    vector<int> suma(vertsize);
    sort(points,points+n);
    //arriba y derecha
    int posho=0;
    int mini=1e9;
    for(int i=0;i<n;i++){
        int posve=lower_bound(vert,vert+vertsize,make_pair(points[i].second,0))-vert;
        for(int j=posve;j<vertsize;j++)suma[j]++;
        if(i && points[i].first!=points[i-1].first)posho++;
        // iterar sobre vert
        for(int j=0;j<vertsize;j++){
            int izab=suma[j];
            int izar=hori[posho].second-izab;
            int deab=vert[j].second-izab;
            int dear=n-izab-deab-izar;
            mini=min(mini,max(max(izab,deab),max(izar,dear)));
        }
    }
    cout << mini;
}