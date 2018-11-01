#include <iostream>

using std::endl;
using std::cout;
using std::string;

#define N 4

struct node
{
	string key;
	node* left;
	node* right;
};

float sigma(int q, int r, const float* p);
void optsearchtree(int n, const float p[N], float& minavg, int R[N+1][N+1]);
node* tree(int i, int j, int R[N+1][N+1]);

const string key[N] = {"Don","Isabelle","Ralph","Wally"};

int main() {
	float p[] = {0.375,0.375,0.125,0.125};
	float minavg;
	int R[N+1][N+1];
	optsearchtree(N,p,minavg,R);
	// node* root = tree(1,N,R);

	cout<<"Minimum Average = "<<minavg<<endl;
	return 0;
}


node* tree(int i, int j, int R[N+1][N+1])
{
	int k;
	node * p;
	k = R[i-1][j];
	if(k == 0)
		return NULL;
	else {
		p = new node;
		p -> key = key[k-1];
		p -> left = tree(i-1,k-1,R);
		p -> right = tree(k,j,R);
		return p;
	}
}

void optsearchtree(int n, const float p[N], float& minavg, int R[N+1][N+1])
{
	int i,j,k,diagonal;
	float A[n+1][n+1];
	
	//
	for(int i =0; i<=n; ++i){
		for(int j =0; j<=n; ++j)
			R[i][j] = 0;
	}
	for(int i =0; i<=n; ++i){
		for(int j =0; j<=n; ++j)
			A[i][j] = 0;
	}
	//init
	for(i = 1; i <= n; ++i){
		A[i-1][i-1] = 0;
		A[i-1][i] = p[i-1];
		R[i-1][i-1] = 0;
		R[i-1][i] = i;
	} A[n][n] = 0; R[n][n] = 0;
	//
	//test
	for(int i =0; i<=n; ++i){
		for(int j =0; j<=n; ++j)
			cout<<R[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	for(int i =0; i<=n; ++i){
		for(int j =0; j<=n; ++j)
			cout<<A[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	//



	for(diagonal = 1; diagonal <= n-1; ++diagonal){
		for(i = 1; i <= n - diagonal; ++i) {
			j = i + diagonal;
			for(k = i; k <= j; ++k){
				float tmp = A[i-1][k-1] + A[k][j] + sigma(i-1,j,p);
				//
				cout<<"di = " <<diagonal<<", i = "<<i<<", j = "<<j<<", tmp = "<<tmp<<endl;
				if( k == i ) {
					A[i-1][j] = tmp;
					R[i-1][j] = k;
				}
				else {
					if(A[i-1][j] > tmp){
						A[i-1][j] = tmp;
						R[i-1][j] = k;
					}
				}
			}}}
			
	minavg = A[0][n];
	cout<<"minavg = "<<minavg<<endl;
}

float sigma(int q, int r, const float* p)
{
	float res = 0;
	for(int i = q; i <= r; ++i)
		res += p[i];
	return res;
}