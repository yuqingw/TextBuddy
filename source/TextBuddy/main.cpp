
#include "TextBuddy.h"
#include "Tester.h"

using namespace std;

int main(int argument_count, char** argument_vars) {

	string file = argument_vars[1];

	TextBuddy TB(file);
	//runTest(argument_count, argument_vars); //run unit test. comment out to disable

	TB.main();

	return 0;
}

