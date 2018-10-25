#include <iostream>

using std::endl;
using std::cout;
using std::min;

int binomial(int n, int k);

int main(){

	int n,k;
	n = 2;
	k = 3;

	int binomialCoefficient = 0;
	try{

		binomialCoefficient = binomial(n,k);

	}catch(int e){
		cout<<"wrong input. k<=n"<<endl;
		return -1;
	}

	cout<<binomialCoefficient<<"a^"<<k<<"*b^"<<n-k<<endl;
	
	return 0;
}

int binomial(int n, int k){

	if(n<k)
		throw -1;
	
	int B[n][k];
	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j <= min(i,k); ++j)
		{
			if(j == 0 || j == i)
				B[i][j] = 1;
			else
				B[i][j] = B[i-1][j-1]+B[i-1][j];
		}
	}
	return B[n][k];
}