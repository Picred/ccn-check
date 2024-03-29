#ifndef CCN_H
#define CCN_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

// Circuits 
#define MASTERCARD 5
#define VISA 4
#define AMERICAN_EXPRESS 3
#define DISCOVER 6

using namespace std;

/**
 * Uses stdin to collect the digits of the credit card
 * @throws String error if digits are out of range or stdin fails
 * @returns The array containing the numbers of the credit card
*/
short* create_ccn(){
    short* ccn = new short[16]{};
    short i=0;
    cout << "Digit your custom CCN (\"1 2 3\"): ";
    
    do{
        cin >> ccn[i];
            //exceptions
            if(cin.fail() || (ccn[i]>9 || ccn[i]<0))
                throw "Input error, restart and insert only 0-9 digits.";
        i++;
    } while(i<16);
    return ccn;
}

/**
 * Uses random generator to create the digits of the credit card
 * @returns The array containing the numbers of the credit card
*/
short* ccn_generator(){
    srand(time(0));
    
    short* ccn = new short[16]{};

    cout << "The randomly generated CCN is: [";
    for(short i=0; i < 16; i++){
        ccn[i] = rand()%10;
        cout << ccn[i] << " ";
    }
    cout << "]\n";
    return ccn;
}

/**
 * Verifies the correctness of the credit card number using Luhn's Formula
 * @returns True if the credit card number is correct, False otherwise
*/
bool verify_ccn(short* ccn){
    short sum_even = 0;
    short sum_odd = 0;
    string circuit = "";

    switch(ccn[0]){
        case MASTERCARD:
            circuit = "It's a Mastercard card!";
            break;
        case VISA:
            circuit = "It's a Visa card!";
            break;
        case AMERICAN_EXPRESS:
            circuit = "It's an American Express card!";
            break;
        case DISCOVER:
            circuit = "It's a Discorver card!";
            break;
        default:
            circuit = "I can't check the circuit of this card!";
            break;
        }

    for(short i = 0; i < 16; i++){
        if (i%2==0){
            ccn[i]*=2;

            if(ccn[i] == 18)
                ccn[i] = 9;

            else if(ccn[i] > 9 )
                ccn[i] = ccn[i]%9;
            
            sum_odd+=ccn[i];
        }
        else
            sum_even+=ccn[i];
    }
    cout << circuit;
    return ((sum_odd + sum_even) % 10) == 0;
}

#endif