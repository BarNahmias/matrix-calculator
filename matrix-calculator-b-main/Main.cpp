//
// Created by בר נחמיאס on 03/05/2022.
//

#include <iostream>
#include <sstream>
#include "sources/Matrix.hpp"



using namespace std;
using namespace zich;




//https://stackoverflow.com/questions/11505438/how-to-use-if-in-switch-statement



int main() {

    vector<double> matrixwA2x3 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    vector<double> matrixwB3x3 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    vector<double> matrixwd3x3 = {1,2,3,4,5,6};

    Matrix a{matrixwd3x3, 2, 3};
    Matrix b{matrixwd3x3, 3, 2};



    int action;





    cout<<"excellent we got this far meaning you got your matrix now you can do couple of action on them"<<endl<<
        "- to add them and see the result type 1"<<endl<<
        "- to multiply them and see the result type 2"<<endl<<
        "- to subtract them and see the result type 3"<<endl<<
        "- to see which one is bigger and see the result type 4"<<endl<<
      "- to divide them and see the result type 5"<<endl<<
        "- to exit  the program type 6"<<endl;
    cout<<"please enter your number"<<endl;

    while(true){
        cin>>action;

        switch (action) {
            case 1:
                cout<<(b*a)<<endl;
                break;
            case 2:
                cout<<(a*b)<<endl;
                break;
            case 3:
                cout<<(a-b)<<endl;
                break;
            case 4:
                cout<<"a < b =";
                if(a<b){
                    cout<<"True"<<endl;
                }else{
                    cout<<"False"<<endl;
                }
                break;
            case 5:
                cout<<(a/b)<<endl;
                break;
            case 6: cout<<"Goodbye";
                break;
            default:
                cout<<"enter one of the the number you were told to"<<endl;
        }
        if (action==6){
            cout<<"Goodbye"<<endl;
            break;
        }
    }


}