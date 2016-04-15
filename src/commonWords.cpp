
/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31

int compare(int starting_index, int ending_index, char *str1, char *str2){
	int temp;
	int i;
	for (i = 0; str2[i] != '\0'; i++){
		for (temp = starting_index; str1[temp] == str2[i] && temp < ending_index; temp++, i++);
		if (temp >= ending_index && (str2[i] == ' ' || str2[i] == '\0'))
			return 1;
	}
	return 0;
}

void copy(char ** res, char *str1, int resIndex, int startIndex, int endIndex) {
	int i;
	for (i = 0; startIndex < endIndex; startIndex++, i++) {
		res[resIndex][i] = str1[startIndex];
	}
}

char ** commonWords(char *str1, char *str2) {
	char **result;
	int result_index;
	int starting_index;
	int ending_index;
	if (str1 == NULL || str2 == NULL)
		return NULL;
	result = (char**)malloc(SIZE * sizeof(char *));
	for (result_index = 0; result_index < SIZE; result_index++)
		result[result_index] = (char*)malloc(SIZE * sizeof(char));
	for (starting_index = 0; starting_index < SIZE; starting_index++)
		for (ending_index = 0; ending_index < SIZE; ending_index++)
			result[starting_index][ending_index] = '\0';
	result_index = 0;
	starting_index = 0;
	for (ending_index = 0; str1[ending_index] != '\0'; ending_index++){
		if (str1[ending_index] == ' ') {
			if (compare(starting_index, ending_index, str1, str2)) {
				copy(result, str1, result_index, starting_index, ending_index);
				result_index++;
			}
			starting_index = ending_index + 1;
		}
	}
	if (compare(starting_index, ending_index, str1, str2)) {
		copy(result, str1, result_index, starting_index, ending_index);
	}
	if (result[0][0] == '\0')
		return NULL;
	return result;
}