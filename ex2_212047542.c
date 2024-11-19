#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	int score = 0, counter = 0;
	printf("Please enter your exam score (0-100):\n");
	scanf("%d", &score);
	counter = 1;
	while (!((score >= 0) && (score <= 100))) {
		if (counter < 3) {
			printf("Invalid input score: %d\nPlease enter a new exam score in the range 0-100:\n", score);
			scanf("%d", &score);
			counter++;
		}
		else {
			printf("The user has inserted 3 consecutive times an invalid score.\nExiting the program!");
			return 1;
		}
	}
	switch (score / 10) {
		case(9):
			printf("Grade: A\nWell Done!");
			break;
		case(8):
			printf("Grade: B\nGood job! There is room for improvement.");
			break;
		case(7):
			printf("Grade: C\nNot bad! But you can do better..");
			break;
		case(6):
			printf("Grade: D\nYou passed, but you need to work harder next time!");
			break;
		case(5):
			printf("Grade: E\nYou barely passed - please review the material once again."); 
			break;
		default:
			printf("Grade: F\nYou failed, better luck next time!");
			break;
	}
	
}