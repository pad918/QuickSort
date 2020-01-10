#include<stdio.h>
#include<iostream>
#include <stdlib.h>
#include <vector> 
#include <ctime>

void printList(std::vector<int> list) {
	for (int i = 0; i < list.size(); i++) {
		std::cout << list[i] << std::endl;
	}
}
void swap(std::vector<int> &list, int a, int b) {
	int temp = list[a];
	list[a] = list[b];
	list[b] = temp;
}
void moveList(std::vector<int> &list, bool dir, int min, int max) { //true dir = down
	if (dir) {
		for (int i = min; i < max; i++) {
			list[i] = list[i + 1];
			
		}
		

	}
	else {
		for (int i = max - 1; i >= min; i--) {
			list[i + 1] = list[i];
		}
	}
}
void quicksortBetween(std::vector<int> &list, int min, int max, int piv) {
	//std::cout << "Mittenpunkten = " << piv << std::endl;
	//printList(list);
	//std::cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_";
	int stegAttFlyttaPiv = 0; //åt höger 
	int felåtHöger = 0;
	int felåtVänster = 0;
	for (int i = min; i < piv; i++) {
		if (list[i] >= list[piv]) {
			felåtVänster++;
		}
	}
	for (int i = piv + 1; i <= max; i++) {
		if (list[i] <= list[piv]) {
			felåtHöger++;
		}
	}
	stegAttFlyttaPiv = (felåtHöger - felåtVänster);
	
	swap(list, piv, piv + stegAttFlyttaPiv);
	piv += stegAttFlyttaPiv;
	for (int i = min; i < piv; i++) {
		if (list[i] >= list[piv]) {
			for (int j = piv + 1; j <= max; j++) {
				if (list[j] <= list[piv]) {
					swap(list, i, j);
					break;
				}
			}
		}
	}

	int elementsOfLowSide = piv - min;
	if (elementsOfLowSide > 2) {
		int middle = (int)(min + piv - 1) / 2.0f;
		quicksortBetween(list, min, piv-1, middle);
	}
	else if (elementsOfLowSide == 2) {
		if (list[min] > list[min + 1]) {
			int temp = list[min];
			list[min] = list[min + 1];
			list[min + 1] = temp;
		}
	}
	int elementsOfHightSide = max - piv;
	if (elementsOfHightSide > 2) {
		int middle = (int)(max + piv + 1) / 2.0f;
		quicksortBetween(list, piv + 1,max, middle);
	}
	else if (elementsOfHightSide == 2) {
		if (list[max] < list[max - 1]) {
			int temp = list[max];
			list[max] = list[max - 1];
			list[max] = temp;
		}
	}
}





int main() {
	std::cout << "Fungerar" << std::endl;
	std::vector<int> j;
	/*j.push_back(5);
	j.push_back(3);
	j.push_back(8);
	j.push_back(7);
	j.push_back(8);
	j.push_back(9);
	j.push_back(2);
	j.push_back(1);
	*/
	for (int i = 0; i < 1000; i++) {
		j.push_back(rand() % 100000);//18.118sekunder
	}
	std::cout << "Ordning från början :" << std::endl;
	printList(j);
	std::cout << "---------------------------" << std::endl;
	int middle = j.size() / 2;
	std::clock_t start;
	double duration;
	start = std::clock();
	quicksortBetween(j, 0, j.size()-1, middle);
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	//moveList(j ,true,0, 7);
	printList(j);
	std::cout << "Calculated in : " << duration << '\n';
	//std::cout << "Sorted numbers = " << std::endl;
	/*for (int i = 0; i < (sizeof(list) / sizeof(*list)); i++) {
		std::cout << list[i] << std::endl;
	}
	*/
	
	std::cin.get();
	return 0;
}