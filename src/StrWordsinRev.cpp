/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void reverse(char *str, int starting_index, int ending_index){
	int i;
	int j;
	char temp;
	for (i = starting_index, j = ending_index - 1; i < j; i++, j--){
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

void str_words_in_rev(char *input, int len){
	int starting_index = 0;
	int ending_index;
	reverse(input, 0, len);
	for (ending_index = 0; ending_index <= len; ending_index++){
		if (input[ending_index] != ' ' && input[ending_index] != '\0')
			continue;
		reverse(input, starting_index, ending_index);
		starting_index = ending_index + 1;
	}
}
