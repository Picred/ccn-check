#include "./lib/ccn.h"
#include <limits>


int main(){
    try{
        cout << (verify_ccn(create_ccn()) ? "Correct CCN!\n" : "Incorrect CCN!\n");
    } catch(const char* exception){
        cerr << exception << endl;
    }
    cin.clear();
    cin.ignore (numeric_limits<streamsize>::max() , '\n');

    char answer;
    cout << "Do you want to generate a random CCN? [Y/N]: ";
    
    cin >> answer;

    if(tolower(answer) == 'y')
        cout << (verify_ccn(ccn_generator()) ? "Correct CCN!" : "Incorrect CCN!");

    return EXIT_SUCCESS;
}