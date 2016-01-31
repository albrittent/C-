#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;


int main()
{

	class Race {
		public:
			int num_cows;
			int races;
			int trk;
			int num_lanes;
			int cows[100000][5];

			Race(int N, int M, int L) {
				num_cows = 0;
				races = N;
				trk = M;
				num_lanes = L;
			}
			void addcow(int name, double lane, long double times, long int laps) {
				double speed;
				this->num_cows = (num_cows + 1);
				this->cows[num_cows][1] = name;
				this->cows[num_cows][2] = lane*laps;
				this->cows[num_cows][3] = times;
				speed = lane/times;
				this->cows[num_cows][4] = speed;
			}

			int get_num_cows() {
				return num_cows;
			}

			int get_winner() {
				int wins[num_cows][2], iter;
				int h, nme, tme, onme, otme, max, omax;
				iter = 0;
				nme = this->cows[1][1];
				tme = this->cows[1][4];
				for (h = 1; h < num_cows; h++) {
					onme = cows[h+1][1];
					otme = cows[h+1][4];
					if (otme - tme > -0.000001) {
						nme = onme;
						tme = otme;
					}
					else if (0.000001 > otme - tme > -0.000001) {
                        wins[iter][0] = otme;
                        wins[iter][1] = onme;
						iter += 1;
					}
					wins[0] = max;
					cout << max << "\n";
					for (int a = 1; a < iter; a++) {
						wins[a] = omax;
						cout << omax << "\n" ;
						if (omax > max) {
							max = omax;
						}
					}
				}
				return nme;
			}
	};
	
	int N, M, L;
	cin >> N >> M >> L;

	Race I(N, M, L);

	int i;

	for (i = 0; i < N; i++) {
		int B, R, j, k;
		cin >> B >> R;

		for (j = 0; j < B; j++) {
			int K;
			cin >> K;
			double t;
			t = 0.0;
		
			for (k = 0; k < R; k++) {
				double s;
				cin >> s;
				t += s;
			}
		int len;
		len = M*(10+j);

		I.addcow(K, len, t, R);

		}
	}
	int win;
	win = I.get_winner();
	cout << win << "\n";
}

		

	







