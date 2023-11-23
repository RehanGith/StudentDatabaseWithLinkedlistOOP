#include "StudentDatabase.h"
#include <iostream>
using namespace std;
AirTime::AirTime(int h, int m, int s) : hour(h), minute(m), second(s) {

}
AirTime AirTime::operator + (const AirTime& TT) {
    int h = hour + TT.hour;
    if (h > 24)
        h = h - 24;
    int m = minute + TT.minute;
    if (m >= 60) {
        m -= 60;
        h++;
    }
    int s = second + TT.second;
    if (s >= 60) {
        s -= 60;
        m++;
    }
    return AirTime(h, m, s);
}
void AirTime::operator +=(const AirTime& TT) {
    hour += TT.hour;
    if (hour > 24)
        hour = hour - 24;
    minute += TT.minute;
    if (minute >= 60) {
        minute -= 60;
        hour++;
    }
    second += TT.second;
    if (second >= 60) {
        second -= 60;
        minute++;
    }
}
AirTime AirTime::operator++() {
    hour++;
    if (hour > 24)
        hour = hour - 24;
    minute++;
    if (minute >= 60) {
        minute -= 60;
        hour++;
    }
    second++;
    if (second >= 60) {
        second -= 60;
        minute++;
    }
    return *this;
}
AirTime AirTime::operator ++(int) {
    AirTime temp = *this;
    hour++;
    if (hour > 24)
        hour = hour - 24;
    minute++;
    if (minute >= 60) {
        minute -= 60;
        hour++;
    }
    second++;
    if (second >= 60) {
        second -= 60;
        minute++;
    }
    return temp;
}
void AirTime::setter() {
    while (true) {
        cout << "Enter hour: ";
        cin >> hour;
        if (hour < 7 && hour > 20) {
            cout << "University Hour should be [7,20]. Please correct it" << endl;
            continue;
        }
        cout << "Enter minute: ";
        cin >> minute;
        if (minute > 60) {
            cout << "Please provide correct minutes. Provide again" << endl;
            continue;
        }
        cout << "Enter second: ";
        cin >> second;
        if (second > 60) {
            cout << "Please Provid correct second. Provide again" << endl;
            continue;
        }
        break;
    }
}
void AirTime::getter() const {
    cout << hour << " : " << minute << " : " << second << endl;
}

Snode::Snode() :marks{} {
    regNum = 0;
    name = "";
    fname = "";
    dob.dd = 0;
    dob.mm = 0;
    dob.yy = 0;
    doa.dd = 0;
    doa.mm = 0;
    doa.yy = 0;
    cgpa = 0;
    Next = nullptr;
}
void Snode::setter() {

    cout << "Enter Students reg number: ";
    cin >> regNum;
    cout << "Enter Students name: ";
    cin >> name;
    cin.ignore(30, '\n');
    cout << "Enter Students father name: ";
    cin >> fname;
    cin.ignore(30, '\n');
    cout << "Enter marks (out of 100):" << endl;
    for (int j = 0; j < MAXSUB; j++)
    {
        cout << "Marks in Subject " << j + 1 << ": ";
        cin >> marks[j];
    } // end of for - j
    cout << "Enter Date of Birth: " << endl;
    cout << "Enter Day: ";
    cin >> dob.dd;
    cout << "Enter Month: ";
    cin >> dob.mm;
    cout << "Enter Year: ";
    cin >> dob.yy;

    cout << "Enter Date of Admission: " << endl;
    cout << "Enter Day: ";
    cin >> doa.dd;
    cout << "Enter Month: ";
    cin >> doa.mm;
    cout << "Enter Year: ";
    cin >> doa.yy;

    cout << "Enter CGPA: ";
    cin >> cgpa;
    cout << "\nEnter Arrival Time of Student: " << endl;
    At.setter();
    cout << "\nEnter Depearture Time of Student: " << endl;
    Dt.setter();
    cout << endl;
    cout << "Student data added sucessfully\n" << endl;
}
void Snode::getter() const {
    cout << "Arivial Time:" << endl;
    At.getter();
    cout << "Deperature time:" << endl;
    Dt.getter();
    cout << "Result Card for Students: " << regNum << endl;
    cout << "-----------------------------------------------------\n";
    cout << "| Name:  " << name << " " << regNum << endl;
    cout << "| Father Name: " << fname << endl;
    cout << endl;

    cout << "| Subject          " << "|  Marks  " << endl;
    int sum{};
    for (int j{ 0 }; j < MAXSUB; j++) {
        cout << "| Subject" << j + 1 << "         " << "|  " << marks[j] << endl;
        sum += marks[j];
    }
    cout << "======================================================\n";
    cout << "|  Total Marks:            " << "|  " << sum << endl;
    cout << "| CGPA:            " << "|  " << cgpa << endl;

}
bool Snode::search(int info) {
    if (info == regNum)
        return true;
    else
        return false;
}
Snode*& Snode::get_Next() {
    return Next;
}
void Snode::set_Next(Snode* node) {
    Next = node;
}
Snode::~Snode() {
    cout << "\nDestructor calls.\n";
}
void create_database(Snode*& first, int nn) {
    if (!nn) {
        cout << "You Have not yet created Database, Please Create first.\n";
        return;
    }
    Snode* cur{ nullptr }, * prev{ nullptr };
    for (int i = 0; i < nn; i++) {
        cur = new Snode;
        cur->setter();
        cur->set_Next(nullptr);
        if (!first)
            prev = first = cur;
        else {
            prev->set_Next(cur);
            prev = cur;
        }
    }
}
void append_record(Snode*& first, int& nn) {
    if (!nn) {
        cout << "You Have not yet created Database, Please Create first.\n";
        return;
    }
    Snode* cur{ nullptr }, * prev{ nullptr };
    cur = prev = first;
    while (cur) {
        prev = cur;
        cur = cur->get_Next();
    }
    cur = new Snode;
    cur->setter();
    cur->set_Next(nullptr);
    prev->set_Next(cur);
    nn++;
}
int search_record(Snode* first, int sinfo, int nn)
{
    if (!nn) {
        cout << "You Have not yet created Database, Please Create first.\n";
        return -1;
    }
    int i = 0;
    while (first) {
        i++;
        if (first->search(sinfo))
            return i;
        first = first->get_Next();
    }
    return -1;
}
int delete_record(Snode*& first, int sinfo, int& nn) {
    if (!nn) {
        cout << "You Have not yet created Database, Please Create first.\n";
        return -1;
    }
    Snode* cur{ nullptr }, * prev{ nullptr };
    cur = prev = first;
    if (first->search(sinfo)) {
        Snode *next = first->get_Next();
        delete first;
        first = next;
        nn--;
        return 1;
    }
    while (cur->search(sinfo) != true && cur != nullptr) {
        prev = cur;
        cur = cur->get_Next();
    }
    if (cur->search(sinfo)) {
        Snode* next = cur->get_Next();
        delete cur;
        prev->set_Next(next);
        nn--;
        return 1;
    }
    return -1;
}
int update_record(Snode* first, int sinfo, int nn) {
    if (!nn) {
        cout << "You Have not yet created Database, Please Create first.\n";
        return -1;
    }
    int i{};
    while (first) {
        if (first->search(sinfo)) {
            i++;
            first->setter();
            return i;
        }
        first = first->get_Next();
    }
    return -1;
}
void display(Snode* first, int nn) {
    if (!nn) {
        cout << "You Have not yet created Database, Please Create first.\n";
        return;
    }
    while (first) {
        first->getter();
        Snode* Next = first->get_Next();
        first = Next;
    }
}