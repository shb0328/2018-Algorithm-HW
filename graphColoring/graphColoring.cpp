#include <iostream>

using std::cout;
using std::endl;

using index = int;
using graph = int;
using colorNum = int;
using color_of_nodes = int;


//ex1
#define N 4 //nodes
const graph W[N][N] = //adjacency matrix
{
	{0,1,1,1},
	{1,0,1,0},
	{1,1,0,1},
	{1,0,1,0}
};
const colorNum m = 3; //color is 1,2,3


bool promising(index i,color_of_nodes vcolor[N]) 
{ 
	int j = 1;
	bool res = true;

	while(j<i && res) {
		if(W[i-1][j-1] && vcolor[i] == vcolor[j]) 
			res = false;
		j++;
	}

	return res;
}

void m_coloring (index i,color_of_nodes vcolor[N]) 
{
	int color;
	if (promising(i,vcolor)) {
		if(i == N+1) {
			for(int k =1; k<=N; ++k)
				cout<<vcolor[k]<<" ";
			cout<<endl;
		}
		else{
			for(color = 1; color <=m; ++color){
				vcolor[i+1] = color;
				m_coloring(i+1,vcolor);
			}
			
		}
	}		
}



int main() {
	color_of_nodes vcolor[N] = {0,};
	m_coloring(0,vcolor);
	return 0;
}