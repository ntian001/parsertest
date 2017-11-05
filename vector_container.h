#ifndef VECTOR_CONTAINER_H
#define VECTOR_CONTAINER_H

#include <stdexcept>
#include <vector>
#include "strategy.h"
#include "container.h"
#include "component.h"

class noSortFunction2: public std::exception
{
	public:
	virtual const char* what() const throw()
	{
		return "\nYou need to call the set_sort_function.\n";
	}
} mynosort2;

bool checkSort2(Sort* sort_function) {
	if (sort_function == 0) {
//		throw noSortFunction("\nYou need to call the set_sort_function\n");
		throw mynosort2;
		return(0);
	}
	return(1);

}

class VectorContainer : public Container
{
	public:
		std::vector<Base*> cVector;
		VectorContainer() {}
		
		void add_element(Base* element) { cVector.push_back(element); }
		
		void print() {
			for (unsigned int i = 0; i < cVector.size(); i++)
			{
				std::cout << cVector.at(i)->evaluate() << ' ';
			}
		}
		
		void set_sort_function(Sort* sort_function) { this->sort_function = sort_function; }
		
		void sort() {
			try {
				if (checkSort2(sort_function)) {
					sort_function->sort(this);
				}
			}
			catch (const noSortFunction2& e)
			{
				std::cout << e.what();
			}
		}

		void swap(int i, int j){
			Base* temp = cVector.at(i);
			cVector.at(i) = cVector.at(j);
			cVector.at(j) = temp;
		}
		
		Base* at(int i) { return cVector.at(i); }
		
		int size() { return cVector.size(); }
		
		
		// DESTRUCTOR
		~VectorContainer() {
			for(unsigned i = 0; i < cVector.size(); ++i)
			{
				delete cVector.at(i);
			}
		}
};

#endif //VECTOR_CONTAINER_H
