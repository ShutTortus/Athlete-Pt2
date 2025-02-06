/**
 * @file pa11.cpp
 * @author Daniel O'Neill
 * @date 9/11/2024
 * @section 1003
 *
 * @note I pledge my word of honor that I have abided by the
 * CSN Academic Integrity Policy while completing this assignment.
 *
 * @brief this program takes in the names, ids, countrys, and scores of
 * olympians and organises them into classes and outputs them
 * @note I could not figure out why it would not work and would like any
 * feedback as to why
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

#include "Olympian.h"
#include "Athlete.h"


/// Function prototypes
bool input(Olympian& olympians, std::istream& input = std::cin);
void output(const Olympian& olympians, std::ostream& output = std::cout);

int main() {
    using namespace std;

    const size_t Max_O = 10;
    Olympian olympian[Max_O];

    size_t count = 0;

    while (count < Max_O && input(olympian[count]))
    {
        count++;
    }

    if (count == 0)
    {
        cout << " 0 records processed .\n";
    }
    else
    {
        char blankline[2]{};

        cout << fixed << showpoint << setprecision(1);

        for (size_t i = 0; i < count; i++)
        {
            cout << blankline;
            output(olympian[i]);
            blankline[0] = '\n';
        }
    }
    return EXIT_SUCCESS;
}

/**
 * @brief This is an input function to retrieve each individual olympians info
 * @param olympains is the copied class olympain
 */
bool input(Olympian& olympians, std::istream& input)
{
    using namespace std;

    int ID {};
    string Name {};
    string Country {};
    bool success = true;

    if (input >> Name >> ID >> Country)
    {
        double score{};
        size_t score_count{};

        olympians = Olympian(Name, ID, Country);

        while (score_count < olympians.capacity() && input >> score)
        {
            olympians.push_back(score);
            ++score_count;
        }

        input.clear();
        if (input.peek() == '\n')
        {
            input.ignore();
        }
    }
    else
    {
        success = false;
    }
    return success;
}

/**
 * @brief This function prints the information of the olympian passed into it
 * @param olympians is the olympian that is passes in and cannot be changed
 */
void output(const Olympian& olympians, std::ostream& output)
{
    using namespace std;


    output << "Olympian: " << olympians.name()
    <<      ", ID: " << olympians.id()
    <<      ", Country: " << olympians.country()
    <<      '\n';


    cout << "Scores: ";

    for (size_t x = 0; x < olympians.size(); x++)
    {
        output << ' ' << olympians.at(x);
    }
    output << '\n';

    output << "Min: "            << olympians.min_score()
    <<        ", Max: "          << olympians.max_score()
    <<        ", Adjusted Avg: " << olympians.average_score()
    << endl;
}

/* EOF */
