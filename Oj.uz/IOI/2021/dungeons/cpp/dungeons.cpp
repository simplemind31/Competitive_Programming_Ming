#include "dungeons.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int N;
bool task3=true;
vector<vi> To;
vi bjlosing[32],bjwining[32];
vll bjsumlosing[32];
ll power,fuerza;
ll bigmod(ll b,ll e){
	ll p=1;
	while(e){
		if(e%2){
			p*=b;
		}
		b*=b;
		e/=2;
	}
	return p;
}
//strenth,losingstrength,winignto,losingto
void init(int n,vi s,vi p,vi w,vi l){
	N=n;
	To.resize(N+1);
	for(int i=0;i<32;i++){
		bjlosing[i].resize(N+1);
		bjwining[i].resize(N+1);
		bjsumlosing[i].resize(N+1);
	}
	power=s[0];
	for(int i=0;i<N;i++){
		To[i]={s[i],p[i],w[i],l[i]};
		if(s[i]!=power){
			task3=false;
		}
		bjlosing[0][i]=l[i];
		bjsumlosing[0][i]=p[i];
		bjwining[0][i]=w[i];
	}
	bjlosing[0][N]=N;
	bjsumlosing[0][N]=0;
	bjwining[0][N]=N;
	for(int i=1;i<32;i++){
		for(int j=0;j<=N;j++){
			bjlosing[i][j]=bjlosing[i-1][bjlosing[i-1][j]];
			bjsumlosing[i][j]=bjsumlosing[i-1][bjlosing[i-1][j]]+bjsumlosing[i-1][j];
			bjwining[i][j]=bjwining[i-1][bjwining[i-1][j]];
		}
	}
	return;
}
ll simulate(int x,int z){
	fuerza=z;
	if(task3){
		if(fuerza<power){
			if(bjlosing[31][x]==N){
				int tempx=x;
				ll tempfuerza=fuerza;
				//hay posibilidad de ganar perdiendo
				for(int i=30;i>=0;i--){
					if(bjlosing[i][tempx]!=N){
						tempfuerza+=bjsumlosing[i][tempx];
						tempx=bjlosing[i][tempx];
					}
				}
				if(tempfuerza<power){
					// gana perdiendo
					tempfuerza+=bjsumlosing[0][tempx];
					tempx=bjlosing[0][tempx];
					return tempfuerza;
				}
			}
			for(int i=31;i>=0;i--){
				if(fuerza+bjsumlosing[i][x]<power){
					fuerza+=bjsumlosing[i][x];
					x=bjlosing[i][x];
				}
			}
			fuerza+=bjsumlosing[0][x];
			x=bjlosing[0][x];
		}
		if(x==N){
			return fuerza;
		}
		for(int i=31;i>=0;i--){
			if(bjwining[i][x]!=N){
				fuerza+=bigmod(2,i)*power;
				x=bjwining[i][x];
			}
		}
		fuerza+=power;
		x=bjwining[0][x];
	}else{
		while(x!=N){
			if(fuerza>=To[x][0]){
				fuerza+=To[x][0];
				x=To[x][2];
			}else{
				fuerza+=To[x][1];
				x=To[x][3];
			}
		}
	}
	return fuerza;
}