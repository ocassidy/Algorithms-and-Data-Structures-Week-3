/**
* Sort.h
*
* Template based Sort functions
*
* @author  your name
* @version 2.0
*/
#ifndef SORT_H_
#define SORT_H_

#include "Array.h"

// ------------------------ Sort Algorithm Templates ------------------------

// PostCondition: Array elements are sorted
template <class T>
void selectionSort(Array<T> & elements) {
	int min;
	int comparisons = 0;
	int movements = 0;

	for (int marker = 0; marker < elements.length() - 1; marker++) {
		min = marker;
		for (int i = marker + 1; i < elements.length(); i++) {
	    	comparisons++;
	 		if (elements[i] < elements[min]) {
				min = i;
			}		
		}

		// swap elements at position min and out
		/*T tmp = elements[marker];
		elements[marker] = elements[min];
		elements[min] = tmp;*/

		std::swap(elements[min], elements[marker]);		
		movements += 3;
	}
	std::cout << "Selection Moves = " << movements << " Comparisons = " << comparisons << std::endl;
}

// PostCondition: collection elements are sorted
template <class T>
void insertionSort(Array<T> & elements) {
	int in, out, temp;
	int comparisons = 0;
	int movements = 0;

	for (out = 1; out < elements.length(); out++) {
		temp = elements[out]; movements++;

		// find position for temp
		comparisons++;
		for (in = out; in > 0 && elements[in - 1] >= temp; in--) {
			elements[in] = elements[in - 1]; movements++;
			comparisons++;
		}
		// place temp in new position
		elements[in] = temp; movements++;
	}
	std::cout << "Insertion Moves = " << movements << " Comparisons = " << comparisons << std::endl;
}

template <class T>
void swap(T & a, T & b) {  
	T temp;
	temp = a;
	a = b;
	b = temp;
}
#endif

