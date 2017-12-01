#include <iostream>
#include <string>

using namespace std;
const int MAXINPUT = 256;

string readLine();

int main()
{
    cout << "Insert e-mail" << endl;
    string email = readLine();
    string name;
    for (int i = 0; i < email.length(); i++)
    {
        if (email[i] == '@')
        {
            if (i == 0)
            {
                cout << "Wrong input" << endl;
                return 0;
            } else {
                name = email.substr(0,i);
                cout << "Correct input! Name is: " << name << endl;
                return 0;
            }
        }
    }
    cout << "Wrong input" << endl;
    return 0;
}


string readLine()
{
    char* input = (char*)calloc(1, sizeof(char)); /* init the array */
    char c;
    int i = 0;
    while ((c = getchar()) != '\n')
    {
        if (c == ' ')
            continue;
        if (i < MAXINPUT)
        {
            input = (char*)realloc(input, (i+1) * sizeof(char));
            input[i] = c;
            i++;
        }
    }
    input = (char*)realloc(input, (i + 1) * sizeof(char)); /* finishing a string */
    input[i] = '\0';
    return string(input);
}
