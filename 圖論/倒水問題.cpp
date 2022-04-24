#include<bits/stdc++.h>
#define maxn 205
using namespace std;
int vis[maxn][maxn], ans[maxn], cap[4];
struct node{
    int cup[3], dump;
    bool operator< (const node& cmp) const{
        return dump > cmp.dump;
    }
};
priority_queue<node> q;

void init(){
    memset(vis, 0, sizeof(vis));
    memset(ans, -1, sizeof(ans));
    while(!q.empty()) q.pop();
    for(int i=0;i<4;i++) cin >> cap[i];
}

void bfs(){
    while(!q.empty()){
        node n = q.top();

        q.pop();
        vis[n.cup[0]][n.cup[1]] = 1;

        for(int i=0;i<3;i++){
            if(ans[n.cup[i]] < 0) ans[n.cup[i]] = n.dump;
        }

        if(ans[cap[3]] >= 0) break;

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){

                if(n.cup[i]==0 || n.cup[j]==cap[j] || i==j)
                    continue;
                //cout << i << " " << j << endl;
                int dumpCap = min(cap[j], n.cup[i]+n.cup[j]) - n.cup[j];

                //cout << dumpCap << endl;
                node tmp = n;
                tmp.dump += dumpCap;
                tmp.cup[i] -= dumpCap;
                tmp.cup[j] += dumpCap;

                if(vis[tmp.cup[0]][tmp.cup[1]] == 0) q.push(tmp);
            }
        }

    }
}

int main(){
    int testCase;
    cin >> testCase;

    while(testCase--){
        init();
        node n;
        n.cup[0] = 0; n.cup[1] = 0; n.cup[2] = cap[2]; n.dump = 0;
        vis[0][0] = 1;
        q.push(n);

        bfs();

        while(cap[3] >= 0){
            if(ans[cap[3]]>=0){
                cout << ans[cap[3]] << " " << cap[3] << '\n';
                break;
            }
            cap[3]--;
        }
    }

    return 0;
}
