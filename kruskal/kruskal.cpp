#include <iostream>

using std::endl;
using std::cout;

#define N 5
#define INF 10000

using index = int;
using set_pointer = index;


class Graph {

private:
	int n; //number of vertex
	int m=0; //number of edges = size of E
	int W[N][N] = {
		{0,1,3,INF,INF},
		{1,0,3,6,INF},
		{3,3,0,4,2},
		{INF,6,4,0,5},
		{INF,INF,2,5,0}
	};

	struct edge
	{
		index v1;
		index v2;
		int weight;
	};

	using keytype = edge;
	void mergeSort(int n, keytype S[]){
		if(n > 1){
			const int h = n/2;
			const int m = n - h;
			keytype U[h], V[m];

			for(int i = 0; i<h; ++i)
				U[i] = S[i];
			for(int i = 0; i<m; ++i)
				V[i] = S[h+i];

			mergeSort(h,U);
			mergeSort(m,V);
			merge(h,m,U,V,S);
		}
	}
	void merge(int h, int m, const keytype U[], const keytype V[], keytype S[]) {
		index i,j,k;
		i = 0; j = 0; k = 0;
		while (i < h && j < m) {
			if (U[i].weight < V[j].weight)
				S[k] = U[i++];
			else
				S[k] = V[j++];
			k++;
		}
		if(i >= h){
			for(int l = j; l < m; ++l )
				S[k++] = V[l];
		}else {
			for(int l = i; l < h; ++l )
				S[k++] = U[l];
		}
	}

public:
	edge E[];

	void show(const edge* ep) {
		for(int i =0; i < m; ++i){
			cout<<ep[i].v1<<"-"
			<<ep[i].v2<<":"
			<<ep[i].weight<<endl;
		}
	}

	Graph(){
		this->n = N;
		for(int i = 0; i < N; ++i){
			for(int j = i+1; j < N; ++j){
				if(W[i][j] > 0 && W[i][j] < INF)
					E[m++] = {i+1,j+1,W[i][j]};
			}
		}

		mergeSort(m,E);
	}

	int get_m(){	return m;}

	void kruskal(int n, int m, edge E, edge& F) {
		index i, j;
		set_pointer p,q;
		edge e;


	}
};

class DisjointSet {

private:

	struct node
	{
		index parent;
		int depth;
	};

	node U[N];

	void makeset(index i) {
		U[i].parent = i;
		U[i].depth = 0;
	}

public:

	void initial(int n) {
		index i;
		for (i = 1; i<=n; ++i) makeset(i);
	}

bool equal (set_pointer p, set_pointer q){
	if(p == q) return true;
	else return false;
}

void merge(set_pointer p, set_pointer q){
	if(U[p].depth == U[q].depth) {
		U[p].depth += 1;
		U[q].parent = p;
	}
}

set_pointer find(index i) {
	index j;
	j = i;
	while(U[j].parent != j) j = U[j].parent;
	return j;
}

};


int main() {
	Graph* myGraph = new Graph();
	cout<<myGraph->get_m()<<endl;
	myGraph->show(myGraph->E);
	return 0;
}