// 40247163, 40281850, 40284702
#include <iostream>
#include <limits>


int* createArray(int requestedSize) {
    if (requestedSize <= 0) {
        return nullptr;
    }
    // Dynamically allocate memory on the heap
    return new int[requestedSize];
}

// deleteArray: deallocates the memory and resets to the empty state.
void deleteArray(int* &data) {
    delete[] data;    // release the memory, knows its size due to "data"s metadata
    data = nullptr;   // release pointer, now pointing to garbage mem
}

void initializeArray(int* arr, int sizeOfArray) {
    if (arr == nullptr) return;

    for (int i = 0; i < sizeOfArray; ++i) {
        arr[i] = i;
    }
}

void printArray(const int* data, int sizeOfArray) {
    std::cout << "Array (" << sizeOfArray << " elements): [";
    for (int i = 0; i < sizeOfArray; ++i) {
        std::cout << data[i];
        if (i < sizeOfArray - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}


int main() {
    int size = 0;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    while (std::cin.fail() || size <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a positive integer: ";
        std::cin >> size;
    }

    {
		int* simpleArray = createArray(size);
		initializeArray(simpleArray, size);
		printArray(simpleArray, size);
		deleteArray(simpleArray); 
    }

    return 0;
}
