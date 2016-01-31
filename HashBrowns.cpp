#include <iostream>
#include <string>

using namespace std;

int main() {
    
	int N, M, D;
	cin >> N >> M >> D;
	
	string crds[1000];
    
	for (int i = 0; i < M; i++) {
		cin >> crds[i];
	}
    
	string hsh[1000][20];
    

	for (int j = 0; j < N; j++) {

		for (int k = 0; k < D; k++) {

			cin >> hsh[j][k];
		} 
	}
    

    long int l, u, w, mid, le, ma, nj, oe;
	string chk[1000][20], c, it, r;

	for (u = 0; u < M; u++) {

		r = crds[u];

		for (l = 0; l < D; l++) {
			it = r[l];
			w = l;
			oe = stoi(it);
			mid = oe + (w*w*w*w);
			le = mid + ( (D-w)*(D-w)*(D-w)*(D-w) );
			ma = le * (D*D);
			nj = ((D - 3)*(D - 3));
			c = to_string(ma / nj) ;
			chk[u][w] = c;
		}
	}

	int t, q, m;
	
	for (t = 0; t < N; t++) {
        
		for (q = 0; q < M; q++) {
            
			bool e;
			e = true;
            
			for (m = 0; m < D; m++) {
                
				int sh, hk;
				sh = stoi(hsh[t][m]);
				hk = stoi(chk[q][m]);
				e = (e && sh == hk);
                
				if (e == false) {
					break;
				}
			}
			if (e == true) {
                
				cout << crds[q] << "\n";
				break;
			}
		}
	}
    return 0;
}