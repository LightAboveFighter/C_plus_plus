// #ifndef _ACTUAL_H_
// #define _ACTUAL_H_
// #include <memory>

// template<typename T, typename A>
// struct vector_base {
//     A alloc;
//     int sz;
//     T* elem;
//     int space;

//     vector_base(const A& a, int n): alloc{a}, sz{n}, elem{a.allocate(n)}, space{n} {};
//     ~vector_base() { alloc.deallocate(elem, space); }
// };

// template<typename T, typename A = std::allocator<T>>
// class vector : private vector_base {
// public:
//     vector(): sz{0}, elem{nullptr}, space{0} {};
//     // vector(std::initializer_list lst): sz{lst.size()}, elem{ new T[lst.size()]} {
//     //     for (int i = 0; i < lst.size(), ++i ) {
//     //         elem[i] = lst[i];
//     //     }
//     // }
//     explicit vector(int n, T item = T()): sz{n}, elem{ alloc.allocate(n)}, space{n} {
//         for (int i = 0; i < sz; ++i ) {
//             alloc.construct(&elem[i], item);
//         }
//     };
//     vector(vector& vec): sz{vec.size()}, elem{ alloc.allocate(vec.size())} {
//         for (int i = 0; i < vec.size(); ++i ) {
//             elem[i] = vec[i];
//         }
//     }
//     vector(vector&& vec): sz{vec.sz}, elem{vec.elem}, space{vec.sz} {
//         vec.sz = 0;
//         vec.elem = nullptr;
//     }

//     int size() { return sz; };
//     void reserve(int newalloc) {
//         if (newalloc <= this->space) return;
//         vector_base<T, A> b(this->alloc, newalloc);
//         std::uninitialized_copy(b.elem, &b.elem[this->sz], this->elem);

//         for (int i = 0; i < this->sz; ++i) {
//             alloc.destroy(&this->elem[i]);
//         }
//         std::swap<vector_base<T, A>>(*this, b);
//     }
//     int capacity() { return space; };
//     void resize(int newsize, T val = T()) {
//         reserve(newsize);
//         for (int i = sz; i < newsize; ++i) {
//             alloc.construct(&elem[i], val);
//         }
//         for (int i = sz; i < newsize; ++i) {
//             alloc.destroy(&elem[i]);
//         }
//         sz = newsize;
//     }
//     void push_back(T item) {
//         if (space == 0) {
//             reserve(8);
//         }
//         else if (sz == space) {
//             reserve(2*space);
//         }
//         alloc.construct(&elem[sz], item);
//         ++sz;
//     }
//     T& at(int n) {
//         if (n < 0 || n >=sz) {
//             throw out_of_range();
//         }
//         return elem[n];
//     }
//     const T& at(int n) const {

//     }

//     T& operator[] (int n) {
//         return elem[n];
//     }
//     const T& operator[] (int n) const {
//         return elem[n];
//     }
//     vector& operator= (const vector& vec) {
//         if (this == &vec) { return *this; }
//         if (vec.size() <= space) {
//             for (int i = 0; i < vec.size(); ++i) {
//                 elem[i] = vec[i];
//             }
//             sz = vec.size();
//             return *this;
//         }

//         T* p = alloc.allocate(vec.size());
//         for (int i = 0; i < vec.size(); ++i) {
//             p[i] = vec[i];
//         }
//         space = sz = vec.size();
//         for (int i = 0; i < sz; ++i) {
//             alloc.destroy(&elem[i]);
//         }
//         alloc.deallocate(elem, space);
//         elem = p;
//         return *this;
//     }
//     vector& operator= (vector&& vec) {
//         for (int i = 0; i < sz; ++i) {
//             alloc.destroy(&elem[i]);
//         }
//         alloc.deallocate(elem, space);
//         elem = vec.elem;
//         vec.elem = nullptr;
//         sz = vec.sz;
//         vec.sz = 0;
//         return *this;
//     }

// private:
//     struct out_of_range {
//         /* rara */
//     };
// };

// #endif