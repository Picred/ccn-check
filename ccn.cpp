#include "./lib/ccn.h"
#include <limits>

int main(){
    try{
        cout << (verify_ccn(create_ccn()) ? "\nCorrect CCN!\n" : "\nIncorrect CCN!\n");
    } catch(const char* exception){
        cerr << exception << endl;
    }
    cin.clear();
    cin.ignore (numeric_limits<streamsize>::max() , '\n');

    char answer;
    cout << "Do you want to generate a random CCN? [Y/N]: ";

    cin >> answer;

    if(tolower(answer) == 'y')
        cout << (verify_ccn(ccn_generator()) ? "\nCorrect CCN!\n" : "\nIncorrect CCN!\n");
    else{
        cout << "Closing.." << endl;

    return EXIT_SUCCESS;
}