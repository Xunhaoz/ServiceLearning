#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<cstring>
#include<vector>
using namespace std;
int main(){
    //�I�ƶq�B��ƶq�B�_�l�I�B���I
    int nodeCount, edgeCount, node1, node2;
    cin >> nodeCount >> edgeCount;

    //�ŧi��C
    vector<int> nodeList[nodeCount];


    //�N��ƶ�J���
    for(int i=0;i<edgeCount;i++){
            cin >> node1 >> node2;
            node1--;
            node2--;
            nodeList[node1].push_back(node2);
    }

    //��ܪ��
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
