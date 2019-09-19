#pragma once

#include <iostream>
#include <vector>

using namespace std;
class graph
{
	enum COLOR
	{
		WHITE,
		GREY,
		BLACK
	};
	int _directed;
	int _size;
	std::vector  <std::vector<int> > adjList; 
public:
	int cycle_start;
	int cycle_end;
	graph(int size, bool isdirected = true);

	void addEdge(int u, int v);

	bool isdfsCycle(int v, std::vector<int> &visited, std::vector<int> &parent, std::vector< std::vector<int> > &cycle, int &cycleno);
	bool printCycle(std::vector<std::vector < int> > &cycle);
	bool dfsCycleUtil();

};