/*
 * Created by Jack Julian on 4/2/24.
 * Initial Matrix Declaration: some errors using classes we have not created yet
*/

#include <iostream>

template<typename T, size_t N>
class Matrix {
public:
    static constexpr size_t order = N; // number of dimensions -- constexpr: constant evaluated at compile time
    using value_type = T;
    using iterator = typename std::vector<T>::iterator;
    using const_iterator = typename std::vector<T>::const_iterator;

    Matrix() = default;                             // use compiler-generated no arg constructor
    Matrix(Matrix&&) = default;                     // move
    Matrix& operator=(Matrix&&) = default;          // operator overloading
    Matrix(const Matrix&) = default;
    Matrix& operator=(const Matrix&) = default;
    ~Matrix() = default;                            // destructor

    template<typename U> Matrix(const Matrix_ref<U,N>&);
    template<typename U>Matrix& operator=(const Matrix_ref<U,N>&);

    template<typename... Exts> explicit Matrix(Exts... exts);

    Matrix(Matrix_initializer<T,N>);
    Matrix& operator=(Matrix_initializer<T,N>);

    template<typename U> Matrix(initializer_list<U>) = delete;
    template<typename U> Matrix& operator=(initializer_list<U>) = delete;

    size_t extent(size_t n) const { return desc.extents[n]; }           // return elements in nth dimension
    size_t size() const { return elems.size(); }                        // return total number of elements
    const Matrix_slice<N>& descriptor() const { return desc; }          // the slice defining subscripting

    T* data() { return elems.data(); }                                  // "flattened (linear)" element access
    const T* data() const { return elems.data(); }

private:
    Matrix_slice<N> desc;               // slice defining extents in the N dimensions
    vector<T> elems;                    // elements of matrix
};
