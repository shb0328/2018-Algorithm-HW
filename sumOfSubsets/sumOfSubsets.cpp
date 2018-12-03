#include <iostream>
#include <string>

#define N 4

using std::cout;
using std::endl;
using std::string;

using index = int;
int W = 13;
const int w[N] = {3,4,5,6};
int total;
string include[N];
int weight;

bool promising (index i, int weight, int total) {
	return ((weight + total >= W) && (weight == W || weight + w[i] <= W));
}

void sum_of_subsets(index i, int weight, int total) {
	if (promising(i,weight,total))
	{
		if(weight == W){
			for(int l = 0; l<i; ++l)
				cout<<include[l]<<" ";
			cout<<endl<<endl;
		}
		else {
			include[i] = "yes";
			sum_of_subsets(i+1, weight+w[i], total - w[i]);
			include[i] = "no";
			sum_of_subsets(i+1, weight, total-w[i]);
		}	
	}
}

int main(){
	for(int i =0; i<N; ++i) {
		total += w[i];
	}
	sum_of_subsets(0,weight,total);
	return 0;
}