/*************************************************************************
 @Author: LMLzz - limingliang0527@gmail.com
 @Created Time : 2019-08-29 11:29:10
 @File Name: vector_constructor_by_copying.h
 @Description:
 ************************************************************************/

template <typename T>
void Vector<T>::copyFrom( T const* A, Rank lo, Rank hi ){
	_capacity = 2 * ( hi - lo );
	_elem = new T[_capacity];
	_size = 0;
	while( lo < hi )
		_elem[_size++] = A[lo+++];
}
