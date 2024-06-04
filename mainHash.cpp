#include "sha1.hpp"

void TEST1() {
    SHA1 checksum;
    checksum.update("hello");
    std::string hash = checksum.final();

    if (hash == "aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d")
        std::cout << "hello " << hash << " sucsess 1\n";
}

void TEST2() {
    SHA1 checksum;
    checksum.update("");
    std::string hash = checksum.final();

    if (hash == "da39a3ee5e6b4b0d3255bfef95601890afd80709")
        std::cout << " " << hash << " sucsess 2\n";
}

void TEST3() {
    SHA1 checksum;
    std::string longString = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas mattis lacinia ex, sit amet sollicitudin lectus tincidunt id. Sed ut feugiat arcu, quis placerat tellus. Proin dictum mauris velit, in malesuada risus hendrerit sed. Donec elementum, ligula ut consectetur pretium, risus augue lacinia urna, sed ultricies diam nibh eget metus. Donec tristique varius massa, ac pulvinar orci tempus in. Proin mollis vitae felis in maximus. Integer id dolor non nunc eleifend tincidunt volutpat id quam. Suspendisse potenti. Nulla facilisi. Aliquam eget maximus nisl. Mauris a molestie nisi, sed finibus tellus. Nunc rutrum sit amet risus vel efficitur. Maecenas ullamcorper mi non commodo dignissim.";
    checksum.update(longString);
    std::string hash = checksum.final();

    if (hash == "f9d15e0509ffe51f7ce3714ad85d1c2ad13debb0")
        std::cout << longString << ' ' << hash << " sucsess 3\n";
}
const std::string makehash(std::string line) {

    SHA1 checksum;
    checksum.update(line);
    const std::string hash = checksum.final();

    return hash;
}


int main(int argc, const char* argv)
{
    std::string input = "hello"; 

    //std::cout << input << '\n' << makehash(input) << std::endl;

    TEST1();
    TEST2();
    TEST3();

    return 0;
}