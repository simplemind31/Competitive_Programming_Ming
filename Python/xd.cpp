#include <bits/stdc++.h>
using namespace std;
int a;
void myFunction(function<int()> func) {
    cout << func();
    func();
}
namespace MyNamespace {
    int x = 42;
}
int main(){
    cout << MyNamespace::x;
    auto message = []() {
        cout << "Hello World!\n";
        return 1;
    };
    //myFunction(message);
    /*
    // Get the timestamp for the current date and time
    time_t timestamp;
    // time() sets a time and retunrs that time
    time(&timestamp);
    // or simply time_t timestamp = time(NULL);
    // Display the date and time represented by the timestamp

    //date time is just a kind of data structure
    struct tm datetime;
    datetime.tm_year = 2023 - 1900; // Number of years since 1900
    datetime.tm_mon = 12 - 1; // Number of months since January
    datetime.tm_mday = 17;
    datetime.tm_hour = 12;
    datetime.tm_min = 30;
    datetime.tm_sec = 1;
    // Daylight Savings must be specified
    // -1 uses the computer's timezone setting
    datetime.tm_isdst = -1;
    //mktime sets the structure and returns it as a time
    timestamp = mktime(&datetime);
    cout << ctime(&timestamp);
    cout << ctime(&timestamp);
    // ctime only displays a time and not the data sturcture
    struct tm datetime = *localtime(&timestamp);
    // localtime turns time to a data structure
    cout << asctime(&datetime);
    // asctime displays a data structure and not a time
    strftime(output, 50, "%B %e, %Y", &datetime);
    // set the time in the format you wish
    int diff = difftime(nextyear, now);
    // diff finds the number of seconds between to times and not sturcture
    */
}