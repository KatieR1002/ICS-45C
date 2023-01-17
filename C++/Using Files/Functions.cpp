#include "Functions.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
void add(string a, string b, string output){
 vector<vector<int>> matrixa;
 string la;
 ifstream inputa(a);
 while (getline(inputa, la)) {
         istringstream stringa(la);
         vector<int> row;
         int value;
         while (stringa >> value) {
             row.push_back(value);
         }
         matrixa.push_back(row);
     }
 vector<vector<int>> matrixb;
 string lb;
 ifstream inputb(b);
 while (getline(inputb, lb)) {
         istringstream stringb(lb);
         vector<int> row;
         int value;
         while (stringb >> value) {
             row.push_back(value);
         }
         matrixb.push_back(row);
     }
vector<vector<int>> matrixc;
 for (size_t i = 0; i < matrixb.size(); ++i) {
   vector<int> rowc;
         for (size_t j = 0; j < matrixb[i].size(); ++j) {
          int value;
          value =matrixa[i][j] + matrixb[i][j];
          rowc.push_back(value);
         }
     matrixc.push_back(rowc);
     }
//put matrix c into Output File.
 ofstream outFile;
 outFile.open(output,ios::out|ios::trunc);
 string outputline;
 for (size_t i = 0; i < matrixc.size(); ++i) {
   string outputline;
         for (size_t j = 0; j < matrixc[i].size(); ++j) {
          if(j +1 == matrixc[i].size()){outputline += to_string(matrixc[i][j]);}
          else{outputline += to_string(matrixc[i][j]) + " ";}
         }
         if(i +1 == matrixc.size()){
         outFile << outputline;}
         else{
          outFile << outputline<<endl;
         }
     }
 outFile.close();
}
void sub(string a, string b, string output){
 vector<vector<int>> matrixa;
 string la;
 ifstream inputa(a);
 while (getline(inputa, la)) {
         istringstream stringa(la);
         vector<int> row;
         int value;
         while (stringa >> value) {
             row.push_back(value);
         }
         matrixa.push_back(row);
     }
 vector<vector<int>> matrixb;
 string lb;
 ifstream inputb(b);
 while (getline(inputb, lb)) {
         istringstream stringb(lb);
         vector<int> row;
         int value;
         while (stringb >> value) {
             row.push_back(value);
         }
         matrixb.push_back(row);
     }
vector<vector<int>> matrixc;
 for (size_t i = 0; i < matrixb.size(); ++i) {
   vector<int> rowc;
         for (size_t j = 0; j < matrixb[i].size(); ++j) {
          int value;
          value =matrixa[i][j] - matrixb[i][j];
          rowc.push_back(value);
         }
     matrixc.push_back(rowc);
     }
//put matrix c into Output File.
 ofstream outFile;
 outFile.open(output,ios::out|ios::trunc);
 string outputline;
 for (size_t i = 0; i < matrixc.size(); ++i) {
   string outputline;
         for (size_t j = 0; j < matrixc[i].size(); ++j) {
          if(j +1 == matrixc[i].size()){outputline += to_string(matrixc[i][j]);}
          else{outputline += to_string(matrixc[i][j]) + " ";}
         }
         if(i +1 == matrixc.size()){
         outFile << outputline;}
         else{
          outFile << outputline<<endl;
         }
     }
 outFile.close();
}
void mul(string a, string b, string output){
 vector<vector<int>> matrixa;
 string la;
 ifstream inputa(a);
 while (getline(inputa, la)) {
         istringstream stringa(la);
         vector<int> row;
         int value;
         while (stringa >> value) {
             row.push_back(value);
         }
         matrixa.push_back(row);
     }
 vector<vector<int>> matrixb;
 string lb;
 ifstream inputb(b);
 while (getline(inputb, lb)) {
         istringstream stringb(lb);
         vector<int> row;
         int value;
         while (stringb >> value) {
             row.push_back(value);
         }
         matrixb.push_back(row);
     }

vector<vector<int>> matrixc;

for (size_t u = 0; u < matrixb[0].size(); ++u) {
    vector<int> rowc;
    for (size_t i = 0; i < matrixb[0].size(); ++i) {
             int value = 0;
             for (size_t j = 0; j < matrixa[0].size(); ++j) {
                value += matrixa[u][j] * matrixb[j][i];}
    rowc.push_back(value);}
    matrixc.push_back(rowc);}
//put matrix c into Output File.
 ofstream outFile;
 outFile.open(output,ios::out|ios::trunc);
 string outputline;
 for (size_t i = 0; i < matrixc.size(); ++i) {
   string outputline;
         for (size_t j = 0; j < matrixc[i].size(); ++j) {
          if(j +1 == matrixc[i].size()){outputline += to_string(matrixc[i][j]);}
          else{outputline += to_string(matrixc[i][j]) + " ";}
         }
         if(i +1 == matrixc.size()){
         outFile << outputline;}
         else{
          outFile << outputline<<endl;
         }
     }
 outFile.close();
}


