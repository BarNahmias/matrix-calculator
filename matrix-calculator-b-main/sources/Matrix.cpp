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
                throw std::out_of_range("operator+ input  error ");}
                    return *this;}


        Matrix  Matrix::  operator-() {
            if (!good_input(*this) ){
                throw std::out_of_range("operator- input  error ");}


            Matrix result{this->_vec, this->_row, this->_column};

            for(unsigned i =0 ; i< result._vec.size();i++)
            {
                    result._vec.at(i)= (-(this->_vec.at(i)));
            }
            return result;}



//      friend global binary operators
         Matrix zich::operator- (const Matrix& a, const Matrix& b){

            if (!good_input(a) ){
                throw std::out_of_range("operator- input  error ");}

            if (!good_input(b) ){
                throw std::out_of_range("operator- input  error ");}

            if (!good_input_add( a,b)){
                throw std::out_of_range("arithmetic  error ");}

            zich::Matrix result{a._vec, a._row, a._column};

            for(unsigned i =0 ; i< result._vec.size();i++)
            {
                    result._vec.at(i)=(a._vec.at(i)-b._vec.at(i));
            }
            return result;
         }



         Matrix zich::operator+ (const Matrix& a, const Matrix& b){
             if (!good_input(a)){
                 throw std::out_of_range("operator+ input  error ");}

             if (!good_input(b)){
                 throw std::out_of_range("operator+ input  error ");}

             if (!good_input_add( a,b)){
                 throw std::out_of_range("operator+ arithmetic  error ");}

             zich::Matrix result{a._vec, a._row, a._column};

             for(unsigned i =0 ; i< result._vec.size();i++)
             {
                 result._vec.at(i)=(a._vec.at(i)+b._vec.at(i));
             }
             return result;
         }


        Matrix zich::operator * (const Matrix& a, const Matrix& b){
            if (!good_input(a) ){
                throw std::out_of_range("operator *input  error ");}

            if (!good_input(b) ){
                throw std::out_of_range("operator *input  error ");}


            if (!good_input_mul( a,b)){
                throw std::out_of_range("operator *arithmetic  mul error ");}


            vector<double > r;
            for (uint i = 0; i < a._row; i++) {
                for (uint j = 0; j < b._column; j++) {
                    r.push_back(0);
                }
            }
            for(unsigned i =0 ; i< a._row;i++)
            {
                for(unsigned j=0;j< b._column;j++)
                {
                    for(unsigned k=0;k< a._column;k++)
                    {
                    r[i*(b._column)+j]=r[i*(b._column)+j]+

                            (  b._vec.at( (k*b._column)+j) )  *(a._vec.at( (i*a._column)+k ) );
                }
            }

        }
            zich::Matrix result{r,a._row,b._column} ;
            return result;}







//      Addition and subtraction in the scalar
        Matrix  Matrix:: operator+(double scalar) const {

         if (!good_input(*this) ){
              throw std::out_of_range("operator+ input  error ");}

            zich::Matrix result{this->_vec, this->_row, this->_column};
                for(unsigned i =0 ; i< result._vec.size();i++)
                {
                    result._vec.at(i)= ( result._vec.at(i)+scalar);
                }
            return result;}


        Matrix  Matrix:: operator-(double scalar) const {
            if (!good_input(*this) ){
                throw std::out_of_range("operator-input  error ");}

            zich::Matrix result{this->_vec, this->_row, this->_column};
            for(unsigned i =0 ; i< result._vec.size();i++)
            {
                result._vec.at(i) = (result._vec.at(i) - scalar);
            }
                return result;}


        Matrix  zich::operator+ (double scalar,  Matrix const & a){
            if (!good_input(a)){
                throw std::out_of_range("operator+ input  error ");}

            zich::Matrix result{a._vec, a._row, a._column};
            for(unsigned i =0 ; i< result._vec.size();i++)
            {
                result._vec.at(i) = (result._vec.at(i) + scalar);
            }
            return result;
            }


        Matrix  zich::operator- (double scalar,  Matrix const & a){

            if (!good_input(a) ){
                throw std::out_of_range("operator- input  error ");}

            zich::Matrix result{a._vec, a._row, a._column};

            for(unsigned i =0 ; i< result._vec.size();i++)
            {
                result._vec.at(i) = (result._vec.at(i) - scalar);
            }
            return result;
            }




        //      Scalar multiplication

        Matrix  Matrix::operator*(double scalar) const {
            if (!good_input(*this) ){
                throw std::out_of_range("operator* input  error ");}

            zich::Matrix result{this->_vec, this->_row, this->_column};

            for(unsigned i =0 ; i< result._vec.size();i++)
            {
                result._vec.at(i) *= scalar;
            }


            return result;}





        Matrix  zich::operator* (double scalar,  Matrix const & a){
            if (!good_input(a)){
                throw std::out_of_range("input  error ");}

            zich::Matrix result{a._vec, a._row, a._column};

            for(unsigned i =0 ; i< result._vec.size();i++)
            {
                result._vec.at(i) = (result._vec.at(i) * scalar);
            }
            return result;
        }



