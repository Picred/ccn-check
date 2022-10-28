#ifndef IBAN_H
#define IBAN_H

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int* create_iban(){
    int* ibans = new int[16]{};

    cout << "Digit your custom IBAN: ";
    
    for(int i=0; i<16; i++){
        cin>>ibans[i];
    }

    return ibans;
}

int* iban_generator(){
    srand(time(0));
    
    int* ibans = new int[16]{};

    cout << "The randomly generated IBAN is: [";
    for(int i=0; i < 16; i++){
        ibans[i] = rand()%10;
        cout << ibans[i] << " ";
    }
    cout << "]\n";
    return ibans;
}

bool verify_iban(int* ibans){
    int sum_even = 0;
    int sum_odd = 0;

    for(int i = 0; i < 16; i += 2){
        ibans[i]*=2;

        if(ibans[i] == 18)
            ibans[i] = 9;

        if(ibans[i] > 9 )
            ibans[i] = ibans[i]%9;
        
        sum_odd+=ibans[i];
    }

    for(int i = 1; i < 16; i += 2)
        sum_even+=ibans[i];

    return ((sum_odd + sum_even) %10) == 0;
}

#endif