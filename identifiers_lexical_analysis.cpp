#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
Rules: First should be character and further Character and digits can repeat any  number of times.
*/
bool isChar(char c) {
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return true;
	return false;
}
bool isIdentifier(char c) {
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c>='0' && c<='9'))
		return true;
	
	return false;
}
int main() {
	int state = 1;
	printf("Enter the string:\n");
	char* str;
	char c = ' ';
	str=(char*)malloc(sizeof(char) * 1000);
	int i = 0;
	while(true){
		scanf("%c", &c);
		//printf("For ch=%d and ch=%c", c,c);
		str[i] = c;
		
		if (state == 1) {
			bool first = isChar(str[i]);
			if (first) {
				state = 2;
			}
			else state = -1;
		}
		else if (state == 2) {
			bool second = isIdentifier(str[i]);
			if (second) {
				state = 2;
			}
			else if ((str[i] == '\n' || str[i] == 32 || str[i]==10)) {
				state = 3;
			}
			else state = -1;
		}
		else if (state == 3) {
			if (str[i] != 32 && str[i]!='\n' && str[i]!=10) {
				state = -1;
			}
		}
		if (str[i] == 10 || str[i] == 13) {
			break;
		}
		i++;
	}
	if (state == 3) {
		printf("\nYes It is a identifier.");
	}
	else
		printf("\nNo its not identifier.\n");
	system("pause");
	return 0;
}