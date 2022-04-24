#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<cstring>
using namespace std;
int main(){
    //點數量、邊數量、起始點、終點
    int nodeCount, edgeCount, node1, node2;
    cin >> nodeCount >> edgeCount;
    
    //宣告矩陣
    int nodeTable[nodeCount][nodeCount];
    
    //陣列初始化
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            nodeTable[i][j] = 0;
        }
    }

    //將資料填入表格
    for(int i=0;i<edgeCount;i++){
            cin >> node1 >> node2;
            node1--;
            node2--;
            nodeTable[node1][node2] = 1;
    }

    //顯示表格
    cout << "Matrix: " << '\n';
    for(int i=0;i<nodeCount;i++){
        for(int j=0;j<nodeCount;j++){
            cout << setw(2) << nodeTable[i][j];
        }
        cout << '\n';
    }

    return 0;
}
