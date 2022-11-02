#ifndef CCN_H
#define CCN_H

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int* create_ccn(){
    int* ccn = new int[16]{};
    int i=0;
    cout << "Digit your custom CCN: ";
    
    do{
        cin>>ccn[i];
            //exceptions
            if(cin.fail() || (ccn[i]>9 || ccn[i]<0))
                throw "Input error, restart and insert only 0-9 digits.";
        i++;
    } while(i<16);

    return ccn;
}

int* ccn_generator(){
    srand(time(0));
    
    int* ccn = new int[16]{};

    cout << "The randomly generated CCN is: [";
    for(int i=0; i < 16; i++){
        ccn[i] = rand()%10;
        cout << ccn[i] << " ";
    }
    cout << "]\n";
    return ccn;
}

bool verify_ccn(int* ccn){
    int sum_even = 0;
    int sum_odd = 0;

    for(int i = 0; i < 16; i += 2){
        ccn[i]*=2;

        if(ccn[i] == 18)
            ccn[i] = 9;

        if(ccn[i] > 9 )
            ccn[i] = ccn[i]%9;
        
        sum_odd+=ccn[i];
    }

    for(int i = 1; i < 16; i += 2)
        sum_even+=ccn[i];

    return ((sum_odd + sum_even) %10) == 0;
}

#endif