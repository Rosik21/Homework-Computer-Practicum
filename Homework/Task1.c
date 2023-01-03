#include<stdio.h>
#include<string.h>



int main() {
	char currentFloor[5] = "G";
	char floorList[9][5] = { "B3", "B2", "B1", "G", "1", "2", "3", "4", "5" };
	size_t floorNumber = 9;

	printf("\n You are now on %s floor", currentFloor);
	printf("\n If you want to exit type \"exit\"");

	while (1) {
		printf("\n Please enter the floor you want to go to: ");

		scanf("%5s", currentFloor);

		if (strcmp(currentFloor, "exit") == 0) {
			printf("\n Thank you for using an elevator \n");
			return 0;
		} else {
			if (validFloor(currentFloor, floorList, floorNumber) == 1) {
				printf("\n You are now on %s floor", currentFloor);
				printf("\n If you want to exit type \"exit\", or select the next floor: ");
			} else {
				printf("\n There are no such floor as \"%s\"", currentFloor);
			}
		}
	}
}
int validFloor(char inputString[], char floorList[][5], size_t floorNumber) //size_t это как инт но всегда положительный
{
	for (int i = 0; i < floorNumber; i++) {
		if (strcmp(inputString, floorList[i]) == 0) {
			return 1;
		}
	}
	return 0;
}

