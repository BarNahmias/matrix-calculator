//
// Created by בר נחמיאס on 30/03/2022.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include "Matrix.hpp"

using namespace std;
using namespace zich;





//      Addition and subtraction of Unary
        Matrix&  Matrix:: operator+() {
            if (!good_input(*this) ){
                throw std::out_of_range("input  error ");}
                    return *this;}

        Matrix  Matrix::  operator-() {
            if (!good_input(*this) ){
                throw std::out_of_range("input  error ");}
            Matrix result{this->_vec, this->_row, this->_column};

            for(unsigned i =0 ; i< this->_row;i++)
            {
                for(unsigned j=0;j< this->_column;j++)
                {
                    result._mat[i][j]= (-(this->_mat[i][j]));


                }
            }
            return result;}



//      friend global binary operators
         Matrix zich::operator- (const Matrix& a, const Matrix& b){
            if (!good_input(a) ){
                throw std::out_of_range("input  error ");}

            if (!good_input(b) ){
                throw std::out_of_range("input  error ");}

            if (!good_input_add( a,b) ){
                throw std::out_of_range("arithmetic  error ");}
            zich::Matrix result{a._vec, a._row, a._column};
            for(unsigned i =0 ; i< result._row;i++)
            {
                for(unsigned j=0;j< result._column;j++)
                {
                    result._mat[i][j]=(a._mat[i][j]-b._mat[i][j]);
                }
            }
            return result;
         }

         Matrix zich::operator+ (const Matrix& a, const Matrix& b){
             if (!good_input(a) ){
                 throw std::out_of_range("input  error ");}

             if (!good_input(b) ){
                 throw std::out_of_range("input  error ");}

             if (!good_input_add( a,b) ){
                 throw std::out_of_range("arithmetic  error ");}
             zich::Matrix result{a._vec, a._row, a._column};
             for(unsigned i =0 ; i< result._row;i++)
             {
                 for(unsigned j=0;j< result._column;j++)
                 {
                     result._mat[i][j]=(a._mat[i][j]+b._mat[i][j]);
                 }
             }
             return result;
         }

        Matrix zich::operator* (const Matrix& a, const Matrix& b){
            if (!good_input(a) ){
                throw std::out_of_range("input  error ");}

            if (!good_input(b) ){
                throw std::out_of_range("input  error ");}


            if (!good_input_mul( a,b) ){
                throw std::out_of_range("arithmetic  error ");}

            zich::Matrix result ;
            for(unsigned i =0 ; i< a._row;i++)
            {
                for(unsigned j=0;j< a._column;j++)
                {
                    for(unsigned k=0;k< b._row;k++)
                    {
                    result._mat[i][j]+=(a._mat[i][k]*b._mat[k][j]);
                }
            }

        }
        return result;}



//      Addition and subtraction in the scalar
        Matrix  Matrix:: operator+(double scalar) {

         if (!good_input(*this) ){
              throw std::out_of_range("input  error ");}

            zich::Matrix result{this->_vec, this->_row, this->_column};
            for(unsigned i =0 ; i< this->_row;i++)
            {
                for(unsigned j=0;j< this->_column;j++)
                {
                    result._mat[i][j]=(this->_mat[i][j]+scalar);
                }
            }
            return result;}

        Matrix  Matrix:: operator-(double scalar) {
            if (!good_input(*this) ){
                throw std::out_of_range("input  error ");}

            zich::Matrix result{this->_vec, this->_row, this->_column};
            for(unsigned i =0 ; i< this->_row;i++)
            {
                for(unsigned j=0;j< this->_column;j++)
                {
                    result._mat[i][j]=(this->_mat[i][j]-scalar);
                }
            }
            return result;}

        Matrix  zich::operator+ (double scalar,  Matrix const & a){
            if (!good_input(a) ){
                throw std::out_of_range("input  error ");}

            zich::Matrix result{a._vec, a._row, a._column};
            for(unsigned i =0 ; i< result._row;i++)
            {
                for(unsigned j=0;j< result._column;j++)
                {
                    result._mat[i][j]=(result._mat[i][j]+scalar);
                }
            }
            return result;
            }


        Matrix  zich::operator- (double scalar,  Matrix const & a){

            if (!good_input(a) ){
                throw std::out_of_range("input  error ");}

            zich::Matrix result{a._vec, a._row, a._column};

                for(unsigned i =0 ; i< result._row;i++)
                {
                    for(unsigned j=0;j< result._column;j++)
                    {
                        result._mat[i][j]=(result._mat[i][j]-scalar);
                    }
                }
            return result;
            }



