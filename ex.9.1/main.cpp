#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class student
{
private:
    string first_name;
    string family_name;
    int student_id;
    int year_of_study;
public:
    student(string first, string family, int id, int year)
    {
        first_name = first;
        family_name = family;
        student_id = id;
        year_of_study = year;

        if (student_id <= 0)
            throw invalid_argument("student_id negative");
        if (1 > year_of_study || 5 < year_of_study)
            throw invalid_argument("wrong year of study");
    }
};

int main()
{
    while (true)
    {
        string first, family;
        int id, year;

        cout << "First name: ";
        cin >> first;
        cout << "Family name: ";
        cin >> family;
        cout << "ID: ";
        cin >> id;
        cout << "Year of study: ";
        cin >> year;

        try
        {
            student T(first, family, id, year);
        }
        catch (const invalid_argument& ia)
        {
            cout << "Error! " << ia.what() << endl;
        }

    }

    return 0;
}
