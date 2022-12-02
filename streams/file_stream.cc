#include <iostream>
#include <fstream>
#include <bitset>


int main(void){

    {
        std::ofstream of("myfile.txt");
        of << "experience is the mother of wisdom\n";
        of << 1234 << std::endl;
        of << 12.34 << std::endl;

        of << std::bitset<8>(14) << std::endl;
    }   //RAII

    {
        std::ofstream of("myfile.txt", std::ofstream::app); // stream pointers points to EOF
        of << "Honesty is the best policy\n";
    }

    {
        std::ofstream of("myfile.txt", std::ofstream::in | std::ofstream::out);
        of.seekp(10, std::ios::beg);    // move output pointer 10 chars after begin
        of << "12345";
        of.seekp(-5, std::ios::end);    // move output pointer 5 chars before end
        of << "Nothing ventured, nothing gained\n";
        of.seekp(-5, std::ios::cur);    // move output pointer 5 chars before the current positioin
    }
}