#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


int main() {

	char inputFloor[5] = "G";
	char floorList[9][5] = { "B3", "B2", "B1", "G", "1", "2", "3", "4", "5" };
	int currentFloorIndex = 3;
	size_t floorNumber = 9;
	int tempFloorIndex;
	char **floorQueue; //** means that this double array haven't been created yet

	printf("\n You are now on %s floor", inputFloor);
	printf("\n If you want to exit type \"exit\" \n");
	printAvaibleFloors();

	int passengersNumber = inputPassengersNumber();
	floorQueue = (char*)malloc(passengersNumber * sizeof(char*)); //https://learn.microsoft.com/en-us/cpp/c-language/sizeof-operator-c?view=msvc-170 | malloc = allocate memory for something | allocate memory for char array
	for (int i = 0; i < passengersNumber; i++) {
		floorQueue[i] = (char)malloc(5 * sizeof(char));
	}

	if (passengersNumber == 1) {
		while (1) {

			printf("\n Please enter the floor you want to go to: ");

			scanf("%4s", inputFloor);

			if (strcmp(inputFloor, "exit") == 0) {
				printf("\n Thank you for using an elevator \n");
				return 0;
			}

			tempFloorIndex = validFloor(inputFloor, floorList, floorNumber);
			if (tempFloorIndex >= 0) {
				currentFloorIndex = tempFloorIndex;
				printCurrentFloor(inputFloor);
			}

			else
				if (strcmp(inputFloor, "up") == 0) {
					if (currentFloorIndex < (floorNumber - 1)) {
						currentFloorIndex += 1;
						memcpy(inputFloor, floorList[currentFloorIndex], 5); // memcpy(copyTo, copyFrom, strSize) https://www.tutorialspoint.com/c_standard_library/c_function_memcpy.htm 
						printCurrentFloor(inputFloor);
					}
					else printf("\n You can't go higher than fifth floor");

				}
				else
					if (strcmp(inputFloor, "down") == 0) {
						if (currentFloorIndex - 1 >= 0) {
							currentFloorIndex -= 1;
							memcpy(inputFloor, floorList[currentFloorIndex], 5);
							printCurrentFloor(inputFloor);
						}
						else
							printf("\n You can't go lower than Basement 3");
					}
					else
						printf("\n There are no such floor as \"%s\"", inputFloor);
		}
	}
	else {

		for (int i = 0; i < passengersNumber; i++) {
			
			while (1) {
				printf("\n Enter the floor the [%d] passenger wants to go to: ", i + 1);
				scanf("%4s", inputFloor);
				tempFloorIndex = validFloor(inputFloor, floorList, floorNumber);
				if (tempFloorIndex >= 0) {
					floorQueue[i] = floorList[tempFloorIndex];
					break;
				}
				else {
					printf("\n There are no such floor as \"%s\"", inputFloor);
				}
				rewind(stdin);
			} 
		}
		moveToFloorQueue(passengersNumber, floorQueue);
	}
}

int validFloor(char inputString[], char floorList[][5], size_t floorNumber) //https://www.tutorialspoint.com/size-t-data-type-in-c#:~:text=The%20datatype%20size_t%20is%20unsigned,It%20can%20never%20be%20negative
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
int inputPassengersNumber() {
	int passengersNumber = 0;

	while (1) {
		printf("\n Enter passengers number: ");
		scanf("%d", &passengersNumber);

		if (passengersNumber > 31)
			printf(" So many passengers won't fit in the elevator\n");
		else
			if (passengersNumber <= 0)
				printf(" Incorrect number of passengers\n");
			else
				if (passengersNumber != 0)
					break;
				else
					printf("\n Incorrect input\n");

		passengersNumber = 0;
		rewind(stdin); // Clear buffer https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/rewind?view=msvc-170
	}

	return passengersNumber;
}
int moveToFloorQueue(int passengerNumber, char *floorQueue[5]) {
	for (int i = 0; i < passengerNumber; i++){
		printf("\n For the [%d] passenger the elevator stopped on the %s floor ",i+1, floorQueue[i]);
	}
}



