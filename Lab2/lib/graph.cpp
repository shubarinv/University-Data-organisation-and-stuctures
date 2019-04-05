//
// Created by vhundef on 05.04.19.
//

#include "graph.h"

Graph::~Graph() {
	delete matrix;
}

Graph::Graph(int vertexAmount) {
	matrix=new int *[vertexAmount];
	for (int i = 0; i <vertexAmount ; ++i) {
		matrix[i]=new int [vertexAmount];
	}
}

void Graph::deepSearch() {

}

void Graph::wideSearch() {

}

void Graph::viewAdjacentVertex() {

}

void Graph::removeNode() {

}

void Graph::addNode() {

}

void Graph::removeEdge() {

}

void Graph::addEdge() {

}

void Graph::checkIfVertexIsAdjToVertex() {

}
