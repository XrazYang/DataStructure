//
// Created by answer on 17-10-10.
//

#ifndef HEAPSORT_SORTTESTHELPER_H
#define HEAPSORT_SORTTESTHELPER_H

#include<iostream>
#include <ctime>
#include <cassert>
#include <algorithm>

using namespace std ;

namespace  SortTestHelper{

    //生成[rangl ,rangR）范围里面的随机数
    int * generateRandomArray(int n ,int rangL ,int rangR){

        assert( rangL <= rangR);
        int *arr = new int[n];

        srand(time(NULL));

        for(int i = 0 ; i < n ; i++){
            arr[i] = rand()%(rangR - rangL +1) + rangL ;
        }
        return  arr ;
    }

    template <typename T>
    T* copyRandomArray(T arr[] , int len){
        T * copyArr = new T[len];
        copy(arr,arr+len,copyArr);
        return  copyArr ;
    }


    template <typename  T>
    void printArry(T arr[] , int len){
        for (int i = 0; i < len; ++i) {
            cout<<arr[i]<<" ";
        }
        cout<<endl ;
    }

    template <typename  T>
    bool isSorted(T arr[] , int len){

        for (int i = 0; i < len-1; ++i) {
            if (arr[i] > arr[i+1])
                return false ;
        }
        return true ;
    }


    template <typename  T>
    void testSort(string sortName , void (* sort)(T arr[] ,int len),T arr[] , int len){

        clock_t  startTime = clock();
        sort(arr, len);

        clock_t  endTime = clock();

        isSorted(arr ,len);
        cout<<sortName << " : "<< double(endTime - startTime )/CLOCKS_PER_SEC << "s" <<endl ;
    }



}

#endif //HEAPSORT_SORTTESTHELPER_H
