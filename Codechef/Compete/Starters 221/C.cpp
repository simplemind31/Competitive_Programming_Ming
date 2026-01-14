#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
int t,l,w;
vi col(3);
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> l >> w >> col[0] >> col[1] >> col[2];
        if(l>w)swap(l,w);
        int minii=1e9;
        vector<int> nec;
        nec={l,l,w,w};
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    for(int iii=0;iii<3;iii++){
                        vector<int> cop=col;
                        cop[i]-=nec[0];
                        cop[j]-=nec[1];
                        cop[k]-=nec[2];
                        cop[iii]-=nec[3];
                        if(cop[0]<0 || cop[1]<0 || cop[2]<0)continue;
                        int sob=0;
                        sob+=cop[0]>0;
                        sob+=cop[1]>0;
                        sob+=cop[2]>0;
                        minii=min(minii,4+sob);
                    }
                }
            }
        }
        nec={l,l,w};
        //a,b,c
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    vector<int> cop=col;
                    cop[i]-=nec[0];
                    cop[j]-=nec[1];
                    cop[k]-=nec[2];
                    if(cop[0]<0 || cop[1]<0 || cop[2]<0)continue;
                    int sob=0;
                    sob+=cop[0]>0;
                    sob+=cop[1]>0;
                    sob+=cop[2]>0;
                    minii=min(minii,3+sob);
                }
            }
        }
        nec={l,w,w};
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    vector<int> cop=col;
                    cop[i]-=nec[0];
                    cop[j]-=nec[1];
                    cop[k]-=nec[2];
                    if(cop[0]<0 || cop[1]<0 || cop[2]<0)continue;
                    int sob=0;
                    sob+=cop[0]>0;
                    sob+=cop[1]>0;
                    sob+=cop[2]>0;
                    minii=min(minii,3+sob);
                }
            }
        }
        nec={l,l};
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                vector<int> cop=col;
                cop[i]-=nec[0];
                cop[j]-=nec[1];
                if(cop[0]<0 || cop[1]<0 || cop[2]<0 || cop[0]>=w || cop[1]>=w ||cop[2]>=w)continue;
                int sob=0;
                sob+=cop[0]>0;
                sob+=cop[1]>0;
                sob+=cop[2]>0;
                minii=min(minii,6);
            }
        }
        nec={l,w};
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                vector<int> cop=col;
                cop[i]-=nec[0];
                cop[j]-=nec[1];
                if(cop[0]<0 || cop[1]<0 || cop[2]<0 || cop[0]>=l || cop[1]>=l ||cop[2]>=l)continue;
                minii=min(minii,6);
            }
        }
        nec={w,w};
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                vector<int> cop=col;
                cop[i]-=nec[0];
                cop[j]-=nec[1];
                if(cop[0]<0 || cop[1]<0 || cop[2]<0 || cop[0]>=l || cop[1]>=l ||cop[2]>=l)continue;
                minii=min(minii,6);
            }
        }
        cout << minii << '\n';
    }
}