//      Promote the matrix values by 1 or -1

        Matrix  zich::operator++(Matrix& m ,int dummy_flag_for_postfix_increment)  {
            if (!good_input(m) ){
                throw std::out_of_range("input  error ");}

//        zich::Matrix result = *this;
        zich:: Matrix result {m._vec, m._row, m._column};
        for(unsigned i =0 ; i< result._row;i++)
        {
            for(unsigned j=0;j< result._column;j++)
            {
                result._mat[i][j]=(result._mat[i][j]++);
            }
        }
             return result;
        }

        Matrix zich::operator--(Matrix& m ,int dummy_flag_for_postfix_increment) {
            if (!good_input(m) ){
                throw std::out_of_range("input  error ");}

            zich:: Matrix result {m._vec, m._row, m._column};
//            zich::Matrix result = *this;

            for(unsigned i =0 ; i< result._row;i++)
            {
                for(unsigned j=0;j< result._column;j++)
                {
                    result._mat[i][j]=(result._mat[i][j]--);
                }
            }
            return result;
        }

            Matrix  Matrix::  operator++(){

                if (!good_input(*this) ){
                    throw std::out_of_range("input  error ");}

                for(unsigned i =0 ; i< this->_row;i++)
                {
                    for(unsigned j=0;j< this->_column;j++)
                    {
                        this->_mat[i][j]=(this->_mat[i][j]+1);
                    }
                }
                return *this;

        }

            Matrix  Matrix::  operator--(){
                if (!good_input(*this) ){
                    throw std::out_of_range("input  error ");}

                for(unsigned i =0 ; i< this->_row;i++)
                {
                    for(unsigned j=0;j< this->_column;j++)
                    {
                        this->_mat[i][j]=(this->_mat[i][j]-1);
                    }
                }
                return *this;

            }



//      Addition or subtraction and expression
        Matrix  Matrix::operator+=( Matrix &other) {

        if (!good_input(other) ){
            throw std::out_of_range("input  error ");}
             vector<double > r;
             for(unsigned  i = 0; i<other._row*other._column;i++){
                 r[i]=other._vec[i]+other._vec[i];
             }
            zich::Matrix result{r, other._row, other._column};

                return result;
         }


        Matrix Matrix::operator-=( Matrix &other) {

            if (!good_input(other) ){
                throw std::out_of_range("input  error ");}
            vector<double > r;
            for(unsigned  i = 0; i<other._row*other._column;i++){
                r[i]=other._vec[i]-other._vec[i];
            }
            zich::Matrix result{r, other._row, other._column};

            return result;
            }

        Matrix  Matrix::operator*=( Matrix &other) {
            if (!good_input(other) ){
                throw std::out_of_range("input  error ");}

            vector<double > r;
            for(unsigned  i = 0; i<other._row*other._column;i++){
                r[i]=other._vec[i]*other._vec[i];
            }
            zich::Matrix result{r, other._row, other._column};

            return result;
            }

        Matrix  Matrix::operator*=( double scalar) {
            if (!good_input(*this) ){
                throw std::out_of_range("input  error ");}
            vector<double > r;
            for(unsigned  i = 0; i< this->_row* this->_column;i++){
                r[i]=this->_vec[i]*scalar;
            }
            zich:: Matrix result{r, this->_row, this->_column};

            return result;
            }


