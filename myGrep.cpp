#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to open the file if the user input requires it to
void fileOpening(const string &fileName, ifstream &readFile, bool &fileIsOpen)
{
  readFile.open(fileName);
  fileIsOpen = readFile.is_open();
}

// Function for looking/searching the user inputted word/characters
void searchingFromFile(const string &addedCommand, int &lineNumbering, ifstream &readFile, string &searchFileString, string &searchableFile, bool &stringNotFoundAlert, int &argc, int &occurrences)
{
  if (argc == 3)
  {
    while (getline(readFile, searchableFile))
    {
      if (searchableFile.find(searchFileString) != string::npos)
      {
        cout << searchableFile << endl;
        stringNotFoundAlert = false;
      }
    }
  }
  if (argc == 4)
  {
    if (addedCommand == "-ol")
    {
      while (getline(readFile, searchableFile))
      {
        lineNumbering++;
        if (searchableFile.find(searchFileString) != string::npos)
        {
          cout << lineNumbering << ":   " << searchableFile << endl;
          stringNotFoundAlert = false;
        }
      }
    }
    else if (addedCommand == "-oo")
    {
      while (getline(readFile, searchableFile))
      {
        if (searchableFile.find(searchFileString) != string::npos)
        {
          cout << searchableFile << endl;
          stringNotFoundAlert = false;
          occurrences++;
        }
      }
      cout << endl;
      cout << "Occurrences of lines containing \"" << searchFileString << "\": " << occurrences << endl;
    }
    else if (addedCommand == "-olo")
    {
      while (getline(readFile, searchableFile))
      {
        lineNumbering++;
        if (searchableFile.find(searchFileString) != string::npos)
        {
          cout << lineNumbering << ":   " << searchableFile << endl;
          stringNotFoundAlert = false;
          occurrences++;
        }
      }
      cout << endl;
      cout << "Occurrences of lines containing \"" << searchFileString << "\": " << occurrences << endl;
    }
    else if (addedCommand == "-o")
    {
      cout << "Please input the wanted command after \"-o\"" << endl;
      stringNotFoundAlert = false;
    }
    else
    {
      cout << "Input is missing an added command, or the input was invalid" << endl;
      stringNotFoundAlert = false;
    }
  }
}

// Main program, which uses a switch to decide how the program is executed
int main(int argc, char *argv[])
{

  ifstream readFile;
  bool fileIsOpen = false, stringNotFoundAlert = true;
  int lineNumbering = 1, occurrences = 0;
  string searchFileString, searchableFile, fileName, addedCommand;

  switch (argc)
  {
  case 1:
  {
    int position = 0;
    bool stringFound = false;
    string temp, searchFromString, searchableString;

    cout << "Give a string from which to search for: ";
    getline(cin, searchFromString);
    cout << "Give a search string: ";
    getline(cin, searchableString);

    size_t substringPosition = searchFromString.find(searchableString);

    if (substringPosition != string::npos)
    {
      cout << "\"" << searchableString << "\" found in \"" << searchFromString << "\" in position " << substringPosition << endl;
      stringFound = true;
    }
    else
    {
      cout << "\"" << searchableString << "\" NOT found in \"" << searchFromString << "\"" << endl;
    }
    break;
  }
  case 3:
  {

    fileName = argv[2];

    fileOpening(fileName, readFile, fileIsOpen);

    searchFileString = argv[1];

    if (!fileIsOpen)
    {
      cout << "Can't open input file: \"" << argv[2] << "\"" << endl;
      return 1;
    }
    else
    {
      searchingFromFile(argv[1], lineNumbering, readFile, searchFileString, searchableFile, stringNotFoundAlert, argc, occurrences);

      if (stringNotFoundAlert)
      {
        cout << "\"" << searchFileString << "\" not found in \"" << argv[2] << "\"" << endl;
      }
    }
    break;
  }
  case 4:
  {
    fileName = argv[3];

    fileOpening(fileName, readFile, fileIsOpen);

    searchFileString = argv[2];
    addedCommand = argv[1];

    if (!fileIsOpen)
    {
      cout << "Can't open input file: \"" << argv[3] << "\"" << endl;
      return 1;
    }
    else
    {
      searchingFromFile(argv[1], lineNumbering, readFile, searchFileString, searchableFile, stringNotFoundAlert, argc, occurrences);

      if (stringNotFoundAlert)
      {
        cout << "\"" << searchFileString << "\" not found in \"" << argv[3] << "\"" << endl;
      }
    }
    break;
  }
  default:
  {
    cout << "Input had an invalid amount of arguments, please try again" << endl;
  }
  }
  readFile.close();
  return 0;
}
