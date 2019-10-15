/*************************************************************************
 @Author: LMLzz - limingliang0527@gmail.com
 @Created Time : 2019-10-15 20:04:13
 @File Name: rod_cutting.cpp
 @Description:
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <limits.h>
#include <sys/time.h>
const int p[11] = { 0,1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };

using std::cout;
using std::endl;
using std::max;

int cut_rod(const int *p, int n){
    if (n==0) 
        return 0;
    int q = INT_MIN;
    for (int i=1; i<=n; ++i) {
        q = max(q, p[i] + cut_rod(p, n-i));
    }
    return q;
}


int main() {
    timeval start, end;

    cout << "Hello World" << endl;
    for(int i = 1; i <= 10; i++) {
        gettimeofday(&start, NULL);
        cout << cut_rod(p, i) << endl;
        gettimeofday(&end, NULL);
        cout << "Naive recusive algorithm is executed for" << 100000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << endl;
    }
    return 0;
}
