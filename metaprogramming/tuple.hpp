

// We're going to specialize the template such that this version 
// only gets instantiated if Types contains no arguments. Hopefully, 
// that makes more sense now.
template <typename... Types>
struct tuple {};


template <typename Type, typename ...Types>
struct tuple{

    Type value;

    tuple<Types...> next;

    constexpr inline tuple(const Type &_value, const Types... &_next) :
                                value{_value}, next{_next} {}

};

