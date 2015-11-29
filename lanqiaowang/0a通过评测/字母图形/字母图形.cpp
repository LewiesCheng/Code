#include<iostream>
using namespace std;

int main(){
	int n,m,temp = 0;
	cin>>n>>m;
	char elem = 'A';
	for(int i=1;i<=n;i++){
		elem = 'A' + i - 1;
		temp = 0;
		for(int j=1;j<=m;j++){
			if(elem=='A')
				temp = 1;
			if(temp){
				cout<<elem;
				elem += 1;
			}
			else{
				cout<<elem;
				elem -= 1;
			}
		}
		cout<<endl;
	}
	return 0;
}
