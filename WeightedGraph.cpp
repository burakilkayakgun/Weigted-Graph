//
// Created by burak on 8.12.2018.
//

#include "WeightedGraph.h"

WeightedGraph::WeightedGraph(int N, int M) {
    this->M=M;
    this->N=N;
    adj = new iVertices [N*M];
}

void WeightedGraph::addUndirectedEdge(int u, int v, int w) {
    Edge temp(u,w);
    Edge temp2(v,w);
    adj[u].second.push_back(temp2);
    adj[v].second.push_back(temp);
}

void WeightedGraph::addHeight(int u, int w) {
    adj[u].first = w;
}

int WeightedGraph::calculate(int s1, int s2, int t1, int t2) {

    priority_queue<Edge,vector<Edge>,Comparator> edge_queue;
    vector<bool> visited(N * M, false);
    int ladder = 0;

    list<Edge>::iterator itr;
    for(itr = adj[(s1-1)*N+(s2-1)].second.begin();itr != adj[(s1-1)*N+(s2-1)].second.end();++itr){
        edge_queue.push(*itr);
    }
    visited[(s1-1)*N+(s2-1)] = true;

    while( !visited[(t1-1)*N+(t2-1)] ){
        Edge curr_edge = edge_queue.top();
        int curr_edge_index = curr_edge.endNode;
        int edge_weight = curr_edge.weight;
        edge_queue.pop();
        if( !visited[curr_edge_index] ){
            visited[curr_edge_index] = true;
            ladder = max(ladder,edge_weight);

            list<Edge>::iterator it;
            for(it = adj[curr_edge_index].second.begin() ;it !=adj[curr_edge_index].second.end();++it) {
                if (!visited[it->endNode]) {
                    edge_queue.push(*it);
                }
            }
        }
    }
    return ladder;
}

WeightedGraph::~WeightedGraph() {

    delete [] adj;
}