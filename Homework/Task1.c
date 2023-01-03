#include<stdio.h>
#include<string.h>



int main() {
	char inputFloor[5] = "G";
	char floorList[9][5] = { "B3", "B2", "B1", "G", "1", "2", "3", "4", "5" };
	int currentFloorIndex = 3;
	size_t floorNumber = 9;
	int tempFloorIndex;

	printf("\n You are now on %s floor", inputFloor);
	printf("\n If you want to exit type \"exit\" \n");
	printAvaibleFloors();

	while (1) {
		printf("\n Please enter the floor you want to go to: ");

		scanf("%5s", inputFloor);

		if (strcmp(inputFloor, "exit") == 0) {
			printf("\n Thank you for using an elevator \n");
			return 0;
		}

		tempFloorIndex = validFloor(inputFloor, floorList, floorNumber);
		if (tempFloorIndex >= 0) {
			currentFloorIndex = tempFloorIndex;
			printCurrentFloor(inputFloor);
		}

		else if(strcmp(inputFloor, "up") == 0) {
			if (currentFloorIndex < (floorNumber - 1)) {
				currentFloorIndex += 1;
				memcpy(inputFloor, floorList[currentFloorIndex], 5); // memcpy(copyTo, copyFrom, strSize) Копирует строку из одной переменной в другую
				printCurrentFloor(inputFloor);
			} else printf("\n You can't go higher than fifth floor");

		}
		else if (strcmp(inputFloor, "down") == 0) {
			if (currentFloorIndex - 1 >= 0){
				currentFloorIndex -= 1;
				memcpy(inputFloor, floorList[currentFloorIndex], 5);
				printCurrentFloor(inputFloor);
			} else 
				printf("\n You can't go lower than Basement 3");
		}	

		else
			printf("\n There are no such floor as \"%s\"", inputFloor);
	}
}
int validFloor(char inputString[], char floorList[][5], size_t floorNumber) //size_t это как инт но всегда положительный
{
	for (int i = 0; i < floorNumber; i++) {
		if (strcmp(inputString, floorList[i]) == 0) {
			return i;
		}
	}
	return -1;
}
int printAvaibleFloors() {
	printf("\n Avaible floors are: ");
	printf("\n Basement 1   -> [B1]");
	printf("\n Basement 2   -> [B2]");
	printf("\n Basement 3   -> [B3]");
	printf("\n Ground floor -> [G]");
	printf("\n First floor  -> [1]");
	printf("\n Second floor -> [2]");
	printf("\n Third floor  -> [3]");
	printf("\n Fourth floor -> [4]");
	printf("\n Fifth floor  -> [5]\n");
	printf("\n To go up   -> [up]");
	printf("\n To go down -> [down]\n");
	return 0;
}  
int printCurrentFloor(char currentFloor[]) {
	printf("\n You are now on %s floor", currentFloor);
	return 0;
}

