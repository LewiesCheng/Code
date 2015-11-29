#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

int main(){
	int n;
	cin>>n;
	int *array = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		cin>>array[i];
	}
	sort(array,array+n);
	for(int i=0;i<n;i++){
		cout<<array[i];
		if(i<n-1)
			cout<<' ';
	}
	return 0;
}
