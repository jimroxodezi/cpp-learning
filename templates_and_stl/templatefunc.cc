#include <iostream>
#include <vector>

template <typename T>
void swap(T &x, T &y){
    T temp = x;
    x = y;
    y = temp;
}

template <typename Q>
void print_vector(const std::vector<Q> &v){
    for (const auto &i : v){
        std::cout << i << " ";
    }
    std::cout << "\n";
}

int main(){
    std::string a = "Up?", b = "What's";
    std::cout << a << " " << b << "\n";
    swap(a,b);
    std::cout << a << " " << b <<"\n";

    int x = 10, y = 20;
    std::cout << x << " " << y << "\n";
    swap(x,y);
    std::cout << x << " " << y << "\n";

    std::vector<int> i = {1,2,3,4,5,6,7};
    std::vector<std::string> s = {"Odezi", "Jimrox", "Inny", "Ufuoma", "Pius", "Grace", "Victory", "Yole"};

    print_vector(i);
    print_vector(s);

}