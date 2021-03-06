//The purpose of this program is to gain familiarity with tempalte classes and how they work.

#include "stdafx.h"
#include <iostream>


using namespace std;

template <typename T>
class nPoint {
public:
	nPoint() { size_ = 0; } //Constructor 1 Declaration & Definition
	nPoint(int size); //Constructor 2 Decleration
	nPoint(T data[], int size); //Constructor 3 Declaration 

	T get_data(int index)const { return data_[index]; }  //Array Getter
	int get_size()const { return size_; } //Int Getter

	void operator =(nPoint<T> a); //= operator Declaration
	void print(); //Print Declaration
private:
	int size_;
	T data_[10];
};

template <typename T>
nPoint<T>::nPoint(int size) { //Constructor 2 Definition
	size_ = size;
	for (int i = 0; i < size_; i++) {
		data_[i] = T();
	}
}

template <typename T>
nPoint<T>::nPoint(T data[], int size) { //Constructor 3 Definitoon
	size_ = size;
	for (int i = 0; i < size_; i++) {
		data_[i] = data[i];
	}
}

template <typename T>
void nPoint<T>::operator =(nPoint<T> a) { //Both types must be able to use the operator =
	size_ = a.get_size();
	for (int i = 0; i < size_; i++) {
			data_[i] = a.get_data(i);
	}
}

	template <typename T> //Print Definition
	void nPoint<T>::print() {
		cout << "size: " << size_
			<< "\nData: ";
		for (int i = 0; i < size_; i++) {
			cout << data_[i] << ", ";
		}
		cout << "\n " << endl;
	}

int main()
{
		int nums[3] = { 1, 2, 3 };
		int nums2[5] = { 4,5,6,7,8, };
		nPoint<int> a = { nums, 3 };
		nPoint<int> b = { nums2, 5 };

		a.print();
		b.print();

		a = b;
		a.print();

		system("pause");
		return 0;
}

