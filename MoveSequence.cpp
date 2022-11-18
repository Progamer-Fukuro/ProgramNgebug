#include "MoveSequence.h"
#include <iostream>

int MoveSequence::getLength()
{
    return mat.size();
}

void MoveSequence::stepForward()
{
    for(int i = 0; i<mat.size(); i++)
    {
        if(i == mat.size() - 1) mat.pop_back();
        else mat[i] = mat[i+1];
    }
}

MoveSequence MoveSequence::operator+(const MoveSequence& obj)
{
    MoveSequence res;
    for(int i = 0; i<getLength(); i++)
    {
        res.appendLast(Matrix1D::getValueAt(i) + obj.mat[i]);
    }
    return res;
}

MoveSequence MoveSequence::operator-(const MoveSequence& obj)
{
    MoveSequence res;
    for(int i = 0; i<getLength(); i++)
    {
        res.appendLast(Matrix1D::getValueAt(i) - obj.mat[i]);
    }
    return res;
}