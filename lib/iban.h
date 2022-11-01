#ifndef IBAN_H
#define IBAN_H

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int* create_iban(){
    int* iban = new int[16]{};
    int i=0;
    cout << "Digit your custom IBAN: ";
    
    do{
        cin>>iban[i];
            //exceptions
            if(cin.fail() || (iban[i]>9 || iban[i]<0))
                throw "Input error, restart and insert only 0-9 digits.";
        i++;
    } while(i<16);

    return iban;
}

int* iban_generator(){
    srand(time(0));
    
    int* iban = new int[16]{};

    cout << "The randomly generated IBAN is: [";
    for(int i=0; i < 16; i++){
        iban[i] = rand()%10;
        cout << iban[i] << " ";
    }
    cout << "]\n";
    return iban;
}

bool verify_iban(int* iban){
    int sum_even = 0;
    int sum_odd = 0;

    for(int i = 0; i < 16; i += 2){
        iban[i]*=2;

        if(iban[i] == 18)
            iban[i] = 9;

        if(iban[i] > 9 )
            iban[i] = iban[i]%9;
        
        sum_odd+=iban[i];
    }

    for(int i = 1; i < 16; i += 2)
        sum_even+=iban[i];

    return ((sum_odd + sum_even) %10) == 0;
}

#endif