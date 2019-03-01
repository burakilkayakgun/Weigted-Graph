//
// Created by burak on 8.12.2018.
//

#ifndef PROJECT_4_GRAPH_H
#define PROJECT_4_GRAPH_H

#include<list>
#include <queue>
#include <iterator>

using namespace std;

struct Edge{
    int endNode =0;
    int weight =0;

    Edge(int e,int w){
        this->endNode = e;
        this->weight = w;
    }
};

typedef pair<int, list<Edge>> iVertices;

struct Comparator{
    bool operator()(const Edge left, const Edge right){
        return left.weight > right.weight;
    }
};

class WeightedGraph{
    int M,N;

public:
    iVertices *adj;
    WeightedGraph(int N,int M);
    void addHeight(int u, int w = 0);     // add an edge to graph
    void addUndirectedEdge(int u, int v, int w=0);     // add an undirected edge to graph
    ~WeightedGraph();
    int calculate(int s1, int s2, int t1,int t2);
};

#endif //PROJECT_4_GRAPH_H
