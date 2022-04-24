#include<iostream>
using namespace std;
int main(){
    int n, D;
    int a[110] = {0}; // it is not neccessary but helping understand
    int holded = 0, sum = 0, status = 1;
    // 0 is empty 1 is stock

    cin >> n >> D;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i == 0){
            holded = a[i];
        }

        else if(a[i] >= holded+D && status == 1){
            sum += (a[i] - holded);
            holded = a[i];
            status = 0;
        }

        else if(a[i] <= holded-D && status == 0){
            holded = a[i];
            status = 1;
        }
    }

    cout << sum << '\n';

    return 0;
}
