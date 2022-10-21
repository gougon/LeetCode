#include "Utils.h"

using namespace std;

template <typename T>
void Utils<T>::printVector(vector<T> vec) {
    for (T &t: vec) 
        cout << t << " ";
    cout << endl;
}
