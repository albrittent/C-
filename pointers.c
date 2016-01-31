#include <stdio.h>

int main(){
	int x = 0;
	printf("%d\n", x);
	int *p;
	p = &x; // p stores location of x
	/* dereferencing */
	*p = 1; // sets int stored at p to 1
	printf("%d\n", x);
}