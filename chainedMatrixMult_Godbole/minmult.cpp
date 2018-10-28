#include <iostream>

using std::endl;
using std::cout;

#define N 6

int minmult(int n, const int d[N], int P[N][N]) ; 
void order(int i,int j,const int P[N][N]) ;

int main() {

	int d[N+1] = {5,2,3,4,6,7,8};//7
	int P[N][N];
	int res = minmult(N,d,P);
	cout<<"Minimum Number of Multiplications = "<<res<<endl;
	order(1,6,P);
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

	for(diagonal = 1; diagonal <= n-1; ++diagonal){
		for(i = 0; i< n - diagonal; ++i){
			j = i + diagonal;
			
			for(k = i; k <= j-1; ++k){
				if(k == i){
					P[i][j] = k+1; 
					M[i][j] = M[i][k] + M[k+1][j] + d[i]*d[k+1]*d[j+1];
				}
				else{
					if(M[i][j] > M[i][k] + M[k+1][j] + d[i]*d[k+1]*d[j+1]){
						P[i][j] = k+1;
						M[i][j] = M[i][k] + M[k+1][j] + d[i]*d[k+1]*d[j+1];
					}
				}
			}
			
			cout<<endl<<"M["<<i<<"]["<<j<<"] = "<<M[i][j]<<endl;
		}
	}

	cout<<endl;
	for(int i =0; i<n;++i){
		for(int j =0; j<n; ++j)
			cout<<M[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
		
	return M[0][n-1];
}

void order(int i,int j,const int P[N][N]) 
{
	if(i == j) cout<<"A"<<i<<"";
	else {
		int k = P[i-1][j-1];
		cout<<"(";
		order(i,k,P);
		order(k+1,j,P);
		cout<<")";
	}
}