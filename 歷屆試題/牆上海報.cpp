#include<iostream>
using namespace std;

int h[200010], w[5010];

int main(){
    int n, k, r = 0, l= 1;
    cin >> n >> k;

    for(int i=1;i<=n;i++){
        cin >> h[i];
        r = max(r, h[i]);
    }
    r++;
    for(int i=1;i<=k;i++) cin >> w[i];

    while(r-l > 1){
        int mid = (l+r)/2;
        int cnt = 0, now = 1;
        bool flag = false;
        for(int i = 1;i<=n;i++){
            if(h[i] >= mid){
                cnt++;
                if(cnt >= w[now]){
                    cnt -= w[now];
                    if(now == k){
                        flag = true;
                        break;
                    }
                    now++;
                }
            }
            else cnt = 0;
        }
        if (flag) l = mid;
        else r = mid;
    }
    cout << l;
    return 0;
}
