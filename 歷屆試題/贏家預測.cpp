#include<iostream>
#include<vector>
using namespace std;
struct player{
    int lose;
    long long int attack;
    long long int react;
};

vector<int> order, win, lose;
int n, m;
player players[1010];


int main(){
    //init
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> players[i].attack;
        players[i].lose = 0;
    }
    for(int i=1;i<=n;i++){
        cin >> players[i].react;
    }
    for(int i=1;i<=n;i++){
        int tmp;
        cin >> tmp;
        order.push_back(tmp);
    }

    while(order.size() > 1){

        for(int i=0;i<order.size()-1;i+=2){


            int x = order[i], y = order[i+1];
            long long int a = players[x].attack, b = players[x].react, c = players[y].attack, d = players[y].react;

            if(a*b >= c*d){
                win.push_back(x);
                players[x].attack = a + c*d/(2*b);
                players[x].react = b + c*d/(2*a);
                players[y].lose += 1;

                if(players[y].lose < m){
                    lose.push_back(y);
                    players[y].attack = c + c/2;
                    players[y].react = d + d/2;
                }
            }
            else{
                win.push_back(y);
                players[y].attack = c + a*b/(2*d);
                players[y].react = d + a*b/(2*c);
                players[x].lose += 1;

                if(players[x].lose < m){
                    lose.push_back(x);
                    players[x].attack = a + a/2;
                    players[x].react = b + b/2;
                }
            }
        }

        if(order.size()%2 == 1){
                    win.push_back(order.back());
        }

        /*
        cout << "order: ";
        for(auto i:order) cout << i << " ";
        cout << endl << "win: ";
        for(auto i:win) cout << i << " ";
        cout << endl << "lose: ";
        for(auto i:lose) cout << i << " ";
        cout << endl;
        */
        order = win;
        for(auto i:lose) order.push_back(i);
        win.clear();
        lose.clear();

    }

    cout << order[0] << endl;

    return 0;
}
