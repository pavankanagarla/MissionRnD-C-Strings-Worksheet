/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void str_words_in_rev(char *input, int len){
	int i;
	int j;
	char temp;
	for (i = 0, j = len - 1; i < j; i++, j--){
		temp = input[i];
		input[i] = input[j];
		input[j] = temp;

	}
	
}
