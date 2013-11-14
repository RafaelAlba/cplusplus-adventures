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

void print_array_pointer(int * arr, int length)
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

int * merge_sort(int unsorted[], int length)
{
    if (length == 1) {
        int * result = new int[1];
        result[0] = unsorted[0];
        return result;
    }
    if (length == 2) {
        int * result = new int[2];
        if (unsorted[0] > unsorted[1]) {
            result[0] = unsorted[1];
            result[1] = unsorted[0];
        } else {
            result[0] = unsorted[0];
            result[1] = unsorted[1];
        }
        return result;
    }
    
    int dividingIndex;
    if (length % 2 == 1) {
        dividingIndex = (length / 2);
    } else {
        dividingIndex = (length / 2) - 1;
    }
    
    int leftLength = dividingIndex + 1;
    int rightLength = length - dividingIndex - 1;
    int * unsorted_left_side = new int[leftLength];
    int * unsorted_right_side = new int[rightLength];
    for (int i = 0; i <= dividingIndex; i++) {
        unsorted_left_side[i] = unsorted[i];
    }
    
    for (int i = leftLength; i <= length; i++) {
        unsorted_right_side[i - dividingIndex - 1] = unsorted[i];
    }
    
    int * sorted_left = merge_sort(unsorted_left_side, leftLength);
    int * sorted_right = merge_sort(unsorted_right_side, rightLength);
    delete [] unsorted_left_side;
    delete [] unsorted_right_side;

    int * sorted = new int[length];

    int k = 0;
    int l = 0;
    for (int i = 0; i < length; i++) {
        if (k < leftLength && l < rightLength) {
            int left = sorted_left[k];
            int right = sorted_right[l];
            if (left < right) {
                sorted[i] = left;
                k++;
            } else {
                sorted[i] = right;
                l++;
            }

        } else {
            if (k < leftLength) {
                sorted[i] = sorted_left[k];
                k++;
            } else {
                sorted[i] = sorted_right[l];
                l++;
            }
        }
    }
    
    delete [] sorted_left;
    delete [] sorted_right;
    
    return sorted;
}

int main(int argc, const char * argv[])
{
    int unsorted[10] = {9, 8 , 7 , 6, 5, 4, 3, 2, 1, 0};
    print_array(unsorted, 10);
//    insertion_sort(unsorted, 10);
//    selection_sort(unsorted, 10);
    int * sorted = merge_sort(unsorted, 10);
    print_array(sorted, 10);
    delete [] sorted;
    return 0;
}

