// Program to show the principals of generating a 2D grid using the neighbours algorithm
// as described here: https://royvanrijn.com/blog/2019/01/longest-path/
#include <iostream>
#include <fstream>
#include "Graph.h"
#include "GraphArc.h"
#include "GraphNode.h"
#include "NodeData.h"



int main()
{
	/*
	// Construct a sample 5x5 grid - cells are numbered from 0 to 24.
	int const ROWS = 5;
	int const COLS = 5;
	int arr[ROWS][COLS] =
	{
		{ 0, 1, 2, 3, 4 },
		{ 5, 6, 7, 8, 9 },
		{ 10, 11, 12, 13, 14 },
		{ 15, 16, 17, 18, 19 },
		{ 20, 21, 22, 23, 24 }
	};

	// Let's see if we can find the neighbours of row 4 and column 4:
	int row = 4;
	int col = 4;

	// List all neighbors:
	for (int direction = 0; direction < 9; direction++) {
		if (direction == 4) continue; // Skip 4, this is ourself.

		int n_row = row + ((direction % 3) - 1); // Neighbor row
		int n_col = col + ((direction / 3) - 1); // Neighbor column

		// Check the bounds:
		if (n_row >= 0 && n_row < ROWS && n_col >= 0 && n_col < COLS) {

			// A valid neighbor:
			std::cout << "Neighbor: " << n_row << "," << n_col << ": " << arr[n_row][n_col] << std::endl;
		}
	}
	*/

	// Create a graph with capacity for 25 nodes.
	// Templates parameters are NodeType (std::string), ArcType (int)
	Graph<NodeData, int> graph(25);

	NodeData nodeData;
	int nodeIndex = 0;
	std::ifstream myfile;

	// Create each node, and assign a name (nodeLabel) from the text file and the position
	myfile.open("nodes.txt");
	while (myfile >> nodeData.m_name >> nodeData.xPos >> nodeData.yPos)
	{
		graph.addNode(nodeData, nodeIndex++);
	}
	myfile.close();

	// Wire up the graph by creating arcs between nodes.
	myfile.open("arcs.txt");
	int from, to, weight;
	while (myfile >> from >> to >> weight)
	{
		graph.addArc(from, to, weight);
	}
	myfile.close();



}