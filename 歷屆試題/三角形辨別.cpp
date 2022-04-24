#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t[3];
    for(int i=0;i<3;i++) cin >>t[i];

    sort(t, t+3);

    int a = t[0], b = t[1], c = t[2];

    for(int i=0;i<3;i++) cout << t[i] << " ";
    cout << endl;


    if(a + b < c) cout << "No" << endl;
    else if(a*a + b*b < c*c) cout << "Obtuse" << endl;
    else if(a*a + b*b == c*c) cout << "Right" << endl;
    else if(a*a + b*b > c*c) cout << "Acute" << endl;
    return 0;
}
