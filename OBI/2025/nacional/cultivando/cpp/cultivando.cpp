#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;

int minimo_dias_para_plantar(int N, vector<int> d, int M, vector<int> a){
	vi copia=d;
	int l=0,r=N;
	while(l<r){
		bool xd=false;
		int mid=(l+r)>>1;
		d=copia;
		int cantidad=0;
		vector<bool> encontrado(M+1);
		for(int i=mid+1;i<N;i++){
			d[i]=0;
		}
		for(int i=mid;i>=0;i--){
			if(!encontrado[d[i]]){
				encontrado[d[i]]=true;
			}else{
				d[i]=0;
			}
		}
		int dialibre=0;
		for(int i=0;i<N;i++){
			if(d[i]==0){
				dialibre++;
			}else{
				if(dialibre-a[d[i]-1]>=0){
					dialibre-=a[d[i]-1];
					cantidad++;
					if(cantidad==M){
						xd=true;
						break;
					}
				}
			}
		}
		if(xd){
			//es posible
			r=mid;
		}else{
			l=mid+1;
		}
	}
	if(l==N){
		return -1;
	}else{
		return l+1;
	}
	
}