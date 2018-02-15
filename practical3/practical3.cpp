//==============================================================================
// Name        : practical3.cpp
// Author      : your name
// Version     : 1.0
// Description : practical 3 test program to exercise the simple sort algorithms
//==============================================================================

#include <string>
#include "Array.h"
#include "Sort.h"
#include <random>

using namespace std;

// PostCondition: array is filled with random numbers 1..range
//void fillRandom(Array<int> & data, int range=100) {
//	for (int i = 0; i < data.length(); i++) {
//		data[i] = rand() % 100 + 1;
//	}
//}

// return difference in the largest and smallest elements in the array  
int maxDiff(const Array<int> & data) {
	int min = data[0];
	int max = data[0];

	for (int i = 0; i < data.length(); i++) {
		if (data[i] < min) {
			min = data[i];
		}
		if (data[i] > max) {
			max = data[i];
		}
	}

	cout << "Max is: " << max << endl;
	cout << "Min is: " << min << endl;
	cout << "Max - min = " << max - min << endl;
	return (max - min);
}
// Compare performance of selection/insertion sort.
void testBoth() {

}

// test string sorting
void testString() {

}

int Random() {
	std::random_device rd; //generator 1
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 100);
	int chance = dis(gen);
	return chance;
}

void fillRandom(Array<int> & data) {
	for (int i = 0; i < data.length(); i++) {
		data[i] = Random();
	}
}


// test selection sort
void testSelect() {
	Array<int> test(10);
	fillRandom(test);
	cout << "Unsorted data: " << test << endl;
	selectionSort(test);
	cout << "Sorted data: " << test << endl;
	cout << endl;	
}

// test insertion sort
void testInsert() {
	Array<int> test(10);
	//t[0] = 10; t[1] = 9; t[2]=8; t[3] = 7; t[4] = 6; t[5] = 5; t[6] = 4; t[7] = 3; t[8] = 2; t[9] = 1;
	fillRandom(test);
	cout << "Unsorted data: " << test << endl;
	insertionSort(test);
	cout << "Sorted data: " << test << endl;
	cout << endl;
}

// Main method.
int main() {
	
	Array<int> t(10);
	t[0] = 10; t[1] = 9; t[2]=8; t[3] = 7; t[4] = 6; t[5] = 5; t[6] = 4; t[7] = 3; t[8] = 2; t[9] = 1;

	// call test methods here
	testSelect();
	testInsert();
	maxDiff(t);

	return 0;
}
