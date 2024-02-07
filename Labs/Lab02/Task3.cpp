/*
 * Programmer: Muhammad Abser Mansoor
 * Date: 4/2/24
 * Desc: Recursively check for a subset adding up to a certain number
 */

#include <iostream>
#include <string>

using namespace std;

bool hasSubsetSum(int *arr, int size, int targetsum) {
    
    if (targetsum == 0) {
        return true;
    }

    if (size < 0) {
        return false;
    }

    if (*(arr+size-1) > targetsum) {
        return hasSubsetSum(arr,size-1,targetsum);
    }

    return hasSubsetSum(arr, size - 1, targetsum) || (hasSubsetSum(arr, size - 1, targetsum - *(arr + size - 1)));
    

}

int main() {
    int arr[] = {1,5,3,6,7};
    hasSubsetSum(arr,5,8) ? cout << "True" : cout << "False";
}
