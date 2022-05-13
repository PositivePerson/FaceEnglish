#include <iostream>
#include "../headers/Console.h"
#include "../headers/Word.h"
#include "../headers/Chapter.h"
//#include "Produkt"

using namespace std;

int main() {
    Console myConsole;
    myConsole.welcome();
    myConsole.choose_chapter();
//    myConsole.ask_id_hint_needed(2, 3);

//    Word word1("Avocado");

//    Chapter chapter1("polHome", "engHome");

    return 0;
}
