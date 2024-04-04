#include "sha1.hpp"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main(int argc, const char* argv)
{
    string input = "sdtgsdfd";              // Ввод строки

    SHA1 checksum;
    checksum.update(input);
    const string hash = checksum.final();   // Вывод хеш - строки

    cout << input << '\n' << hash << endl;  // Печать

    return 0;
}