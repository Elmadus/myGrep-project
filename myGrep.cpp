#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(){

int position = 0;
bool stringFound = false;
string temp, searchFromString, searchableString, readFile;

cout << "Give a string from which to search for: ";
getline(cin, searchFromString);
cout << "Give a search string: ";
getline(cin, searchableString);

stringstream s(searchFromString);

//ifstream readFile("mygrep.txt");

//if(!readFile){
   // cout << "Can't open input file";
   // return 0;
//}

//while (getline(readFile, searchString)){

//}

//readFile.close();

size_t substringPosition = searchFromString.find(searchableString);

if(substringPosition != string::npos) {
     cout << "\"" << searchableString << "\" found in \"" << searchFromString << "\" in position " << substringPosition << endl;
stringFound = true;
  } else {
    cout << "\"" << searchableString << "\" NOT found in \"" << searchFromString << "\"";
}
cout << endl;
system("pause");
    return 0;
}

