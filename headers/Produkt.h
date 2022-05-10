//
// Created by My on 07.05.2022.
//

#ifndef UNTITLED_PRODUKT_H
#define UNTITLED_PRODUKT_H

#include <string>

class Produkt {
private:
    int mLp;
    std::string mName;  // nazwa produktu
    double count;   // liczba produkt�w
    std::string mUnit = "unset";   // ilo�c
    double mPrize = 0;   // cena netto 1 sztuki
    double mVat = 0;     // warto�� podatku VAT
public:
    Produkt();
    Produkt(int aLp, std::__cxx11::basic_string<char> aName);
    void setPrize();
    virtual void Wypelnij();
    virtual void Pokaz();
    virtual ~Produkt();
};

#endif //UNTITLED_PRODUKT_H
