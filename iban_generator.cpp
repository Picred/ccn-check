#include "./lib/iban.h"
#define EXIT_SUCCESS 0

using namespace std;
int main(){
    //if you wanna try with a custom iban, use the following if
    cout << (verify_iban(create_iban()) ? "Correct iban!" : "Incorrect iban!");

    //if you wanna try a random iban, use the following instrucion by removing "//"
    
    // cout << verify_iban(iban_generator()) ? "Correct iban!" : "Incorrect iban!";

    return EXIT_SUCCESS;
}