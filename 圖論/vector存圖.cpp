#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<cstring>
#include<vector>
using namespace std;
int main(){
    //點數量、邊數量、起始點、終點
    int nodeCount, edgeCount, node1, node2;
    cin >> nodeCount >> edgeCount;

    //宣告串列
    vector<int> nodeList[nodeCount];


    //將資料填入表格
    for(int i=0;i<edgeCount;i++){
            cin >> node1 >> node2;
            node1--;
            node2--;
            nodeList[node1].push_back(node2);
    }

    //顯示表格
    cout << "Matrix: " << '\n';
    for(int i=0;i<nodeCount;i++){
        cout << "List " << i+1 << ":";
        for(auto j:nodeList[i]){
            cout << setw(2) << j+1;
        }
        cout << '\n';
    }

    return 0;
}