//      Promote the matrix values by 1 or -1

        Matrix  Matrix::operator++(int dummy_flag_for_postfix_increment)  {
            if (!good_input(*this)){
                throw std::out_of_range("operator++ input  error ");}

            zich:: Matrix result {this->_vec, this->_row, this->_column};
                   ++*this;
             return result;
        }

        Matrix Matrix::operator--(int dummy_flag_for_postfix_increment) {
            if (!good_input(*this)){
                throw std::out_of_range("operator++ input  error ");}

            zich:: Matrix result {this->_vec, this->_row, this->_column};
                --*this;
            return result;
        }

            Matrix  Matrix::  operator++(){

                if (!good_input(*this)){
                    throw std::out_of_range("operator++ input  error ");}

                vector<double > v(this->_vec.size(),1);
                Matrix result(v, this->_row, this->_column);
                *this+=result;

                return *this;

        }

            Matrix  Matrix::  operator--(){
                if (!good_input(*this) ){
                    throw std::out_of_range("operator-- input  error ");}

                vector<double > v(this->_vec.size(),-1);
                Matrix result(v, this->_row, this->_column);
                *this+=result;

                return *this;

            }



//      Addition or subtraction and expression
        Matrix  Matrix::operator+=( Matrix &other) {
        if (!good_input(other)){
            throw std::out_of_range("input  error ");}
        if (!good_input(*this)){
            throw std::out_of_range("input  error ");}
        if (!good_input_add(*this,other)){
            throw std::out_of_range("input  error add ");}

            for(unsigned  i = 0; i<this->_vec.size();i++){
                this->_vec.at(i)+=other._vec.at(i);
            }
            return *this;
         }


        Matrix  Matrix::operator+( Matrix &other) {
            if (!good_input(other)){
                throw std::out_of_range("input  error ");}
            if (!good_input(*this)){
                throw std::out_of_range("input  error ");}
            if (!good_input_add(*this,other)){
                throw std::out_of_range("input  error add ");}
            vector<double > r;
            for(unsigned  i = 0; i<other._vec.size();i++){
                r.push_back( this->_vec[i]+other._vec[i]);
            }
            zich::Matrix result{r, other._row, other._column};

            return result;

        }

        Matrix  Matrix::operator-( Matrix &other) {
            if (!good_input(other)){
                throw std::out_of_range("input  error ");}
            if (!good_input(*this)){
                throw std::out_of_range("input  error ");}
            if (!good_input_add(*this,other)){
                throw std::out_of_range("input  error add ");}
            vector<double > r;
            for(unsigned  i = 0; i<other._vec.size();i++){
                r.push_back( this->_vec[i]-other._vec[i]);
            }
            zich::Matrix result{r, other._row, other._column};

            return result;

        }

        Matrix Matrix::operator-=( Matrix &other) {

            if (!good_input(other)){
                throw std::out_of_range("input  error ");}
            if (!good_input(*this)){
                throw std::out_of_range("input  error ");}
            if (!good_input_add(*this,other)){
                throw std::out_of_range("input  error add ");}
            for(unsigned  i = 0; i<this->_vec.size();i++){
                this->_vec.at(i)-=other._vec.at(i);
            }
            return *this;
            }

        Matrix  Matrix::operator*=( Matrix &other) {

            if (!good_input(other)){
                throw std::out_of_range("input  error ");}
            if (!good_input(*this)){
                throw std::out_of_range("input  error ");}
            if (!good_input_mul(*this,other)){
                throw std::out_of_range("can't mul  error ");}


            std::vector<double> temp( (this->_row*other._column),0) ;

            for(unsigned i =0 ; i< this->_row;i++)
            {
                for(unsigned j=0;j<other._column;j++)
                {
                    for(unsigned k=0;k< this->_column;k++)
                    {
                        temp.at(i*(other._column)+j)+=
                                this->_vec[(i*this->_column)+k]*other._vec[k*(other._column)+j];

                    }
                }

            }
            this->_vec=temp;
            this->_column=other._column;



            return *this;

            }

            Matrix  Matrix::operator*( Matrix &other) {
            //            return (*this)*(other);

                if (!good_input(other)){
                    throw std::out_of_range("input  error ");}
                if (!good_input(*this)){
                    throw std::out_of_range("input  error ");}
                if (!good_input_mul(*this,other)){
                    throw std::out_of_range("can't mul  error ");}

                std::vector<double> temp( (this->_row*other._column),0) ;


                for(unsigned i =0 ; i< this->_row;i++)
                {
                    for(unsigned j=0;j<other._column;j++)
                    {
                        for(unsigned k=0;k< this->_column;k++)
                        {
                            temp[i*(other._column)+j]+=this->_vec.at((i*this->_column) +k)*other._vec.at((k*other._column) +j);

                        }
                    }

                }

                zich::Matrix result{temp,this->_row,other._column} ;

                return result;

            }

        Matrix  Matrix::operator*=( double scalar)  {
            if (!good_input(*this)){
                throw std::out_of_range("input  error ");}

            for(unsigned i =0 ; i< this->_vec.size();i++)
            {
                this->_vec.at(i) = this->_vec.at(i) *scalar;
            }

            return *this;}


