#include<stdio.h>
#include<string.h>



int main() {
	char currentFloor[5] = "G";

	printf("\n You are now on %s floor", currentFloor);
	printf("\n If you want to exit type \"exit\"");
	printf("\n Please enter the floor you want to go to: ");

	while (1) {

		scanf("%4s", currentFloor);

		if (strcmp(currentFloor, "exit") == 0) {
			printf("\n Thank you for using an elevator ");
			return 0;
		} else {
			if (strcmp(currentFloor, "B3") == 0 ||
				strcmp(currentFloor, "B2") == 0 ||
				strcmp(currentFloor, "B1") == 0 ||
				strcmp(currentFloor, "G") == 0 ||
				strcmp(currentFloor, "1") == 0 ||
				strcmp(currentFloor, "2") == 0 ||
				strcmp(currentFloor, "3") == 0 ||
				strcmp(currentFloor, "4") == 0 ||
				strcmp(currentFloor, "5") == 0)
			{
				printf("\n You are now on %s floor", currentFloor);
				printf("\n If you want to exit type \"exit\", or select the next floor: ");
				continue;
			}
		}
	}
}

