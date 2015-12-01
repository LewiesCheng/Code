/*
 *this is a information management system.
 */

#include <iostream>
#include <string>

struct men
{
	std::string name;
	std::string number;
	std::string mail;
	int password;
}people[100] =
{
	{ "zhangsan", "123456789", "123456789@qq.com", 111 },
	{ "lisi", "123456789", "123456789@yeat.com", 222 },
	{ "wangwu", "123456789", "123456789@gmail.com", 333 },
	{ "huangliu", "123456798", "123456789@163.com", 444 }
};

//void searchMember ( int length ) ---- C style
void searchMember(const int & length)
{
	std::cout << "input the name who you want to search: ";
	std::string name;
	std::cin >> name;
	for (int i = 0; i < length; i++)
	{
		if (people[i].name == name)
		{
			std::cout << "the name you want to search is exist\n";
			return;
		}
	}
	std::cout << "no this member in the array\n";
	return;
}

//void insertMember ( int & length ) -----this is a c++ style
void insertMember(int * length)
{
	if (*length < 1000)
	{
		std::cout << "if you want to insert a member in array, so you need give a location\n"\
			"tht locatioin is the index of  array\n";
		int location;
		std::cin >> location;
		while (location <= -1 || location >= 100 || location > (*length))
		{
			std::cout << "the value you input is more than the length of array\n"\
				", you need input a reasonable value for location\n"\
				"the location is the index of array\n";
			std::cin >> location;
		}
		int i;
		for (i = *length - 1; i >= location; i--)
		{
			people[i + 1] = people[i];
		}
		std::cout << "input the name, number, email, password you want insert, each input separate by Enter: ";
		std::cin >> people[i + 1].name >> people[i + 1].number >> people[i + 1].mail >> people[i + 1].password;
		std::cout << "now we insert the information you want to insert" << std::endl;
	}
	else
	{
		std::cout << "the array is full\n";
	}
}

void deleteMember(int * length)
{
	if (*length != 0)
	{
		std::cout << "if you want delete a member, but only know his location of array\n"\
			"you can input number 1. \nif you want delete a member, but only know his name\n"\
			"you can input number 2.\n";
		int sign = 0;
		std::cin >> sign;
		int location;
		std::string name;
		if (sign == 1)
		{
			std::cout << "input the location, you want delete: ";
			std::cin >> location;
			for (int i = location; i < *length; i++)
			{
				people[i] = people[i + 1];
			}
			(*length)--;
			std::cout << "now we delete it\n";
		}
		else if (sign == 2)
		{
			std::cout << "input the name, you want delete: ";
			std::cin >> name;
			for (int i = 0; i < *length; i++)
			{
				if (people[i].name == name)
				{
					if (i == *length)
					{
						(*length)--;
					}
					else
					{
						for (int j = i; j < *length; j++)
						{
							people[j] = people[j + 1];
						}
						(*length)--;
						return;
					}
				}
			}
		}
		else
		{
			std::cout << "you input number was wrong, we will do not delete\n";
		}
	}
	else
	{
		std::cout << "the array is empty, now\n";
	}
}


int main(int argc, const char * argv[])
{
	int length = 4; //initation length of array
	std::string search;
	while (1)
	{

		//list all the information
		std::cout << std::endl;
		for (int i = 0; i < length; i++)
		{
			std::cout << people[i].name << " "\
				<< people[i].number << " "\
				<< people[i].mail << std::endl;
		}
		std::cout << std::endl;

		//given the operate management
		std::cout << "\ninput \"search\" to search the member of array\n"\
			"input \"insert\" to insert a new member in the array\n"\
			"input \"delete\" to delete a memebr in the array\n";

		std::cin >> search;
		if (search == "search")
		{
			searchMember(length);//search may not change the value of length, wo we convey by value
		}
		else if (search == "insert")
		{
			insertMember(&length);//insert maybe change the value of length, so we convey by referencce
		}
		else if (search == "delete")
		{
			deleteMember(&length);//delete maybe change the value of length, so we convey by reference
		}
	}
	return 0;
}
