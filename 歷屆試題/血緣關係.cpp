#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int> graph[100010];
set<int> isVisit;
int dfs(int, int);
int N, longestN=0, longestW=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> N){
        int f, s;
        for(int i=1;i<N;i++){
            cin >> f >> s;
            graph[f].push_back(s);
            graph[s].push_back(f);
        }

        isVisit.insert(0);
        dfs(0, 0);

        //init
        isVisit.clear();

        isVisit.insert(longestW);
        dfs(longestW, 0);

        cout << longestN << '\n';

        //init
        for(int i=0;i<N;i++) graph[i].clear();
        isVisit.clear();
        longestN = 0;
        longestW = 0;
    }


    return 0;
}

int dfs(int a, int level){

    if(level > longestN){
        longestN = level;
        longestW = a;
    }

    for(auto node:graph[a]){
        if(!isVisit.count(node)){
            isVisit.insert(node);
            dfs(node, level+1);
        }
    }
}
