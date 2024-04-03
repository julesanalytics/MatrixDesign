Creating an N-Dimensional matrix
* Matrix<T,N> is an N-dimensional matrix of some type T
* i.e
  * Matrix<double,0> m0 {1} --- 0 dimensions: a scalar
  * Matrix<double,1> m1 {1,2,3,4} --- 1 dimension: a vector
  * Matrix<double,2> m2 {
        {00,01,02,03},
        {10,11,12,13},
        {20,21,22,23}
      }
  * Matrix<double,3> m3(4,7,9); --- 3 dimensions (4x7x9), all 0-initialized
  * Matrix<complex<double>,17> m17; --17 dimensions, no elements so far
  * 