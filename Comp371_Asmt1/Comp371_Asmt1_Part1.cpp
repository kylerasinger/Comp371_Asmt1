// 40247163, 40281850, 40284702
#include <iostream>
#include <limits>

class DynamicArray
{
private:
    int* data;  // points to allocated memory for data
    int  sizeOfArray;

public:
    DynamicArray() : data(nullptr), sizeOfArray(0) {}

    ~DynamicArray() {
        // RAII pattern, prevents mem leaks by deleting memory when object destroys (goes out of scope) 
        deleteArray();
    }

    int* createArray(int requestedSize) {
        // prevents reallocating over an existing array
        deleteArray();

        sizeOfArray = requestedSize;
        data = new int[sizeOfArray];  // dynamic alloc, need to remember to delete or we get a memory leak
        return data;
    }

    // deleteArray: deallocates the memory and resets to the empty state.
    void deleteArray() {
        delete[] data;    // release the memory, knows its size due to "data"s metadata
        data = nullptr;   // release pointer, now pointing to garbage mem
        sizeOfArray = 0;
    }

    void initializeArray() {
        for (int i = 0; i < sizeOfArray; ++i) {
            data[i] = i;
        }
    }

    void printArray() const {
        std::cout << "Array (" << sizeOfArray << " elements): [";
        for (int i = 0; i < sizeOfArray; ++i) {
            std::cout << data[i];
            if (i < sizeOfArray - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";
    }
};

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
        DynamicArray array;

        array.createArray(size);
        array.initializeArray();
        array.printArray();
        array.deleteArray(); // could remove this, and it would still free the memory due to the destructor
    } // destructs here, when the program leaves its scope, calling its destructor

    return 0;
}
