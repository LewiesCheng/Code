#include<iostream>
#include<cstdlib>

using namespace std;

int main(){
	int n;
	cin>>n;
	int *F = (int *)malloc(n*sizeof(int));
	F[0] = 1;
	F[1] = 1;
	int i = 0; 
	for(i=2;i<n;i++){
		F[i] = (F[i-1]%10007+F[i-2]%10007)%10007;
	}
	cout<<F[i-1];
	return 0;
}
