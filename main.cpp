#include <iostream>

using namespace std;

struct Date {
 int year;
 int month;
 int day;
};

bool isleap(int year){
  
  if (year % 4 != 0){
    return false;
  }
  else {
    if (year % 100 != 0){
      return true;
    }
    else {
      if (year % 400 != 0){
        return false;
      }
      else{
        return true;
      }
    }
  }
}

int monthLength(int yearNum, int monthNum){
  int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31 ,30,31};
  if((monthNum > 13) || (monthNum < 1))
    return 0;
  else{
    if((isleap(yearNum)) && (monthNum == 2))
      return month[2] + 1;
    else
     return month[monthNum];
  }

}

int dayOfYear(Date date){
  int total = 0;
  for(int i = date.month - 1; i > 0; i--){
    total += monthLength(date.year, i);
  }
  total += date.day;
  return total;
}

int daysBetween(Date since, Date till) {
  int daysTill = 0, diffInYears;
  if((till.year < since.year) || (till.month < since.month) || (till.month == since.month && till.day < since.day)){
    return -1;
  }
  else{
    for(int i = since.year + 1; i < till.year; i++){  //till year -1 since+1
      if(isleap(i))                               //rhs =till add in day of year
        daysTill += 366;                          //lhs 365-dayOfYear(since)
      else
        daysTill += 365;
    }
    if(since.month != till.month){
      for(int m = since.month; m < till.month; m++){
        daysTill += monthLength(till.year, m);
      }
    }
    //daysTill += till.day - since.day;
    daysTill += dayOfYear(till);
    daysTill += 365-dayOfYear(since);
  }
  return daysTill;
}
// Note to self
// test case 2001 12 30 & 2016 12 31 off by one day

int main(void) {
 Date since,to;
 cout << "Enter first date (y m d): ";
 cin >> since.year >> since.month >> since.day;
 cout << "Enter second date (y m d): ";
 cin >> to.year >> to.month >> to.day;
 cout << daysBetween(since,to) << endl;
 return 0;
}