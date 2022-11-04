#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * @brief An example program. This program demonstrates simple vector storage
 *        and element iteration. A welcome string is output to the user.
 *
 * @return Returns 0 when execution completes successfully.
 */
int main()
{
    vector<string> msg{"Hello", "C++", "World", "from", "VS Code",
                       "and the C++ extension!"};

    for (const string &word : msg)
    {
        cout << word << " ";
    }

    cout << endl;
}
