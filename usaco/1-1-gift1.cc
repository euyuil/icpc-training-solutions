/*
ID: 31415926
LANG: C++
TASK: gift1
*/

#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

struct person
{
    string name;
    long original;
    long remainder;
    long received;
};

vector<person> persons;

inline person *find_person(const string &name)
{
    for (int i = 0; i < persons.size(); ++i)
        if (persons[i].name == name)
            return &persons[i];
    return NULL;
}

inline void read_person_names()
{
    int n;
    cin >> n;
    persons.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> persons[i].name;
        persons[i].original = 0;
        persons[i].remainder = 0;
        persons[i].received = 0;
    }
    clog << "person names read." << endl;
}

inline void give_money_gifts()
{
    while (cin)
    {
        string giver_name;
        cin >> giver_name;
        person *giver = find_person(giver_name);

        if (giver == NULL)
            break;

        int n;
        cin >> giver->original >> n;

        long money_each = 0;
        if (n != 0)
        {
            money_each = giver->original / n;
            giver->remainder = giver->original % n;
        }

        for (int i = 0; i < n; ++i)
        {
            string accepter_name;
            cin >> accepter_name;
            person *accepter = find_person(accepter_name);
            accepter->received += money_each;
        }

        clog << giver_name << " gave his/her money to others." << endl;
    }
    clog << "all persons gave their money to others." << endl;
}

inline long calc_money_delta(const person &pers)
{
    return pers.remainder + pers.received - pers.original;
}

inline void output_persons()
{
    for (int i = 0; i < persons.size(); ++i)
    {
        cout << persons[i].name << ' ';
        cout << calc_money_delta(persons[i]) << endl;
    }
}

int main()
{
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);

    read_person_names();
    give_money_gifts();
    output_persons();

    return EXIT_SUCCESS;
}
