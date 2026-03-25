#include "supertrees.h"
#include <bits/stdc++.h>
using namespace std;
struct dsu{
	vector<int> pad,tam;
	int find(int a){return (a==pad[a])?a:pad[a]=find(pad[a]);}
	bool unite(int a,int b){
		if((a=find(a))==(b=find(b)))return false;
		if(tam[a]<tam[b])swap(a,b);
		tam[pad[b]=a]+=tam[b];
		return true;
	}
	dsu(int n){
		pad.resize(n);
		tam.resize(n);
		for(int i=0;i<n;i++)tam[pad[i]=i]=1;
	}
};
int construct(vector<vector<int>> p){
	int n=p.size();
	vector<vector<int>> answer(n,vector<int>(n));
	// si p=3, entonces no hay solucion porque tenemos que tener 2 ciclos:
	// 0-1,1-3,0-2,2-3,0-3, pero entonces hay 4 caminos e 1 a 2
	dsu clave(n),subdsu(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(p[i][j]==3)return 0;
			// si es 0 pertenecen a diferentes componentes
			if(p[i][j])clave.unite(i,j);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!p[i][j] && clave.find(i)==clave.find(j))return 0;
		}
	}
	// no puede haber 2 ciclos en un mismo componente sino habria >=4 caminos de a a b
	// -> cada componente hay a lo mucho un ciclo, y los demas conectan al ciclo
	for(int i=0;i<n;i++){
		vector<int> componentes;
		for(int j=0;j<n;j++)if(clave.find(j)==i)componentes.push_back(j);
		// resolver cada componente
		if(componentes.size()<=1)continue;
		// si dos tiene 1 solo camino, entonces estan en el mismo lado
		for(int j=0;j<componentes.size();j++){
			for(int k=j+1;k<componentes.size();k++){
				if(p[componentes[j]][componentes[k]]==1){
					if(subdsu.unite(componentes[j],componentes[k]))answer[componentes[j]][componentes[k]]=answer[componentes[k]][componentes[j]]=1;
				}
			}
		}
		// si hay un par que tienen 2 caminos pero pertenecen al mismo lado, entonces es imposible
		for(int j=0;j<componentes.size();j++){
			for(int k=j+1;k<componentes.size();k++){
				if(p[componentes[j]][componentes[k]]==2 && subdsu.find(componentes[j])==subdsu.find(componentes[k]))return 0;
			}
		}
		// cuantos subcomponentes hay?
		vector<int> subcomponentes;
		for(int j=0;j<componentes.size();j++)if(subdsu.find(componentes[j])==componentes[j])subcomponentes.push_back(componentes[j]);
		// los jefes de cada subcomponente se conecta
		if(subcomponentes.size()==1)continue;
		// es un tree
		if(subcomponentes.size()==2)return 0;
		// imposible ciclo de tamaño 2
		for(int j=0;j<subcomponentes.size();j++)answer[subcomponentes[j]][subcomponentes[(j+1)%subcomponentes.size()]]=answer[subcomponentes[(j+1)%subcomponentes.size()]][subcomponentes[j]]=1;
	}
	build(answer);
	return 1;
}
