
// /**
//  * curiously recurring template pattern
// */

// #include <iostream>
// #include <vector>
// #include <memory>

// // abstract base class
// struct abstract_shape
// {
//     // pure virtual function
//     virtual std::unique_ptr<abstract_shape> clone() = 0;  
//     virtual ~abstract_shape() = default;
// };

// template <typename Derived>
// struct shape : public abstract_shape
// {

//     virtual std::unique_ptr<abstract_shape> clone() const override { 
//         return std::make_unique<Derived const&>(static_cast<Derived>(*this)); 
//     }

// protected:
//     shape() = default;
//     shape(const shape&) = default;
//     shape(shape&&) noexcept = default;
// };

// struct square : public shape<square>
// {
//     int x = 1;
// };

// struct rectangle : public shape<rectangle>
// {
//     int x = 1;
//     int y = 2;
// };

// int main(void) {

//     std::vector<std::unique_ptr<abstract_shape>> v;
//     v.push_back(std::unique_ptr<square>{});
//     v.push_back(std::unique_ptr<rectangle>{});
//     // v.push_back(std::make_unique<square>);
//     // v.push_back();
//     for (auto &s : v) {
//         std::unique_ptr<abstract_shape> c = s->clone();

//     }
//     return 0;
// }