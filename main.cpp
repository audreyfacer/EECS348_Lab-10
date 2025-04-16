#include <iostream>
#include <fstream>
#include <string>
#include "calculator.hpp"
using namespace std;
int main(int argc, char *argv[]) {
    if (argc != 2)
    {
        cout << "Please provide the input file." << endl;
        exit(1);
    }
    
    ifstream inFile;
    inFile.open(argv[1]);
    if (inFile.is_open())
    {
        string str;
        while(std::getline(inFile, str))
        {
            int len = str.length();
            if(len == 0){
                cout<<str<<"is invalid.";
            }
            int i = 0;

            if(str[0]=='+'||str[0]=='-') i++;
            bool digitsBeforeDot = false;
            while(i < len && str[i] != '.'){
                if (!(str[i] >= '0' && str[i] <= '9')) {
                    cout<<str<<"is not a valid double.";
                }
                digitsBeforeDot = true;
                i++;
            }
            if(str[i]=='.'){
                i++;
                while(i <len){
                    if (!(str[i] >= '0' && str[i] <= '9')) {
                        cout<<str<<"is not a valid double.";
                    }
                    i++;
                }
            }
            parse_number(str)
        }
    }
    else
    {
        cout << "Input file cannot be opened" << endl;
        exit(1);
    }
    inFile.close();
    return 0;

}
