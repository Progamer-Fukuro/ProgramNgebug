#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

template <class T>
class Matrix1D
{
    protected:
        std::vector<T> mat;

    public:
        Matrix1D(){}
        Matrix1D(int size_) {resize(size_);}
        Matrix1D(std::vector<T> mat_) : mat(mat_) {}

        void setMatrix1D(Matrix1D<T> mat_) {mat = mat_.mat;}
        void resize(int size_){mat.resize(size_);}
        void appendLast(T);
        void appendFirst(T);
        T getValueAt(int idx) {return mat[idx];}
        void setValueAt(int idx,T val_) {mat[idx] = val_;}

        Matrix1D<T> operator+(const Matrix1D<T>&);
        Matrix1D<T> operator-(const Matrix1D<T>&);
};

template <class T>
void Matrix1D<T>::appendLast(T val_)
{
    mat.push_back(val_);
}

template <class T>
void Matrix1D<T>::appendFirst(T val_)
{
    appendLast(val_);

    int mat_size = mat.size();

    T temp_mat = mat.back();

    for(int i = mat_size; i>0; i--)
    {
        if(i == 0) mat[i] = temp_mat;
        else mat[i] = mat[i-1];
    }
}

template <class T>
Matrix1D<T> Matrix1D<T>::operator+(const Matrix1D<T>& obj)
{
    int iter_size = (mat.size()>obj.mat.size())? obj.mat.size() : mat.size();

    Matrix1D<T> res(mat);

    for(int i = 0; i<iter_size; i++) res.mat[i] = mat[i] + obj.mat[i];

    return res;
}

template <class T>
Matrix1D<T> Matrix1D<T>::operator-(const Matrix1D<T>& obj)
{
    int iter_size = (mat.size()>obj.mat.size())? obj.mat.size() : mat.size();

    Matrix1D<T> res(mat);

    for(int i = 0; i<iter_size; i++) res.mat[i] = mat[i] - obj.mat[i];

    return res;
}

#endif //MATRIX_H