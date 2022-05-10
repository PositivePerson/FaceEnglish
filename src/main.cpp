#include <iostream>
#include "../headers/Console.h"
//#include "Produkt"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    Console myConsole;
//    string text1 = "Write me Smoothly";
//    myConsole.smooth_cout(text1);
    myConsole.welcome();
    myConsole.ask_id_hint_needed(2, 3);

    return 0;
}
