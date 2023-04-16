#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <array>
#include <iomanip>

#define FLT_MAX 3.402823466e+38F
#define DBL_MAX 1.7976931348623158e+308

using namespace std;

vector<string> rndString(int size);
vector<int> rndInt(int size);
vector<long long> rndLong(int size);
vector<float> rndFloat(int size);
vector<double> rndDouble(int size);
string runTimer(bool status);

template <typename T> T* vectorToArray(vector<T> data);
template <typename T, size_t N> array<T, N> vectorToSTLArray(vector<T> data);

template <typename T> vector<T> insertionSort(vector<T> data);
template <typename T> vector<T> selectionSort(vector<T> data);
template <typename T> vector<T> bubbleSort(vector<T> data);
template <typename T> vector<T> mergeSort(vector<T> data);

template <typename T> T* insertionSort(T* data, int size);
template <typename T> T* selectionSort(T* data, int size);
template <typename T> T* bubbleSort(T* data, int size);
template <typename T> T* mergeSort(T* data, int size);

template <typename T, size_t N> array<T, N> insertionSort(array<T, N> data);
template <typename T, size_t N> array<T, N> selectionSort(array<T, N> data);
template <typename T, size_t N> array<T, N> bubbleSort(array<T, N> data);
template <typename T, size_t N> array<T, N> mergeSort(array<T, N> data);

double START, END;

