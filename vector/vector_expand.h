/*************************************************************************
 @Author: LMLzz - limingliang0527@gmail.com
 @Created Time : 2019-08-24 17:17:50
 @File Name: vector_expand.h
 @Description:
 ************************************************************************/

#ifndef __VECTOR_EXPAND_H__
#define __VECTOR_EXPAND_H__

template <typename T> 
void Vector<T>::expand(){
    // 尚未满员时，无需扩容
    if (_size < _capacity)
        return;
    if (_capacity < DEFAULT_CAPACITY)
        _capacity = DEFAULT_CAPACITY;

    T* odlElem = _elem;
    _elem = new T[_capacity << 1];
    //复制原向量内容
    for ( int i = 0; i < _size; i++ )
        _elem[i] = oldElem[i];
    delete [] oldElem;
}
#endif
