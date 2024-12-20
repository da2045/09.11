#include <iostream>


class Drib {
private:
    int chyselnyk; 
    int znamenyk;  

public:
  
    Drib() : chyselnyk(0), znamenyk(1) {}

    
    Drib(int ch, int zn) : chyselnyk(ch), znamenyk(zn) {
        if (zn == 0) {
            std::cerr << "Pomylka: znamenyk ne mozhe buty nulem." << std::endl;
            znamenyk = 1;
        }
    }

  
    void vvesty() {
        std::cout << "Vvedit chyselnyk: ";
        std::cin >> chyselnyk;
        std::cout << "Vvedit znamenyk: ";
        std::cin >> znamenyk;
        if (znamenyk == 0) {
            std::cerr << "Pomylka: znamenyk ne mozhe buty nulem." << std::endl;
            znamenyk = 1;
        }
    }


    void drukuaty() const {
        std::cout << chyselnyk << "/" << znamenyk << std::endl;
    }

 
    Drib dodaty(const Drib& dr) const {
        return Drib(chyselnyk * dr.znamenyk + dr.chyselnyk * znamenyk, znamenyk * dr.znamenyk);
    }

  
    Drib vidnyaty(const Drib& dr) const {
        return Drib(chyselnyk * dr.znamenyk - dr.chyselnyk * znamenyk, znamenyk * dr.znamenyk);
    }

   
    Drib mnozhyty(const Drib& dr) const {
        return Drib(chyselnyk * dr.chyselnyk, znamenyk * dr.znamenyk);
    }

    
    Drib dilyty(const Drib& dr) const {
        return Drib(chyselnyk * dr.znamenyk, znamenyk * dr.chyselnyk);
    }
};

int main() {
    Drib drib1, drib2;

    std::cout << "Vvedennia pershoho drobu:" << std::endl;
    drib1.vvesty();

    std::cout << "Vvedennia druhoho drobu:" << std::endl;
    drib2.vvesty();

    Drib suma = drib1.dodaty(drib2);
    Drib riznytsia = drib1.vidnyaty(drib2);
    Drib dobuto = drib1.mnozhyty(drib2);
    Drib chastka = drib1.dilyty(drib2);

    std::cout << "Suma drobiv: ";
    suma.drukuaty();

    std::cout << "Riznytsia drobiv: ";
    riznytsia.drukuaty();

    std::cout << "Dobuto drobiv: ";
    dobuto.drukuaty();

    std::cout << "Chastka drobiv: ";
    chastka.drukuaty();

    return 0;
}
