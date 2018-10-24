#include <iostream>
#include <limits.h>

using std::endl;
using std::cout;

#define INFINITY 100 //Maximum value for an object of type int
#define N 5 //Number of nodes 

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
				if(W[i][j] == 100)
					cout<<"INFINITY ";
				else
					cout<<W[i][j]<<" ";
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

		for(k=0; k<N; ++k){
			for(i=0; i<N; ++i){
				for(j=0; j<N; ++j){
					if(D[i][k] + D[k][j] < D[i][j]){
						P[i][j] = k+1;
						D[i][j] = D[i][k] + D[k][j];
					}
				}
			}
		}
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
	int W[N][N] = 	{	
						{0,1,INFINITY,1,5},
						{9,0,3,2,INFINITY},
						{INFINITY,INFINITY,0,4,INFINITY},
						{INFINITY,INFINITY,2,0,3},
						{3,INFINITY,INFINITY,INFINITY,0}
					};

	Graph sampleGraph1 = Graph(W);
	sampleGraph1.floyd();

	int vStart = 1; //1~N
	int vEnd = 3; //1~N

	cout<<endl<<"v"<<vStart<<" ";
	sampleGraph1.path(vStart,vEnd);
	cout<<"v"<<vEnd<<endl;

	return 0;
}






