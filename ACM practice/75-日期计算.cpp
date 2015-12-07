// DateCount.cpp 
// from NYOJ”Ô—‘»Î√≈ 

#include<iostream>
#include<cstdlib>
using namespace std;

struct MyStruct
{
	int year;
	int month;
	int day;
	int n;
};

int JudgeLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return 1;
	}
	else
		return 0;
}

int main()
{
	int N;
	cin >> N;
	struct MyStruct *date = (struct MyStruct *)malloc(N * sizeof(struct MyStruct));
	for (int i = 0; i < N; i++)
	{
		cin >> date[i].year >> date[i].month >> date[i].day;
	}
	for (int i = 0; i<N; i++)
	{
		date[i].n = date[i].day;
		switch (date[i].month-1)
		{
		case 12:date[i].n += 31;
		case 11:date[i].n += 30;
		case 10:date[i].n += 31;
		case 9:date[i].n += 30;
		case 8:date[i].n += 31;
		case 7:date[i].n += 31;
		case 6:date[i].n += 30;
		case 5:date[i].n += 31;
		case 4:date[i].n += 30;
		case 3:date[i].n += 31;
		case 2:if (JudgeLeapYear(date[i].year))
				   date[i].n += 29;
			   else
				   date[i].n += 28;
		case 1:date[i].n += 31;
		default:
			break;
		}
	}
	for (int i = 0; i<N; i++)
	{
		cout << date[i].n << endl;
	}
	
	return 0;
}
