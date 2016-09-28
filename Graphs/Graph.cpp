#include "stdafx.h"
#include "Graph.h"
#include <iostream>
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