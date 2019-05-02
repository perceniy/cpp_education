#include "categorizer.hpp"

using namespace std;

unsigned int histogram[256];
int alphabet[256];
int wigth = 0;
int height = 0;

int main(int argc, char** args) {

    fstream f;
    ofstream out("histogram.txt");
    char PGM_hdr1[2];
    if(argc == 1) {
        cout << "Please specify input file(s)!" << endl;
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        f.open(args[i], ios::binary|ios::in);
        if(!f.is_open()){
            cout << "File: " << args[i] << " is not accessible!" << endl;
            continue;
        }
        cout << "File " << args[i] << " opened" << endl;
        f.read(PGM_hdr1, 2);
        if((PGM_hdr1[0] != 0x50)||(PGM_hdr1[1] != 0x35)) {
            f.close();
            continue;
        }

        cout << "PGM header detected" << endl;
        f.seekg(static_cast<unsigned int>(f.tellg()) + 1);
        unsigned int digit_b = static_cast<unsigned int>(f.tellg());
        char sym;
        do {
            f.read(&sym, 1);
        } while(sym!=0x20);

        unsigned int digit_e = static_cast<unsigned int>(f.tellg()) - 2;

        int j = 0;
        for(int d = '0'; d <= '9'; d++, j++) alphabet[d] = j;
        int count = 1;
        for (j = digit_e; j >= digit_b ; j--, count *= 10) {
            f.seekg(j);
            f.read(&sym, 1);
            wigth += alphabet[sym] * count;
        }
        cout << "wigth: " << wigth << endl;

        digit_b = digit_e + 2;
        count = 1;
        do {
            f.read(&sym, 1);
        }while(sym != 0x0A);
        digit_e = static_cast<unsigned int>(f.tellg()) - 2;
        for (j = digit_e; j >= digit_b ; j--, count *= 10) {
            f.seekg(j);
            f.read(&sym, 1);
            height += alphabet[sym] * count;
        }

        cout << "height: " << height << endl;

        for (int d = 0; d < 256; ++d) histogram[d] = 0;
        f.seekg(digit_e + 6);
        for (int d = 0; d < (wigth * height); ++d) {
            if(f.eof())break;
            f.read(&sym, 1);
            histogram[static_cast<unsigned char>(sym)] += 1;
        }
        cout << endl;
        /*
        for (j = 0; j < 256; j++) {
            cout << "[" << j << "] ";
            for (count = 0; count < histogram[j]; count++) cout << "|";
            cout << endl;
        }
        */
        f.close();
        out << "File: " << args[i] << endl;
        out << "wigth: " << wigth << "\tHeight: " << height << endl;
        for (j = 0; j < 256; j++) {
            out << "[" << j << "] ";
            for (count = 0; count < histogram[j]; count++) out << "|";
            out << endl;
        }
        out << "End of file: " << args[i] << endl << endl;
    }
    out.close();
    return 0;
}