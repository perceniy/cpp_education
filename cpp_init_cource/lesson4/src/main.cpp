
#include "main.hpp"

using namespace std;

unsigned int auiHistogram[256];
unsigned int aiAlphabet[256];

int main(int argc, char** args)
{
    if (argc==1) {
        cout << "Please specify file" << endl;
        return 1;
    }

    fstream oFileStream;

    for (int iIndex=1; iIndex<argc; iIndex++) {
        oFileStream.open(args[iIndex], ios::binary | ios::in);

        if (!oFileStream.is_open()) {
            printf("Can't open file: %s\n", args[iIndex]);
            continue;
        }

        cout << "File: " << args[iIndex] << " opened" << endl;

        char acPGMHeader[2];
        oFileStream.read(acPGMHeader, 2);

        if (acPGMHeader[0] != 0x50 || acPGMHeader[1] != 0x35) {
            cout << "Wrong PGM header" << endl;
            oFileStream.close();
            continue;
        }

        cout << "PGM header detected" << endl;

        oFileStream.seekg(static_cast<unsigned int>(oFileStream.tellg()) + 1);

        unsigned int uiDigitB = static_cast<unsigned int>(oFileStream.tellg());

        int iWidth = 0;
        int iHeight = 0;

        char cSymbol = 0;

        do {
            oFileStream.read(&cSymbol, 1);
        } while (cSymbol != 0x20);

        unsigned int uiDigitE = static_cast<unsigned int>(oFileStream.tellg()) - 2;

        unsigned int iJ = 0;

        for (int iD = '0'; iD<='9'; iD++, iJ++) {
            aiAlphabet[iD] = iJ;
        }

        unsigned int iC = 1;

        for (iJ = uiDigitE; iJ>=uiDigitB; iJ--, iC *= 10) {
            oFileStream.seekg(iJ);
            oFileStream.read(&cSymbol, 1);
            iWidth += aiAlphabet[static_cast<unsigned int>(cSymbol)]*iC;
        }

        cout << "Width: " << iWidth << endl;

        uiDigitB = uiDigitE + 2;
        iC = 1;

        do {
            oFileStream.read(&cSymbol, 1);
        } while (cSymbol != 0x0A);

        uiDigitE = static_cast<unsigned int>(oFileStream.tellg()) - 2;

        for (iJ = uiDigitE; iJ>=uiDigitB; iJ--, iC *= 10) {
            oFileStream.seekg(iJ);
            oFileStream.read(&cSymbol, 1);
            iHeight += aiAlphabet[static_cast<unsigned int>(cSymbol)]*iC;
        }

        cout << "Height: " << iHeight << endl;

        memset(auiHistogram, 0, 256*sizeof(unsigned int));

        oFileStream.seekg(uiDigitE + 6);

        for (int iD=0; iD<iWidth*iHeight; iD++) {
            if (oFileStream.eof()) {
                break;
            }

            oFileStream.read(&cSymbol, 1);

            auiHistogram[static_cast<unsigned char>(cSymbol)] += 1;
        }

        cout << endl;

        for (iJ=0; iJ<256; iJ++) {
            cout << "[" << iJ << "] ";
            for (iC=0; iC<auiHistogram[iJ]; iC++) {
                cout << "|";
            }
            cout << endl;
        }

        oFileStream.close();

        ofstream oOFStream("histogram.txt");

        oOFStream << "File: " << args[iIndex] << endl;
        oOFStream << "Width: " << iWidth << "\tHeight: " << iHeight << endl;

        for (iJ=0; iJ<256; iJ++) {
            oOFStream << "[" << iJ << "] ";
            for (iC=0; iC<auiHistogram[iJ]; iC++) {
                oOFStream << "|";
            }
            oOFStream << endl;
        }

        oOFStream << "End of file: " << args[iIndex] << endl << endl;

        oOFStream.close();
    }

    return 0;
}
