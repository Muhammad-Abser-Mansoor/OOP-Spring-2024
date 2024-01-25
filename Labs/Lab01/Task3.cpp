#include <iostream>
#include <string>

using namespace std;

void find (int *ar,int tar,int size) {
    int alr[size] = {0};
    int k = 0;
    int check = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            check = 0;
            if (i != j && ar[i] + ar[j] == tar) {
                for (int m = 0;m < k; m++) {
                    if (i + j == alr[m]) {
                        check++;
                        break;
                    }
                }
                if (!check) {
                cout << "[" << i << "," << j << "]" << endl;
                alr[k] = i + j;
                k++; }
            }
        }
    }
    return;
}

int main() {
    int nums[4] = {2,7,11,15};
    int tar = 9;
    find (nums,9,4);
    return 0;
}
