#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

class Galaz {
    public:
        Galaz(){};
        void dlugosc(double dlg){
            double xx = dlg;
            dlug = xx;
        }
        void lisc2(int liczba){
            size_t tak = liczba;
            lisc = tak;
        }
    private:
        double dlug = 0;
        size_t lisc = 0;
}; 

class Drzewo {
    public:
        Drzewo( const char* n, double h ){
			name = n;
			height = h;
			
		};
        string nazwa()
        {

            return name;
        }

        vector<Galaz> galaz;

        unsigned int rozmiar()
        {
        unsigned int x = galaz.size();
            return x;

        }

    private:
        string name;
        double height;
        //vector<Galaz> galaz; // pamietac o skasowaniu obiektow
};



int main() {
    Drzewo d1("brzoza", 20); // nazwa wysokosc
    Drzewo d2("sekwoja", 100); 
    Galaz g1;
    Galaz g2;
    d1.galaz.push_back(g1);
    d2.galaz.push_back(g2);
    d1.galaz[0].dlugosc(5);
    d1.galaz[0].lisc2(100);
    d2.galaz[0].dlugosc(3);
    d2.galaz[0].lisc2(70);



 //   cout << d1.nazwa() << " ma galezi: " << d1.galaz() << endl;
//    cout << d2.nazwa() << " ma galezi: " << d2.galaz() << endl;
/*    d1.galaz( new Galaz ); // dodaje pierwsza galaz
    d1.galaz( new Galaz ); // dodaje kolejna galaz
    Galaz* g1 = d1.galaz( 0 ); // pobieram pierwsza galaz
    g1->dlugosc( 5 ); // ustawiam dlugosc galezi
    g1->lisc( 100 ); // ustawiam liczbe lisci
    Galaz* g2 = d2.galaz( 1 ); // pobieram druga galaz
    g2->dlugosc( 3 ); // ustawiam dlugosc galezi
    g2->lisc( 70 ); // ustawiam liczbe lisci
*/
    cout << d1.nazwa() << " ma galezi: " << d1.rozmiar() << endl;
    cout << d2.nazwa() << " ma galezi: " << d2.rozmiar() << endl;
    cin.get();

}
