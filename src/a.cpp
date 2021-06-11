#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream arqOut;
    arqOut.open("../teste.txt",ios::out); 
    arqOut << "Henricky" <<"\n";
    arqOut.close();              

    return 0;
}