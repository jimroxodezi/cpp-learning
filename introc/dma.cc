#include <iostream>


/*
With C type NULL, there can be an implicit conversion to integer.
*/
int main(){

    double *movie_scores = nullptr;
    int *i = nullptr;

    movie_scores = new double[8];
    i = new int;

    if (movie_scores == nullptr){
        std::cout << "Couldn't allocate memory!\n";
        return -1;
    }
    
    if (i == nullptr) {
        std::cout << "Couldn't allocate memory!!\n";
        return -2;
    }

    std::cout << "Enter 8 integers\n";
    for (*i = 0; *i < 8; *i+=1){
        std::cin >> *(movie_scores + *i); // why?
    }

    for (*i = 0; *i < 8; *i+=1){
        std::cout << *(movie_scores + *i) << " ";
    }
    std::cout << std::endl;

    delete[] movie_scores;
    delete i;

    return 0;
}