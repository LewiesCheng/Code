#include<iostream>
#include<cstdlib>
using namespace std;

struct step{
	int m;
	int stepfoots; 
};

int main(){
	int n;
	cin >> n;
	int max = 0;
	struct step *s = (struct step *) malloc (n * sizeof(struct step));
	for(int i=0; i < n; i++){
		cin >> s[i].m;
		if(max < s[i].m)
			max = s[i].m;
	}	
	int *temp = (int *) malloc (max * sizeof(int));
	temp[0] = 0;
	temp[1] = 1;
	temp[2] = 2;
	for(int j=3; j<max; j++){
		temp[j] = temp[j-1] + temp[j-2];
	}	
	for(int i=0; i < n; i++){
		s[i].stepfoots = temp[s[i].m - 1];
		cout << s[i].stepfoots <<endl;
	}
	return 0;
} 
