#include<iostream>
using namespace std;
int main(){
    string a = "��J�d�Ҥ@�G";

    a = a.substr(0, 2) + "�X" + a.substr(4, 11);
    cout << a;
    return 0;
}
