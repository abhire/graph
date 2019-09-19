#include"graph.h"

int main()
{
	
	graph x(5, false);
	x.addEdge(0, 1);
	x.addEdge(1, 2);
	x.addEdge(2, 3);
	x.addEdge(3, 4);
	x.addEdge(4, 1);
	x.addEdge(0, 3);
	
	x.dfsCycleUtil();
	
	int input;
	cin >> input;
}