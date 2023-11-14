#include <iostream>
#include "StudentDatabase.h"
using namespace std;
#define MAXSTUDENT 70
#define MAXSUB 5

int main() {
    Snode* first{ nullptr };
    int n{}, ch{}, sinfo{}, index{};
    do
    {
        cout << "\n\nStudent Database Menu:" << endl
            << "1. Create Data Base" << endl
            << "2. Append a record" << endl
            << "3. Search a record" << endl
            << "4. Delete a record" << endl
            << "5. Update a record" << endl
            << "6. Display Result" << endl
            << "7. Exit" << endl
            << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1: // Create DB
            while (true) {
                cout << "Enter how many students are [MAX. 70]: ";
                cin >> n;
                if (n > MAXSTUDENT) {
                    cout << "Please provide correct number of students, Between [MAX. 70]. \n";
                }
                else {
                    break;
                }
            }
            create_database(first, n);
            break;
        case 2: // Append
            append_record(first, n);
            break;
        case 3: // Searching
            cout << "Enter reg. number to search: ";
            cin >> sinfo;
            index = search_record(first, sinfo, n);
            if (index != -1)
                cout << "Found at position: " << index << endl;
            else
                cout << "Not Found in the Data Base" << endl;
            break;
        case 4: // Deletion
            cout << "Enter reg. number to search: ";
            cin >> sinfo;
            index = delete_record(first, sinfo, n);
            if (index != -1)
                cout << "Found at position: " << index << endl;
            else
                cout << "Not Found in the Data Base" << endl;
            break;
        case 5: //updating
            cout << "Updating Record" << endl;
            cout << "Enter reg. number to update Record: ";
            cin >> sinfo;
            index = update_record(first, sinfo, n);
            if (index == -1)
                cout << "Not Found in the Data Base" << endl;
            break;
        case 6: // displaying
            cout << "Displaying Students result Card\n";
            display(first, n);
            break;
        case 7: // Exit
            return 0;
        default:
            cout << "Invalid choice. Enter again..." << endl;
        } // end of switch
    } while (true);
    return 0;
}