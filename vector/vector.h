/*************************************************************************
 @Author: LMLzz - limingliang0527@gmail.com
 @Created Time : 2019-08-24 10:06:34
 @File Name: vector.h
 @Description:
 	the header file of vector structure
 ************************************************************************/

#ifndef __VECTOR_H__
#define __VECTOR_H__


typedef int Rank;
#define DEFAULT_CAPACITY 3

template <typename T> class vector {
protected:
	Rank _size;		//���ù�ģ
	int _capacity;	//��������
	T* _elem;		//������

	void copyFrom (T const* A, Rank lo, Rank hi);
//	void expand();	//������������
//	void shrink();	//װ������Сʱѹ��
//	void bubble(Rank lo, Rank hi);
//	void bubbleSort(Rank lo, Rank hi);
//	Rank max (Rank lo, Rank hi);
//	Rank selectionSort(Rank lo, Rank hi);
//	void merge(Rank lo, Rank mi, Rank hi);
//	void mergeSort(Rank lo, Rank hi);
//	Rank partition(Rank lo, Rank hi);
//	void quickSort(Rank lo, Rank hi);
//	void heapSort(Rank lo, Rank hi);
public:
	// ���캯��
	Vector (int c = DEFAULT_CAPACITY, int s = 0, T v = 0){ //����Ϊc����ģΪs������Ԫ�س�ʼΪv
		_elem = new T[_capacity = c];
		for(_size = 0; _size < s; _elem[_size++] = v);
	}
	Vector(T const* A, Rank n) {
		copyFrom(A, 0, n);
	}
	Vector(T const* A, Rank lo, Rank hi){
		copyFrom(A, lo, hi);
	}
	Vector(Vector<T> const& V){
		copyFrom(V._elem, 0, V._size);
	}
	// ��������
	~Vector(){ delete [] _elem;}
	// ��
	Rank size() const {
		return _size;
	}
	bool empty() const {
        	return !_size;
	}
	// ��д���ʽӿ�
	Vector<T> & operator= (Vector<T> const&);
}

#include "vector_implementation.h"
#endif
