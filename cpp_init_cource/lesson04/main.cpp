#include <iostream>
#include <fstream>

using namespace std;

unsigned int histogram[256];
unsigned int Digits[256];

int main (int argc, const char** args) {

    if (argc == 1) {
        cout << "Please specify files names!" << endl;
        return EXIT_FAILURE;
    }

    fstream f;
    ofstream result("Output.txt");
    char pgm_header[2];
    char Symbol;
    int width = 0;
    int hieght = 0;
    int maxBright = 0;
    int maxDensity;
    int d = 0;

    //Fill mapping symbols code and digits
    for (int chr = '0'; chr <'9'; chr++, d++) Digits[chr] = d;

    for (int i = 1; i < argc; i++) {
        // Read files
        f.open(args[i], ios::binary|ios::in);
        if (!f.is_open()) {
            cout << "File " << args[i] << " is not accessible!" << endl;
            continue;
        }

        f.read(pgm_header,2);

        if ((pgm_header[0]!=0x50) || (pgm_header[1]!=0x35)) {
            cout << endl << "File " << args[i] << " has wrong header format, skipping..." << endl;
            f.close();
            continue;
        }
        cout<< endl << "Start analysis of file " << args[i] << endl;
        cout<<"PGM header was detected"<<endl;

        f.seekg(static_cast<unsigned int>(f.tellg()) + 1);

        width = 0;
        hieght = 0;
        maxBright = 0;

        do {
            f.read(&Symbol, 1);
            if (Symbol == 0x20) break;
            width = width*10 + Digits[Symbol];
        } while (Symbol != 0x20);

        do {
            f.read(&Symbol, 1);
            if (Symbol == 0x0A) break;
            hieght = hieght*10 + Digits[Symbol];
        } while (Symbol != 0x0A);

        do {
            f.read(&Symbol, 1);
            if (Symbol == 0x0A) break;
            maxBright = maxBright*10 + Digits[Symbol];
        } while (Symbol != 0x0A);

        cout << "Width: " << width << "; Hieght: " <<  hieght << "; Bright: " <<  maxBright << endl;

        for (int j = 0; j<256; j++) histogram[j] = 0;
        maxDensity = 0;

        for (int j = 0; j < (width*hieght); j++) {
            f.read(&Symbol,1);
            if (f.eof()) break;
            if (++histogram[static_cast<unsigned char>(Symbol)] > maxDensity)
                maxDensity = histogram[static_cast<unsigned char>(Symbol)] ;
        }

        f.close();
        result << "File: " << args[i] << endl << endl;
        //Normalizing histogram
        for (int j = 0; j<256; j++) {
            result << "[" << j << "]";
            for (int i = 0; i < histogram[j]*100/maxDensity; ++i) result<<"|";
            result << endl;
        }

        cout<<"Histogram was exported"<<endl;

    }

    result.close();

    return EXIT_SUCCESS;
}