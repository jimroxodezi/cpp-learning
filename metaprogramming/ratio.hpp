


template <unsigned int N, unsigned int D = 1>
struct ratio {
    static constexpr unsigned num = N;
    static constexpr unsigned den = D;
    using Type = ratio<num, den>;
};


template <typename R1, typename R2>
struct ratio_add_impl
{
    private:
        static constexpr unsigned int den = R1::den * R2::den;
        static constexpr unsigned int num = R1::num * R2::den + R2::num * R1::den;
    public:
        using Type = ratio<num, den>;
};


