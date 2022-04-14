//
// Created by בר נחמיאס on 30/03/2022.
//
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
namespace zich{

    class Matrix {

    private:


    public:
        double _row;
        double _column;
        std::vector< double> _vec;

        //constructor

        //default constructor
        Matrix();

        //constructor without vector
        Matrix(double row_a,double column_b){
            if(row_a<0||column_b<0){
                throw std::out_of_range("error : negative input");}
            this->_row=row_a;
            this->_column=column_b;
            std::vector<double > vect;
            for (unsigned i = 0; i < row_a; i++) {
                for (unsigned j = 0; j < column_b; j++) {
                vect.push_back(0);
                }
            }
            this->_vec=vect;
        }

        //full constructor
        Matrix(std::vector<double> vec , double row,double column) {
//            check good input for constructor
            if(row<0||column<0){
                throw std::out_of_range("error : negative input");}
            if(row*column!=vec.size()){

                throw std::out_of_range("error : bad arr input");}
            this->_row = row;
            this->_column = column;
            this->_vec=vec;

        }



        //copy constructor

        Matrix(Matrix const &object){
            this->_row= object._row;
            this->_column= object._column;
            this->_vec= object._vec;
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
        Matrix operator+(double scalar) const ;
        Matrix operator-(double scalar) const;
        friend Matrix operator+ (double scalar,  Matrix const & a);
        friend Matrix operator- (double scalar,  Matrix const & a);

//      Promote the matrix values by 1 or -1
//      a++
        Matrix  operator++() ;
        Matrix  operator--() ;
//      ++a
         Matrix  operator++( int dummy_flag_for_postfix_increment) ;
         Matrix  operator--(int dummy_flag_for_postfix_increment) ;

//      Addition or subtraction and expression
        Matrix operator+=( Matrix &other) ;
        Matrix operator-=( Matrix &other) ;
        Matrix operator*=( Matrix &other) ;
        Matrix operator*=( double scalar)  ;

        Matrix operator+( Matrix &other) ;
        Matrix operator-( Matrix &other) ;
        Matrix operator*( Matrix &other) ;


        //      Comparison
        friend bool operator<(const Matrix &a,const Matrix &b) ;
        friend  bool operator<=(const Matrix &a,const Matrix &b) ;
        friend  bool operator>(const Matrix &a,const Matrix &b) ;
        friend  bool operator>=(const Matrix &a,const Matrix &b) ;
        friend  bool operator==(const Matrix &a,const Matrix &b) ;
        friend   bool operator!=(const Matrix &a,const Matrix &b) ;

//      Scalar multiplication
        Matrix operator*(double scalar)const ;
//        Matrix operator*(int scalar) const;

        friend Matrix operator* (double scalar,  Matrix const & a);



//      output
        friend std::istream& operator>>(std::istream& input,  Matrix &m) ;

//      input
        friend std::ostream& operator<<(std::ostream& output ,const Matrix &m) ;


        //function

        friend bool good_input_mul(const Matrix& a,const Matrix& b);
        friend bool good_input_add(const Matrix& a,const Matrix& b);
        friend bool good_input(const Matrix& a);
        friend double sum_matrix(const Matrix& a);
    };
}