//      Comparison
        bool zich::operator<(const Matrix &a,const Matrix &b) {
        if (!good_input(a) ){
            throw std::out_of_range("operator< input  error ");}
        if (!good_input(b) ){
            throw std::out_of_range("operator< input  error ");}
        if (!good_input_add(a,b) ){
            throw std::out_of_range("operator< input  error ");}

        double sum_a=sum_matrix(a);
        double sum_b=sum_matrix(b);


            return (sum_a<sum_b);
         }
        bool zich::operator<=(const Matrix &a,const Matrix &b) {

            if (!good_input(a) ){
                throw std::out_of_range("operator<= input  error ");}
            if (!good_input(b) ){
                throw std::out_of_range("operator<= input  error ");}
            if (!good_input_add(a,b) ){
                throw std::out_of_range("operator< input  error ");}
            double sum_a=sum_matrix(a);
            double sum_b=sum_matrix(b);

            return (sum_a<=sum_b);
        }

        bool zich::operator>(const Matrix &a,const Matrix &b) {

            if (!good_input(a)){
                throw std::out_of_range("operator> input  error ");}
            if (!good_input(b)){
                throw std::out_of_range("operator> input  error ");}
            if (!good_input_add(a,b) ){
                throw std::out_of_range("operator< input  error ");}
            double sum_a=sum_matrix(a);
            double sum_b=sum_matrix(b);

            return (sum_a>sum_b);
        }

        bool zich::operator>=(const Matrix &a,const Matrix &b) {
            if (!good_input(a)){
                throw std::out_of_range("operator>= input  error ");}
            if (!good_input(b) ){
                throw std::out_of_range("operator>= input  error ");}
            if (!good_input_add(a,b) ){
                throw std::out_of_range("operator< input  error ");}
            double sum_a=sum_matrix(a);
            double sum_b=sum_matrix(b);
            return (sum_a>=sum_b);
        }

        bool zich::operator==(const Matrix &a,const Matrix &b) {

            if (!good_input(a) ){
                throw std::out_of_range("operator== input  error ");}
            if (!good_input(b) ){
                throw std::out_of_range("operator== input  error ");}
            if (!good_input_add(a,b) ){
                throw std::out_of_range("operator< input  error ");}
            double sum_a=sum_matrix(a);
            double sum_b=sum_matrix(b);
            return (sum_a==sum_b);
        }

        bool zich::operator!=(const Matrix &a,const Matrix &b) {

            if (!good_input(a)){
                throw std::out_of_range("operator!= input  error ");}
            if (!good_input(b) ){
                throw std::out_of_range("operator!= input  error ");}
            if (!good_input_add(a,b) ){
                throw std::out_of_range("operator< input  error ");}
            double sum_a=sum_matrix(a);
            double sum_b=sum_matrix(b);

            return (sum_a!=sum_b);
        }






//      input
        std::istream& zich:: operator>>(std::istream& input,  Matrix &mat)  {

    if (!good_input(mat) ){
        throw std::out_of_range("input  error ");}
        vector<double> vec;
        int row=0;
        int rowLenght = 1;
        int counter = 1;
        double number = 0;
        bool first = false;
        string tempNum;
        char temp = input.get();
        while(temp!='\n'){
            if(temp==' '){
                number= stod(tempNum);
                vec.push_back(number);
                tempNum="";
                counter++;
            }
            if(temp==','){
                row++;
                if(first&&rowLenght!=counter){
                    throw invalid_argument("wrong input for matrix");
                }
                if(!first) {
                    rowLenght = counter;
                    first= true;
                }
                counter=0;

            }
            if(temp!='['&&temp!=']') {
                tempNum += temp;
            }
            temp = input.get();

        }
        mat._column=rowLenght;
        mat._row = row;
        mat._vec = vec;
        return input;
    }


//      output
        std::ostream& zich::operator<<(std::ostream& output ,const Matrix &m) {

    if (!good_input(m) ){
        throw std::out_of_range("input  error ");}

             string result ;
             for (unsigned i = 0; i < m._row; i++) {
                 result +="[";
                 for (unsigned j = 0; j <m._column ; j++) {
                     result +=  to_string( int(m._vec.at(i*m._column+j)));
                     if(j!=m._column-1){
                     result += " ";}
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

             return (b._row==a._column);}

             bool zich:: good_input_add(const Matrix& a,const Matrix& b){
                 return ((a._row==b._row)&&(a._column==b._column)&&(a._vec.size()==b._vec.size()));
                 }

        bool zich:: good_input(const Matrix& a){
            return ((a._row*a._column==a._vec.size())&&(a._row>0)&&(a._column>0));}

        double zich:: sum_matrix(const Matrix& a){
            double sum_a=0;
            for(unsigned i =0 ; i< a._vec.size();i++)
            {
                    sum_a=sum_a + a._vec.at(i);
            }
            return sum_a;}


