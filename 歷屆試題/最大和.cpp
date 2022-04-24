#include<iostream>
#include<vector>
using namespace std;
vector<int> sequence;
int main(){
    int N, M;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        int a = 0, b;
        for(int j=0;j<M;j++){
            cin >> b;
            a = max(a, b);
        }
        sequence.push_back(a);
    }

    int all = 0;
    for(auto i:sequence) all += i;
    cout << all << '\n';

    bool check = true;
    for(auto i:sequence){
        if(all % i ==0){
            if(!check) cout << " ";
            cout << i;
            check = false;
        }
    }

    if(check) cout << "-1";

    cout << endl;

    return 0;
}
