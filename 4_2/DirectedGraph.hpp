#pragma once
#include <vector>
#include <queue>
#include <map>
#define TElem int


class DirectedGraph
{
private:
	std::map< TElem, std::map< TElem, TElem> > outEdges;
	std::map< TElem, std::map< TElem, TElem> > inEdges;
	std::map< TElem, bool > nodes;

public:
	DirectedGraph(){};
	~DirectedGraph(){};

	bool addEdge( TElem sourceNode, TElem destinationNode, TElem cost = 1)
	{
		if ( nodes.find(sourceNode) == nodes.end())
			nodes[sourceNode] = true;
		if ( nodes.find(destinationNode) == nodes.end())
			nodes[destinationNode] = true;

		outEdges[sourceNode][destinationNode] = cost;
		inEdges[destinationNode][sourceNode] = cost;
	}

	std::vector< TElem > getNodes()
	{
		std::vector< TElem > result;
		for( auto it = nodes.begin(); it != nodes.end(); it++ )
			result.push_back(it->first);
		return result;
	}

	std::vector< TElem > getNOut( TElem node )
	{
		std::vector< TElem > result;
		if( outEdges.find(node) != outEdges.end())
			for (auto it = outEdges[node].begin(); it != outEdges[node].end(); it++ )
				result.push_back(it->first);
		return result;
	}

	std::vector< TElem > getNIn( TElem node )
	{
		std::vector< TElem > result;
		if( inEdges.find(node) != inEdges.end())
			for (auto it = inEdges[node].begin(); it != inEdges[node].end(); it++ )
				result.push_back(it->first);
		return result;
	}

	std::vector< TElem > getPath( TElem source, TElem destination )
	{
		std::vector< TElem > path;
		std::queue< TElem > q;
		std::map< TElem, TElem > prev;


		q.push( source );
		prev[source] = -1;

		while( !q.empty() )
		{
			TElem currentNode = q.front();
			q.pop();

			for (TElem node : getNOut( currentNode ))
				if (prev.find(node) == prev.end())
				{
					prev[node] = currentNode;
					q.push(node);
				}

		}

		if (prev.find(destination) != prev.end())
		{
			TElem current = destination;
			while( current != -1)
			{
				path.push_back(current);
				current = prev[current];
			}
		}
		reverse(path.begin(), path.end());
		return path;
	}
};
