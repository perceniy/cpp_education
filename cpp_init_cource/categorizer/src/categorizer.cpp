#include "categorizer.hpp"

using namespace std;

/*
 * Внес изменения:
 * 1) Избавился от дублирования кода: вынес участок кода, непосредственно печатающий диаграмму в отдельную функцию outputHistogram,
 * которой на вход можно подавать либо файл, либо стандартный вывод.
 * 2) Вынес заполнение алфавита в отдельную функцию fillAlphabet, которая вызывается единожды в main,
 * далее передаем алфавит в функции-обработчики в виде указателя
 * 3) Сделал динамическое выделение памяти для считываемого файла fstream* f = new fstream;
 * 4) Передал считываемый файл f в функцию ProcessFile как указатеь
 *
 * */


void fillAlphabet(int* alphabet) {
    int j = 0;
    for(int d = '0'; d <= '9'; d++, j++) alphabet[d] = j;
}

int ExtractNum(fstream *file, const char delimiter, int* alphabet)
{

    char sym;
    int res = 0;
    unsigned int digit_b = static_cast<unsigned int>(file->tellg());

    do
    {
        file->read(&sym, 1);
    }while(sym != delimiter);

    unsigned int digit_e = static_cast<unsigned int>(file->tellg()) - 2;
    int j = 0;
    int c = 1;
    for(j = digit_e; j >= digit_b; j--, c *= 10)
    {
        file->seekg(j);
        file->read(&sym, 1);
        res += alphabet[sym] * c;
    }
    file->seekg(digit_e + 2);
    return res;
}

void outputHistogram (ostream* os,
                      unsigned int *histogram,
                      unsigned int len
                      )
{
    for(int j = 0; j < len; j++)
    {
        *os << "[" << j << "] ";
        for(unsigned int c = 0; c < histogram[j]; c++) *os  << "|";
        *os << endl;
    }

}

void BuildHistogram(std::fstream* file,
                    unsigned int* histogram,
                    unsigned int len,
                    int width,
                    int height)
{
    char sym;

    for(unsigned int d = 0; d < len; ++d)histogram[d] = 0;

    file->seekg(static_cast<unsigned int>(file->tellg()) + 4);

    for(unsigned int d = 0; d < (width * height); ++d)
    {
        if(file->eof())break;
        file->read(&sym, 1);
        histogram[static_cast<unsigned char>(sym)] += 1;
    }
    cout << endl;
    outputHistogram(&cout, histogram, len);
}

void PrintHistogram(unsigned int *histogram,
                    unsigned int len,
                    int width,
                    int height)
{
    ofstream* out = new ofstream("histogram.txt");
    *out << "Building histogram for graphic file" << endl;
    *out << "Width: " << width << "\t Height: " << height << endl;

    outputHistogram(out, histogram, len);

    *out << "End of file " << endl << endl;
    out->close();
    delete out;
}

void ProcessFile(std::fstream *file, unsigned int* histogram, unsigned int len, int* alphabet)
{
    int width, height;
    width = 0;
    height = 0;
    char PGM_hdr1[2];

    file->read(PGM_hdr1, 2);

    if((PGM_hdr1[0] != 0x50)||(PGM_hdr1[1] != 0x35)) return;
    cout << "PGM header detected" << endl;

    file->seekg(static_cast<unsigned int>(file->tellg()) + 1);

    width = ExtractNum(file, 0x20, alphabet);
    cout << "Width: " << width <<  endl;

    height = ExtractNum(file, 0x0A, alphabet);
    cout << "Height: " << width <<  endl;

    BuildHistogram(file, histogram, len, width, height);

    PrintHistogram(histogram, len, width, height);
}

int main(int argc, char** args)
{
    fstream* f = new fstream;
    unsigned int histogram[256];

    if(argc == 1)
    {
        cout << "Please specify input file(s)!" << endl;
        return 1;
    }

    int alphabet[256];
    fillAlphabet(alphabet);

    for(int i = 1; i < argc; i++)
    {
        f->open(args[i], ios::binary|ios::in);
        if(!f->is_open())
        {
            cout << "File: " << args[i] << " is not accessible!" << endl;
            continue;
        }
        cout << "File " << args[i] << " opened" << endl;
        ProcessFile( f, histogram, 256, alphabet);
        f -> close();
    }
    delete f;
    return 0;
}
