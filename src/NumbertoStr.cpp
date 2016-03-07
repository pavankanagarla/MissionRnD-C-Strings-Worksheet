/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>

int reverse(int number){
	int modified_number = 0;
	while (number != 0){
		modified_number = (modified_number * 10) + (number % 10);
		number = number / 10;
	}
	return modified_number;
}

void ftos(int main_number, char *s){
	int temp;
	int i = 0;
	for (i = 0; s[i] != '\0'; i++);
	while (main_number != 0){
		temp = main_number % 10;
		s[i] = temp + '0';
		i++;
		main_number = main_number / 10;
	}
	s[i] = '\0';
}

void number_to_str(float number, char *str,int afterdecimal){
	int i;
	if (number < 0) {
		number *= -1;
		str[0] = '-';
		str[1] = '\0';
	}
	else {
		str[0] = '\0';
	}
	int integer_part = number;
	float fraction_part = number - integer_part;
	integer_part = reverse(integer_part);
	ftos(integer_part, str);
	if (afterdecimal > 0){
		for (i = 0; str[i] != '\0'; i++);
		str[i] = '.';
		str[i + 1] = '\0';
		for (i = 0; i < afterdecimal; i++){
			fraction_part *= 10;
		}
		integer_part = fraction_part;
		integer_part = reverse(integer_part);
		ftos(integer_part, str);
	}
}