int main(void) {
    srand(static_cast<unsigned>(time(NULL)));
    cout<< "int MAX value: "<< INT_MAX << endl;
    cout<< "long MAX value: "<< LONG_MAX << endl;
    cout<< "long long MAX value: "<< LLONG_MAX << "\n" << endl;

    ofstream outputFile("output.txt", ios::out | ios::trunc);
    if (!outputFile.is_open()) {
        cout<< "Unable to open file: output.txt" << endl;
        return 0;
    }

    outputFile<< "10筆隨機資料: ";
    runTimer(true);
    vector<string> dataVecStr10 = rndString(10);
    vector<int> dataVecInt10 = rndInt(10);
    vector<long long> dataVecLong10 = rndLong(10);
    vector<float> dataVecFlt10 = rndFloat(10);
    vector<double> dataVecDbl10 = rndDouble(10);
    string* dataArrStr10 = vectorToArray(dataVecStr10);
    int* dataArrInt10 = vectorToArray(dataVecInt10);
    long long* dataArrLong10 = vectorToArray(dataVecLong10);
    float* dataArrFlt10 = vectorToArray(dataVecFlt10);
    double* dataArrDbl10 = vectorToArray(dataVecDbl10);
    array<string, 10> dataSTLArrStr10 = vectorToSTLArray<string, 10>(dataVecStr10);
    array<int, 10> dataSTLArrInt10 = vectorToSTLArray<int, 10>(dataVecInt10);
    array<long long, 10> dataSTLArrLong10 = vectorToSTLArray<long long, 10>(dataVecLong10);
    array<float, 10> dataSTLArrFlt10 = vectorToSTLArray<float, 10>(dataVecFlt10);
    array<double, 10> dataSTLArrDbl10 = vectorToSTLArray<double, 10>(dataVecDbl10);
    outputFile<< "產生時間 "<< runTimer(false) << endl;

    outputFile<< setw(15)<< "資料結構"<< setw(22)<< "排序演算法"<< setw(15)<< "資料型別"<< setw(10)<< "時間" << endl;

    runTimer(true);
    insertionSort(dataArrStr10, 10);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrInt10, 10);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrLong10, 10);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrFlt10, 10);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrDbl10, 10);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrStr10, 10);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrInt10, 10);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrLong10, 10);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrFlt10, 10);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrDbl10, 10);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrStr10, 10);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrInt10, 10);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrLong10, 10);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrFlt10, 10);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrDbl10, 10);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrStr10, 10);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrInt10, 10);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrLong10, 10);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrFlt10, 10);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrDbl10, 10);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecStr10);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecInt10);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecLong10);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecFlt10);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecDbl10);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecStr10);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecInt10);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecLong10);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecFlt10);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecDbl10);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecStr10);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecInt10);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecLong10);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecFlt10);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecDbl10);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecStr10);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecInt10);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecLong10);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecFlt10);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecDbl10);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<string, 10>(dataSTLArrStr10);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<int, 10>(dataSTLArrInt10);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<long long, 10>(dataSTLArrLong10);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<float, 10>(dataSTLArrFlt10);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<double, 10>(dataSTLArrDbl10);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<string, 10>(dataSTLArrStr10);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<int, 10>(dataSTLArrInt10);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<long long, 10>(dataSTLArrLong10);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<float, 10>(dataSTLArrFlt10);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<double, 10>(dataSTLArrDbl10);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<string, 10>(dataSTLArrStr10);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<int, 10>(dataSTLArrInt10);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<long long, 10>(dataSTLArrLong10);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<float, 10>(dataSTLArrFlt10);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<double, 10>(dataSTLArrDbl10);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<string, 10>(dataSTLArrStr10);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<int, 10>(dataSTLArrInt10);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<long long, 10>(dataSTLArrLong10);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<float, 10>(dataSTLArrFlt10);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<double, 10>(dataSTLArrDbl10);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    outputFile<< endl;


    outputFile<< "20筆隨機資料: ";
    runTimer(true);
    vector<string> dataVecStr20 = rndString(20);
    vector<int> dataVecInt20 = rndInt(20);
    vector<long long> dataVecLong20 = rndLong(20);
    vector<float> dataVecFlt20 = rndFloat(20);
    vector<double> dataVecDbl20 = rndDouble(20);
    string* dataArrStr20 = vectorToArray(dataVecStr20);
    int* dataArrInt20 = vectorToArray(dataVecInt20);
    long long* dataArrLong20 = vectorToArray(dataVecLong20);
    float* dataArrFlt20 = vectorToArray(dataVecFlt20);
    double* dataArrDbl20 = vectorToArray(dataVecDbl20);
    array<string, 20> dataSTLArrStr20 = vectorToSTLArray<string, 20>(dataVecStr20);
    array<int, 20> dataSTLArrInt20 = vectorToSTLArray<int, 20>(dataVecInt20);
    array<long long, 20> dataSTLArrLong20 = vectorToSTLArray<long long, 20>(dataVecLong20);
    array<float, 20> dataSTLArrFlt20 = vectorToSTLArray<float, 20>(dataVecFlt20);
    array<double, 20> dataSTLArrDbl20 = vectorToSTLArray<double, 20>(dataVecDbl20);
    outputFile<< "產生時間 "<< runTimer(false)<< endl;

    outputFile<< setw(15)<< "資料結構"<< setw(22)<< "排序演算法"<< setw(15)<< "資料型別"<< setw(10)<< "時間" << endl;

    runTimer(true);
    insertionSort(dataArrStr20, 20);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrInt20, 20);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrLong20, 20);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrFlt20, 20);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrDbl20, 20);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrStr20, 20);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrInt20, 20);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrLong20, 20);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrFlt20, 20);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrDbl20, 20);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrStr20, 20);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrInt20, 20);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrLong20, 20);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrFlt20, 20);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrDbl20, 20);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrStr20, 20);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrInt20, 20);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrLong20, 20);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrFlt20, 20);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrDbl20, 20);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecStr20);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecInt20);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecLong20);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecFlt20);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecDbl20);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecStr20);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecInt20);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecLong20);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecFlt20);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecDbl20);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecStr20);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecInt20);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecLong20);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecFlt20);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecDbl20);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecStr20);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecInt20);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecLong20);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecFlt20);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecDbl20);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<string, 20>(dataSTLArrStr20);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<int, 20>(dataSTLArrInt20);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<long long, 20>(dataSTLArrLong20);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<float, 20>(dataSTLArrFlt20);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<double, 20>(dataSTLArrDbl20);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<string, 20>(dataSTLArrStr20);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<int, 20>(dataSTLArrInt20);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<long long, 20>(dataSTLArrLong20);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<float, 20>(dataSTLArrFlt20);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<double, 20>(dataSTLArrDbl20);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<string, 20>(dataSTLArrStr20);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<int, 20>(dataSTLArrInt20);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<long long, 20>(dataSTLArrLong20);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<float, 20>(dataSTLArrFlt20);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<double, 20>(dataSTLArrDbl20);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<string, 20>(dataSTLArrStr20);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<int, 20>(dataSTLArrInt20);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<long long, 20>(dataSTLArrLong20);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<float, 20>(dataSTLArrFlt20);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<double, 20>(dataSTLArrDbl20);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    outputFile<< endl;


    outputFile<< "30筆隨機資料: ";
    runTimer(true);
    vector<string> dataVecStr30 = rndString(30);
    vector<int> dataVecInt30 = rndInt(30);
    vector<long long> dataVecLong30 = rndLong(30);
    vector<float> dataVecFlt30 = rndFloat(30);
    vector<double> dataVecDbl30 = rndDouble(30);
    string* dataArrStr30 = vectorToArray(dataVecStr30);
    int* dataArrInt30 = vectorToArray(dataVecInt30);
    long long* dataArrLong30 = vectorToArray(dataVecLong30);
    float* dataArrFlt30 = vectorToArray(dataVecFlt30);
    double* dataArrDbl30 = vectorToArray(dataVecDbl30);
    array<string, 30> dataSTLArrStr30 = vectorToSTLArray<string, 30>(dataVecStr30);
    array<int, 30> dataSTLArrInt30 = vectorToSTLArray<int, 30>(dataVecInt30);
    array<long long, 30> dataSTLArrLong30 = vectorToSTLArray<long long, 30>(dataVecLong30);
    array<float, 30> dataSTLArrFlt30 = vectorToSTLArray<float, 30>(dataVecFlt30);
    array<double, 30> dataSTLArrDbl30 = vectorToSTLArray<double, 30>(dataVecDbl30);
    outputFile<< "產生時間 "<< runTimer(false)<< endl;

    outputFile<< setw(15)<< "資料結構"<< setw(22)<< "排序演算法"<< setw(15)<< "資料型別"<< setw(10)<< "時間" << endl;

    runTimer(true);
    insertionSort(dataArrStr30, 30);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrInt30, 30);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrLong30, 30);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrFlt30, 30);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrDbl30, 30);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrStr30, 30);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrInt30, 30);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrLong30, 30);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrFlt30, 30);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrDbl30, 30);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrStr30, 30);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrInt30, 30);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrLong30, 30);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrFlt30, 30);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrDbl30, 30);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrStr30, 30);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrInt30, 30);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrLong30, 30);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrFlt30, 30);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrDbl30, 30);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecStr30);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecInt30);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecLong30);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecFlt30);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecDbl30);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecStr30);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecInt30);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecLong30);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecFlt30);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecDbl30);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecStr30);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecInt30);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecLong30);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecFlt30);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecDbl30);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecStr30);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecInt30);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecLong30);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecFlt30);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecDbl30);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<string, 30>(dataSTLArrStr30);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<int, 30>(dataSTLArrInt30);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<long long, 30>(dataSTLArrLong30);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<float, 30>(dataSTLArrFlt30);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<double, 30>(dataSTLArrDbl30);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<string, 30>(dataSTLArrStr30);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<int, 30>(dataSTLArrInt30);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<long long, 30>(dataSTLArrLong30);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<float, 30>(dataSTLArrFlt30);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<double, 30>(dataSTLArrDbl30);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<string, 30>(dataSTLArrStr30);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<int, 30>(dataSTLArrInt30);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<long long, 30>(dataSTLArrLong30);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<float, 30>(dataSTLArrFlt30);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<double, 30>(dataSTLArrDbl30);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<string, 30>(dataSTLArrStr30);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<int, 30>(dataSTLArrInt30);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<long long, 30>(dataSTLArrLong30);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<float, 30>(dataSTLArrFlt30);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<double, 30>(dataSTLArrDbl30);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    outputFile<< endl;


    outputFile<< "40筆隨機資料: ";
    runTimer(true);
    vector<string> dataVecStr40 = rndString(40);
    vector<int> dataVecInt40 = rndInt(40);
    vector<long long> dataVecLong40 = rndLong(40);
    vector<float> dataVecFlt40 = rndFloat(40);
    vector<double> dataVecDbl40 = rndDouble(40);
    string* dataArrStr40 = vectorToArray(dataVecStr40);
    int* dataArrInt40 = vectorToArray(dataVecInt40);
    long long* dataArrLong40 = vectorToArray(dataVecLong40);
    float* dataArrFlt40 = vectorToArray(dataVecFlt40);
    double* dataArrDbl40 = vectorToArray(dataVecDbl40);
    array<string, 40> dataSTLArrStr40 = vectorToSTLArray<string, 40>(dataVecStr40);
    array<int, 40> dataSTLArrInt40 = vectorToSTLArray<int, 40>(dataVecInt40);
    array<long long, 40> dataSTLArrLong40 = vectorToSTLArray<long long, 40>(dataVecLong40);
    array<float, 40> dataSTLArrFlt40 = vectorToSTLArray<float, 40>(dataVecFlt40);
    array<double, 40> dataSTLArrDbl40 = vectorToSTLArray<double, 40>(dataVecDbl40);
    outputFile<< "產生時間 "<< runTimer(false)<< endl;

    outputFile<< setw(15)<< "資料結構"<< setw(22)<< "排序演算法"<< setw(15)<< "資料型別"<< setw(10)<< "時間" << endl;

    runTimer(true);
    insertionSort(dataArrStr40, 40);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrInt40, 40);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrLong40, 40);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrFlt40, 40);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrDbl40, 40);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrStr40, 40);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrInt40, 40);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrLong40, 40);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrFlt40, 40);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrDbl40, 40);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrStr40, 40);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrInt40, 40);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrLong40, 40);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrFlt40, 40);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrDbl40, 40);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrStr40, 40);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrInt40, 40);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrLong40, 40);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrFlt40, 40);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrDbl40, 40);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecStr40);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecInt40);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecLong40);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecFlt40);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecDbl40);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecStr40);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecInt40);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecLong40);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecFlt40);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecDbl40);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecStr40);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecInt40);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecLong40);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecFlt40);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecDbl40);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecStr40);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecInt40);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecLong40);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecFlt40);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecDbl40);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<string, 40>(dataSTLArrStr40);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<int, 40>(dataSTLArrInt40);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<long long, 40>(dataSTLArrLong40);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<float, 40>(dataSTLArrFlt40);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<double, 40>(dataSTLArrDbl40);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<string, 40>(dataSTLArrStr40);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<int, 40>(dataSTLArrInt40);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<long long, 40>(dataSTLArrLong40);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<float, 40>(dataSTLArrFlt40);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<double, 40>(dataSTLArrDbl40);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<string, 40>(dataSTLArrStr40);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<int, 40>(dataSTLArrInt40);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<long long, 40>(dataSTLArrLong40);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<float, 40>(dataSTLArrFlt40);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<double, 40>(dataSTLArrDbl40);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<string, 40>(dataSTLArrStr40);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<int, 40>(dataSTLArrInt40);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<long long, 40>(dataSTLArrLong40);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<float, 40>(dataSTLArrFlt40);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<double, 40>(dataSTLArrDbl40);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    outputFile<< endl;


    outputFile<< "50筆隨機資料: ";
    runTimer(true);
    vector<string> dataVecStr50 = rndString(50);
    vector<int> dataVecInt50 = rndInt(50);
    vector<long long> dataVecLong50 = rndLong(50);
    vector<float> dataVecFlt50 = rndFloat(50);
    vector<double> dataVecDbl50 = rndDouble(50);
    string* dataArrStr50 = vectorToArray(dataVecStr50);
    int* dataArrInt50 = vectorToArray(dataVecInt50);
    long long* dataArrLong50 = vectorToArray(dataVecLong50);
    float* dataArrFlt50 = vectorToArray(dataVecFlt50);
    double* dataArrDbl50 = vectorToArray(dataVecDbl50);
    array<string, 50> dataSTLArrStr50 = vectorToSTLArray<string, 50>(dataVecStr50);
    array<int, 50> dataSTLArrInt50 = vectorToSTLArray<int, 50>(dataVecInt50);
    array<long long, 50> dataSTLArrLong50 = vectorToSTLArray<long long, 50>(dataVecLong50);
    array<float, 50> dataSTLArrFlt50 = vectorToSTLArray<float, 50>(dataVecFlt50);
    array<double, 50> dataSTLArrDbl50 = vectorToSTLArray<double, 50>(dataVecDbl50);
    outputFile<< "產生時間 "<< runTimer(false)<< endl;

    outputFile<< setw(15)<< "資料結構"<< setw(22)<< "排序演算法"<< setw(15)<< "資料型別"<< setw(10)<< "時間" << endl;

    runTimer(true);
    insertionSort(dataArrStr50, 50);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrInt50, 50);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrLong50, 50);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrFlt50, 50);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrDbl50, 50);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrStr50, 50);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrInt50, 50);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrLong50, 50);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrFlt50, 50);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrDbl50, 50);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrStr50, 50);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrInt50, 50);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrLong50, 50);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrFlt50, 50);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrDbl50, 50);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrStr50, 50);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrInt50, 50);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrLong50, 50);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrFlt50, 50);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrDbl50, 50);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecStr50);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecInt50);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecLong50);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecFlt50);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecDbl50);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecStr50);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecInt50);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecLong50);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecFlt50);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecDbl50);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecStr50);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecInt50);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecLong50);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecFlt50);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecDbl50);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecStr50);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecInt50);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecLong50);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecFlt50);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecDbl50);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<string, 50>(dataSTLArrStr50);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<int, 50>(dataSTLArrInt50);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<long long, 50>(dataSTLArrLong50);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<float, 50>(dataSTLArrFlt50);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort<double, 50>(dataSTLArrDbl50);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<string, 50>(dataSTLArrStr50);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<int, 50>(dataSTLArrInt50);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<long long, 50>(dataSTLArrLong50);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<float, 50>(dataSTLArrFlt50);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort<double, 50>(dataSTLArrDbl50);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<string, 50>(dataSTLArrStr50);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<int, 50>(dataSTLArrInt50);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<long long, 50>(dataSTLArrLong50);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<float, 50>(dataSTLArrFlt50);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort<double, 50>(dataSTLArrDbl50);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<string, 50>(dataSTLArrStr50);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<int, 50>(dataSTLArrInt50);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<long long, 50>(dataSTLArrLong50);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<float, 50>(dataSTLArrFlt50);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort<double, 50>(dataSTLArrDbl50);
    outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    outputFile<< endl;


    outputFile<< "10萬筆隨機資料: ";
    runTimer(true);
    vector<string> dataVecStr100k = rndString(100000);
    vector<int> dataVecInt100k = rndInt(100000);
    vector<long long> dataVecLong100k = rndLong(100000);
    vector<float> dataVecFlt100k = rndFloat(100000);
    vector<double> dataVecDbl100k = rndDouble(100000);
    string* dataArrStr100k = vectorToArray(dataVecStr100k);
    int* dataArrInt100k = vectorToArray(dataVecInt100k);
    long long* dataArrLong100k = vectorToArray(dataVecLong100k);
    float* dataArrFlt100k = vectorToArray(dataVecFlt100k);
    double* dataArrDbl100k = vectorToArray(dataVecDbl100k);
    // array<string, 100000> dataSTLArrStr100k = vectorToSTLArray<string, 100000>(dataVecStr100k);
    // array<int, 100000> dataSTLArrInt100k = vectorToSTLArray<int, 100000>(dataVecInt100k);
    // array<long long, 100000> dataSTLArrLong100k = vectorToSTLArray<long long, 100000>(dataVecLong100k);
    // array<float, 100000> dataSTLArrFlt100k = vectorToSTLArray<float, 100000>(dataVecFlt100k);
    // array<double, 100000> dataSTLArrDbl100k = vectorToSTLArray<double, 100000>(dataVecDbl100k);
    outputFile<< "產生時間 "<< runTimer(false)<< endl;

    outputFile<< setw(15)<< "資料結構"<< setw(22)<< "排序演算法"<< setw(15)<< "資料型別"<< setw(10)<< "時間" << endl;

    runTimer(true);
    insertionSort(dataArrStr100k, 100000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrInt100k, 100000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrLong100k, 100000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrFlt100k, 100000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrDbl100k, 100000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrStr100k, 100000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrInt100k, 100000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrLong100k, 100000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrFlt100k, 100000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrDbl100k, 100000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrStr100k, 100000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrInt100k, 100000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrLong100k, 100000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrFlt100k, 100000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrDbl100k, 100000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrStr100k, 100000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrInt100k, 100000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrLong100k, 100000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrFlt100k, 100000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrDbl100k, 100000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecStr100k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecInt100k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecLong100k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecFlt100k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecDbl100k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecStr100k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecInt100k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecLong100k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecFlt100k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecDbl100k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecStr100k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecInt100k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecLong100k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecFlt100k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecDbl100k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecStr100k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecInt100k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecLong100k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecFlt100k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecDbl100k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<string, 100000>(dataSTLArrStr100k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<int, 100000>(dataSTLArrInt100k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<long long, 100000>(dataSTLArrLong100k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<float, 100000>(dataSTLArrFlt100k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<double, 100000>(dataSTLArrDbl100k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<string, 100000>(dataSTLArrStr100k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<int, 100000>(dataSTLArrInt100k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<long long, 100000>(dataSTLArrLong100k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<float, 100000>(dataSTLArrFlt100k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<double, 100000>(dataSTLArrDbl100k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<string, 100000>(dataSTLArrStr100k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<int, 100000>(dataSTLArrInt100k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<long long, 100000>(dataSTLArrLong100k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<float, 100000>(dataSTLArrFlt100k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<double, 100000>(dataSTLArrDbl100k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<string, 100000>(dataSTLArrStr100k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<int, 100000>(dataSTLArrInt100k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<long long, 100000>(dataSTLArrLong100k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<float, 100000>(dataSTLArrFlt100k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<double, 100000>(dataSTLArrDbl100k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    outputFile<< endl;


    outputFile<< "20萬筆隨機資料: ";
    runTimer(true);
    vector<string> dataVecStr200k = rndString(200000);
    vector<int> dataVecInt200k = rndInt(200000);
    vector<long long> dataVecLong200k = rndLong(200000);
    vector<float> dataVecFlt200k = rndFloat(200000);
    vector<double> dataVecDbl200k = rndDouble(200000);
    string* dataArrStr200k = vectorToArray(dataVecStr200k);
    int* dataArrInt200k = vectorToArray(dataVecInt200k);
    long long* dataArrLong200k = vectorToArray(dataVecLong200k);
    float* dataArrFlt200k = vectorToArray(dataVecFlt200k);
    double* dataArrDbl200k = vectorToArray(dataVecDbl200k);
    // array<string, 200000> dataSTLArrStr200k = vectorToSTLArray<string, 200000>(dataVecStr200k);
    // array<int, 200000> dataSTLArrInt200k = vectorToSTLArray<int, 200000>(dataVecInt200k);
    // array<long long, 200000> dataSTLArrLong200k = vectorToSTLArray<long long, 200000>(dataVecLong200k);
    // array<float, 200000> dataSTLArrFlt200k = vectorToSTLArray<float, 200000>(dataVecFlt200k);
    // array<double, 200000> dataSTLArrDbl200k = vectorToSTLArray<double, 200000>(dataVecDbl200k);
    outputFile<< "產生時間 "<< runTimer(false)<< endl;

    outputFile<< setw(15)<< "資料結構"<< setw(22)<< "排序演算法"<< setw(15)<< "資料型別"<< setw(10)<< "時間" << endl;

    runTimer(true);
    insertionSort(dataArrStr200k, 200000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrInt200k, 200000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrLong200k, 200000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrFlt200k, 200000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrDbl200k, 200000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrStr200k, 200000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrInt200k, 200000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrLong200k, 200000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrFlt200k, 200000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrDbl200k, 200000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrStr200k, 200000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrInt200k, 200000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrLong200k, 200000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrFlt200k, 200000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrDbl200k, 200000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrStr200k, 200000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrInt200k, 200000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrLong200k, 200000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrFlt200k, 200000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrDbl200k, 200000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecStr200k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecInt200k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecLong200k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecFlt200k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecDbl200k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecStr200k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecInt200k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecLong200k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecFlt200k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecDbl200k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecStr200k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecInt200k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecLong200k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecFlt200k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecDbl200k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecStr200k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecInt200k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecLong200k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecFlt200k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecDbl200k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<string, 200000>(dataSTLArrStr200k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<int, 200000>(dataSTLArrInt200k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<long long, 200000>(dataSTLArrLong200k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<float, 200000>(dataSTLArrFlt200k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<double, 200000>(dataSTLArrDbl200k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<string, 200000>(dataSTLArrStr200k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<int, 200000>(dataSTLArrInt200k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<long long, 200000>(dataSTLArrLong200k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<float, 200000>(dataSTLArrFlt200k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<double, 200000>(dataSTLArrDbl200k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<string, 200000>(dataSTLArrStr200k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<int, 200000>(dataSTLArrInt200k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<long long, 200000>(dataSTLArrLong200k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<float, 200000>(dataSTLArrFlt200k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<double, 200000>(dataSTLArrDbl200k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<string, 200000>(dataSTLArrStr200k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<int, 200000>(dataSTLArrInt200k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<long long, 200000>(dataSTLArrLong200k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<float, 200000>(dataSTLArrFlt200k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<double, 200000>(dataSTLArrDbl200k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    outputFile<< endl;


    outputFile<< "30萬筆隨機資料: ";
    runTimer(true);
    vector<string> dataVecStr300k = rndString(300000);
    vector<int> dataVecInt300k = rndInt(300000);
    vector<long long> dataVecLong300k = rndLong(300000);
    vector<float> dataVecFlt300k = rndFloat(300000);
    vector<double> dataVecDbl300k = rndDouble(300000);
    string* dataArrStr300k = vectorToArray(dataVecStr300k);
    int* dataArrInt300k = vectorToArray(dataVecInt300k);
    long long* dataArrLong300k = vectorToArray(dataVecLong300k);
    float* dataArrFlt300k = vectorToArray(dataVecFlt300k);
    double* dataArrDbl300k = vectorToArray(dataVecDbl300k);
    // array<string, 300000> dataSTLArrStr300k = vectorToSTLArray<string, 300000>(dataVecStr300k);
    // array<int, 300000> dataSTLArrInt300k = vectorToSTLArray<int, 300000>(dataVecInt300k);
    // array<long long, 300000> dataSTLArrLong300k = vectorToSTLArray<long long, 300000>(dataVecLong300k);
    // array<float, 300000> dataSTLArrFlt300k = vectorToSTLArray<float, 300000>(dataVecFlt300k);
    // array<double, 300000> dataSTLArrDbl300k = vectorToSTLArray<double, 300000>(dataVecDbl300k);
    outputFile<< "產生時間 "<< runTimer(false)<< endl;

    outputFile<< setw(15)<< "資料結構"<< setw(22)<< "排序演算法"<< setw(15)<< "資料型別"<< setw(10)<< "時間" << endl;

    runTimer(true);
    insertionSort(dataArrStr300k, 300000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrInt300k, 300000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrLong300k, 300000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrFlt300k, 300000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrDbl300k, 300000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrStr300k, 300000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrInt300k, 300000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrLong300k, 300000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrFlt300k, 300000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrDbl300k, 300000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrStr300k, 300000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrInt300k, 300000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrLong300k, 300000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrFlt300k, 300000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrDbl300k, 300000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrStr300k, 300000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrInt300k, 300000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrLong300k, 300000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrFlt300k, 300000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrDbl300k, 300000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecStr300k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecInt300k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecLong300k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecFlt300k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecDbl300k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecStr300k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecInt300k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecLong300k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecFlt300k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecDbl300k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecStr300k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecInt300k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecLong300k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecFlt300k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecDbl300k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecStr300k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecInt300k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecLong300k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecFlt300k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecDbl300k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<string, 300000>(dataSTLArrStr300k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<int, 300000>(dataSTLArrInt300k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<long long, 300000>(dataSTLArrLong300k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<float, 300000>(dataSTLArrFlt300k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<double, 300000>(dataSTLArrDbl300k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<string, 300000>(dataSTLArrStr300k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<int, 300000>(dataSTLArrInt300k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<long long, 300000>(dataSTLArrLong300k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<float, 300000>(dataSTLArrFlt300k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<double, 300000>(dataSTLArrDbl300k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<string, 300000>(dataSTLArrStr300k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<int, 300000>(dataSTLArrInt300k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<long long, 300000>(dataSTLArrLong300k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<float, 300000>(dataSTLArrFlt300k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<double, 300000>(dataSTLArrDbl300k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<string, 300000>(dataSTLArrStr300k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<int, 300000>(dataSTLArrInt300k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<long long, 300000>(dataSTLArrLong300k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<float, 300000>(dataSTLArrFlt300k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<double, 300000>(dataSTLArrDbl300k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    outputFile<< endl;


    outputFile<< "40萬筆隨機資料: ";
    runTimer(true);
    vector<string> dataVecStr400k = rndString(400000);
    vector<int> dataVecInt400k = rndInt(400000);
    vector<long long> dataVecLong400k = rndLong(400000);
    vector<float> dataVecFlt400k = rndFloat(400000);
    vector<double> dataVecDbl400k = rndDouble(400000);
    string* dataArrStr400k = vectorToArray(dataVecStr400k);
    int* dataArrInt400k = vectorToArray(dataVecInt400k);
    long long* dataArrLong400k = vectorToArray(dataVecLong400k);
    float* dataArrFlt400k = vectorToArray(dataVecFlt400k);
    double* dataArrDbl400k = vectorToArray(dataVecDbl400k);
    // array<string, 400000> dataSTLArrStr400k = vectorToSTLArray<string, 400000>(dataVecStr400k);
    // array<int, 400000> dataSTLArrInt400k = vectorToSTLArray<int, 400000>(dataVecInt400k);
    // array<long long, 400000> dataSTLArrLong400k = vectorToSTLArray<long long, 400000>(dataVecLong400k);
    // array<float, 400000> dataSTLArrFlt400k = vectorToSTLArray<float, 400000>(dataVecFlt400k);
    // array<double, 400000> dataSTLArrDbl400k = vectorToSTLArray<double, 400000>(dataVecDbl400k);
    outputFile<< "產生時間 "<< runTimer(false)<< endl;

    outputFile<< setw(15)<< "資料結構"<< setw(22)<< "排序演算法"<< setw(15)<< "資料型別"<< setw(10)<< "時間" << endl;

    runTimer(true);
    insertionSort(dataArrStr400k, 400000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrInt400k, 400000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrLong400k, 400000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrFlt400k, 400000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrDbl400k, 400000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrStr400k, 400000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrInt400k, 400000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrLong400k, 400000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrFlt400k, 400000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrDbl400k, 400000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrStr400k, 400000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrInt400k, 400000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrLong400k, 400000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrFlt400k, 400000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrDbl400k, 400000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrStr400k, 400000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrInt400k, 400000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrLong400k, 400000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrFlt400k, 400000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrDbl400k, 400000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecStr400k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecInt400k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecLong400k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecFlt400k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecDbl400k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecStr400k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecInt400k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecLong400k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecFlt400k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecDbl400k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecStr400k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecInt400k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecLong400k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecFlt400k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecDbl400k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecStr400k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecInt400k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecLong400k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecFlt400k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecDbl400k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<string, 400000>(dataSTLArrStr400k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<int, 400000>(dataSTLArrInt400k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<long long, 400000>(dataSTLArrLong400k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<float, 400000>(dataSTLArrFlt400k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<double, 400000>(dataSTLArrDbl400k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<string, 400000>(dataSTLArrStr400k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<int, 400000>(dataSTLArrInt400k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<long long, 400000>(dataSTLArrLong400k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<float, 400000>(dataSTLArrFlt400k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<double, 400000>(dataSTLArrDbl400k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<string, 400000>(dataSTLArrStr400k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<int, 400000>(dataSTLArrInt400k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<long long, 400000>(dataSTLArrLong400k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<float, 400000>(dataSTLArrFlt400k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<double, 400000>(dataSTLArrDbl400k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<string, 400000>(dataSTLArrStr400k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<int, 400000>(dataSTLArrInt400k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<long long, 400000>(dataSTLArrLong400k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<float, 400000>(dataSTLArrFlt400k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<double, 400000>(dataSTLArrDbl400k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    outputFile<< endl;


    outputFile<< "50萬筆隨機資料: ";
    runTimer(true);
    vector<string> dataVecStr500k = rndString(500000);
    vector<int> dataVecInt500k = rndInt(500000);
    vector<long long> dataVecLong500k = rndLong(500000);
    vector<float> dataVecFlt500k = rndFloat(500000);
    vector<double> dataVecDbl500k = rndDouble(500000);
    string* dataArrStr500k = vectorToArray(dataVecStr500k);
    int* dataArrInt500k = vectorToArray(dataVecInt500k);
    long long* dataArrLong500k = vectorToArray(dataVecLong500k);
    float* dataArrFlt500k = vectorToArray(dataVecFlt500k);
    double* dataArrDbl500k = vectorToArray(dataVecDbl500k);
    // array<string, 500000> dataSTLArrStr500k = vectorToSTLArray<string, 500000>(dataVecStr500k);
    // array<int, 500000> dataSTLArrInt500k = vectorToSTLArray<int, 500000>(dataVecInt500k);
    // array<long long, 500000> dataSTLArrLong500k = vectorToSTLArray<long long, 500000>(dataVecLong500k);
    // array<float, 500000> dataSTLArrFlt500k = vectorToSTLArray<float, 500000>(dataVecFlt500k);
    // array<double, 500000> dataSTLArrDbl500k = vectorToSTLArray<double, 500000>(dataVecDbl500k);
    outputFile<< "產生時間 "<< runTimer(false)<< endl;

    outputFile<< setw(15)<< "資料結構"<< setw(22)<< "排序演算法"<< setw(15)<< "資料型別"<< setw(10)<< "時間" << endl;

    runTimer(true);
    insertionSort(dataArrStr500k, 500000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrInt500k, 500000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrLong500k, 500000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrFlt500k, 500000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataArrDbl500k, 500000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrStr500k, 500000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrInt500k, 500000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrLong500k, 500000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrFlt500k, 500000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataArrDbl500k, 500000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrStr500k, 500000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrInt500k, 500000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrLong500k, 500000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrFlt500k, 500000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataArrDbl500k, 500000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrStr500k, 500000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrInt500k, 500000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrLong500k, 500000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrFlt500k, 500000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataArrDbl500k, 500000);
    outputFile<< setw(10)<< "array"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecStr500k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecInt500k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecLong500k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecFlt500k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    insertionSort(dataVecDbl500k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecStr500k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecInt500k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecLong500k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecFlt500k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    selectionSort(dataVecDbl500k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecStr500k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecInt500k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecLong500k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecFlt500k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    bubbleSort(dataVecDbl500k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecStr500k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecInt500k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecLong500k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecFlt500k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    runTimer(true);
    mergeSort(dataVecDbl500k);
    outputFile<< setw(10)<< "vector"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<string, 500000>(dataSTLArrStr500k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<int, 500000>(dataSTLArrInt500k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<long long, 500000>(dataSTLArrLong500k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<float, 500000>(dataSTLArrFlt500k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // insertionSort<double, 500000>(dataSTLArrDbl500k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "insertion Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<string, 500000>(dataSTLArrStr500k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<int, 500000>(dataSTLArrInt500k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<long long, 500000>(dataSTLArrLong500k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<float, 500000>(dataSTLArrFlt500k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // selectionSort<double, 500000>(dataSTLArrDbl500k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "selection Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<string, 500000>(dataSTLArrStr500k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<int, 500000>(dataSTLArrInt500k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<long long, 500000>(dataSTLArrLong500k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<float, 500000>(dataSTLArrFlt500k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // bubbleSort<double, 500000>(dataSTLArrDbl500k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "bubble Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<string, 500000>(dataSTLArrStr500k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "string"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<int, 500000>(dataSTLArrInt500k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "integer"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<long long, 500000>(dataSTLArrLong500k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "long"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<float, 500000>(dataSTLArrFlt500k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "float"<< setw(9)<< runTimer(false) << endl;
    // runTimer(true);
    // mergeSort<double, 500000>(dataSTLArrDbl500k);
    // outputFile<< setw(10)<< "std::array"<< setw(16)<< "merge Sort"<< setw(10)<< "double"<< setw(9)<< runTimer(false) << endl;
    outputFile<< endl;

    cout<< "End of program."<< endl;
    outputFile.close();
    getchar();
    return 0;
}

vector<string> rndString(int size) {
    vector<string> data;
    data.reserve(size);
    for (int j = 0; j < size; j++) {
        string temp= "";
        for (int i = 0; i < 6; i++) {
            char alphabet = static_cast<char>(rand() % 26 + ((rand() % 2) ? 65 : 97));
            temp += alphabet;
        }
        data.push_back(temp);
    }
    return data;
}

vector<int> rndInt(int size) {
    vector<int> data;
    data.reserve(size);
    for (int j = 0; j < size; j++) {
        int num = 0;
        for (int i = 0; i < 30; i++) {
            num |= (rand() % 2);
            num <<= 1;
        }
        data.push_back(num);
    }
    return data;
}

vector<long long> rndLong(int size) {
    vector<long long> data;
    data.reserve(size);
    for (int j = 0; j < size; j++) {
        long long num = 0;
        for (int i = 0; i < 62; i++) {
            num |= (rand() % 2);
            num <<= 1;
        }
        data.push_back(num);
    }
    return data;
}

vector<float> rndFloat(int size) {
    vector<float> data;
    data.reserve(size);
    for (int j = 0; j < size; j++) {
        data.push_back(static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * FLT_MAX);
    }
    return data;
}

vector<double> rndDouble(int size) {
    vector<double> data;
    data.reserve(size);
    for (int j = 0; j < size; j++) {
        data.push_back(static_cast<double>(rand()) / static_cast<float>(RAND_MAX) * DBL_MAX);
    }
    return data;
}

string runTimer(bool status) {
    if (status) {
        START = clock();
        return "";
    } else {
        END = clock();
        ostringstream ss;
        ss << fixed << setprecision(3) << (END - START) / CLOCKS_PER_SEC<< "s";
        return ss.str();
    }
}

template <typename T>
T* vectorToArray(vector<T> data) {
    T* arr = new T[data.size()];
    for (int i = 0; i < data.size(); i++) {
        arr[i] = data[i];
    }
    return arr;
}

template <typename T, size_t N>
array<T, N> vectorToSTLArray(vector<T> data) {
    array<T, N> arr;
    for (int i = 0; i < data.size(); i++) {
        arr[i] = data[i];
    }
    return arr;
}

template <typename T>
vector<T> insertionSort(vector<T> data) {
    for (int i = 1; i < data.size(); i++) {
        T temp = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > temp) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }
    return data;
}

template <typename T>
vector<T> selectionSort(vector<T> data) {
    for (int i = 0; i < data.size(); i++) {
        int min = i;
        for (int j = i + 1; j < data.size(); j++) {
            if (data[j] < data[min]) {
                min = j;
            }
        }
        T temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
    return data;
}

template <typename T>
vector<T> bubbleSort(vector<T> data) {
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data.size() - 1; j++) {
            if (data[j] > data[j + 1]) {
                T temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    return data;
}

template <typename T>
vector<T> merge(vector<T> left, vector<T> right) {
    vector<T> result;
    int i = 0, j = 0;

    while (i < left.size() || j < right.size()) {
        if (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                result.push_back(left[i]);
                i++;
            } else {
                result.push_back(right[j]);
                j++;
            }
        } else if (i < left.size()) {
            result.push_back(left[i]);
            i++;
        } else if (j < right.size()) {
            result.push_back(right[j]);
            j++;
        }
    }
    return result;
}
template <typename T>
vector<T> mergeSort(vector<T> data) {
    if (data.size() == 1) return data;
    vector<T> left, right;
    int mid = data.size() / 2;
    for (int i = 0; i < mid; i++) left.push_back(data[i]);
    for (int i = mid; i < data.size(); i++) right.push_back(data[i]);
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}

template <typename T>
T* insertionSort(T* data, int size) {
    for (int i = 1; i < size; i++) {
        T temp = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > temp) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }
    return data;
}

template <typename T>
T* selectionSort(T* data, int size) {
    for (int i = 0; i < size; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (data[j] < data[min]) {
                min = j;
            }
        }
        T temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
    return data;
}

template <typename T>
T* bubbleSort(T* data, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (data[j] > data[j + 1]) {
                T temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    return data;
}

template <typename T>
T* merge(T* left, int leftSize, T* right, int rightSize) {
    T* result = new T[leftSize + rightSize];
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            result[k++] = left[i++];
        } else {
            result[k++] = right[j++];
        }
    }

    while (i < leftSize) {
        result[k++] = left[i++];
    }

    while (j < rightSize) {
        result[k++] = right[j++];
    }

    delete[] left;
    delete[] right;

    return result;
}
template <typename T>
T* mergeSort(T* data, int size) {
    if (size <= 1) return data;
    int mid = size / 2;
    T* left = new T[mid];
    T* right = new T[size - mid];
    for (int i = 0; i < mid; i++) left[i] = data[i];
    for (int i = mid; i < size; i++) right[i - mid] = data[i];
    left = mergeSort(left, mid);
    right = mergeSort(right, size - mid);
    return merge(left, mid, right, size - mid);
}

template <typename T, size_t N>
array<T, N> insertionSort(array<T, N> data) {
    for (int i = 1; i < data.size(); i++) {
        T temp = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > temp) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }
    return data;
}

template <typename T, size_t N>
array<T, N> selectionSort(array<T, N> data) {
    for (int i = 0; i < data.size(); i++) {
        int min = i;
        for (int j = i + 1; j < data.size(); j++) {
            if (data[j] < data[min]) {
                min = j;
            }
        }
        T temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
    return data;
}

template <typename T, size_t N>
array<T, N> bubbleSort(array<T, N> data) {
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data.size() - 1; j++) {
            if (data[j] > data[j + 1]) {
                T temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    return data;
}

template <typename T, size_t N1, size_t N2>
array<T, N1 + N2> merge(const array<T, N1>& left, const array<T, N2>& right) {
    array<T, N1 + N2> result;
    size_t i = 0, j = 0, k = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            result[k++] = left[i++];
        } else {
            result[k++] = right[j++];
        }
    }

    while (i < left.size()) {
        result[k++] = left[i++];
    }

    while (j < right.size()) {
        result[k++] = right[j++];
    }

    return result;
}
template <typename T, size_t N>
array<T, N> mergeSort(array<T, N> data) {
    if constexpr (N <= 1) {
        return data;
    } else {
        constexpr size_t mid = N / 2;
        array<T, mid> left;
        array<T, N - mid> right;

        for (size_t i = 0; i < mid; i++) {
            left[i] = data[i];
            right[i] = data[mid + i];
        }

        left = mergeSort(left);
        right = mergeSort(right);

        return merge(left, right);
    }
}