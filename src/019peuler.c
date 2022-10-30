#include <stdio.h>

int isLeapYear(unsigned int year){
	if(year % 4 == 0){
		if(year % 100 == 0){
			if(year % 400 == 0){
				return 1;
			}
			return 0;
		}
		return 1;
	}
	return 0;
}

int main(){
	unsigned int day = 1, weekday = 1, month = 1, year = 1900, count = 0;

	while(year < 2001){
		if(day == 1 && weekday == 7 && year >= 1901)
			count ++;

		weekday++;
		if(weekday == 8)
			weekday = 1;

		day++;
		if(day >= 29){
			if(day == 29 + isLeapYear(year) && month == 2){
				month ++;
				day = 1;
			}
			else if(day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)){
				month ++;
				day = 1;
			}
			else if(day == 32 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)){
				month ++;
				day = 1;
			}
			if(month == 13){
				month = 1;
				year ++;
			}
		}
	}
	printf("%d\n", count);
	return 0;
}
