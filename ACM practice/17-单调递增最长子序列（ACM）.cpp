#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>

using namespace std;

int Length(string str) {
	int n = str.size();
	int *max = (int *)malloc(n * sizeof(int));
	int maxLength = 0;

	for (int i = 0; i < n; i++) {
		max[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (str[i] > str[j] && max[i] < max[j] + 1){
				max[i] = max[j] + 1;
			}
		}
		if (maxLength < max[i]) {
			maxLength = max[i];
		}
	}
	return maxLength;
}

int main() {
	int N;
	cin >> N;
	int MaxLength[20];
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		MaxLength[i] = Length(s);
	}
	for (int i = 0; i < N; i++) {
		cout << MaxLength[i] << endl;
	}
	return 0;
}
