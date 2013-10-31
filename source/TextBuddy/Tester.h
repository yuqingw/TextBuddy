#include "gtest/gtest.h" //include to use Google Unit test's stuff
#include <string>
#include "TextBuddy.h"


TEST(basic_test, add_Text)

{

string result = TextBuddy::addText("a little brown fox");
	ASSERT_EQ("Added to mytextfile.txt: \"a little brown fox\"", result);

	result = TextBuddy::addText("little brown fox");
	ASSERT_EQ("Added to mytextfile.txt: \"little brown fox\"", result);

	result = TextBuddy::addText("little brown fox");
	ASSERT_EQ("Added to mytextfile.txt: \"little brown fox\"", result);
	
	result = TextBuddy::addText("A black panda");
	ASSERT_EQ("Added to mytextfile.txt: \"A black panda\"", result);

	result = TextBuddy::addText("blue little sheep");
	ASSERT_EQ("Added to mytextfile.txt: \"blue little sheep\"", result);

	result = TextBuddy::addText("they all jumped onto the moon");
	ASSERT_EQ("Added to mytextfile.txt: \"they all jumped onto the moon\"", result);

	result = TextBuddy::addText("The moon fell");
	ASSERT_EQ("Added to mytextfile.txt: \"The moon fell\"", result);


}

TEST(basic_test, delete_Text1)

{

string result = TextBuddy::deleteText(2);
	ASSERT_EQ("Deleted from mytextfile.txt: \"little brown fox\"", result);

	result = TextBuddy::deleteText(2);
	ASSERT_EQ("Deleted from mytextfile.txt: \"little brown fox\"", result);


}

TEST(basic_test, delete_Text2)

{
string result = TextBuddy::deleteText(12);
	ASSERT_EQ("This line does not exist. Please try again.", result);

}



TEST(basic_test, sort_Text)

{
	string result;
	vector <string> sort = TextBuddy::sortText();

	result = sort[0];
	ASSERT_EQ("a black panda\n", result);

	result = sort[1];
	ASSERT_EQ("a little brown fox\n", result);
	
	result = sort[2];
	ASSERT_EQ("blue little sheep\n", result);

	result = sort[3];
	ASSERT_EQ("the moon fell\n", result);
	
	result = sort[4];
	ASSERT_EQ("they all jumped onto the moon\n", result);

}

TEST(basic_test, search_Text1)

{
	string result;
	vector <string> search = TextBuddy::searchText("sheep");
	result = search[0];
	ASSERT_EQ("blue little sheep\n", result);

}

TEST(basic_test, search_Text2)

{
	string result;
	vector <string> search = TextBuddy::searchText("hello");
	result = search[0];
	ASSERT_EQ("This word does not exist in the file. Please try again.\n", result);
	
}

TEST(basic_test, display_Text1)

{
	string result;
	vector <string> display = TextBuddy::displayAll();
	
	result = display[0];
	ASSERT_EQ("1. a little brown fox\n", result);
	
	result = display[1];
	ASSERT_EQ("2. A black panda\n", result);

	result = display[2];
	ASSERT_EQ("3. blue little sheep\n", result);

	result = display[3];
	ASSERT_EQ("4. they all jumped onto the moon\n", result);

	result = display[4];
	ASSERT_EQ("5. The moon fell\n", result);

}


TEST(basic_test, clear_Test)
{
	string result = TextBuddy::clearAll();
	ASSERT_EQ("All content deleted from mytextfile.txt", result);

}

TEST(basic_test, display_Test2)
{
	string result;
	vector <string> display = TextBuddy::displayAll();
	result=display[0];
	ASSERT_EQ("mytextfile.txt is empty\n", result);

}
 

void runTest(int argument_count, char** argument_vars)

{

testing::InitGoogleTest(&argument_count, argument_vars); //initialize GTest

RUN_ALL_TESTS();

std::getchar(); //pause the program after all the testing

}