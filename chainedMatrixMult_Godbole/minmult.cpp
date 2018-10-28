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
	// for(int i = 0 ; i < N ; ++i) {
	// 	for(int j = 0; j < N; ++j)
	// 		P[i][j] = 0;
	// }
	int res = minmult(N,d,P);
	cout<<"result = "<<res<<endl;
	return 0;
}

int minmult(const int n, const int d[N], int P[N][N])  
{
	int i,j,k,diagonal;
	int M[n][n];
	for(int i=0;i<n;++i){
		for (int j = 0; j <= i; ++j)
			M[i][j] = 0;
		for (int j = 0; j < n; ++j)
			P[i][j] = 0;
	}

	for(int i =0; i<n;++i){
		for(int j =0; j<n; ++j)
			cout<<M[i][j]<<" ";
		cout<<endl;
	}
		

	for(diagonal = 1; diagonal <= n-1; ++diagonal){
		for(i = 0; i< n - diagonal; ++i){
			j = i + diagonal;
			int temp[diagonal];
			//std::vector<int> temp;
			for(k = i; k <= j-1; ++k){
				cout<<"i = "<<i<<", k = "<<k<<", j = "<<j<<endl;
				cout<<"M[i,k] = "<<M[i][k]<<", M[k+1,j] = "<<M[k+1][j]<<", d[i]d[k+1]d[j+1] = "<<d[i]*d[k+1]*d[j+1]<<endl;
				temp[k-i] = M[i][k] + M[k+1][j] + d[i]*d[k+1]*d[j+1];
				cout<<"temp[k-i] = "<<temp[k-i]<<endl;
				//temp.push_back(M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j]);
				// int temp = M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j];
				// if(M[i][j]>temp)
				// 	M[i][j] = temp;
			}
			for(int q = 0; q < sizeof(temp) ; ++q)
					cout<<temp[q]<<" ";
				cout<<endl;
				M[i][j] = *min_element(temp,temp+diagonal);
			//M[i][j] = *min_element(temp.begin(),temp.end());
			// M[i][j] = *min_element(temp,temp+diagonal);
			cout<<endl<<"M["<<i<<"]["<<j<<"] = "<<M[i][j]<<endl;
		}
	}

	for(int i =0; i<n;++i){
		for(int j =0; j<n; ++j)
			cout<<M[i][j]<<" ";
		cout<<endl;
	}
	return M[0][n-1];
}