#include<iostream>
#include<vector>
#define MatrixSize 5
using namespace std;
vector<int> graph[MatrixSize];
int dfs(int);
int ran[MatrixSize] = {0};
int main(){
    //¦s¹Ï
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

    dfs(0);
    return 0;
}

int dfs(int n){
    ran[n] = 1;
    for(auto i:graph[n]){
        if(ran[i]==0)
            dfs(i);
    }
    cout << "\n[" << n+1 << "]";
}
