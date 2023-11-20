#pragma once
#include <string>
#define MAXSUB 5
class AirTime {
private:
    int hour;
    int minute;
    int second;
public:
    AirTime(int h = 00, int m = 00, int s = 00);
    AirTime operator +(const AirTime&);

    void operator +=(const AirTime&);
    AirTime operator ++();
    AirTime operator ++(int);
    void setter();
    void getter() const;
};
struct Date
{
    int dd, mm, yy;
};
class Snode
{
private:
    int regNum{};
    std::string name;
    std::string fname;
    int marks[MAXSUB];
    Date dob, doa;
    float cgpa;
    AirTime At, Dt;
    Snode* Next;
public:
    Snode();
    void setter();
    void getter() const;
    bool search(int);
    Snode*& get_Next();
    void set_Next( Snode* node);
    ~Snode();
};
void create_database(Snode*& first, int nn);
void append_record(Snode*& first, int& nn);
int search_record(Snode* first, int sinfo, int nn);
int delete_record(Snode*& first, int sinfo, int& nn);
int update_record(Snode* first, int sinfo, int nn);
void display(Snode* first, int nn);