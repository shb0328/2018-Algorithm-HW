#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


// ex1
// #define N 4
// const int W = 13;
// const int w[N] = {3,4,5,6};

//ex2
#define N 5
const int W = 23;
const int w[N] = {5,6,8,10,12};

int total;
string include[N];
int weight;


using index = int;

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