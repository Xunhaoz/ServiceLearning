#include<iostream>
#include<queue>
using namespace std;
int arr[10] = {8, 7, 6, 5, 4, 3, 2, 1};
void mergeSortDevide(int, int);
void mergeSortMerge(int, int, int);
int main(){
    mergeSortDevide(0, 7);
    for(int i=0;i<=7;i++) cout << arr[i] << endl;
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
                arr[i] = tmpB.front();
                tmpB.pop();
            }
        }
    }

}
