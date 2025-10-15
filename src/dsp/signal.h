#ifndef SIGNAL_H_
#define SIGNAL_H_

#pragma once
#include <complex>
#include <vector>
#include <string>
#include <utility>

namespace dse {
    inline constexpr double DEFAULT_T0  = 0.0;
    inline constexpr double DEFAULT_TS  = 1.0;
    inline constexpr double DEFAULT_EPS = 1e-12;

template <typename T = double>
class Signal {
    public:
        using value_type = T;
        using index_type = int;
        using size_type = std::size_t;
        using range = std::pair<size_type, size_type>;
        using container = std::vector<value_type>;

        Signal(); // Default constructor
        Signal(index_type n_min, index_type n_max); // Construct domain based on min and max n
        Signal(index_type [n_min, n_max]); // Construct domain based on array of size 2 with min and max n
        Signal(range domain); // Construct domain based on pair with min and max n
        Signal(container samples); // Construct signal based on samples; autofill domain
        Signal(const Signal& other); // Copy constructor
        ~Signal(); // Default destructor

        index_type n_min() const; // Private variable getters
        index_type n_max() const;
        range domain() const;
        std::string label() const;
        double t0() const;
        double Ts() const;
        double eps() const;

        [[nodiscard]] value_type at(index_type n) const noexcept;
        value_type& operator[](size_type i) noexcept;


        Signal& operator=(const Signal& other); // Overloaded copy assignment operator



    private:
        index_type n_min_;
        index_type n_max_;
        container samples_;
        std::string label_;
        double t0_  = dse::DEFAULT_T0;
        double Ts_  = dse::DEFAULT_TS;
        double eps_ = dse::DEFAULT_EPS;
};

using SignalR = Signal<double>; // Real-valued signal
using SignalC = Signal<std::complex<double>>; // Complex-valued signal

} // namespace dse

#endif // SIGNAL_H_