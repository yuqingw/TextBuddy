#include "TextBuddy.h"

char TextBuddy::outputStatement[MAX_CHAR];
string TextBuddy::WELCOME_MESSAGE = "Welcome to TextBuddy. %s is ready for use.";
string TextBuddy::ADDED_MESSAGE = "Added to %s: \"%s\""; 
string TextBuddy::DELETED_MESSAGE = "Deleted from %s: \"%s\"";
string TextBuddy::CLEAR_MESSAGE = "All content deleted from %s";
string TextBuddy::SORTED_MESSAGE = "The sorted text are:";
string TextBuddy::INVALID_MESSAGE = "The command is invalid. Please re-enter.";
string TextBuddy::NOTFOUND_MESSAGE = "This word does not exist in the file. Please try again.\n";
string TextBuddy::ERROR_MESSAGE = "This line does not exist. Please try again.";
string TextBuddy::EMPTY_MESSAGE = "%s is empty\n";
vector <string> TextBuddy::textStorage;
string TextBuddy:: filename;
fstream TextBuddy::myfile;


TextBuddy::TextBuddy(string file){
	filename = file;
}

TextBuddy::~TextBuddy(){}

TextBuddy::COMMAND_TYPE TextBuddy::getCommandType(string command) {
if (command == "add"){
	return COMMAND_ADD;
	}
	else if(command == "display"){
		return COMMAND_DISPLAY;}
	else if (command == "delete"){
		return COMMAND_DELETE;}
	else if (command == "clear"){
		return COMMAND_CLEAR;} 
	else if(command == "sort"){
		return COMMAND_SORT;} 
	else if(command == "search"){
		return COMMAND_SEARCH;} 
	else if(command == "exit"){
		return COMMAND_EXIT;}
	else{
		return COMMAND_INVALID;}
}

void TextBuddy::loadFile()
{
	string text;
	myfile.open(filename, ios::in);
	if (myfile.peek() != EOF){    
			while (getline(myfile, text)){ 	
				textStorage.push_back(text);
			}
	}
	myfile.close();			

}

void TextBuddy::inputToFile(){
	myfile.open(filename, ios::out);
	vector<string>::iterator it;
	for ( it=textStorage.begin() ; it <textStorage.end(); it++ ){
		myfile << *it << endl; 
	}
	myfile.close();
}

string TextBuddy::addText(string text){
	textStorage.push_back(text);
	inputToFile();
	sprintf_s(outputStatement, ADDED_MESSAGE.c_str(), filename.c_str(), text.c_str());
	
	return outputStatement;
}

string TextBuddy::deleteText(int index){

	if (index > textStorage.size()){
		return ERROR_MESSAGE;
	}
	
	else{
	string deletedText;
	deletedText = textStorage[index-1];
	textStorage.erase(textStorage.begin()+(index-1));
	sprintf_s(outputStatement, DELETED_MESSAGE.c_str(), filename.c_str(), deletedText.c_str());
	inputToFile();
	}

	return outputStatement;
}

string TextBuddy::clearAll(){
	textStorage.clear();
	
	myfile.open(filename, ios::out);
	myfile.close();
	sprintf_s(outputStatement, CLEAR_MESSAGE.c_str(), filename.c_str());

	return outputStatement;
}

vector<string> TextBuddy::displayAll(){
	
	vector<string> allText;
	int lineNum=1;	
	
	if (textStorage.empty()){    
		sprintf_s(outputStatement, EMPTY_MESSAGE.c_str(), filename.c_str());
		allText.push_back(outputStatement);
		}
		else{
			for (int i = 0; i<textStorage.size(); i++)
			{
				ostringstream output;
				output << lineNum <<". " << textStorage[i] <<endl;
				lineNum++;
				string linedText = output.str();
				allText.push_back(linedText);
			}
				}


	return allText;
}

string TextBuddy::toLowerCase(string text) {
	string lowCaseText = text;
	for(int i=0; i<lowCaseText.size(); i++)
		lowCaseText[i] = tolower(lowCaseText[i]);

	return lowCaseText;
}

vector<string> TextBuddy::sortText(){
	vector <string> lowerCaseString; //create a temporary storage to convert strings to lowercase for easy sorting
	vector <string> sortedText; 

	for (int i = 0; i<textStorage.size(); i++){	
		lowerCaseString.push_back(toLowerCase(textStorage[i]));
	}

	sort(lowerCaseString.begin(),lowerCaseString.end(),less<string>());
        for (auto i=lowerCaseString.begin();i!=lowerCaseString.end();++i){
            ostringstream output;
			output <<*i <<endl;
			sortedText.push_back(output.str());
        }
		
return sortedText;
}

vector<string> TextBuddy::searchText(string text){
	
	text.append(" ");
	text.insert(0, " ");
	text = toLowerCase(text);
	vector <string> foundText;
	size_t found;
	
	for (int i = 0; i<textStorage.size(); i++){
		string appendedString=textStorage[i]; 
		//string is appended so that search funtion can search words
		//instead of characters which is what the STL .find() does.
		appendedString.append(" ").insert(0, " ");
		ostringstream output;
		found = appendedString.find(text);
	
	if (found!=string::npos){
			output << textStorage[i] << endl;
			foundText.push_back(output.str());
		}
	}
	
	if (foundText.size() ==0)
	{
		foundText.push_back(NOTFOUND_MESSAGE);
	}
	
	return foundText;
}

void TextBuddy::showUser(string text) {
	cout << text << endl;
}

void TextBuddy::showUser(vector<string> textLines) {

	for(int i=0; i<textLines.size(); i++) {
		string text = textLines[i];
		cout << text;
	}
}

void TextBuddy::executeCommand(COMMAND_TYPE userCommand)
{
	char whitespace;
	string message;
	static vector <string> requiredText;

		if(userCommand == COMMAND_ADD) {

			string text;
			cin >> noskipws >> whitespace;
			getline(cin, text);
			message = addText(text);
			showUser(message);
			
		} else if(userCommand == COMMAND_DELETE ) {

			int lineNumber;
			cin >> noskipws >> whitespace;
			cin >> lineNumber;
			getchar();
			message = deleteText(lineNumber);
			showUser(message);

		} else if(userCommand == COMMAND_DISPLAY) {

			requiredText = displayAll();
			showUser(requiredText);
			getchar();

		} else if(userCommand == COMMAND_CLEAR) {

			message = clearAll();
			showUser(message);
			getchar();

		} else if(userCommand == COMMAND_SORT) {

			showUser(SORTED_MESSAGE);
			requiredText = sortText();
			showUser(requiredText);
			getchar();

		} else if(userCommand == COMMAND_SEARCH) {

			string text;
			cin >> noskipws >> whitespace;
			getline(cin, text);
			requiredText = searchText(text);
			showUser(requiredText);
		}
		else if (userCommand == COMMAND_EXIT){
		exit(0);
		
		} else {

			showUser(INVALID_MESSAGE);
			getchar();
		}
}
	
void TextBuddy :: main ()
{
	string userCommand;
	COMMAND_TYPE commandType;

	sprintf_s(outputStatement, WELCOME_MESSAGE.c_str(), filename.c_str());
	showUser(outputStatement);
	
	loadFile();
	do{		
		cout << "command: ";
		cin >> userCommand;
		commandType = getCommandType(userCommand);
		executeCommand(commandType);
				
	}while(commandType!=COMMAND_EXIT);
}
