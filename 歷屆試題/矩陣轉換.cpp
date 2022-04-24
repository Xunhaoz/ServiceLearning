#include<iostream>
using namespace std;
int main(){
    int R, C, M, Mdata[100];
    int matrix[100][100];
    while(cin >> R >> C >> M){
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cin >> matrix[i][j];
            }
        }

        for(int i=M-1;i>=0;i--) cin >> Mdata[i];

        for(int i=0;i<M;i++){
            if(Mdata[i] == 0){
                int newMatrix[100][100] = {0};
                for(int i=0;i<R;i++){
                    for(int j=0;j<C;j++){
                        newMatrix[C-j-1][i] = matrix[i][j];
                    }
                }

                int tmp = R;
                R = C;
                C = tmp;

                for(int i=0;i<R;i++){
                    for(int j=0;j<C;j++){
                        matrix[i][j] = newMatrix[i][j];
                    }
                }
            }

            if(Mdata[i] == 1){
                for(int i=0;i<C;i++){
                    for(int j=0;j<(R+1)/2;j++){
                        int tmp = matrix[j][i];
                        matrix[j][i] = matrix[R-j-1][i];
                        matrix[R-j-1][i] = tmp;
                    }
                }
            }
        }

        cout << R << " " << C << endl;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cout << matrix[i][j];
                if(j != C-1) cout << ' ';
            }
            cout << endl;
        }

    }


    return 0;
}
