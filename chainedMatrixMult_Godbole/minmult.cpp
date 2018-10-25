#include <iostream>
#include <algorithm>
#include <vector>

using std::endl;
using std::cout;
using std::min;
using std::min_element;

#define N 6

int minmult(int n, const int d[N], int P[N][N]) ; 

int main() {

	int d[N+1] = {5,2,3,4,6,7,8};//7
	int P[N][N];
	for(int i = 0 ; i < N ; ++i) {
		for(int j = 0; j < N; ++j)
			P[i][j] = 0;
	}
	int res = minmult(N,d,P);
	cout<<"result = "<<res<<endl;
	return 0;
}

int minmult(int n, const int d[N], int P[N][N])  
{
	int i,j,k,diagonal;
	int M[n][n];
	for(i=0;i<n;++i)
		M[i][i] = 0;

	for(diagonal = 1; diagonal <= n-1; ++diagonal){
		for(i = 1; i<= n - diagonal; ++i){
			j = i + diagonal;
			int temp[j-i];
			//std::vector<int> temp;
			for(k = i; k <= j-1; ++k){
				temp[k-i] = M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j];
				//temp.push_back(M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j]);
				for(int q = 0; q < sizeof(temp) ; ++q)
					cout<<temp[q]<<" ";
				cout<<endl;
			}
			//M[i][j] = *min_element(temp.begin(),temp.end());
			M[i][j] = *min_element(temp,temp+(j-i));
		}
	}

	for(int q=0;q<n;++q){
		for(int r=0;r<n;++r)
			cout<<M[q][r]<<" ";
		cout<<endl;
	}
	return M[0][n-1];
}