#include<bits/stdc++.h>
using namespace std;

long long divide(vector<int> data, int floor, int top){

    //for(auto i : data) cout << i << " ";
    //cout << endl;

    if(data.size() <= 2) return 0;

    vector<int> small, big;
    set<int> between;
    int mid = (floor+top)/2;
    long long ans = 0;
    for(auto i:data){
        if(i <= mid){
            ans += between.size();
            small.push_back(i);
        }
        else{
            if(!between.count(i)){
                between.insert(i);
            }
            else{
                between.erase(i);
            }
            big.push_back(i);
        }
    }

    ans += divide(small, floor, mid);
    ans += divide(big, mid+1, top);
    return ans;
}
int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    vector<int> data;
    int n, tmp;
    cin >> n;

    for(int i=0;i<2*n;i++){
        cin >> tmp;
        data.push_back(tmp);
    }

    cout << divide(data, 1, n) << endl;
}
