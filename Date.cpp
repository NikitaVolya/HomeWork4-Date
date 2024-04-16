#include "Date.h"


void Date::setDay(int pDay)
{
	if (pDay <= 0 || pDay > 31)
	{
		std::cout << "[ INFO ] Date: ivalide day number!\n";
		return;
	}
	day = pDay;
}

void Date::setMount(int pMounth)
{
	if (pMounth <= 0 || pMounth > 12)
	{
		std::cout << "[ INFO ] Date: ivalide mounth number!\n";
		return;
	}

	mounth = pMounth;
}

void Date::setYear(int pYear)
{
	if (pYear <= 0)
	{
		std::cout << "[ INFO ] Date: ivalide year number!\n";
		return;
	}

	year = pYear;
}

void Date::operator-=(int pDays)
{
	int tmpDay = (int)day - pDays;

	while (tmpDay < 1)
	{
		tmpDay = tmpDay + getMounthDaysNumber(mounth--, year);
		if (mounth < 1)
		{
			year--;
			mounth = 12;
		}
	}
	day = tmpDay;
}

void Date::operator+=(int pDays)
{
	int tmpDay = (int)day + pDays;

	while (getMounthDaysNumber(mounth, year) < tmpDay)
	{
		tmpDay = std::max(tmpDay - getMounthDaysNumber(mounth++, year), 1);
		if (mounth > 12)
		{
			year++;
			mounth = 1;
		}
	}

	day = tmpDay;
}

bool Date::operator==(const Date& other) const
{
	return day == other.day && mounth == other.mounth && year == other.year;
}

bool Date::operator!=(const Date& other) const
{
	return day != other.day || mounth != other.mounth || year != other.year;
}

unsigned int Date::toDays() const
{
	unsigned int days = 0;

	int currentYear = year - 1;
	int currentMounth = mounth - 1;

	for (; 0 < currentYear; currentYear--)
		if (LeapYear(currentYear))
			days += 366;
		else
			days += 365;

	for (; 0 < currentMounth; currentMounth--)
		days += getMounthDaysNumber(currentMounth, year);
		

	return days + day;
}

unsigned int Date::differenceInDays(const Date& other) const
{
	unsigned int first = toDays();
	unsigned int second = other.toDays();

	if (first > second)
		return first - second;
	else
		return second - first;
}

void Date::print() const
{
	if (day < 10) std::cout << "0";
	std::cout << day << " | ";
	if (mounth < 10) std::cout << "0";
	std::cout << mounth << " | " << year << std::endl;
}


int Date::getMounthDaysNumber(int pMount, int pYear)
{
	switch (pMount)
	{
		case 4: case 6: 
		case 9: case 11:
			return 30;
		case 1: case 3: 
		case 5: case 7: 
		case 8: case 10: 
		case 12:
			return 31;
		case 2:
			return LeapYear(pYear) ? 29 : 28;
	}

	return 0;
}
