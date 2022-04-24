#include<iostream>
#include<vector>
#include<queue>
#define MatrixSize 5
using namespace std;
vector<int> graph[MatrixSize];
int ran[5] = {0};
queue<int> bfs;
int main(){
    //«Ø¹Ï
    graph[0].push_back(1);
    graph[0].push_back(4);
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[2].push_back(4);
    graph[3].push_back(1);
    graph[3].push_back(2);
    graph[3].push_back(4);
    graph[4].push_back(0);
    graph[4].push_back(2);
    graph[4].push_back(3);

    for(int i=0;i<MatrixSize;i++){
        cout << i+1 << ": ";
        for(auto j:graph[i])
            cout << j+1 << " ";
        cout << endl;
    }

    bfs.push(0);
    ran[0] = 1;

    while(!bfs.empty()){
        for(auto i:graph[bfs.front()]){
            if(ran[i] == 0){
                ran[i] = 1;
                bfs.push(i);
            }
        }
        cout << "\n[" << bfs.front()+1 << "]";
        bfs.pop();
    }

    return 0;
}
