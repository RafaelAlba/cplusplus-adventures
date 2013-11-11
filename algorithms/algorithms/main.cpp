//
//  main.cpp
//  algorithms
//
//  Created by Rafael Alba on 11/8/13.
//  Copyright (c) 2013 Rafael Alba. All rights reserved.
//

#include <iostream>

using namespace std;

// debugging functions
void print_array(int arr[], int length)
{
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << endl;
}


void insertion_sort(int unsorted[], int length)
{
    for (int i = 1; i < length; i++) {
        int current = unsorted[i];
        
        int k = i - 1;
        
        while (k >= 0) {
            int comparing = unsorted[k];
            
            if (current >= comparing) {
                break;
            } else {
                unsorted[k+1] = comparing;
                unsorted[k] = current;
                k--;
            }
        }
    }
}

void selection_sort(int unsorted[], int length)
{
    for (int i = 0; i < length; i++) {
        int min = INT32_MAX;
        int min_index = -1;
        for (int j = i; j < length; j++) {
            if (unsorted[j] < min) {
                min = unsorted[j];
                min_index = j;
            }
        }
        min = unsorted[min_index];
        unsorted[min_index] = unsorted[i];
        unsorted[i] = min;
    }
    
}

int main(int argc, const char * argv[])
{
    int unsorted[10] = {9, 8 , 7 , 6, 5, 4, 3, 2, 1, 0};
//    insertion_sort(unsorted, 10);
//    selection_sort(unsorted, 10);
    print_array(unsorted, 10);
    return 0;
}

