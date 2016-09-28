#include "stdafx.h"
#include "Graph.h"
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

Graph::Graph(int V)
{
	this->V = V;
	array = new AdjList[V];
	for (int i = 0; i < V; i++)
		array[i].head = NULL;
}


Graph::~Graph()
{
	delete[] array;
}


Graph::AdjListNode* Graph::newAdjListNode(int dest)
{
	AdjListNode* n = new AdjListNode;
	n->dest = dest;
	n->next = NULL;
	return n;
}

void Graph::addEdge(int src, int dest)
{
	AdjListNode* n = newAdjListNode(dest);
	n->next = array[src].head;
	array[src].head = n;

	n = newAdjListNode(src);
	n->next = array[dest].head;
	array[dest].head = n;
}

void Graph::printGraph()
{
	for (int i = 0; i < V; i++)
	{
	
		AdjListNode* n = array[i].head;
		cout << "AdjList of vertex "<<i <<": ";	
		
		while (n)
		{
			cout << n->dest <<" -> ";
			n = n->next;
		}
		cout << "NULL"<<endl;
	}
}

void Graph::BFS(int s)
{
	vector<bool> visited(V, false);
	queue<int> orderQ;

	visited[s] = true;
	orderQ.push(s);
	while (!orderQ.empty())
	{
		int curDest = orderQ.front();
		auto i = array[curDest].head;
		while (i)
		{
			if (!visited[i->dest])
			{				
				orderQ.push(i->dest);		
				visited[i->dest] = true;
			}
			i = i->next;			
		}
		cout << curDest << " ";
		orderQ.pop();
	}
}

void Graph::DFS_Visit_rec(int s)
{

}

void Graph::DFS_Visit_stack(int s)
{
	//vector<bool> visited(V, false);
	//stack<int> orderStack;
	//visited[s] = true;
	//orderStack.push(s);
	//while (!orderStack.empty())
	//{	
	//	int curDest = orderStack.top();
	//	auto i = array[curDest].head;
	//	while (i)
	//	{		
	//		if (!visited[i->dest])
	//		{
	//			orderStack.push(i->dest);
	//			visited[i->dest] = true;
	//		}
	//		i = i->next;
	//	}
	//	cout << curDest << " ";
	//	orderStack.pop();
	//}
}