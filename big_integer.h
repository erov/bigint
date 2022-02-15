#pragma once

#include <iosfwd>
#include <string>
#include <vector>
#include <functional>

struct big_integer
{
    big_integer();
    big_integer(big_integer const& other);
    big_integer(int a);
    big_integer(long a);
    big_integer(long long a);
    big_integer(unsigned a);
    big_integer(unsigned long a);
    big_integer(unsigned long long a);
    explicit big_integer(std::string const& str);

    ~big_integer();

    big_integer& operator=(big_integer const& other);

    big_integer& operator+=(big_integer const& rhs);
    big_integer& operator-=(big_integer const& rhs);
    big_integer& operator*=(big_integer const& rhs);
    big_integer& operator/=(big_integer const& rhs);
    big_integer& operator%=(big_integer const& rhs);

    big_integer& operator&=(big_integer const& rhs);
    big_integer& operator|=(big_integer const& rhs);
    big_integer& operator^=(big_integer const& rhs);

    big_integer& operator<<=(int rhs);
    big_integer& operator>>=(int rhs);

    big_integer operator+() const;
    big_integer operator-() const;
    big_integer operator~() const;

    big_integer& operator++();
    big_integer operator++(int);

    big_integer& operator--();
    big_integer operator--(int);

    friend bool operator==(big_integer const& a, big_integer const& b);
    friend bool operator!=(big_integer const& a, big_integer const& b);
    friend bool operator<(big_integer const& a, big_integer const& b);
    friend bool operator>(big_integer const& a, big_integer const& b);
    friend bool operator<=(big_integer const& a, big_integer const& b);
    friend bool operator>=(big_integer const& a, big_integer const& b);

    friend std::string to_string(big_integer const& a);

private:
    std::vector<uint32_t> data_;
    bool sign_;

    big_integer& bitwise_op(big_integer const& rhs, std::function<uint32_t (uint32_t, uint32_t)> func, uint32_t neutral);

    enum class comparison_result {
        LESS, EQUAL, GREATER
    };
    comparison_result compare_to(big_integer const& b) const;

    void set(size_t id, uint32_t value);
    uint32_t get_or_default(size_t id, uint32_t def) const;
    void delete_leading_zeroes();

    void to_twos_complement();
    void to_sign_bit();

    uint32_t divide(uint32_t b);
    void multiply(uint32_t b);
    void add(big_integer const& b, bool negated);
    void subtract(big_integer const& b, bool negated);
};

big_integer operator+(big_integer a, big_integer const& b);
big_integer operator-(big_integer a, big_integer const& b);
big_integer operator*(big_integer a, big_integer const& b);
big_integer operator/(big_integer a, big_integer const& b);
big_integer operator%(big_integer a, big_integer const& b);

big_integer operator&(big_integer a, big_integer const& b);
big_integer operator|(big_integer a, big_integer const& b);
big_integer operator^(big_integer a, big_integer const& b);

big_integer operator<<(big_integer a, int b);
big_integer operator>>(big_integer a, int b);

bool operator==(big_integer const& a, big_integer const& b);
bool operator!=(big_integer const& a, big_integer const& b);
bool operator<(big_integer const& a, big_integer const& b);
bool operator>(big_integer const& a, big_integer const& b);
bool operator<=(big_integer const& a, big_integer const& b);
bool operator>=(big_integer const& a, big_integer const& b);

std::string to_string(big_integer const& a);
std::ostream& operator<<(std::ostream& s, big_integer const& a);

