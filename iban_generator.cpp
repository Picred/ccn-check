#include "./lib/iban.h"
#include <limits>


int main(){
    try{
        cout << (verify_iban(create_iban()) ? "Correct iban!\n" : "Incorrect iban!\n");
    } catch(const char* exception){
        cerr << exception << endl;
    }
    cin.clear();
    cin.ignore (numeric_limits<streamsize>::max() , '\n');

    char answer;
    cout << "Do you want to generate a random iban? [Y/N]: ";
    
    cin >> answer;

    if(tolower(answer) == 'y')
        cout << (verify_iban(iban_generator()) ? "Correct iban!" : "Incorrect iban!");

    return EXIT_SUCCESS;
}