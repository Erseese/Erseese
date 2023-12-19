#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[]) {
   for (int i = 1; i < argc; ++i) {
       std::stringstream ss(argv[i]);

       char c;
       if (ss >> c) {
           std::cout << "1\n";
           continue;
       }

       float f;
       if (ss >> f) {
           std::cout << "2\n";
           continue;
       }

       double d;
       if (ss >> d) {
           std::cout << "3\n";
           continue;
       }

       int n;
       if (ss >> n) {
           std::cout << "4\n";
           continue;
       }

       std::cout << "Invalid type\n";
   }

   return 0;
}