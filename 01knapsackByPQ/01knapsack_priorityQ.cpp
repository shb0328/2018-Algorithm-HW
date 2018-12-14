#include <iostream>

using namespace std;

int W;//weight of bag
int n;//items
int *w;//weights of items
int *p;//profits of items

struct  node //for priority Q
{
	int level;
	int profit;
	int weight;
	float bound;
};

class priorityQ{
public:
	int cnt;
	node arr[20];
	priorityQ() { cnt = 0; }

	void push(node data)
	{
		int i = ++cnt;
		while(i != 1 && data.profit > arr[i/2].profit)
		{
			arr[i] = arr[i/2];
			i = i/2;
		}
		arr[i] = data;
	}

	node pop()
	{
		node item = arr[1];
		node temp = arr[cnt--];
		int c = 2; int p =1;

		while(c<=cnt)
		{
			if((arr[c].profit < arr[c+1].profit) && c+1 <= cnt) c++;
			if(temp.profit >= arr[c].profit) break;
			arr[p] = arr[c];
			p = c;
			c *= 2;
		}

		arr[p] = temp;
		return item;
	}

	bool empty()
	{
		if(cnt == 0) return true;
		return false;
	}
};

float bound(node u)
{
	int j, k=0;
	int totweight;
	float result;

	if(u.weight >= W) 
		return 0;
	else {
		result = u.profit;
		j = u.level + 1;
		totweight = u.weight;

		while(j <= n && totweight + w[j] <= W) {
			totweight = totweight + w[j];
			result = result + p[j++];
		}

		k=j;
		if(k <= n)
			result = result + (W-totweight) * p[k]/w[k];

		return result;
	}
}

void knapsack(int &maxprofit)
{
	priorityQ PQ = priorityQ();
	node u,v;

	v = {0,0,0,};
	maxprofit = 0;
	v.bound = bound(v);
	PQ.push(v);

	while(!PQ.empty()){
		v = PQ.pop();
		if(v.bound > maxprofit) {
			u.level = v.level +1;

			//left child u
			u.weight = v.weight + w[u.level];
			u.profit = v.profit + p[u.level];

			if(u.weight <= W && u.profit > maxprofit)
				maxprofit = u.profit;

			u.bound = bound(u);

			if(u.bound > maxprofit)
				PQ.push(u);

			//right child u
			u.weight = v.weight;
			u.profit = v.profit;

			if(u.bound > maxprofit)
				PQ.push(u);
		}
	}
}

int main() {
	n = 4; 	W = 16;

	//sorted by pi/wi
	w = new int[n+1]; 	//not use w[0]
	p = new int[n+1]; 	//not use p[0]

	w[1] = 2; w[2] = 5; w[3] = 10; w[4] = 5;
	p[1] = 40; p[2] = 30; p[3] = 50; p[4] = 10;

	int maxprofit = 0;

	knapsack(maxprofit);

	cout<<"maxprofit = "<<maxprofit<<endl;

	return 0;
}

//https://blog.naver.com/fusis1/221185390203