#include"graph.h"

int main()
{
	
	graph x(7, true);
	x.addEdge(0, 1);
	x.addEdge(1, 2);
	x.addEdge(2, 3);
	x.addEdge(3, 1);
	x.addEdge(2, 4);
	x.addEdge(4, 5);
	x.addEdge(5, 6);
	x.addEdge(6, 4);

	x.dfsCycleUtil();
	
	int input;
	cin >> input;
}