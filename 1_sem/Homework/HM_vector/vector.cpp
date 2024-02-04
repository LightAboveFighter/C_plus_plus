// #include "vector.h"

// // template<typename T>
// // T* vector<T>::memory_get() {
// //     first = static_cast<T*>( new char[sizeof(T)*space]);
// // };

// // template<typename T>
// // T* vector<T>::memory_get(std::size_t sp) {
// //     first = static_cast<T*>( new char[sizeof(T)*sp]);
// // };

// template<typename T>
// vector<T>::vector(vector<T>& vec):
//         sz{vec.sz}, space{vec.size()} {
//     memory_get(vec.size());
//     for (int i = 0; i < vec.size; ++i) {
//         first[i] = vec[i];
//     }

// }

// template<typename T>
// void vector<T>::push_back(T elem) {
//     // if (space == sz) {
//     //     space += 10;
//     //     first = static_cast<T*>( new char[sizeof(T)*space]);
//     //     for (int i = 0; i < sp; ++i) {
//     //         first[i] = vec[i];
//     //     }
//     // }
//     first[sz] = elem;
//     sz += 1;
// }

