#include <iostream>
#include "strategy.h"
#include "component.h"


Sort::Sort() {}

void SelectionSort::sort(Container* container) {
	int cSize = container->size();
	for(int i = 0; i < cSize; i++) {
		double min = container->at(i)->evaluate();
		int min_index = i;
		for(int j = i + 1; j < cSize; j++) {
			if (container->at(j)->evaluate() < min) {
				min = container->at(j)->evaluate();
				min_index = j;
			}
		}
		if (i != min_index) {
			container->swap(i,min_index);
		}
	}
}

void BubbleSort::sort(Container* container) {
	int cSize = container->size();
	std::cout << "\nIn the BubbleSort. Container->size() is " << cSize << "\n";
	for(int i = 0; i < cSize - 1; i++) {
		for(int j = 0; j < cSize - i - 1; j++) {
			if (container->at(j)->evaluate() > container->at(j + 1)->evaluate()) {
				container->swap(j,j+1);
			//	container->swap(container->at(j)->evaluate(), container->at(j + 1)->evaluate());
			}
		}
	}
}
