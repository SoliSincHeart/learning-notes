#include<iostream>


using namespace std;

enum class Weekend
{
	Sunday,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
};

string getWeekend(Weekend day)
{
	const string weekend[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	return weekend[static_cast<int>(day)];
}

int main()
{
	int num;
	cin>>num;
	Weekend day = static_cast<Weekend>(num);
	cout<<getWeekend(day)<<endl;
	return 0;
}