#include <iostream>
#include <array>

#define N 5
#define INF 10000

using std::cout;
using std::endl;

struct edge
{
	int v1,v2;
	int weight;
};

using set_of_edges = edge*;
using graph = int[N][N];
using index = int;

void dijkstra(int n, const graph W, set_of_edges& F){
	cout<<" **********dijkstra start********** "<<endl<<endl; 
	index i,vnear;
	edge e;
	index touch[n]; //not use 0th
	int length[n];

	F = new edge[N-1] {{0,0,0},};
	//test
	cout<<"F = "<<endl;
		for(index i = 0; i<N-1; ++i)
			cout<<"("<<F[i].v1<<","<<F[i].v2<<","<<F[i].weight<<")"<<endl;

	for(i = 1; i < n; ++i) { 	//path's start node : 1
		touch[i] = 1;
		length[i] = W[0][i];		//init length to (1 -> i)'s weights
	}

	index k =0;
	while (k<n-1) {
		int min = INF;
		for(i = 1; i < n; ++i) {
			if(0<=length[i] && length[i] <min) {
				min = length[i];
				vnear = i;
			}
		}

		cout<<endl<<"vnear = "<<vnear+1<<endl; //test
		cout<<endl<<"length = "<<endl; //test
		for(index i = 1; i<n; ++i) cout<<length[i]<<" ";
		cout<<endl<<endl;
		e = {touch[vnear],vnear+1,W[touch[vnear]-1][vnear]};
		//test
		cout<<"e = "<<"("<<e.v1<<","<<e.v2<<","<<e.weight<<")"<<endl<<endl;

		F[k++] = e; //add F about edge

		//test
		cout<<"F = "<<endl;
		for(index i = 0; i<N-1; ++i)
			cout<<"("<<F[i].v1<<","<<F[i].v2<<","<<F[i].weight<<")"<<endl;

		for(i = 1; i < n; ++i) {
			if(length[vnear] + W[vnear][i] < length[i]) { //path through vnear is faster
				cout<<"length["<<vnear+1<<"] + W["<<vnear<<"]["<<i<<"] = "<<length[vnear] + W[vnear][i]<<" < length["<<i<<"] = "<<length[i]<<endl;
				length[i] = length[vnear] + W[vnear][i];
				touch[i] = vnear+1;
			}
		}

		length[vnear] = -1; //add Y about vertex

	}
	cout<<" **********dijkstra end********** "<<endl<<endl;
}

int main() {
	graph W = {
		{0,7,4,6,1},
		{INF,0,INF,INF,INF},
		{INF,2,0,5,INF},
		{INF,3,INF,0,INF},
		{INF,INF,INF,1,0}
	};

	cout<<"W = "<<endl;
	for(index i =0; i<N; ++i){
		for(index j =0; j<N; ++j){
			if(W[i][j] == INF) cout<<"INF ";
			else cout<<W[i][j]<<" ";
		}
		cout<<endl;
	}cout<<endl;

	set_of_edges F;

	dijkstra(N,W,F);

	cout<<"F = "<<endl;
	for(index i = 0; i<N-1; ++i)
		cout<<"("<<F[i].v1<<","<<F[i].v2<<","<<F[i].weight<<")"<<endl;
	return 0;
}