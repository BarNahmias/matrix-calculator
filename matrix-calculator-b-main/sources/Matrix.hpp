//
// Created by בר נחמיאס on 30/03/2022.
//
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

namespace zich{

    class Matrix {

    private:
//        double _row;
//        double _column;
//        std::vector<double> _vec;
//        std::vector<std::vector<double >>_mat;



    public:
        double _row;
        double _column;
        std::vector<double> _vec;
        std::vector< std:: vector<double >> _mat;



        //constructor

        Matrix();

        Matrix(std::vector<double> vec , double row,double column) {
            this->_row = row;
            this->_column = column;
            for (unsigned i=0; i<vec.size(); i++)
                this->_vec.push_back(vec.at(i));
            for (unsigned i = 0; i < row; i++) {
                for (unsigned j = 0; j < column; j++) {
                    this->_mat[i][j] = vec.at(j + i * column) ;
                }
            }
        }

//        Matrix(std::vector<double> vec , double row,double column) {
//            this->_row = row;
//            this->_column = column;
//            this->_vec=vec;
//        }



        //copy constructor

        Matrix(Matrix const &object){
            this->_row= object._row;
            this->_column= object._column;
            this->_vec= object._vec;
//            this->_mat=object._mat;
        }

//      **operators**

//      Addition and subtraction of Unary
        Matrix& operator+() ;
        Matrix  operator-() ;



//      friend global binary operators
        friend Matrix operator- (const Matrix& a, const Matrix& b);
        friend Matrix operator+(const Matrix& a, const Matrix& b);
        friend Matrix operator* (const Matrix& a, const Matrix& b);


//      Addition and subtraction in the scalar
        Matrix operator+(double scalar) ;
        Matrix operator-(double scalar) ;
        friend Matrix operator+ (double scalar,  Matrix const & a);
        friend Matrix operator- (double scalar,  Matrix const & a);

//      Promote the matrix values by 1 or -1
//      a++
        Matrix  operator++() ;
        Matrix  operator--() ;
//      ++a
        friend Matrix  operator++( Matrix& m ,int dummy_flag_for_postfix_increment) ;
        friend Matrix  operator--(Matrix& m ,int dummy_flag_for_postfix_increment) ;

//      Addition or subtraction and expression
        Matrix operator+=( Matrix &other) ;
        Matrix operator-=( Matrix &other) ;
        Matrix operator*=( Matrix &other) ;
        Matrix operator*=( double scalar) ;


        //      Comparison
        friend bool operator<(const Matrix &a,const Matrix &b) ;
        friend  bool operator<=(const Matrix &a,const Matrix &b) ;
        friend  bool operator>(const Matrix &a,const Matrix &b) ;
        friend  bool operator>=(const Matrix &a,const Matrix &b) ;
        friend  bool operator==(const Matrix &a,const Matrix &b) ;
        friend   bool operator!=(const Matrix &a,const Matrix &b) ;

//      Scalar multiplication
        Matrix operator*(double scalar) ;
        friend Matrix operator* (double scalar,  Matrix const & a);



//      output
        friend std::istream& operator>>(std::istream& input, const Matrix &m) ;

//      input
        friend std::ostream& operator<<(std::ostream& output ,const Matrix &m) ;


        //function

        friend bool good_input_mul(const Matrix& a,const Matrix& b);
        friend bool good_input_add(const Matrix& a,const Matrix& b);
        friend bool good_input(const Matrix& a);

    };
}


