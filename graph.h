#include <list>
using namespace std;

#ifndef Graph_H
#define Graph_H

// GLOBAL VARIABLES
int menu = 1;
int example = 1;
int numNode = 0;

void start()
{
	cout << "#### MENU LIST" << endl;
	cout << "1. Create your own graph" << endl;
	cout << "2. Create from examples" << endl << endl;

	do
	{
		cout << "Select menu item: ";
		cin >> menu;
	} while (menu != 1 && menu != 2);

	cout << "\n-------------------------------\n\n";

	if (menu == 1)
	{
		cout << "How many nodes: ";
		cin >> numNode;
		cout << endl;
	}
	else if (menu == 2)
	{
		cout << "Select example (1-5): ";
		cin >> example;
		cout << endl;

		if (example == 1)
			numNode = 5;
		else if (example == 2)
			numNode = 4;
		else if (example == 3)
			numNode = 5;
		else if (example == 4)
			numNode = 7;
		else if (example == 5)
			numNode = 9;
	}
}

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
	Edges();
	Edges(int w)
	{
		weight = w;
	}
	int weight = 0;
	NodeData *edge = NULL;
};

class Graph
{
public:
	Graph();
	Graph(int num)
	{
		numNode = num;
		char_ascii = 65; // ini tialize char 'A' using ASCII = 65
		arrPtr = new NodeData*[numNode]; // create an array to store pointers of each 'NodeData' i.e. A, B, C, ...
		matrix = new int*[numNode]; // create two dimentional dynamic array of adjacency matrix (SIZE = numNode*numNode)
		path = new float[numNode]; // store the latest cost (shortest path) of every nodes
		status = false; // a 'status' to check & answer questions
	}
	~Graph()
	{
		for (int i = 0; i < numNode; i++)
		{
			delete[] matrix[i];
		}
		delete[] arrPtr;
		delete[] matrix;
		delete[] path;
		arrPtr = NULL;
		matrix = NULL;
		path = NULL;
	}
	void init()
	{
		for (int i = 0; i < numNode; i++)
		{
			graph.push_back(char_ascii++); // push the 'NodeData' into the graph
			arrPtr[i] = &graph.back(); // keep its address to a temporary array called 'arrPtr'
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
	void create_matrix_withValue(int item)
	{
		for (int i = 0; i < numNode; i++)
		{
			matrix[i] = new int[numNode];
		}

		if (item == 1)
		{
			matrix[0][0] = 0;
			matrix[0][1] = 2;
			matrix[0][2] = 0;
			matrix[0][3] = 0;
			matrix[0][4] = 0;

			matrix[1][0] = 0;
			matrix[1][1] = 0;
			matrix[1][2] = 3;
			matrix[1][3] = 4;
			matrix[1][4] = 0;

			matrix[2][0] = 0;
			matrix[2][1] = 0;
			matrix[2][2] = 0;
			matrix[2][3] = 0;
			matrix[2][4] = 7;

			matrix[3][0] = 0;
			matrix[3][1] = 0;
			matrix[3][2] = 0;
			matrix[3][3] = 0;
			matrix[3][4] = 0;

			matrix[4][0] = 0;
			matrix[4][1] = 0;
			matrix[4][2] = 0;
			matrix[4][3] = 0;
			matrix[4][4] = 0;
		}

		/////////////////////////////////////////////////////////////

		else if (item == 2)
		{
			matrix[0][0] = 0;
			matrix[0][1] = 2;
			matrix[0][2] = 3;
			matrix[0][3] = 0;

			matrix[1][0] = 0;
			matrix[1][1] = 0;
			matrix[1][2] = 0;
			matrix[1][3] = 3;

			matrix[2][0] = 0;
			matrix[2][1] = 1;
			matrix[2][2] = 0;
			matrix[2][3] = 2;

			matrix[3][0] = 0;
			matrix[3][1] = 0;
			matrix[3][2] = 0;
			matrix[3][3] = 0;
		}

		/////////////////////////////////////////////////////////////

		else if (item == 3)
		{
			matrix[0][0] = 0;
			matrix[0][1] = 2;
			matrix[0][2] = 0;
			matrix[0][3] = 0;
			matrix[0][4] = 0;

			matrix[1][0] = 0;
			matrix[1][1] = 0;
			matrix[1][2] = 2;
			matrix[1][3] = 1;
			matrix[1][4] = 0;

			matrix[2][0] = 0;
			matrix[2][1] = 0;
			matrix[2][2] = 0;
			matrix[2][3] = 0;
			matrix[2][4] = 1;

			matrix[3][0] = 0;
			matrix[3][1] = 0;
			matrix[3][2] = 0;
			matrix[3][3] = 0;
			matrix[3][4] = 3;

			matrix[4][0] = 0;
			matrix[4][1] = 0;
			matrix[4][2] = 0;
			matrix[4][3] = 0;
			matrix[4][4] = 0;
		}

		/////////////////////////////////////////////////////////////

		else if (item == 4)
		{
			matrix[0][0] = 0;
			matrix[0][1] = 2;
			matrix[0][2] = 3;
			matrix[0][3] = 2;
			matrix[0][4] = 0;
			matrix[0][5] = 0;
			matrix[0][6] = 0;

			matrix[1][0] = 0;
			matrix[1][1] = 0;
			matrix[1][2] = 0;
			matrix[1][3] = 0;
			matrix[1][4] = 1;
			matrix[1][5] = 0;
			matrix[1][6] = 0;

			matrix[2][0] = 0;
			matrix[2][1] = 0;
			matrix[2][2] = 0;
			matrix[2][3] = 0;
			matrix[2][4] = 2;
			matrix[2][5] = 0;
			matrix[2][6] = 0;

			matrix[3][0] = 0;
			matrix[3][1] = 0;
			matrix[3][2] = 0;
			matrix[3][3] = 0;
			matrix[3][4] = 0;
			matrix[3][5] = 2;
			matrix[3][6] = 0;

			matrix[4][0] = 0;
			matrix[4][1] = 0;
			matrix[4][2] = 0;
			matrix[4][3] = 0;
			matrix[4][4] = 0;
			matrix[4][5] = 0;
			matrix[4][6] = 3;

			matrix[5][0] = 0;
			matrix[5][1] = 0;
			matrix[5][2] = 0;
			matrix[5][3] = 0;
			matrix[5][4] = 0;
			matrix[5][5] = 0;
			matrix[5][5] = 0;
			matrix[5][6] = 2;

			matrix[6][0] = 0;
			matrix[6][1] = 0;
			matrix[6][2] = 0;
			matrix[6][3] = 0;
			matrix[6][4] = 0;
			matrix[6][5] = 0;
			matrix[6][5] = 0;
			matrix[6][6] = 0;
		}

		/////////////////////////////////////////////////////////////

		else if (item == 5)
		{
			matrix[0][0] = 0;
			matrix[0][1] = 0;
			matrix[0][2] = 9;
			matrix[0][3] = 17;
			matrix[0][4] = 0;
			matrix[0][5] = 0;
			matrix[0][6] = 0;
			matrix[0][7] = 0;
			matrix[0][8] = 0;

			matrix[1][0] = 5;
			matrix[1][1] = 0;
			matrix[1][2] = 0;
			matrix[1][3] = 0;
			matrix[1][4] = 0;
			matrix[1][5] = 0;
			matrix[1][6] = 0;
			matrix[1][7] = 0;
			matrix[1][8] = 0;

			matrix[2][0] = 0;
			matrix[2][1] = 0;
			matrix[2][2] = 0;
			matrix[2][3] = 0;
			matrix[2][4] = 0;
			matrix[2][5] = 12;
			matrix[2][6] = 0;
			matrix[2][7] = 0;
			matrix[2][8] = 0;

			matrix[3][0] = 0;
			matrix[3][1] = 11;
			matrix[3][2] = 6;
			matrix[3][3] = 0;
			matrix[3][4] = 7;
			matrix[3][5] = 0;
			matrix[3][6] = 0;
			matrix[3][7] = 0;
			matrix[3][8] = 0;

			matrix[4][0] = 0;
			matrix[4][1] = 0;
			matrix[4][2] = 0;
			matrix[4][3] = 0;
			matrix[4][4] = 0;
			matrix[4][5] = 0;
			matrix[4][6] = 6;
			matrix[4][7] = 0;
			matrix[4][8] = 0;

			matrix[5][0] = 0;
			matrix[5][1] = 0;
			matrix[5][2] = 0;
			matrix[5][3] = 0;
			matrix[5][4] = 0;
			matrix[5][5] = 0;
			matrix[5][6] = 3;
			matrix[5][7] = 0;
			matrix[5][8] = 0;

			matrix[6][0] = 0;
			matrix[6][1] = 0;
			matrix[6][2] = 0;
			matrix[6][3] = 0;
			matrix[6][4] = 0;
			matrix[6][5] = 0;
			matrix[6][6] = 0;
			matrix[6][7] = 5;
			matrix[6][8] = 4;

			matrix[7][0] = 0;
			matrix[7][1] = 0;
			matrix[7][2] = 0;
			matrix[7][3] = 0;
			matrix[7][4] = 0;
			matrix[7][5] = 0;
			matrix[7][6] = 0;
			matrix[7][7] = 0;
			matrix[7][8] = 0;

			matrix[8][0] = 0;
			matrix[8][1] = 0;
			matrix[8][2] = 0;
			matrix[8][3] = 0;
			matrix[8][4] = 0;
			matrix[8][5] = 0;
			matrix[8][6] = 0;
			matrix[8][7] = 3;
			matrix[8][8] = 0;
		}

		/////////////////////////////////////////////////////////////

		for (int i = 0; i < numNode; i++)
		{
			for (int j = 0; j < numNode; j++)
			{
				cout << "Input matrix[" << i << "][" << j << "]: " << matrix[i][j] << endl;
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
					it->edges.back().edge = arrPtr[j]; // point that 'Edges' toward to the 'NodeData' that it connected with
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
			cout << arrPtr[i]->data << " "; // print the first row headline: A B C ...
		}
		cout << endl;
		for (int i = 0; i < numNode; i++)
		{
			cout << "\t" << arrPtr[i]->data << " "; // print the first column: A B C ...
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
			cout << "\t" << arrPtr[i]->data << " "; // print the name of each 'NodeData'
			for (list<Edges>::iterator it = arrPtr[i]->edges.begin(); it != arrPtr[i]->edges.end(); it++) // iterate the list 'edges'
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
			for (list<Edges>::iterator it = arrPtr[i]->edges.begin(); it != arrPtr[i]->edges.end(); it++) // iterate the list 'edges'
			{
				list<Edges>::iterator tmp = it;
				for (list<Edges>::iterator it2 = ++tmp; it2 != arrPtr[i]->edges.end(); it2++)
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
	NodeData* ptr_path(char el)
	{
		NodeData *tmp = NULL;
		for (int i = 0; i < numNode; i++)
		{
			if (arrPtr[i]->data == el)
			{
				tmp = arrPtr[i];
			}
		}
		return tmp;
	}
	int index_path(char el)
	{
		int index = 0;
		for (int i = 0; i < numNode; i++)
		{
			if (arrPtr[i]->data == el)
			{
				index = i;
				break;
			}
		}
		return index;
	}
	bool findInVisited(char el)
	{
		for (list<NodeData>::iterator it = visited.begin(); it != visited.end(); it++)
		{
			if (it->data == el)
			{
				return true;
			}
		}
		return false;
	}
	int indexOfMin()
	{
		bool firstTime = true;
		int min = INFINITY;
		int index = 0;
		for (int i = 0; i < numNode; i++)
		{
			if (!findInVisited(arrPtr[i]->data))
			{
				if (firstTime && (path[i] != INFINITY)) // The first, set 'min'
				{
					min = path[i];
					index = i;
					firstTime = false;
				}
				
				if (path[i] < min)
				{
					min = path[i];
					index = i;
				}
			}
		}
		return index;
	}
	void shortest_path()
	{
		char el;
		cout << "\n-------------------------------\n\n";
		cout << "#### Dijkstra's Algorithm\n\n";

		do
		{
			cout << "\tStarts from node: ";
			cin >> el;
			el = toupper(el);
		} while (ptr_path(el) == NULL);


		for (int i = 0; i < numNode; i++)
		{
			path[i] = INFINITY;
		}
		path[index_path(el)] = 0; // set distance of start node is zero

		visited.push_back(*ptr_path(el)); // visit start node first
		
		int i = index_path(el);
		for (int count = 0; count < numNode; count++)
		{
			for (int j = 0; j < numNode; j++)
			{
				if (!findInVisited(arrPtr[j]->data) && (matrix[i][j] != 0))
				{
					if ((path[i] + matrix[i][j]) < path[j])
					{
						path[j] = path[i] + matrix[i][j];
					}
				}
			}
			i = indexOfMin();
			visited.push_back(*ptr_path(arrPtr[i]->data));
			//cout << arrPtr[i]->data;
		}

		for (int i = 0; i < numNode; i++)
		{
			cout << "\t" << ptr_path(el)->data << " --> " << arrPtr[i]->data << " = " << path[i] << endl;
		}
	}

	int numNode;
	list<NodeData> graph;
	int char_ascii;
	NodeData **arrPtr;
	int **matrix;
	bool status;
	float *path;
	list<NodeData> visited; // keep visited nodes into the list
};

#endif // Graph_H
