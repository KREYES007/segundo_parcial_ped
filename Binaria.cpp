#include<iostream>

int FindLargestSmaller(
const int values[],
int n,
int target) {
    int left = 0;
    int right = n - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (values[mid] < target) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1; 
        }
    }

    return result;
}

main(){
    
    int values[] = {2, 4, 4, 7, 9, 12, 15};
    int n = sizeof(values) / sizeof(values[0]);

    int target1 = 6;
    int result1 = FindLargestSmaller(values, n, target1);
    std::cout << "Target: " << target1 << ", Resultado: " << result1 << std::endl;

    int target2 = 4;
    int result2 = FindLargestSmaller(values, n, target2);
    std::cout << "Target: " << target2 << ", Resultado: " << result2 << std::endl;

    int target3 = 2;
    int result3 = FindLargestSmaller(values, n, target3);
    std::cout << "Target: " << target3 << ", Resultado: " << result3 << std::endl;

    int target4 = 20;
    int result4 = FindLargestSmaller(values, n, target4);
    std::cout << "Target: " << target4 << ", Resultado: " << result4 << std::endl;
}
