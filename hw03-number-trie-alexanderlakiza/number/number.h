#pragma once

#include <cstdint>
#include <iostream>

class number_t {
public:
  // constructors
  number_t();                      // empty
  number_t(int64_t number);        // from number
  number_t(const number_t &other); // copy

  // =
  void swap(number_t &other);
  number_t &operator=(const number_t &other);

  // casts
  explicit operator bool() const;
  explicit operator long() const;
  explicit operator std::string() const;

  // comparisons
  friend bool operator==(const number_t &first, const number_t &second);
  friend bool operator!=(const number_t &first, const number_t &second);
  friend bool operator<(const number_t &first, const number_t &second);
  friend bool operator>(const number_t &first, const number_t &second);
  friend bool operator<=(const number_t &first, const number_t &second);
  friend bool operator>=(const number_t &first, const number_t &second);

  // stream
  friend std::ostream &operator<<(std::ostream &output, const number_t &other);
  friend std::istream &operator>>(std::istream &input, number_t &other);

  // binary arithmetic
  friend long operator+(const number_t &first, const number_t &second);
  friend long operator-(const number_t &first, const number_t &second);
  friend long operator*(const number_t &first, const number_t &second);
  friend long operator/(const number_t &first, const number_t &second);
  friend long operator%(const number_t &first, const number_t &second);

  // binary assignment
  friend long operator+=(number_t &first, const number_t &second);
  friend long operator-=(number_t &first, const number_t &second);
  friend long operator*=(number_t &first, const number_t &second);
  friend long operator/=(number_t &first, const number_t &second);
  friend long operator%=(number_t &first, const number_t &second);

  // bitwise
  friend long operator|(const number_t &first, const number_t &second);
  friend long operator&(const number_t &first, const number_t &second);
  friend long operator^(const number_t &first, const number_t &second);

  // bitwise assignment
  friend long operator|=(number_t &first, const number_t &second);
  friend long operator&=(number_t &first, const number_t &second);
  friend long operator^=(number_t &first, const number_t &second);

  // incr
  number_t &operator++();
  number_t operator++(int);

  // decr
  number_t &operator--();
  number_t operator--(int);

  // unary
  number_t operator-() const;
  number_t operator+() const;
  number_t operator!() const;
  number_t operator~() const;

  // binary shifts
  friend long operator<<(const number_t &first, const number_t &second);
  friend long operator>>(const number_t &first, const number_t &second);
  number_t &operator<<=(const number_t &number);
  number_t &operator>>=(const number_t &number);

private:
  long _val{0};
};
