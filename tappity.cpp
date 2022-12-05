#include "tappity.h"
#include <string>
/**
 * Class for tappity
**/

//Constructor sets the reference phrase
tappity::tappity(std::string reference)
{
	ref = reference;
	inp = "";
}

//Provide the input to be compared to the reference. Before this 
//function is called, the input should be considered an empty string
void tappity::entry(std::string input)
{
	inp = input;
}

//Compares the length of the reference to that of the input and
//returns the absolute value of the difference, or 0 if they are the
//same length
int tappity::length_difference()
{
	//int refLength = ref.length();
	//int inpLength = inp.length();
	int diff = ref.length() - inp.length();
	if (diff < 0){
		diff = diff*-1;	
	}
	return diff;
}

//Compares the content of the reference to that of the input and
//calculates the accuracy of matching characters. If the two strings
//are identical, accuracy should be 100. However, for each 
//corresponding character that does not match in the same location,
//the percentage of corresponding characters should be returned.
//For example, if the reference and input have 10 letters and the input
//matches 8 of the corresponding reference characters, the function 
//should return 80. When input does not have the same number of
//characters as the reference, the accuracy should represent the percent
//of matching characters between the shorter and longer strings. For
//example, if one string has 8 characters matching the corresponding
//locations in another string that has 16 characters, the accuracy is 50.
double tappity::accuracy()
{
	double denom;
	double size;
	//Determine which string is longer for calculation and which
	//is shorter for iteration
	if (ref.length() >= inp.length()){
		denom = ref.length();
		size = inp.length();
	} else {
		denom = inp.length();
		size = ref.length();
	}
	
	//Iterates through both strings, comparing the characters at
	//each position in the string. Sums up total number of matches.
	double matches = 0;
	for (int i = 0; i < size; i++){
		if (ref.at(i) == inp.at(i)){
			matches +=1;
		}
	}

	//divides number of matches by larger string length, then mult.
	//by 100 to get percentage accurate
	double percentage = matches/denom * 100;
	return percentage;
}
