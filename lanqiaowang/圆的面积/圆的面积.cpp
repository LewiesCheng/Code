#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main(){
	int r;
	cin>>r;
	double area = atan(1.0)*4*r*r;
	printf("%.7lf",area+0.00000005);
	return 0;
}
