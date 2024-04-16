#pragma once

#include <iostream>

class Date
{
private:
	unsigned short day : 5;
	unsigned short mounth : 4;
	unsigned short year;

public:
	Date(int pDay, int pMounth, int pYear) : day(1), mounth(1), year(1) 
	{ setDay(pDay); setMount(pMounth); setYear(pYear); };

	bool isLeapYear() const { return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); };

	int getDay() const { return day; }
	int getMounth() const { return mounth; }
	int getYear() const { return year; }

	void setDay(int pDay);
	void setMount(int pMounth);
	void setYear(int pYear);

	void operator-=(int pDays);
	void operator+=(int pDays);

	bool operator==(const Date& other) const;
	bool operator!=(const Date& other) const;

	unsigned int toDays() const;

	unsigned int differenceInDays(const Date& other) const;
	void print() const;

	static int getMounthDaysNumber(int pMount, int pYear);
	static bool LeapYear(int pYear) { return (pYear % 4 == 0 && pYear % 100 != 0) || (pYear % 400 == 0); };
};

