#include "Date.h"


void Date::setDay(short pDay)
{
	if (pDay <= 0 || pDay > getMounthDaysNumber(mounth, year))
	{
		std::cout << "[ INFO ] Date: ivalide day number!\n";
		return;
	}
	day = pDay;
}

void Date::setMounth(short pMounth)
{
	if (pMounth <= 0 || pMounth > 12)
	{
		std::cout << "[ INFO ] Date: ivalide mounth number!\n";
		return;
	}

	mounth = pMounth;
}

void Date::setYear(short pYear)
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
		tmpDay = tmpDay - getMounthDaysNumber(mounth++, year);
		if (mounth > 12)
		{
			year++;
			mounth = 1;
		}
	}
	day = tmpDay;
}


const Date Date::operator-(int pDays)
{
	Date tmp(*this);
	tmp -= pDays;
	return tmp;
}

const Date Date::operator+(int pDays)
{
	Date tmp(*this);
	tmp += pDays;
	return tmp;
}


int Date::operator-(const Date& other)
{
	return differenceInDays(other);
}

bool Date::operator==(const Date& other) const
{
	return day == other.day && mounth == other.mounth && year == other.year;
}

bool Date::operator!=(const Date& other) const
{
	return day != other.day || mounth != other.mounth || year != other.year;
}

const Date& Date::operator++()
{
	int tmpDay = (int)day + 1;

	if (tmpDay > getMounthDaysNumber(mounth, year))
		tmpDay -= getMounthDaysNumber(mounth++, year);

	if (mounth > 12)
	{
		year = year + 1;
		mounth = 1;
	}

	day = tmpDay;

	return *this;
}

const Date Date::operator++(int)
{
	Date tmp(*this);
	++(*this);
	return tmp;
}

const Date& Date::operator--()
{
	--day;

	if (day == 0)
	{
		if (--mounth == 0)
		{
			mounth = 12;
			year--;
		}
		day = getMounthDaysNumber(mounth, year);
	}
	
	return *this;
}

const Date Date::operator--(int)
{
	Date tmp(*this);
	--(*this);
	return tmp;
}

unsigned int Date::toDays() const
{
	unsigned int days = 0;

	for (int currentYear = year - 1; 0 < currentYear; currentYear--)
		if (LeapYear(currentYear))
			days += 366;
		else
			days += 365;

	for (int currentMounth = mounth - 1; 0 < currentMounth; currentMounth--)
		days += getMounthDaysNumber(currentMounth, year);
		

	return days + day;
}

int Date::differenceInDays(const Date& other) const
{
	unsigned int first = toDays();
	unsigned int second = other.toDays();

	if (first > second)
		return (int)(first - second);
	else
		return -(int)(second - first);
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
