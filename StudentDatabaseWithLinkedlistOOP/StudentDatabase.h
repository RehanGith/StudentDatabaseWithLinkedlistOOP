#pragma once
#include <string>
#define MAXSUB 5
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