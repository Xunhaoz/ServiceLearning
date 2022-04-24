#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<string> signs;
unordered_set<string> searchSet;

int main(){
    int m, ans = 0;
    cin >> m;

    for(int i=0;i<m;i++){
        string tmp;
        cin >> tmp;
        signs.push_back(tmp);
        searchSet.insert(tmp);
    }

    for(auto sign:signs){
        if(sign.size()<3) continue;
        for(int i=1;2*i<=sign.size();i++){
            if(sign.substr(0, i) == sign.substr(sign.size()-i, i)){
                ans += searchSet.count(sign.substr(i, sign.size()-i-i));
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
