#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
#include <cmath>
#include <string>
#include "WeightedGraph.h"

using namespace std;

template <class Container>
void split(const string& str, Container& cont)
{
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);

    if (argc != 3) {
        cout << "Run the code with the following command: ./project4 [input_file] [output_file]" << endl;
        return 1;
    }

    ifstream infile(argv[1]);
    string line;
    // process first line
    getline(infile,line);
    vector<string> firstLine;
    split(line,firstLine);
    int N = stoi(firstLine[0]);
    int M = stoi(firstLine[1]);

    WeightedGraph GridLand(N,M);

    for(int i=0;i<N;i++){
        getline(infile, line);
        vector<string> nums;
        split(line,nums);
        for(int j=0;j<M;j++){
            GridLand.addHeight(i*N+j,stoi(nums[j]));
        }
    }

    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            if(j==0){
                if(i==0) {
                    GridLand.addUndirectedEdge(0, 1, abs(GridLand.adj[0].first - GridLand.adj[1].first));
                    GridLand.addUndirectedEdge(0, N, abs(GridLand.adj[0].first - GridLand.adj[N].first));
                }else if(i>0 && i<N-1){
                    GridLand.addUndirectedEdge(i*N,i*N-N,abs(GridLand.adj[i*N].first - GridLand.adj[i*N-N].first));
                    GridLand.addUndirectedEdge(i*N,i*N+N,abs(GridLand.adj[i*N].first - GridLand.adj[i*N+N].first));
                    GridLand.addUndirectedEdge(i*N,i*N+1,abs(GridLand.adj[i*N].first - GridLand.adj[i*N+1].first));
                }else if(i==N-1){
                    GridLand.addUndirectedEdge(i*N,i*N-N,abs(GridLand.adj[i*N].first - GridLand.adj[i*N-N].first));
                    GridLand.addUndirectedEdge(i*N,i*N+1,abs(GridLand.adj[i*N].first - GridLand.adj[i*N+1].first));
                }
            }else if(j>0 && j<M-1){
                if(i==0) {
                    GridLand.addUndirectedEdge(j,j-1,abs(GridLand.adj[j].first - GridLand.adj[j-1].first));
                    GridLand.addUndirectedEdge(j,j+1,abs(GridLand.adj[j].first - GridLand.adj[j+1].first));
                    GridLand.addUndirectedEdge(j,N+j,abs(GridLand.adj[j].first - GridLand.adj[N+j].first));
                }else if(i>0 && i<N-1){
                    GridLand.addUndirectedEdge(i*N+j,i*N+j+1,abs(GridLand.adj[i*N+j].first - GridLand.adj[i*N+j+1].first));
                    GridLand.addUndirectedEdge(i*N+j,i*N+j-1,abs(GridLand.adj[i*N+j].first - GridLand.adj[i*N+j-1].first));
                    GridLand.addUndirectedEdge(i*N+j,i*N-N+j,abs(GridLand.adj[i*N+j].first - GridLand.adj[i*N-N+j].first));
                    GridLand.addUndirectedEdge(i*N+j,i*N+N+j,abs(GridLand.adj[i*N+j].first - GridLand.adj[i*N+N+j].first));
                }else if(i==N-1){
                    GridLand.addUndirectedEdge(i*N+j,i*N+j+1,abs(GridLand.adj[i*N+j].first - GridLand.adj[i*N+j+1].first));
                    GridLand.addUndirectedEdge(i*N+j,i*N+j-1,abs(GridLand.adj[i*N+j].first - GridLand.adj[i*N+j-1].first));
                    GridLand.addUndirectedEdge(i*N+j,i*N-N+j,abs(GridLand.adj[i*N+j].first - GridLand.adj[i*N-N+j].first));
                }
            }else if (j==M-1){
                if(i==0){
                    GridLand.addUndirectedEdge(j,j-1,abs(GridLand.adj[j].first - GridLand.adj[j-1].first));
                    GridLand.addUndirectedEdge(j,N+j,abs(GridLand.adj[j].first - GridLand.adj[N+j].first));
                }else if(i>0 && i<N-1){
                    GridLand.addUndirectedEdge(i*N+j,i*N+j-1,abs(GridLand.adj[i*N+j].first - GridLand.adj[i*N+j-1].first));
                    GridLand.addUndirectedEdge(i*N+j,i*N-N+j,abs(GridLand.adj[i*N+j].first - GridLand.adj[i*N-N+j].first));
                    GridLand.addUndirectedEdge(i*N+j,i*N+N+j,abs(GridLand.adj[i*N+j].first - GridLand.adj[i*N+N+j].first));
                }else if(i==N-1){
                    GridLand.addUndirectedEdge(i*N+j,i*N+j-1,abs(GridLand.adj[i*N+j].first - GridLand.adj[i*N+j-1].first));
                    GridLand.addUndirectedEdge(i*N+j,i*N-N+j,abs(GridLand.adj[i*N+j].first - GridLand.adj[i*N-N+j].first));
                }
            }
        }
    }

    getline(infile,line);
    int Q = stoi(line);
    vector<int> result;
    result.resize(Q);
    int s1;
    int s2;
    int t1;
    int t2;
    for (int i = 0 ;i<Q ;++i){
        getline(infile,line);
        vector<string> index;
        split(line,index);
        s1 = stoi(index[0]);
        s2 = stoi(index[1]);
        t1 = stoi(index[2]);
        t2 = stoi(index[3]);
        result[i] = GridLand.calculate(s1,s2,t1,t2);
    }
    infile.close();

    ofstream myfile;
    myfile.open (argv[2]);
    for(int i=0;i<Q;++i){
        myfile << result[i] << endl;
    }
    myfile.close();
}