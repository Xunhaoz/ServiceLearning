#include<iostream>
#include<queue>
#define MatrixSize 5
using namespace std;

//矩陣存圖
int table[MatrixSize][MatrixSize] = {
       /*1  2  3  4  5*/
        {0, 1, 0, 0, 1},//1
        {1, 0, 1, 1, 0},//2
        {0, 1, 0, 1, 1},//3
        {0, 1, 1, 0, 1},//4
        {1, 0, 1, 1, 0},//5
};
//紀錄已拜訪點
int ran[5] = {0};
queue<int> bfs;

int main(){

    //輸出看看
    cout << "  ";
    for(int j=1;j<=MatrixSize;j++) cout << j << " ";
    cout << endl;
    for(int i=0;i<MatrixSize;i++){
        cout << i+1 << " ";
        for(int j=0;j<MatrixSize;j++){
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    bfs.push(0);
    ran[0] = 1;

    while(!bfs.empty()){
        for(int i=0;i<MatrixSize;i++){
            if(ran[i] == 0 && table[bfs.front()][i]){
                ran[i] = 1;
                bfs.push(i);
            }
        }
        cout << "\n[" << bfs.front()+1 << "]";
        bfs.pop();
    }

    return 0;
}
