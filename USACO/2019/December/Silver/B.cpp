#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int n,l,sum,T;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("meetings.in","r",stdin);
    freopen("meetings.out","w",stdout);
    cin >> n >> l;
    pair<int,pair<int,int>> cows[n],cop[n];
    for(int i=0;i<n;i++)cin >> cows[i].second.first >> cows[i].first >> cows[i].second.second;
    sort(cows,cows+n);
    for(int i=0;i<n;i++)cop[i]=cows[i];
    int tiempo[n],restiempo[n];
    vector<int> iz,de;
    for(int i=0;i<n;i++){
        if(cop[i].second.second==1){
            tiempo[i]=l-cop[i].first;
            de.push_back(tiempo[i]);
        }else{
            tiempo[i]=cop[i].first;
            iz.push_back(tiempo[i]);
        }
    }
    for(int i=0;i<iz.size();i++)restiempo[i]=iz[i];
    for(int i=0;i<de.size();i++)restiempo[iz.size()+i]=de[i];
    for(int i=0;i<n;i++){
        cop[i].first=restiempo[i];
        sum+=cop[i].second.first;
    }
    sort(cop,cop+n);
    int nue=0;
    for(int i=0;i<n;i++){
        nue+=cop[i].second.first;
        if(2*nue>=sum){
            T=cop[i].first;
            break;
        }
    }
    //cout << T << ' ';
    queue<int> rig;
	int ans=0;
	for(int i=0;i<n;i++){
		if(cows[i].second.second==-1) {
			while (rig.size() && rig.front()+2*T<cows[i].first)rig.pop();
			ans+=rig.size();
		}else rig.push(cows[i].first);
	}
	cout << ans << "\n";
}