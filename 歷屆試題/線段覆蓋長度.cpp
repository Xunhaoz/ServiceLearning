#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> segment;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first)
        return a.first < b.first;
    else
        return a.second > b.second;
}

int main(){
    long long int N, a, b, sum = 0;
    while(cin >> N){
        sum = 0;
        while(N--){
            cin >> a >> b;
            segment.push_back(make_pair(a, b));
        }

        sort(segment.begin(), segment.end(), cmp);

        //cout << endl;
        for(int i=0;i<segment.size();i++){
            //cout << segment[i].first << ' ' << segment[i].second << endl;
            sum += segment[i].second - segment[i].first;

            if(segment[i+1].second <= segment[i].second){
                segment[i+1].second = segment[i].second;
                segment[i+1].first = segment[i].second;
            }
            else if(segment[i+1].first <= segment[i].second)
                segment[i+1].first = segment[i].second;
        }
        cout << sum << endl;
        segment.clear();
    }

    return 0;
}
