#include <iostream>

using std::endl;
using std::cout;

#define N 5
#define INF 10000

using index = int;
using set_pointer = index;


class Graph {

private:
	int n;
	int m;
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

	edge E[];

	void quickSort() {

	}

public:

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

	return 0;
}