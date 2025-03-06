"#myGrep-project"
 
Welcome to using mygrep program to search ASCII -files for words. The programs source code is in .cpp format so before you can use it you'll have to compile it into an executable .exe -file first. Here's a quick rundown how to set up the program as such.

Getting started with the program:

:: Download the source code from the repository to your PC.

:: Extract or move the files from the .zip folder into a empty folder where you wan't to store the program

:: Use CMD or other command interpreter or shell to navigate to the program folder where you just extracted/moved the files into

:: Compile the program with the following command: 
"g++ -o mygrep.exe mygrep.cpp" 
This will compile the source .cpp file into an executable .exe file, which the computer can run. The new .exe file will appear into the same directory where the source files exist. 

Now you can launch the program with CMD/other likewise interpretet. There are a few ways to start the program, each of which gives the user different functions to use. The most basic feature set is called with the command ".\mygrep.exe"

What different functions exist inside the program:
".\mygrep.exe"
:: This launches the program into the first version, in which the user can search for characters, or character combinations/words inside from another word or a whole sentence. 

".\mygrep.exe following mygrep.txt"
:: This launches the program into the second version which enables the user to open a ASCII file (in this case it's the "mygrep.txt") and look for lines inside the file that contain a certain word/combinations of characters, or just one character (in this case the word "following")

".\mygrep.exe -olo following mygrep.txt"
:: This is the last version of the program, in which the functionality is the same as in with the aforementioned, but with added features. The "-o" mark opens the program into a mode where the user can input different functions for the program to execute. "-o" is shortened from the word "options" and the user has to input the additional options it want's to use in order for the program to execute correctly.

List of different options: 
"-o"
Means it opens the program with different avaivable functions, but won't execute correctly because the options themselves are missig. The program will give out an error: "Input is missing a command, or the input was invalid"

"-oo"
This will open the program with the function to calculate how many times the searched word/characters appear in the text file. 

"-ol"
This opens the program with the function to tell the user from what row did the program find the occurence of the searched word/characters.

"-olo"
This combines the two features together, telling the user the amount of occurences, and also from what rows did it find the occurences.

