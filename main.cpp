#include <iostream>
#include "graph.h"
using namespace std;

void main()
{
	start(); // start with selecting menu and input the graph
	
	Graph mygraph(numNode); // create a Graph's object called 'mygraph'
	mygraph.init(); // initialize a graph

	if (menu == 1)
		mygraph.create_matrix(); // ask user to input the whole weight, then create an adjacency matrix
	else if (menu == 2)
		mygraph.create_matrix_withValue(example); // select graph from example (1-5)

	mygraph.create_list(); // convert the matrix to an adjacency linked list
	mygraph.print_matrix(); // print the matrix
	mygraph.print_list(); // print the linked list
	mygraph.check_graph(); // check the graph to answer questions including output results
	mygraph.shortest_path(); // implement dijkstra's algorithm

	cout << endl;
}
