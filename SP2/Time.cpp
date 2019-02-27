#include "Time.h"
#include <iostream>
#include <iomanip>
using namespace std;

int Time::n_time = 0;

Time::Time(){
    hour = 0;
    minute = 0;
    second = 0;
    n_time++;
}

Time::Time(int _hour, int _minute, int _second){
    hour = _hour;
    minute = _minute;
    second = _second;
    n_time++;
}

Time::Time(const Time& T){
    hour = T.hour;
    minute = T.minute;
    second = T.second;
    n_time++;
}

Time::~Time(){
    n_time--;
}

void Time::setHour(int _hour){
    hour = _hour;
}
void Time::setMinute(int _minute){
    minute = _minute;
}
void Time::setSecond(int _second){
    second = _second;
}
int Time::getHour() const{
    return hour;
}
int Time::getMinute() const{
    return minute;
}
int Time::getSecond() const{
    return second;
}


int Time::countTimeInstance(){
    return n_time;
}


int Time::convertToSecond() const{
    return 3600*hour+60*minute+second;
}


void Time::printTime(){
    cout << setw(2) << setfill('0') << hour << ':' << setw(2) << setfill('0') << minute << ':' << setw(2) << setfill('0') << second << endl;
}

void Time::addTime(const Time& T){
    second += T.second;
    if (second >= 60){
        second -= 60;
        minute++;
    }
    minute += T.minute;
    if (minute >= 60){
        minute -= 60;
        hour++;
    }
    hour += T.hour;
    if (hour >= 24){
        hour -= 24;
    }
}
void Time::decreaseTime(const Time& T){
    if (!earlierThan(T)){
        second -= T.second;
        if (second < 0){
            second += 60;
            minute--;
        }
        minute -= T.minute;
        if (minute < 0){
            minute += 60;
            hour--;
        }
        hour -= T.hour;
    }
}
bool Time::earlierThan(const Time& T){
    return convertToSecond() < T.convertToSecond();
}
bool Time::laterThan(const Time& T){
    return convertToSecond() > T.convertToSecond();
}
