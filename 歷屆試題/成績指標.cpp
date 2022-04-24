#include<iostream>
#include<algorithm>
using namespace std;

int n, data[30], BC = 101, WC = -1;
int main(){
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> data[i];
        if(data[i]<BC && data[i]>=60) BC = data[i];
        else if(data[i]>WC && data[i]<60) WC = data[i];
    }
    sort(data, data+n);
    for(int i=0;i<n;i++) cout << data[i] << " ";
    cout << endl;

    if(WC!=-1) cout << WC;
    else cout << "best case";
    cout << endl;

    if(BC!=101) cout << BC;
    else cout << "worst case";
    cout << endl;

    return 0;
}
