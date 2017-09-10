#include <iostream>
#include <fstream>
#include <algorithm>

#include "DirectedGraph.hpp"

using namespace std;

ostream& operator<< (ostream& os, vector<TElem> v)
{
	for ( TElem t : v )
		os << t << " ";
	os << "\n";
	return os;
}

int main()
{
	ifstream f("graph.txt");

	DirectedGraph graph;
	int x, y;
	while( f >> x >> y)
	{
		graph.addEdge(x, y);
	}

	cout << graph.getPath(1, 2);

	f.close();
	return 0;
}
