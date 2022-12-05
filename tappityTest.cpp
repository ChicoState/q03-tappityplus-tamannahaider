/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(tappityTest, smoke_test)
{
	ASSERT_TRUE(true);
}

//Reference is longer than input
TEST(tappityTest, lengthTestPass1)
{
	tappity obj("My dear friend likes noodles");
	obj.entry("My dear friend");
	int result = obj.length_difference();
	ASSERT_EQ(result, 14);
}

//Input is longer than reference
TEST(tappityTest, lengthTestPass2)
{
	tappity obj("Shut up");
	obj.entry("Sally sells sea shells at the sea shore");
	int result = obj.length_difference();
	ASSERT_EQ(result, 32);
}

//Input and reference are different lengths
TEST(tappityTest, lengthTestFail1)
{
	tappity obj("Will this work?");
	obj.entry("No");
	int result = obj.length_difference();
	ASSERT_EQ(result, 0);
}

//Reference and input are same length
TEST(tappityTest, lengthTestPass3)
{
	tappity obj("It's a beautiful day to save lives");
	obj.entry("Why did this show kill my favorite");
	int result = obj.length_difference();
	ASSERT_EQ(result, 0);
}

//Reference and input are same length
TEST(tappityTest, lengthTestFail3)
{
	tappity obj("... Well, because I wanted us to fail.");
	obj.entry("OBVIOUSLY I DIDN'T KNOW!!!!!!!!!!!!!");
	int result = obj.length_difference();
	ASSERT_EQ(result, 9);
}

//100 (Reference and input are exactly the same)
TEST(tappityTest, accTestPass1)
{
	tappity obj("Turtleneck and Chain");
	obj.entry("Turtleneck and Chain");
	double result = obj.accuracy();
	ASSERT_EQ(result, 100);
}

//0 (Reference and input are same length, no characters match)
TEST(tappityTest, accTestPass2)
{
	tappity obj("It's a beauitful day to save lives");
	obj.entry("Why did this show kill my favorite");
	double result = obj.accuracy();
	ASSERT_EQ(result, 0);
}

//1-49 (Reference and input are same length, less than half of characters match)
TEST(tappityTest, accTestPass3)
{
	tappity obj("Classes and Objects");
	obj.entry("Kittens for puppies");
	double result = obj.accuracy();
	ASSERT_EQ(result, 21.052631578947368);
}

//50-99 (Reference and input are same length, more than half of characters match)
TEST(tappityTest, accTestPass4)
{
	tappity obj("Classes and Objects");
	obj.entry("Classes for puppies");
	double result = obj.accuracy();
	ASSERT_EQ(result, 52.631578947368421);
}

//0 (Nearly same string, should fail)
TEST(tappityTest, accTestFail1)
{
	tappity obj("OK, what do we do?");
	obj.entry("ok what do we do?");
	double result = obj.accuracy();
	ASSERT_EQ(result, 100);
}

//<100 (Input matches all reference characters but has extra characters)
TEST(tappityTest, accTestPass5)
{
	tappity obj("Let's eat ice cream");
	obj.entry("Let's eat ice cream later");
	double result = obj.accuracy();
	ASSERT_EQ(result, 76);
}

//50 (Input is half the length of reference, all characters in input match corresponding spots in reference)
TEST(tappityTest, accTestPass6)
{
	tappity obj("Do you believe in magic?");
	obj.entry("Do you belie");
	double result = obj.accuracy();
	ASSERT_EQ(result, 50);
}

//50 (Input is half the length of reference, all characters in input match corresponding spots in reference, should fail)
TEST(tappityTest, accTesFail2)
{
        tappity obj("Do you believe in magic?");
        obj.entry("Do you belie");
        double result = obj.accuracy();
        ASSERT_EQ(result, 100);
}


//0-49 (Input is half the length of reference, some characters in input match corresponding spots in reference)
TEST(tappityTest, accTestPass7)
{
	tappity obj("Do you believe in magic?");
	obj.entry("Do you play ");
	double result = obj.accuracy();
	ASSERT_EQ(result, 29.166666666666667);
}

//0 (Input is half the length of reference, no characters in input match corresponding spots in reference)
TEST(tappityTest, accTestPass8)
{
	tappity obj("Some meaningless strings");
	obj.entry("Can we eat a");
	double result = obj.accuracy();
	ASSERT_EQ(result, 0);
}

//0 (Input is longer than reference, no characters in input match corresponding spots in reference)
TEST(tappityTest, accTestPass9)
{
	tappity obj("Shut up");
	obj.entry("I want Taco Bell");
	double result = obj.accuracy();
	ASSERT_EQ(result, 0);
}

//100 (Input and reference are exactly the same, capitals & punctuations match)
TEST(tappityTest, accTestPass10)
{
	tappity obj("Hello World!");
	obj.entry("Hello World!");
	double result = obj.accuracy();
	ASSERT_EQ(result, 100);
}

//20 (Capitals and lowercases are inversed, punctuation doesn't match, only space matches)
TEST(tappityTest, accTestPass11)
{
	tappity obj("hELLO wORLD..!!");
	obj.entry("Hello World!!!!");
	double result = obj.accuracy();
	ASSERT_EQ(result, 20);
}

//0 (Nothing matches, should fail)
TEST(tappityTest, accTestFail2)
{
	tappity obj("This test will FAIL!");
	obj.entry("But I want it to pass...");
	double result = obj.accuracy();
	ASSERT_EQ(result, 100);
}

//8.333333333333329 (No spaces in entry)
TEST(tappityTest, accTestPass12)
{
	tappity obj("Do spaces really matter?");
	obj.entry("Dospacesreallymatter?");
	double result = obj.accuracy();
	ASSERT_EQ(result, 8.333333333333333);
}

//16.666666666666667 (No spaces in entry, should fail)
TEST(tappityTest, accTestFail3)
{
	tappity obj("Yes, they really matter.");
	obj.entry("Yes,theyreallymatter.");
	double result = obj.accuracy();
	ASSERT_EQ(result, 100);
}

//39.130434782608696 (Random symbols match)
TEST(tappityTest, accTestPass13)
{
	tappity obj("Woah!? That's... odd???");
	obj.entry("Ewww!! %&@*'$... why?!?");
	double result = obj.accuracy();
	ASSERT_EQ(result, 39.130434782608696);
}
