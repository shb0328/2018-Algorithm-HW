#include <iostream>

using std::endl;
using std::cout;
using std::string;
using std::fixed;

// #define N 4
#define N 5

struct node
{
	string key;
	node* left;
	node* right;
};

float sigma(int q, int r, const float* p);
void optsearchtree(int n, const float p[N], float& minavg, int R[N+1][N+1]);
node* tree(int i, int j, const int R[N+1][N+1]);

// const string keys[N] = {"Don","Isabelle","Ralph","Wally"};
// const float p[] = {0.375,0.375,0.125,0.125};

const string keys[N] = {"apple","banana","cherry","mango","strawberry"};
const float p[] = {0.1,0.2,0.3,0.2,0.2};

int main() {
	cout<<fixed;
	cout.precision(2);

	float minavg;
	int R[N+1][N+1];
	optsearchtree(N,p,minavg,R);

	node* root = tree(1,N,R);

	cout<<"Minimum Average = "<<minavg<<endl;
	return 0;
}


node* tree(int i, int j, const int R[N+1][N+1])
{
	// cout<<"tree("<<i-1<<", "<<j<<")"<<endl;
	int k;
	node * p;
	// cout<<"R["<<i-1<<"]["<<j<<"] = "<<R[i-1][j]<<endl;
	k = R[i-1][j];
	if(k <= 0){
		// cout<<"return null"<<endl;
		return NULL;
	}
	else {
		p = new node;
		p -> key = keys[k-1];
		// cout<<"key = "<<p->key<<endl;
		p -> left = tree(i,k-1,R);
		p -> right = tree(k+1,j,R);
		return p;
	}
}

void optsearchtree(int n, const float p[N], float& minavg, int R[N+1][N+1])
{
	int i,j,k,diagonal;
	float A[n+1][n+1];
	
	//init
	for(int i =0; i<=n; ++i){
		for(int j =0; j<=n; ++j){
			R[i][j] = 0;
			A[i][j] = 0;
		}	
	}

	for(i = 1; i <= n; ++i){
		A[i-1][i-1] = 0;
		A[i-1][i] = p[i-1];
		R[i-1][i-1] = 0;
		R[i-1][i] = i;
	} A[n][n] = 0; R[n][n] = 0;
	//

	for(diagonal = 1; diagonal <= n-1; ++diagonal){
		for(i = 1; i <= n - diagonal; ++i) {
			j = i + diagonal;
			float sigmaValue = sigma(i-1,j-1,p);
			
			for(k = i; k <= j; ++k){
				float tmp = A[i-1][k-1] + A[k][j] + sigmaValue;
				
				if( k == i ) {
					A[i-1][j] = tmp;
					R[i-1][j] = k;
				}else {
					if(A[i-1][j] > tmp){
						A[i-1][j] = tmp;
						R[i-1][j] = k; }
				}

			}}}
			
			//show A,R
			cout<<"A = "<<endl;
			for(int i =0; i<=n; ++i){
				for(int j =0; j<=n; ++j)
					cout<<A[i][j]<<" ";
				cout<<endl;
			}
			cout<<endl<<"R = "<<endl;
			for(int i =0; i<=n; ++i){
				for(int j =0; j<=n; ++j)
					cout<<R[i][j]<<" ";
				cout<<endl;
			}
			cout<<endl;
			//
			minavg = A[0][n];
		}

		float sigma(int q, int r, const float* p)
		{
			float res = 0;
			for(int i = q; i <= r; ++i){
				res += p[i];
			}
			return res;
		}