#include <iostream>
#include <limits.h>

using std::endl;
using std::cout;

#define INFINITY INT_MAX/2 
#define N 6 //Number of nodes 

class Graph {
private:
	int (*W)[N];
	int (*D)[N];
	int P[N][N];

public:
	Graph(int (*W)[N]) {
		this->W = W;
		show();
	}

	~Graph(){
	}

	void show()
	{
		cout<<"W = "<<endl;
		for(int i =0;i<N;++i){
			for(int j =0;j<N;++j){
				if(W[i][j] == INFINITY)
					cout<<"E ";
				else
					cout<<W[i][j]<<" ";
			}
				cout<<endl;
		}
	}

void showD()
	{
		cout<<"D = "<<endl;
		for(int i =0;i<N;++i){
			for(int j =0;j<N;++j){
				if(D[i][j] == INFINITY)
					cout<<"E ";
				else
					cout<<D[i][j]<<" ";
			}
				cout<<endl;
		}
	}

	void showP()
	{
		cout<<"P = "<<endl;
		for(int i =0;i<N;++i){
			for(int j =0;j<N;++j){
				if(P[i][j] == INFINITY)
					cout<<"E ";
				else
					cout<<P[i][j]<<" ";
			}
				cout<<endl;
		}
	}

	void floyd()
	{
		int i,j,k;

		for(i=0; i<N; ++i){
			for(j=0; j<N; ++j)
				P[i][j] = 0;
		}
		
		D = W;

		for(k=1; k<=N; ++k){
			for(i=0; i<N; ++i){
				for(j=0; j<N; ++j){
					if(D[i][k-1] + D[k-1][j] < D[i][j]){
						P[i][j] = k;
						D[i][j] = D[i][k-1] + D[k-1][j];
					} } } } 
	}

	void path(int q, int r) {
		int i = q-1;
        int j = r-1;
		if(P[i][j] != 0) {
			path(q,P[i][j]);
			cout<<"v"<<P[i][j]<<" ";
			path(P[i][j],r);
		}
	}
};

int main() {
	cout<<"E means infinity"<<endl<<endl;
	//N = 5
	// int W[N][N] = 	{	
	// 					{0,1,INFINITY,1,5},
	// 					{9,0,3,2,INFINITY},
	// 					{INFINITY,INFINITY,0,4,INFINITY},
	// 					{INFINITY,INFINITY,2,0,3},
	// 					{3,INFINITY,INFINITY,INFINITY,0}
	// 				};

	//N = 6
	int W[N][N] = 	{	
						{0,1,INFINITY,INFINITY,2,INFINITY},
						{INFINITY,0,14,9,3,INFINITY},
						{INFINITY,INFINITY,0,2,INFINITY,INFINITY},
						{8,INFINITY,11,0,INFINITY,INFINITY},
						{3,INFINITY,INFINITY,INFINITY,0,1},
						{5,INFINITY,6,INFINITY,1,0}
					};

	Graph myGraph = Graph(W);
	myGraph.floyd();
	myGraph.showD();
	myGraph.showP();

	int vStart = 1; //1~N
	int vEnd = 3; //1~N

	cout<<endl<<"v"<<vStart<<" ";
	myGraph.path(vStart,vEnd);
	cout<<"v"<<vEnd<<endl;

	return 0;
}