//      Comparison
        bool zich::operator<(const Matrix &a,const Matrix &b) {
        if (!good_input(a) ){
            throw std::out_of_range("input  error ");}
        if (!good_input(b) ){
            throw std::out_of_range("input  error ");}


            double sum_a=0;
            double sum_b=0;
            for(unsigned i =0 ; i< a._row;i++)
            {
                for(unsigned j=0;j< a._column;j++) {
                   sum_a=sum_a+ a._mat[i][j];
                     }
                }
            for(unsigned i =0 ; i< b._row;i++)
            {
                for(unsigned j=0;j< b._column;j++) {
                    sum_b=sum_b+ b._mat[i][j];
                }
            }

            return (sum_a<sum_b);
         }
        bool zich::operator<=(const Matrix &a,const Matrix &b) {

            if (!good_input(a) ){
                throw std::out_of_range("input  error ");}
            if (!good_input(b) ){
                throw std::out_of_range("input  error ");}

            double sum_a=0;
            double sum_b=0;

            for(unsigned i =0 ; i< a._row;i++)
            {
                for(unsigned j=0;j< a._column;j++) {
                    sum_a=sum_a+ a._mat[i][j];
                }
            }
            for(unsigned i =0 ; i< b._row;i++)
            {
                for(unsigned j=0;j< b._column;j++) {
                    sum_b=sum_b+ b._mat[i][j];
                }
            }

            return (sum_a<=sum_b);
        }

        bool zich::operator>(const Matrix &a,const Matrix &b) {

            if (!good_input(a) ){
                throw std::out_of_range("input  error ");}
            if (!good_input(b) ){
                throw std::out_of_range("input  error ");}
            double sum_a=0;
            double sum_b=0;

            for(unsigned i =0 ; i< a._row;i++)
            {
                for(unsigned j=0;j< a._column;j++) {
                    sum_a=sum_a+ a._mat[i][j];
                }
            }
            for(unsigned i =0 ; i< b._row;i++)
            {
                for(unsigned j=0;j< b._column;j++) {
                    sum_b=sum_b+ b._mat[i][j];
                }
            }

            return (sum_a>sum_b);
        }

        bool zich::operator>=(const Matrix &a,const Matrix &b) {
            if (!good_input(a) ){
                throw std::out_of_range("input  error ");}
            if (!good_input(b) ){
                throw std::out_of_range("input  error ");}

            double sum_a=0;
            double sum_b=0;

            for(unsigned i =0 ; i< a._row;i++)
            {
                for(unsigned j=0;j< a._column;j++) {
                    sum_a=sum_a+ a._mat[i][j];
                }
            }
            for(unsigned i =0 ; i< b._row;i++)
            {
                for(unsigned j=0;j< b._column;j++) {
                    sum_b=sum_b+ b._mat[i][j];
                }
            }

            return (sum_a>=sum_b);
        }

        bool zich::operator==(const Matrix &a,const Matrix &b) {

            if (!good_input(a) ){
                throw std::out_of_range("input  error ");}
            if (!good_input(b) ){
                throw std::out_of_range("input  error ");}

            double sum_a=0;
            double sum_b=0;

            for(unsigned i =0 ; i< a._row;i++)
            {
                for(unsigned j=0;j< a._column;j++) {
                    sum_a=sum_a+ a._mat[i][j];
                }
            }
            for(unsigned i =0 ; i< b._row;i++)
            {
                for(unsigned j=0;j< b._column;j++) {
                    sum_b=sum_b+ b._mat[i][j];
                }
            }

            return (sum_a==sum_b);
        }

        bool zich::operator!=(const Matrix &a,const Matrix &b) {

            if (!good_input(a) ){
                throw std::out_of_range("input  error ");}
            if (!good_input(b) ){
                throw std::out_of_range("input  error ");}

            double sum_a=0;
            double sum_b=0;

            for(unsigned i =0 ; i< a._row;i++)
            {
                for(unsigned j=0;j< a._column;j++) {
                    sum_a=sum_a+ a._mat[i][j];
                }
            }
            for(unsigned i =0 ; i< b._row;i++)
            {
                for(unsigned j=0;j< b._column;j++) {
                    sum_b=sum_b+ b._mat[i][j];
                }
            }

            return (sum_a!=sum_b);
        }


//      Scalar multiplication
        Matrix  Matrix::operator*(double scalar) {

    if (!good_input(*this) ){
        throw std::out_of_range("input  error ");}


            zich::Matrix result{this->_vec, this->_row, this->_column};
            for(unsigned i =0 ; i< this->_row;i++)
            {
                for(unsigned j=0;j< this->_column;j++)
                {
                    result._mat[i][j]=((this->_mat[i][j])*scalar);
                }
            }
            return result;}





        Matrix  zich::operator* (double scalar,  Matrix const & a){
            if (!good_input(a) ){
                throw std::out_of_range("input  error ");}

            zich::Matrix result{a._vec, a._row, a._column};
            for(unsigned i =0 ; i< a._row;i++)
            {
                for(unsigned j=0;j< a._column;j++)
                {
                    result._mat[i][j]=((a._mat[i][j])*scalar);

                }
            }
            return result;}




//      input
        std::istream& zich:: operator>>(std::istream& input, const Matrix &m)  {

    if (!good_input(m) ){
        throw std::out_of_range("input  error ");}

        for (int i = 0; i < m._row; i++)    {
            for (int j = 0; j < m._column; j++){
//                if ( ! (input >> m._mat[i][j]) ) return input;
            }
        }
        return input; }

//      output
        std::ostream& zich::operator<<(std::ostream& output ,const Matrix &m) {

    if (!good_input(m) ){
        throw std::out_of_range("input  error ");}

             string result ;
             for (unsigned i = 0; i < m._row; i++) {
                 result +="[";
                 for (unsigned j = 0; j <m._column ; j++) {
                     result +=  to_string( m._mat[i][j]);
                     result += " ";
                 }
                 result +="]";
                 if(i!=m._row-1)
                 {
                 result +="\n";
                 }
                    }

             return output <<result;  }


        //function

         bool zich:: good_input_mul(const Matrix& a,const Matrix& b){
             return (a._row!=b._column);}

             bool zich:: good_input_add(const Matrix& a,const Matrix& b){
                 return ((a._row!=b._row)||(a._column!=b._column));
                 }

        bool zich:: good_input(const Matrix& a){
            return (a._row*a._column==a._vec.size());}

