#pragma once

//A structure to represent an adjacency list node
struct AdjListNode
{
	int dest;
	struct AdjListNode* next;
};

// A structure to represent an adjacency list
struct AdjList
{
	struct AdjListNode* head;
};

class Graph
{
private:
	int V;
	struct AdjList* array;

public:

	Graph(int V);
	~Graph();
	AdjListNode* newAdjListNode(int dest);
	void addEdge(int src, int dest);
	void printGraph();
};

