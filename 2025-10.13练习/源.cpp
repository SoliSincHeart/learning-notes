#include<iostream>
#include<string>
#include<ctime>
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
	time_t now = time(NULL);
	tm localnow;
	localtime_s(&localnow, &now);
	Weekend day = static_cast<Weekend>(localnow.tm_wday);
	cout<<getWeekend(day)<<endl;
	return 0;
}