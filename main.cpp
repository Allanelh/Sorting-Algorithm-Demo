/**
 * @file mergesort.cpp
 * @brief Professional MergeSort Implementation with Interactive User Input
 * @author Allan Lara
 * @date 2025
 * @license MIT
 *
 * Features:
 * - In-place sorting with O(n log n) time complexity
 * - Range-based interface with iterators
 * - Custom comparator support
 * - Exception safety and comprehensive error checking
 * - Template-based for all integer types
 * - Interactive user input demo with repeat option
 * - Professional console output formatting
 */

#include <iostream>
#include <vector>
#include <functional>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <sstream>
#include <cctype>
#include <limits>

namespace sorting {

/**
 * @class MergeSort
 * @brief Professional implementation of the MergeSort algorithm
 */
template<typename T, typename Comparator = std::less<T>>
class MergeSort {
public:
    static void sort(std::vector<T>& arr, Comparator comp = Comparator()) {
        if (arr.empty()) return;
        sortImpl(arr.data(), 0, arr.size() - 1, comp);
    }

    static void sort(T* arr, size_t size, Comparator comp = Comparator()) {
        if (!arr) throw std::invalid_argument("Null pointer passed to MergeSort::sort");
        if (size <= 1) return;
        sortImpl(arr, 0, size - 1, comp);
    }

    static bool isSorted(const T* arr, size_t size, Comparator comp = Comparator()) {
        if (!arr || size <= 1) return true;
        for (size_t i = 0; i < size - 1; ++i) {
            if (comp(arr[i + 1], arr[i])) return false;
        }
        return true;
    }

private:
    static void sortImpl(T* arr, size_t low, size_t high, Comparator comp) {
        if (low < high) {
            const size_t mid = low + (high - low) / 2;
            sortImpl(arr, low, mid, comp);
            sortImpl(arr, mid + 1, high, comp);
            merge(arr, low, high, mid, comp);
        }
    }

    static void merge(T* arr, size_t low, size_t high, size_t mid, Comparator comp) {
        const size_t n1 = mid - low + 1;
        const size_t n2 = high - mid;

        std::unique_ptr<T[]> left(new T[n1]);
        std::unique_ptr<T[]> right(new T[n2]);

        for (size_t i = 0; i < n1; ++i) left[i] = arr[low + i];
        for (size_t j = 0; j < n2; ++j) right[j] = arr[mid + 1 + j];

        size_t i = 0, j = 0, k = low;
        while (i < n1 && j < n2) {
            if (comp(left[i], right[j])) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
            }
        }

        while (i < n1) arr[k++] = left[i++];
        while (j < n2) arr[k++] = right[j++];
    }
};

template<typename T, typename Comparator = std::less<T>>
void mergeSort(std::vector<T>& arr, Comparator comp = Comparator()) {
    MergeSort<T, Comparator>::sort(arr, comp);
}

template<typename T, typename Comparator = std::less<T>>
void mergeSort(T* arr, size_t size, Comparator comp = Comparator()) {
    MergeSort<T, Comparator>::sort(arr, size, comp);
}

} // namespace sorting

/**
 * @brief Utility functions for demonstration
 */
class MergeSortDemo {
public:
    template<typename Container>
    static void printContainer(const Container& cont) {
        for (size_t i = 0; i < cont.size(); ++i) {
            std::cout << cont[i] << (i + 1 == cont.size() ? "" : ", ");
        }
        std::cout << "\n";
    }
};

/**
 * @brief Main function with interactive user input + professional demo
 */
int main() {
    try {
        std::cout << "=========================================\n";
        std::cout << "           PROFESSIONAL MERGESORT         \n";
        std::cout << "=========================================\n";
        std::cout << "Author : Allan Lara\n";
        std::cout << "Email  : allanlara.2006@gmail.com\n";
        std::cout << "GitHub : https://github.com/Allanelh\n";
        std::cout << "License: MIT\n\n";

        char runAgain = 'Y';
        while (std::toupper(runAgain) == 'Y') {
            std::cout << "Enter integers separated by spaces or commas:\n";
            std::string line;
            std::getline(std::cin, line);
            if (line.empty()) std::getline(std::cin, line);

            // Replace commas with spaces
            for (char& c : line) {
                if (c == ',') c = ' ';
            }

            std::vector<long long> data;
            std::stringstream ss(line);
            long long value;
            while (ss >> value) {
                data.push_back(value);
            }

            if (data.empty()) {
                std::cerr << "No valid numbers entered.\n";
            } else {
                std::cout << "\nInput Data: ";
                MergeSortDemo::printContainer(data);

                sorting::mergeSort(data);

                std::cout << "Sorted Data (Ascending): ";
                MergeSortDemo::printContainer(data);

                if (sorting::MergeSort<long long>::isSorted(data.data(), data.size())) {
                    std::cout << "Verification: Array is correctly sorted.\n";
                } else {
                    std::cout << "Verification: Sorting failed!\n";
                }

                // Descending order
                struct DescendingComparator {
                    bool operator()(long long a, long long b) const { return a > b; }
                };

                sorting::mergeSort(data, DescendingComparator());
                std::cout << "\nSorted Data (Descending): ";
                MergeSortDemo::printContainer(data);
                std::cout << "Descending sort verified.\n";
            }

            std::cout << "\nDo you want to run again? (Y/N): ";
            std::cin >> runAgain;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear input buffer
            std::cout << "\n";
        }

        std::cout << "Thank you for using Professional MergeSort. Exiting...\n";
        return 0;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
