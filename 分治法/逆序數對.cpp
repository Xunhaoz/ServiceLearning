#include<iostream>
#include<queue>
using namespace std;
int arr[1000000], pairNum = 0;
void mergeSortDevide(int, int);
void mergeSortMerge(int, int, int);
int main(){
    int testCase, dataCase;
    testCase = 1;
    while(testCase--){
        pairNum = 0;
        cin >> dataCase;
        for(int i=0;i<dataCase;i++) cin >> arr[i];
        mergeSortDevide(0, dataCase-1);
        cout << pairNum << endl;

    }
    return 0;
}
void mergeSortDevide(int a, int b){
    if(a < b){
        int mid = (a+b)/2;
        mergeSortDevide(a, mid);
        mergeSortDevide(mid+1, b);
        mergeSortMerge(a, mid, b);
    }
}
void mergeSortMerge(int a, int mid, int b){
    queue<int> tmpA;
    queue<int> tmpB;
    for(int i=a;i<=mid;i++) tmpA.push(arr[i]);
    for(int i=mid+1;i<=b;i++) tmpB.push(arr[i]);

    for(int i=a;i<=b;i++){
        if(tmpA.empty()){
            pairNum += tmpA.size();
            arr[i] = tmpB.front();
            tmpB.pop();
        }
        else if(tmpB.empty()){
            arr[i] = tmpA.front();
            tmpA.pop();
        }
        else{
            if(tmpA.front() <= tmpB.front()){
                arr[i] = tmpA.front();
                tmpA.pop();
            }
            else{
                pairNum += tmpA.size();
                arr[i] = tmpB.front();
                tmpB.pop();
            }
        }
    }

}
