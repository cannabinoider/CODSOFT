#include <iostream> //necessary header files
#include <fstream>
#include <sstream>
using namespace std;

// below is a function which was not asked but i did add it for more usage
void countCharacters(const string &content, int &spaces, int &lowercase, int &capitals, int &numerals, int &symbols)
{
    spaces = capitals = lowercase = numerals = symbols = 0;
    for (char ch : content)
    {
        if (ch == ' ')
            spaces++;
        else if (isupper(ch)) //
            lowercase++;
        else if (islower(ch))
            capitals++;
        else if (isdigit(ch)) // its used to know whether it belongs to digits or not
            numerals++;
        else if (!isalpha(ch) && !isspace(ch)) // its used to know if it does not belonf to either of a-z
                                               // or A-Z or spaces than we will assume it to be symbols
            symbols++;
    }
}
// function to count words in the content in file
int countWords(const string &content)
{
    stringstream ss(content);
    string word;
    int count = 0;
    while (ss >> word)
    {
        count++;
    }
    return count;
}

int main()
{
    string filePath; // path of file is stored
    fstream fp;      // file stream object
    int spaces, capitals, numerals, symbols, lowercase;

    int count = 0;

    cout << "Enter the Name of File: ";
    cin >> filePath;

    fp.open(filePath, fstream::in);
    if (!fp)
    {
        cout << "\nError Occurred!";
        return 0;
    }

    cout << "\nContent of " << filePath << ":-\n";

    string content;
    string line; // reads content line by line
    while (getline(fp, line))
    {
        content += line + '\n'; // appending content
    }

    fp.close();

    int wordCount = countWords(content);              // calling function
    cout << "Number of words: " << wordCount << endl; // showing total words

    cout << "\nDo you want to know extra information? (press'y' for yes/else any key for no): ";
    char answer;
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        countCharacters(content, spaces, capitals, lowercase, numerals, symbols);

        cout << "\nNumber of spaces: " << spaces << endl;
        cout << "\nNumber of capital letters: " << capitals << endl;
        cout << "\nNumber of lowercase letters: " << lowercase << endl;
        cout << "\nNumber of numerals: " << numerals << endl;
        cout << "\nNumber of symbols: " << symbols << endl;
    }

    return 0;
}
