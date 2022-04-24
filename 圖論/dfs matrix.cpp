#include<iostream>
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

//深度優先
void dfs(int);

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

    cout << "\noutput: ";
    dfs(1);

    return 0;
}
void dfs(int n){
    //實際數值比 index 多 1 記得減掉
    n = n-1;
    ran[n] = 1;
    for(int i=0;i<MatrixSize;i++){
        if(table[n][i]==1 && ran[i]==0)
            dfs(i+1);
    }
    cout << "\n[" << n+1 << "]";
}
