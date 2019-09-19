#include "graph.h"

graph::graph(int size, bool isdirected)
{
	adjList.resize(size);
	_size = size;
	_directed = isdirected;
}

void graph::addEdge(int u, int v)
{
	adjList[u].push_back(v);

	if (!_directed)
		adjList[v].push_back(u);
}

bool graph::isdfsCycle(int v, std::vector<int>& visited, std::vector<int> &parent, std::vector<std::vector <int> > &cycle, int &cyclelNo)
{
	visited[v] = GREY;

	int size = adjList[v].size();

	for (int i = 0; i < size; i++)
	{
			
		if (visited[adjList[v][i]] == WHITE)
		{
			parent[adjList[v][i]] = v;
			isdfsCycle(adjList[v][i], visited, parent, cycle, cyclelNo);
		}

		if (visited[adjList[v][i]] == GREY && adjList[v][i] != parent[v]) // partial visited inside the recursion
		{
			cyclelNo ++;
			int curr = v;
			int end = adjList[v][i];
			
			cycle[cyclelNo].push_back(end);
			
			while (curr != end)
			{
				cycle[cyclelNo].push_back(curr);
				curr = parent[curr];
			}
		}
	}

	visited[v] = BLACK;
	return false;
}
bool graph::printCycle(std::vector<std::vector <int> > &CycleMap)
{
	cout << "================detecting  cycle ================" << endl;
	
	int count = 0;
	bool found = false;
	
	for (int i = 0; i < _size; i++)
	{
		if (CycleMap[i].size())
		{
			found = true;
			cout << "\n Cycle found ------\n";

			for (int j = 0; j < CycleMap[i].size(); j++)
			{
				cout << CycleMap[i][j] << " ";
			}


			cout << "\n Cycle ends \n";
		}
	}

	if (!found)
		cout << "\n No cycles found";

	return true;
}

bool graph::dfsCycleUtil()
{
	std::vector<int> parent(_size, -1);

	std::vector<int> visited(_size, WHITE);

	std::vector<std::vector< int>>  cycle(_size); // maximum cycles can be lesser than size
	int cycleno =-1;

	for (int i = 0; i < _size; i++)
	{
		isdfsCycle(i, visited, parent, cycle, cycleno);
		
	}

	printCycle(cycle);

	//cout << cycle_end;



	return false;
}
