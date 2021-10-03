#include <iostream>
using namespace std;

struct TIME
{
  int seconds;
  int minutes;
  int hours;
};

void computeTimeDifference(struct TIME, struct TIME, struct TIME *);

int main()
{
    struct TIME T1, T2, difference;

    cout << "Enter start time." << endl;
    cout << "Enter hours, minutes and seconds respectively: ";
    cin >> T1.hours >> T1.minutes >> T1.seconds;

    cout << "Enter stop time." << endl;
    cout << "Enter hours, minutes and seconds respectively: ";
    cin >> T2.hours >> T2.minutes >> T2.seconds;

    computeTimeDifference(T1, T2, &difference);

    cout << endl << "TIME DIFFERENCE: " << T1.hours << ":" <<T1.minutes << ":" << T1.seconds;
    cout << " - " <<T2.hours << ":" << T2.minutes << ":" << T2.seconds;
    cout << " = " << difference.hours << ":" << difference.minutes << ":" << difference.seconds;
    return 0;
}
void computeTimeDifference(struct TIME T1, struct TIME T2, struct TIME *difference){
    
    if(T2.seconds > T1.seconds)
    {
        --T1.minutes;
        T1.seconds += 60;
    }

    difference->seconds = T1.seconds - T2.seconds;
    if(T2.minutes > T1.minutes)
    {
        --T1.hours;
        T1.minutes += 60;
    }
    difference->minutes = T1.minutes-T2.minutes;
    difference->hours = T1.hours-T2.hours;
}
