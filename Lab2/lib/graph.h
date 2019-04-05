//
// Created by vhundef on 05.04.19.
//

#ifndef UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_GRAPH_H
#define UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_GRAPH_H


class Graph {
public:
	void addEdge();
	void removeEdge();
	void addNode();
	void removeNode();
	void viewAdjacentVertex();
	void getIndexOfFirstVertexAdjToVertex();
	void getIndexOfNextVertexAdjToVertex();
	void checkIfVertexIsAdjToVertex();
	void wideSearch();
	void deepSearch();
	Graph(int);
	~Graph();

private:
	int **matrix= nullptr;

};


#endif //UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_GRAPH_H
