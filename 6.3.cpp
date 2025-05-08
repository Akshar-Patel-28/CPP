#include <iostream>
void mergeSortedArrays(int* arr1, int size1, int* arr2, int size2, int*& result, int& resultSize) {
resultSize = size1 + size2;
result = new int[resultSize];
int i = 0, j = 0, k = 0;
// Merge both arrays in sorted order
while (i < size1 && j < size2) {
if (arr1[i] < arr2[j]) {
result[k++] = arr1[i++];
} else {
result[k++] = arr2[j++];
}
}
// Copy remaining elements
while (i < size1) result[k++] = arr1[i++];
while (j < size2) result[k++] = arr2[j++];
}
int main() {int size1, size2;
std::cout << "Enter size of first sorted array: ";
std::cin >> size1;
int* arr1 = new int[size1];
std::cout << "Enter " << size1 << " sorted elements:\n";
for (int i = 0; i < size1; ++i) std::cin >> arr1[i];
std::cout << "Enter size of second sorted array: ";
std::cin >> size2;
int* arr2 = new int[size2];
std::cout << "Enter " << size2 << " sorted elements:\n";
for (int i = 0; i < size2; ++i) std::cin >> arr2[i];
int* mergedArray = nullptr;
int mergedSize = 0;
mergeSortedArrays(arr1, size1, arr2, size2, mergedArray, mergedSize);
std::cout << "Merged sorted array:\n";
for (int i = 0; i < mergedSize; ++i)
std::cout << mergedArray[i] << " ";
std::cout << "\n";
// Memory cleanup
delete[] arr1;
delete[] arr2;
delete[] mergedArray;

return 0;

}

