// Eric Singleterry
// CS - 210 Project One
// 7/18/2021


#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

class GetTime {
public:
    int hour;
    int minute;
    int seconds;
};

class Clock12 :public GetTime { //Retrieve and Display UTC 12 Hour Format
public:
    string meridiem; //Establish ante and post meridiem
    Clock12() {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        hour = ltm->tm_hour;
        minute = ltm->tm_min;
        seconds = ltm->tm_sec;
        if (hour >= 12) {
            meridiem = "PM";
            hour -= 12;
        }
        else
            meridiem = "AM";

    }
    void add_hour(int h) { //user adds one hour to 12 hour format
        hour += h;
        if (hour > 12) {
            hour -= 12;
        }
        else if (hour >= 12)
        {
            if (meridiem == "AM") {
                meridiem = "PM";
            }
            else if (meridiem == "PM") {
                meridiem = "AM";
            }
        }

    }

    void add_minute(int min) { //user adds one minute to 12 hour format
        minute += min;
        if (minute >= 0) {
            int h = minute / 60;
            minute -= 60 * h;
            add_hour(h);
        }
    }

    void add_seconds(int sec) { //user adds one second to 12 hour format
        seconds += sec;
        if (seconds >= 60) {
            int m = seconds / 60;
            seconds -= 60 * m;
            add_minute(m);
        }
    }
};

class Clock24 :public GetTime { //Retrieve and Display UTC 24 Hour Format
public:
    int hour;
    int minute;
    int seconds;

    Clock24() {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        hour = ltm->tm_hour;
        minute = ltm->tm_min;
        seconds = ltm->tm_sec;
    }

    void add_hour(int h) { //user adds one hour to 24 hour format
        hour += h;
        if (hour >= 24) {
            hour -= 24;
        }
    }

    void add_minute(int min) { //user adds one minute to 24 hour format
        minute += min;
        if (minute >= 60) {
            int h = minute / 60;
            minute -= 60 * h;
            add_hour(h);
        }
    }

    void add_seconds(int sec) { //user adds one second to 24 hour format
        seconds += sec;
        if (seconds >= 60) {
            int m = seconds / 60;
            seconds -= 60 * m;
            add_minute(m);
        }
    }
};

void display(Clock12 c1, Clock24 c2) { //Display both formats in UTC in a "Dashboard"
    cout << "**************************\t\t";
    cout << "**************************" << endl;
    cout << "*\t12-Hour Clock\t *\t\t";
    cout << "*\t24-Hour Clock\t *" << endl;
    cout << "*\t" << setw(2) << setfill('0') << c1.hour << ":" << setw(2) << setfill('0') << c1.minute << ":" << setw(2) << setfill('0') << c1.seconds << " " << c1.meridiem << "\t *\t\t";
    cout << "*\t" << setw(2) << setfill('0') << c2.hour << ":" << setw(2) << setfill('0') << c2.minute << ":" << setw(2) << setfill('0') << c2.seconds << "\t *" << endl;
    cout << "**************************\t\t";
    cout << "**************************" << endl;
}

int main() { //Display user options to add time to Hours, Minutes or Seconds in a "Dashboard"
    Clock12 c1;
    Clock24 c2;
    display(c1, c2);
    int choice = 0;
    while (choice != 4) {
        cout << endl;
        cout << "\t\t    **************************" << endl; // Added \t and spaces to make user "Dashboard" centered with Clock "Dashboard"
        cout << "\t\t    * 1 - Add One Hour\t     *" << endl;
        cout << "\t\t    * 2 - Add One Minute     *" << endl;
        cout << "\t\t    * 3 - Add One Second     *" << endl;
        cout << "\t\t    * 4 - Exit Program\t     *" << endl;
        cout << "\t\t    **************************" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1: c1.add_hour(1);
            c2.add_hour(1);
            break;

        case 2: c1.add_minute(1);
            c2.add_minute(1);
            break;

        case 3: c1.add_seconds(1);
            c2.add_seconds(1);
            break;

        case 4:
            exit(0);
            break;

        default:
            cout << "All Done" << endl;
        }

        system("cls");
        display(c1, c2);
}