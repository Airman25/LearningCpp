#include <iostream >
using namespace std;
 
int main()
{   
    const int N = 7;
    int S[N][N];
    for (int i2=0; i2<N; i2++){
        for (int i=0; i<N; i++){
            S[i][i2] = (rand() % 80) + 10;
        }
    }
    for (int i2=0; i2<N; i2++){
        for (int i=0; i<N; i++){
            cout << S[i][i2] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int tmp, tmp2;
        /*
        tmp = S[4][1];
        S[4][1] = S[1][0];
        tmp2 = S[3][4];
        S[3][4] = tmp;
        tmp = S[0][3];
        S[0][3]= tmp2;
        S[1][0]=tmp;
        */
       /*
        tmp = S[3][1];
        S[3][1] = S[1][1];
        tmp2 = S[3][3];
        S[3][3] = tmp;
        tmp = S[1][3];
        S[1][3]= tmp2;
        S[1][1]=tmp;
        */
    for (int i2=0; i2<N/2;i2++){
        for (int i=0; i<N-1-i2*2;i++){
            tmp = S[N-1-i2][i+i2];
            S[N-1-i2][i+i2] = S[i+i2][i2];
            tmp2 = S[N-1-i2-i][N-1-i2];
            S[N-1-i2-i][N-1-i2] = tmp;
            tmp = S[i2][N-1-i2-i];
            S[i2][N-1-i2-i]= tmp2;
            S[i+i2][i2]=tmp;
        }
    }

    for (int i2=0; i2<N; i2++){
        for (int i=0; i<N; i++){
            cout << S[i][i2] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    /*
    for (int i=0; i<N; i++){
        for (int i2=0; i2<N; i2++){
            cout << S[i][N-1-i2] << " ";
        }
        cout << endl;
    }
    */
    system ("pause");
    return 0;
}
