#include "number.h"

// constructors
number_t::number_t() = default;                                 // empty
number_t::number_t(int64_t value) : _val{value} {}              // from number
number_t::number_t(const number_t &other) : _val{other._val} {} // copy

// =
void number_t::swap(number_t &other) {
  std::swap(_val, other._val);
}
number_t &number_t::operator=(const number_t &other) {
  number_t tmp(other);
  swap(tmp);
  return *this;
}

// casts
number_t::operator bool() const {
  return _val != 0;
}
number_t::operator long() const {
  return _val;
}
number_t::operator std::string() const {
  return std::to_string(_val);
}

// comparisons
bool operator==(const number_t &first, const number_t &second) {
  return first._val == second._val;
}
bool operator!=(const number_t &first, const number_t &second) {
  return first._val != second._val;
}
bool operator<(const number_t &first, const number_t &second) {
  return first._val < second._val;
}
bool operator>(const number_t &first, const number_t &second) {
  return first._val > second._val;
}
bool operator<=(const number_t &first, const number_t &second) {
  return first._val <= second._val;
}
bool operator>=(const number_t &first, const number_t &second) {
  return first._val >= second._val;
}

// stream
std::ostream &operator<<(std::ostream &output, const number_t &other) {
  return output << other._val;
}
std::istream &operator>>(std::istream &input, number_t &other) {
  return input >> other._val;
}

// binary arithmetic
long operator+(const number_t &first, const number_t &second) {
  return first._val + second._val;
}
long operator-(const number_t &first, const number_t &second) {
  return first._val - second._val;
}
long operator*(const number_t &first, const number_t &second) {
  return first._val * second._val;
}
long operator/(const number_t &first, const number_t &second) {
  return first._val / second._val;
}
long operator%(const number_t &first, const number_t &second) {
  return first._val % second._val;
}

// binary assignments
long operator+=(number_t &first, const number_t &second) {
  return first._val += second._val;
}
long operator-=(number_t &first, const number_t &second) {
  return first._val -= second._val;
}
long operator*=(number_t &first, const number_t &second) {
  return first._val *= second._val;
}
long operator/=(number_t &first, const number_t &second) {
  return first._val /= second._val;
}
long operator%=(number_t &first, const number_t &second) {
  return first._val %= second._val;
}

// bitwise
long operator|(const number_t &first, const number_t &second) {
  return first._val | second._val;
}
long operator&(const number_t &first, const number_t &second) {
  return first._val & second._val;
}
long operator^(const number_t &first, const number_t &second) {
  return first._val ^ second._val;
}

// bitwise assignment
long operator|=(number_t &first, const number_t &second) {
  return first._val |= second._val;
}
long operator&=(number_t &first, const number_t &second) {
  return first._val &= second._val;
}
long operator^=(number_t &first, const number_t &second) {
  return first._val ^= second._val;
}

// incr
number_t &number_t::operator++() {
  _val += 1;
  return *this;
}
number_t number_t::operator++(int) {
  number_t old = *this;
  operator++();
  return old;
}

// decr
number_t &number_t::operator--() {
  _val -= 1;
  return *this;
}
number_t number_t::operator--(int) {
  number_t old = *this;
  operator--();
  return old;
}

// unary
number_t number_t::operator-() const {
  return number_t(-_val);
}
number_t number_t::operator+() const {
  return number_t(+_val);
}
number_t number_t::operator!() const {
  return number_t(!_val);
}
number_t number_t::operator~() const {
  return number_t(~_val);
}

// binary shifts
long operator<<(const number_t &first, const number_t &second) {
  return first._val << second._val;
}
long operator>>(const number_t &first, const number_t &second) {
  return first._val >> second._val;
}
number_t &number_t::operator<<=(const number_t &number) {
  return reinterpret_cast<number_t &>(_val <<= number._val);
}
number_t &number_t::operator>>=(const number_t &number) {
  return reinterpret_cast<number_t &>(_val >>= number._val);
}
