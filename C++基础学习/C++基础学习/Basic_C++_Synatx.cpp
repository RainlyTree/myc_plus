#include "Basic_C++_Synatx.h"

void textDate()
{
	Date d;
	d.SetDate(2019, 10, 22);
	d.Display();

	Date d2;
	d2.SetDate(2019, 10, 23);
	d2.Display();
}

int main()
{
	textDate();
	//system("pause");
	return 0;
}

