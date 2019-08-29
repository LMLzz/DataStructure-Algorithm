/*************************************************************************
 @Author: LMLzz - limingliang0527@gmail.com
 @Created Time : 2019-08-29 16:54:11
 @File Name: vector_assignment.h
 @Description:
 ************************************************************************/
template <typename T> 
Vector<T>& Vector<T>::operator = ( Vector<T> const& V ) {
	if ( _elem ) delete []_elem;//释放原有内容
	copyFrom( V._elem, 0, V.size() );
	return *this;
}
