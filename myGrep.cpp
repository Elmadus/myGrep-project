#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]){
switch (argc){
case 1:
{
int position = 0;
bool stringFound = false;
string temp, searchFromString, searchableString, readFile;

cout << "Give a string from which to search for: ";
getline(cin, searchFromString);
cout << "Give a search string: ";
getline(cin, searchableString);

stringstream s(searchFromString);

size_t substringPosition = searchFromString.find(searchableString);

if(substringPosition != string::npos) {
     cout << "\"" << searchableString << "\" found in \"" << searchFromString << "\" in position " << substringPosition << endl;
stringFound = true;
  } else {
    cout << "\"" << searchableString << "\" NOT found in \"" << searchFromString << "\"";
}

system("pause");
  break;
}
case 3:
{
ifstream readFile(argv[2]);
  string searchFileString = argv[1], searchableFile;
  bool txtFound = false;

if(!readFile){
    cout << "Can't open input file";
    return 0;

}else {

while (getline(readFile, searchableFile)){
  if (searchableFile.find(searchFileString) != string::npos){
    cout << searchableFile << endl;
    txtFound = true;    
  }
}
if (!txtFound){
  cout << searchFileString << " not found in " << argv[2] << endl;
  }
      }
      readFile.close();
      return 0;
    }
  }
}



 



