#include <iostream>

using std::cout;
using std::endl;

#define N 4
int W[N][N] = {
	{0,1,0,1},
	{1,0,1,1},
	{0,1,0,1},
	{1,1,1,0}
};

using index = int;
bool promising(index i,int vindex[N]) {
	int j; bool res;

	if(i == N-1 && !W[vindex[i]-1][vindex[0]-1]) //마지막 노드가 첫번째 노드랑 연결되어 있지 않다면
		res = false;
	else if (i>0 && !W[vindex[i-1]-1][vindex[i]-1]) //이전노드와 현재노드가 연결되어 있지 않다면
		res = false;
	else { //i = 0 or i>0,W[vindex[i-1]][vindex[i]] = 1 / 
		res = true;
		j = 1;
		while (j<i && res)
			if(vindex[i] == vindex[j++]) res = false;
	}
	return res;
}		


void hamiltonian(index i,int vindex[N]) {
	index j;

	if(promising(i,vindex)) {
		if(i == N-1){
			for(int k =1; k<=i; ++k)
				cout<<vindex[k]<<" ";
			cout<<endl;
		}
		else {
			for(j = 2; j<=N; ++j) {
				vindex[i+1] = j;
				hamiltonian(i+1,vindex);
			}
		}
	}
}

int main() {
	int vindex[N] = {1,};
	hamiltonian(0,vindex);
	return 0;
}