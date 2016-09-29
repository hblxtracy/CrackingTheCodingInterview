// Graphs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"
#include <iostream>
using namespace std;

int main()
{
	Graph gh(5);
	gh.addEdge(0, 1);
	gh.addEdge(0, 4);
	gh.addEdge(1, 2);
	gh.addEdge(1, 3);
	gh.addEdge(1, 4);
	gh.addEdge(2, 3);
	gh.addEdge(3, 4);

	// print the adjacency list representation of the above graph
	gh.printGraph();

	cout << "BFS- start vertex 2: ";
	gh.BFS(2);
	cout << endl;

	cout << "DFS-stack - start vertex 2: ";
	gh.DFS_Visit_stack(2);


//	4.7 Build Order : You are given a list of projects and a list of dependencies(which is a list of pairs of
//		projects, where the second project is dependent on the first project).All of a project's dependencies
//		must be built before the project is.Find a build order that will allow the projects to be built.If there
//		is no valid build order, return an error.
//		EXAMPLE
//	Input :
//  projects : a, b, c, d, e, f
//  dependencies : (a, d), (f, b), (b, d), (f, a), (d, c)
//	    Output : f, e, a, b, d, c
				

	getchar();
    return 0;
}

