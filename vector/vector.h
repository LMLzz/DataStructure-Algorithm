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
	Rank _size;		//设置规模
	int _capacity;	//设置容量
	T* _elem;		//数据区
	void copyFrom (T const* A, Rank lo, Rank hi);
	void expand();	//用于容量扩充
	void shrink();	//装填因子小时压缩
	void bubble(Rank lo, Rank hi);
	void bubbleSort(Rank lo, Rank hi);
	Rank max (Rank lo, Rank hi);
	Rank selectionSort(Rank lo, Rank hi);
	void merge(Rank lo, Rank mi, Rank hi);
	void mergeSort(Rank lo, Rank hi);
	Rank partition(Rank lo, Rank hi);
	void quickSort(Rank lo, Rank hi);
	void heapSort(Rank lo, Rank hi);
public:
	//构造函数
	Vector (int c = DEFAULT_CAPACITY, int s = 0, T v = 0){ //容量为c、规模为s、所有元素初始为v
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
	//析构函数
	~Vector(){ delete [] _elem;}
	//读
	Rank size() const {
		return _size;
	}
	bool empty() const {
        return !_size;
    }
    int disordered() const;
    Rank find(T const& e) const {
        return find(e, 0, _size);
    }
    Rank find(T const& e, Rank lo, Rank hi) const;
    Rank search (T const&e) const {
        return (0>=_size) ? -1 : search(e, 0, _size);
    }
	//写
}

#endif
