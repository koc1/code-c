#include  <stdio.h>
int main()
{
	int m��1,n��2;
	int *p;
	int *q;
	int r;
	*p=& m;
	*q=& n;
	*r;
	r��p, p��q, q��r;
	printf("%d,%d,%d,%d\n",m,n,*p,*q);
}