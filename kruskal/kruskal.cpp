#include <iostream>

using std::endl;
using std::cout;

//ex1
// #define N 5
//ex2
#define N 6
#define INF 10000

using index = int;
using set_pointer = index;

class DisjointSet {

private:
	int n;
	struct node
	{
		index parent;
		int depth;
	};

	node *U;

	void makeset(index i) {
		U[i-1].parent = i;
		U[i-1].depth = 0;
	}

public:
	DisjointSet(int n){
		this->n = n;
		U = new node[n];
	}
	~DisjointSet(){
		delete[] U;
	}

	void initial(int n) {
		index i;
		for (i = 1; i<=n; ++i) makeset(i);
	}

	bool equal (set_pointer p, set_pointer q){
		if(p == q) return true;
		else return false;
	}

	void merge(set_pointer p, set_pointer q){
		if(U[p-1].depth == U[q-1].depth) {
			U[p-1].depth += 1;
			U[q-1].parent = p;
		}
		else if(U[p-1].depth < U[q-1].depth)
			U[p-1].parent = q;
		else
			U[q-1].parent = p;
	}

	set_pointer find(index i) {
		index j;
		j = i;
		while(U[j-1].parent != j) j = U[j-1].parent;
		return j;
	}

	void show() {
		cout<<"U = "<<endl;
		for(int i = 0; i<n; ++i){
		cout<<"["<<i+1<<"]"
		<<"parent : "<<U[i].parent<<endl
		<<"depth : "<<U[i].depth<<endl;
		}
	}

};


class Graph {

private:
	int n; //number of vertices
	int m=0; //number of edges = size of E
	int (*W)[N];

	struct edge
	{
		index v1;
		index v2;
		int weight;
	};

	edge* F; //edges of Graph (MST)
	edge* E; //edges of Graph (Original)

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
	void show(const int n,const edge* ep) {
		for(int i =0; i < n; ++i){
			cout<<ep[i].v1<<"-"
			<<ep[i].v2<<":"
			<<ep[i].weight<<endl;
		}
	}

	Graph(int W[N][N]){
		this->n = N;
		this->W = W;
		for(int i = 0; i < n; ++i){
			for(int j = i+1; j < n; ++j)
				if(W[i][j] > 0 && W[i][j] < INF) m++;
		}

		E = new edge[m]; index k =0;

		for(int i = 0; i < n; ++i){
			for(int j = i+1; j < n; ++j)
				if(W[i][j] > 0 && W[i][j] < INF) E[k++] = {i+1,j+1,W[i][j]};
		}
	}

	~Graph(){
		delete[] E;
		delete[] F;
	}

	void kruskal(){
		cout<<"**********kruskal start**********"<<endl<<endl;

		index k=0,l=0;
		set_pointer p,q;
		edge e;

		//sort E
		mergeSort(m,E);
		cout<<"E = "<<endl; show(m,E); cout<<endl;

		//init F
		F = new edge[n-1];
		for(int i =0; i<n-1; ++i)
			F[i] = {0,0,0};
		cout<<"F = "<<endl; show(n-1,F); cout<<endl;

		//create disjoint set U
		DisjointSet DS = DisjointSet(n);
		DS.initial(n);
		DS.show(); cout<<endl;

		cout<<endl<<"..."<<endl<<endl<<endl;

		//selection
		while(k<n-1){
			p = DS.find(E[l].v1);
			q = DS.find(E[l].v2);
			if(!DS.equal(q,p)){
				DS.merge(p,q);
				F[k++] = E[l];
			}l++;
		}

		cout<<"F = "<<endl; show(n-1,F); cout<<endl;
		DS.show(); cout<<endl;
		cout<<"**********kruskal finish**********"<<endl;
	}
};





int main() {
	//ex1
	// int W[N][N] = {
	// 	{0,1,3,INF,INF},
	// 	{1,0,3,6,INF},
	// 	{3,3,0,4,2},
	// 	{INF,6,4,0,5},
	// 	{INF,INF,2,5,0}
	// };

	//ex2
	int W[N][N] = {
		{0,3,1,INF,INF,INF},
		{3,0,1,INF,INF,INF},
		{1,1,0,5,5,2},
		{INF,INF,5,0,INF,2},
		{INF,INF,5,INF,0,8},
		{INF,INF,2,2,8,0}
	};

	Graph* myGraph = new Graph(W);
	myGraph->kruskal();
	return 0;
}