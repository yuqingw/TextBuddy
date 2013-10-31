/*This program is written to manipulate text in a file, 
functions include add, delete, display, clear,
sort and search.
Input as below:
===================================================
Welcome to TextBuddy. mytextfile.txt is ready for use.
command: add little brown fox
added to mytextfile.txt: ¡°little brown fox¡±
command: display
1. little brown fox
command: add jumped over the moon
Added to mytextfile.txt: "jumped over the moon".
command: display
1. little brown fox
2. jumped over the moon
command: sort
The sorted list is:
jumped over the moon
little brown fox
command: search moon
jumped over the moon
command: delete 2
Deleted from mytextfile.txt: "jumped over the moon".
command: delete 3
That line does not exist. Please try again.
command: display
1. little brown fox
command: clear
All content deleted from mytextfile.txt.
command: display
mytextfile.txt is empty.
command: exit
===================================================
*/

#ifndef _TEXTBUDDY_H_
#define _TEXTBUDDY_H_
#define MAX_CHAR 255
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;


/*This class stores the text input from the user into a vector
It loads the previous data from the file (if any) and and additional datas
by taking in user coommands and write these changes into the textfile.
*/
class TextBuddy
{
private:
	static fstream myfile;
	static string filename;
	static vector <string> textStorage;
	
	//Could be refactored to enum but it will complicate gunit testing
	static string WELCOME_MESSAGE;
	static string ADDED_MESSAGE;
	static string DELETED_MESSAGE;
	static string CLEAR_MESSAGE;
	static string SORTED_MESSAGE;
	static string NOTFOUND_MESSAGE;
	static string ERROR_MESSAGE;
	static string INVALID_MESSAGE;
	static string EMPTY_MESSAGE;
	static char outputStatement[MAX_CHAR];

	static enum COMMAND_TYPE {
	COMMAND_ADD, COMMAND_DISPLAY, COMMAND_DELETE, COMMAND_CLEAR,
	COMMAND_INVALID, COMMAND_SORT, COMMAND_SEARCH, COMMAND_EXIT};
	static void showUser(string text);
	static void showUser(vector<string> textLines);
	static void inputToFile();//input information from file to textStorage
	static string toLowerCase(string text);
	

public:
	
	static string command;
	TextBuddy(string fileName);
	~TextBuddy();
	
	static COMMAND_TYPE getCommandType(string userCommand);
	static void executeCommand(COMMAND_TYPE commandType);

	static string addText(string text);
	static string deleteText(int index);
	static vector<string> displayAll(); //display what is in the file, not sorted list

	static string clearAll();

	static vector<string> sortText(); //output a temporary list of sorted text
	static vector<string> searchText(string text);

	static void loadFile(); //to load the data from the file
	

	void main();

};
#endif

