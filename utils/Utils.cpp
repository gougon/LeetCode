#include "Utils.h"

using namespace std;

template <typename T>
void Utils<T>::printVector(vector<T> vec) {
    for (T &t: vec) 
        cout << t << " ";
    cout << endl;
}

template <typename T>
void Utils<T>::printNestedVector(vector<vector<T>> nvec) {
    for (vector<T> &vec: nvec) 
        Utils<T>::printVector(vec);
}
