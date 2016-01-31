#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
 
int main() {
    int N, M, D;
    cin >> N >> M >> D;
    
     int crds[M];
 
    for (int i = 0; i < M; i++) {
        cin >> crds[i];
    }
 
    int j, k, hsh[N][D];
 
    for (j = 0; j < N; j++) {
 
        for (k = 0; k < D; k++) {
 
            cin >> hsh[j][k];
        } 
    }
 
    int l, u, r, c, chk[M][D], x, w, mid, le, ma, nj ;
    int it;
 
    for (u = 0; u < M; u++) {
 
        r = crds[u];
        x = 1;
 
        for (l = 0; l < D; l++) {
            x = 10*x; 
            it = (r%x)*10/x;
            w = D - (l+1);
            r = r - it;
            mid = it + (w*w*w*w);
            le = mid + ( (D-w)*(D-w)*(D-w)*(D-w) );
            ma = le * (D*D);
            nj = ((D - 3)*(D - 3));
            c = ma / nj ;
            chk[u][w] = c;
        }
    }
 
    int t, q, m;
    
 
    for (t = 0; t < N; t++) {
 
        for (q = 0; q < M; q++) {
            bool e;
            e = true;
            for (m = 0; m < D; m++) {
 
                e = (e && hsh[t][m] ==  chk[q][m]);
                //cout << hsh[t][m] << "\n" << chk[q][m] << "\n";
                if (e == false) {
                	break;
                }
            }
            if (e == true) {
                cout << crds[q] << "\n";
                break;
            }
            else {
                //cout << "fuk\n";
            }
 
            
        }
    }
 
 
 
 
 
 
 
 
 
}