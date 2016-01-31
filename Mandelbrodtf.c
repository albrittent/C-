#include <stdio.h>
#include <math.h>
#include <complex.h>

int main() {
	int N, M;
	printf("\nEnter two integers separated by a space\n");
	scanf("%d %d", &N, &M);
	char mdl[N][M];
	int i, j, k, l, m;
	double x, y;
	double _Complex z, c;


	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			z = 0.0;
			x = i;
			y = j;
			c = (((x/N)*3.5) - 2.5) + 2 * _Complex_I *((y/M) - 0.5);
			for (k = 0; k < 500; k++) {
				z = (z*z) + c;
			}
			if ((sqrt(z * conj(z))) < 2) {
				/*printf("%f", z);*/
				mdl[j][i] = '*';
				/*puts("check");*/
			} else {
				mdl[j][i] = ' ';
				/*puts("eh");*/
			}
		}
	}
	for (l = 0; l < M; l++) {
        for (m = 0; m < N; m++) {
            printf("%c ", mdl[m][l]);
        }
        printf("\n");
    }	
}
	


