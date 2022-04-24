#include<iostream>
using namespace std;
int data[1000000];
int main(){
    int dataCase, pairNum = 0;
    cin >> dataCase;
    for(int i=0;i<dataCase;i++){
        cin >> data[i];
    }

    for(int i=0;i<dataCase;i++){
        for(int j=0;j<i;j++){
            if(data[i] < data[j]) pairNum++;
        }
    }

    cout << pairNum << endl;
    return 0;
}
