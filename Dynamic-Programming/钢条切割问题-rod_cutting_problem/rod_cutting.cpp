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

int cut_rod(const int *price_table, int n);
int memoized_cut_rod(const int* price_table, int n);
int memoized_cut_rod_aux(const int* price_table, int *revenue, int n);
int bottom_up_rod_cut(const int* price_table, int n);

int main() {
    timeval start, end;

    for(int i = 1; i <= 10; i++) {
        gettimeofday(&start, NULL);
        int result = bottom_up_rod_cut(p, i);
        gettimeofday(&end, NULL);
        cout<< "n = "<<  i << ", memoized recusive algorithm is executed for" << 100000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << endl;

        gettimeofday(&start, NULL);
        result = cut_rod(p, i);
        gettimeofday(&end, NULL);
        cout<< "n = "<<  i << ",  naive recusive algorithm is executed for" << 100000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << endl;
    }
    return 0;
}

int cut_rod(const int *price_table, int n) {
    if (n==0) 
        return 0;
    int q = INT_MIN;
    for (int i=1; i<=n; ++i) {
        q = max(q, price_table[i] + cut_rod(price_table, n-i));
    }
    return q;
}

int memoized_cut_rod(const int* price_table, int n) {
    int *revenue = new int[n+1];
    for(int i=0; i<=n; ++i) {
        revenue[i] = INT_MIN;
    }
    return memoized_cut_rod_aux(price_table, revenue, n);
}

int memoized_cut_rod_aux(const int* price_table, int * revenue, int n) {
    int r =0;
    if ( revenue[n] >=0 ) return revenue[n];
    if ( n == 0 ) r=0;
    else {
        r = INT_MIN;
        for ( int i = 1; i <= n; i++) {
            r =  max(r, price_table[i] + memoized_cut_rod_aux(price_table, revenue, n-i));
        }
    }
    revenue[n] = r;
    return r;
}

int bottom_up_rod_cut(const int* price_table, int n) {
    int* revenue = new int[n+1];
    revenue[0] = 0;
    for(int i=1; i <=n; ++i) {
        int q = INT_MIN;
        for(int j = 1;j<=i;++j) {
            q = max(q, p[j] + revenue[i-j]);
        }
        revenue[i] = q;
    }
    return revenue[n];
}