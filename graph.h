#include <list>
using namespace std;

#ifndef Graph_H
#define Graph_H

class Edges;

class NodeData
{
public:
	NodeData();
	NodeData(char el)
	{
		data = el;
	}
	char data;
	list<Edges> edges;
};

class Edges
{
public:
	Edges()
	{
		weight = 0;
	}
	Edges(int w)
	{
		weight = w;
	}
	int weight;
	NodeData *edge;
};

class Graph
{
public:
	Graph();
	Graph(int num)
	{
		numNode = num;
	}
	void init()
	{
		for (int i = 0; i < numNode; i++)
		{
			graph.push_back(char_ascii); // push the 'NodeData' into the graph
			arrPtr_Graph[i] = &graph.back(); // keep its address to a temporary array called 'arrPtr_Graph'
			path.push_back(char_ascii++); // push the 'NodeData' into the path as well
			arrPtr_Path[i] = &path.back(); // keep its address to a temporary array called 'arrPtr_Path'
		}
	}
	void create_matrix()
	{
		for (int i = 0; i < numNode; i++)
		{
			matrix[i] = new int[numNode];
			for (int j = 0; j < numNode; j++)
			{
				cout << "Input matrix[" << i << "][" << j << "]: "; // ask user to input a data in 'matrix[i][j]'
				cin >> matrix[i][j]; // user have to input a weight in (numNode*numNode) times
			}
			cout << endl;
		}
	}
	void create_list()
	{
		int i = 0;
		for (list<NodeData>::iterator it = graph.begin(); it != graph.end(); it++) // iterate the graph
		{
			for (int j = 0; j < numNode; j++)
			{
				if (matrix[i][j] != 0) // just push a weighted 'Edges' into its list 'edge' EXCEPT: 0 (zero)
				{
					it->edges.push_back(matrix[i][j]);
					it->edges.back().edge = arrPtr_Graph[j]; // point that 'Edges' toward to the 'NodeData' that it connected with
				}
			}
			i++;
		}
	}
	void print_matrix()
	{
		cout << "-------------------------------\n\n";
		cout << "#### Adjacency matrix (array)\n\n";
		cout << "\t  ";
		for (int i = 0; i < numNode; i++)
		{
			cout << arrPtr_Graph[i]->data << " "; // print the first row headline: A B C ...
		}
		cout << endl;
		for (int i = 0; i < numNode; i++)
		{
			cout << "\t" << arrPtr_Graph[i]->data << " "; // print the first column: A B C ...
			for (int j = 0; j < numNode; j++)
			{
				cout << matrix[i][j]; // print all data in the adjacency matrix
				cout << " ";
			}
			cout << endl;
		}
	}
	void print_list()
	{
		cout << "\n-------------------------------\n\n";
		cout << "#### Adjacency linked list\n\n";
		for (int i = 0; i < numNode; i++) // iterate the graph
		{
			cout << "\t" << arrPtr_Graph[i]->data << " "; // print the name of each 'NodeData'
			for (list<Edges>::iterator it = arrPtr_Graph[i]->edges.begin(); it != arrPtr_Graph[i]->edges.end(); it++) // iterate the list 'edges'
			{
				cout << "[" << it->weight << "->" << it->edge->data << "] -> "; // print the list 'edges' of each 'NodeData'
			}
			cout << "|NULL|\n"; // the last node must point toward to NULL
		}
	}
	void check_graph()
	{
		status = false; // reset defalut 'status' to FALSE
		cout << "\n-------------------------------\n\n";
		cout << "#### Check the graph to answer;" << endl;

		cout << "\t1. Is it a multigraph?\t\t";
		cout << isMultigraph() << endl;

		cout << "\t2. Is it a pseudograph?\t\t";
		cout << isPseudograph() << endl;

		cout << "\t3. Is it a digraph?\t\t";
		cout << isDigraph() << endl;

		cout << "\t4. Is it a weighted graph?\t";
		cout << isWeightedgraph() << endl;

		cout << "\t5. Is it a complete graph?\t";
		cout << isCompletegraph() << endl;
	}
	bool isMultigraph()
	{
		status = false; // reset defalut 'status' to FALSE
		for (int i = 0; i < numNode; i++) // iterate the graph
		{
			for (list<Edges>::iterator it = arrPtr_Graph[i]->edges.begin(); it != arrPtr_Graph[i]->edges.end(); it++) // iterate the list 'edges'
			{
				list<Edges>::iterator tmp = it;
				for (list<Edges>::iterator it2 = ++tmp; it2 != arrPtr_Graph[i]->edges.end(); it2++)
				{
					if (it->edge == it2->edge)
					{
						status = true;
						break;
					}
				}
				if (status)
					break;
			}
			if (status)
				break;
		}
		return status;
	}
	bool isPseudograph()
	{
		status = false; // reset defalut 'status' to FALSE
		if (isMultigraph())
		{
			for (int i = 0; i < numNode; i++)
			{
				if (matrix[i][i] != 0)
				{
					status = true;
					break;
				}
			}
		}
		return status;
	}
	bool isDigraph()
	{
		status = false; // reset defalut 'status' to FALSE
		for (int i = 0; i < numNode; i++)
		{
			for (int j = 0; j < numNode; j++)
			{
				if (matrix[i][j] != matrix[j][i])
				{
					status = true;
					break;
				}
			}
			if (status)
				break;
		}
		return status;
	}
	bool isWeightedgraph()
	{
		status = false; // reset defalut 'status' to FALSE
		for (int i = 0; i < numNode; i++)
		{
			for (int j = 0; j < numNode; j++)
			{
				if (matrix[i][j] != 0)
				{
					status = true;
					break;
				}
			}
			if (status)
				break;
		}
		return status;
	}
	bool isCompletegraph()
	{
		status = true; // reset defalut 'status' to TURE
		for (int i = 0; i < numNode; i++)
		{
			for (int j = 0; j < numNode; j++)
			{
				if (matrix[i][j] == 0)
				{
					status = false;
					break;
				}
			}
			if (!status)
				break;
		}
		return status;
	}
	NodeData* ptr_graph(char el)
	{
		for (int i = 0; i < numNode; i++)
		{
			if (arrPtr_Graph[i]->data == el)
			{
				return arrPtr_Graph[i];
			}
		}
	}
	NodeData* ptr_path(char el)
	{
		for (int i = 0; i < numNode; i++)
		{
			if (arrPtr_Path[i]->data == el)
			{
				return arrPtr_Path[i];
			}
		}
	}
	void shortest_path(char el)
	{
		for (list<NodeData>::iterator it = path.begin(); it != path.end(); it++)
		{
			it->edges.push_back(Edges(0));
		}

		/*for (list<Edges>::iterator it = ptr_graph(el)->edges.begin(); it != ptr_graph(el)->edges.end(); it++)
		{
			ptr_path(it->edge->data)->edges.push_back(it->weight);
		}*/
		int count1 = 0;
		while (count1 < numNode)
		{
			int count2 = 0;
			list<Edges>::iterator it_tmp = ptr_graph(el)->edges.begin();
			while (count2 < numNode)
			{
				if (it_tmp->edge->data == arrPtr_Path[count2]->data)
				{
					arrPtr_Path[count2]->edges.push_back(Edges(it_tmp->weight));
					if (it_tmp != ptr_graph(el)->edges.end())
					{
						it_tmp++;
					}
				}
				else
				{
					arrPtr_Path[count2]->edges.push_back(Edges(0));
				}
				count2++;
			}
			count1++;
		}




		///////////////////////////////////////////////////////////////////////////////

		start from 'A'
			'A' // started node
			'C'.push(9)
			'D'.push(17)
			--->min(9C, 17D) = 9C;
		visit node 'C'
			'A' // started node
			'C' // v.ing
			'D'.push(17)
			'F'.push(9 + 12) // 21
			--->min(17D, 21F) = 17D;
		visit node 'D'
			'A' // started node
			'B'.push(17 + 11) // 28
			'C' // v.ed
			'D' // v.ing
			'E'.push(17 + 7) // 24
			'F'.push(21)
			--->min(28B, 24E, 21F) = 21F;
		visit node 'F'
			'A' // started node
			'B'.push(28)
			'C' // v.ed
			'D' // v.ed
			'E'.push(24)
			'F' // v.ing
			'G'.push(21 + 3) // 24
			--->min(28B, 24E, 24G) = 24E;
		visit node 'E'
			'A' // started node
			'B'.push(28)
			'C' // v.ed
			'D' // v.ed
			'E' // v.ing
			'F' // v.ed
			'G'.push(24) // 'G'.push(24 + 6) -- 30 > 24
			--->min(28B, 24G) = 24G;
		visit node 'G'
			'A' // started node
			'B'.push(28)
			'C' // v.ed
			'D' // v.ed
			'E' // v.ed
			'F' // v.ed
			'G' // v.ing
			'H'.push(24 + 5) // 29
			'I'.push(24 + 4) // 28
			--->min(28B, 29H, 28I) = 28B;
		visit node 'B'
			'A' // started node
			'B' // v.ing
			'C' // v.ed
			'D' // v.ed
			'E' // v.ed
			'F' // v.ed
			'G' // v.ed
			'H'.push(29)
			'I'.push(28)
			--->min(29H, 28I) = 28I;
		visit node 'I'
			'A' // started node
			'B' // v.ed
			'C' // v.ed
			'D' // v.ed
			'E' // v.ed
			'F' // v.ed
			'G' // v.ed
			'H'.push(29) // 'H'.push(28 + 3) -- 31 > 29
			'I' // v.ing
			--->min(29H) = 29H;
		visit node 'H'
			'A' // started node
			'B' // v.ed
			'C' // v.ed
			'D' // v.ed
			'E' // v.ed
			'F' // v.ed
			'G' // v.ed
			'H' // v.ing
			'I' // v.ed

		///////////////////////////////////////////////////////////////////////////////




		cout << "\n-------------------------------\n\n";
		cout << "#### Dijkstra's Algorithm\n\n";
		cout << "\tStarts from node: " << ptr_graph(el)->data;
		cout << "\n\n\tIteration\t\init";
		for (int i = 1; i <= numNode; i++)
		{
			cout << " " << i;
		}
		cout << "\n\tActive vertex\t    ";
		/*for (int i = 0; i < numNode; i++)
		{
			cout << " " << arrPtr_Graph[i]->data;
		}*/
		for (list<NodeData>::iterator it = path.begin(); it != path.end(); it++)
		{
			cout << "\n\t" << it->data << "\t\t  ";
			for (list<Edges>::iterator it2 = it->edges.begin(); it2 != it->edges.end(); it2++)
			{
				cout << " " << it2->weight;
			}
		}
	}

	int numNode;
	list<NodeData> graph;
	list<NodeData> path; // prepare for the dijkstra's algorithm
	int char_ascii = 65; // ini tialize char 'A' using ASCII = 65
	NodeData **arrPtr_Graph = new NodeData*[numNode]; // create an array to store pointers of each 'NodeData' in 'graph'
	NodeData **arrPtr_Path = new NodeData*[numNode]; // create an array to store pointers of each 'NodeData' in 'path'
	int **matrix = new int*[numNode]; // create two dimentional dynamic array of adjacency matrix (SIZE = numNode*numNode)
	bool status = false; // a 'status' to check & answer questions
};

#endif // Graph_H
