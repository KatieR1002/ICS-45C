#include "Functions.h"

string createPyramid(int num)
{   if (num>=500){
        return "Pyramid size too large.";
    }
    else if (num<0){
        return "Negative pyramid size.";
    }
    else if (num==0){
        return"Invalid pyramid size.";
    }
    string fr;
    int sn = num;
    int bn = 1;
    int vn = 1;
    for (int i = 0; i< num; i++){
        //space needed for this line8
        string s;
        //verticle slice needed for this line
        string v;
        //blocks needed
        string b;
        /*std:;cout<<bn<<std::endl;*/
        for (int k = 0; k < sn-1; k++){
            s+= ' ';
        }
        //default display
        if (i == 0){
            fr += s;
            fr += ' ';
            fr += '-';
            fr += '\n';
        }
        sn -=1;
        if (i != num-1){
            bn +=2;
        }
        b+= s;
        for (int e = 0; e < bn; e++){
            b += '-';
        }
        v += s;
        v += '|';
        v += ' ';
        for (int f = 0; f < vn; f++){
            if (f != vn-1){
                v += '|';
                v += ' ';
            }
            else{
                v+='|';
            }
        }
        vn += 1;
        /*std::cout << i << std::endl;*/
        fr += v;
        fr += '\n';
        if(i == num-1){
            fr += ' ';
        }
        fr += b;
        if (i != num-1){
            fr += '\n';
        }
        /*std::cout << fr << std::endl;*/
    }
    return fr;
}

int getUserInput()
{
    int x;
    cin >> x;
    return x;
}




