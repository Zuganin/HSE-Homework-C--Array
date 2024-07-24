

#ifndef ARRAY_H
#define ARRAY_H

#include <iterator>
#include <stdexcept>

class ArrayOutOfRange : public std::out_of_range {
 public:
  ArrayOutOfRange() : std::out_of_range("ArrayOutOfRange") {}
};

template <class T, size_t N>
class Array {
 public:
  T buffer[N]{};

  T& operator[](size_t pos) { return buffer[pos]; }

  const T& operator[](size_t pos) const { return buffer[pos]; }
  T& At(size_t pos) {
    if (pos > N) {
      throw ArrayOutOfRange();
    }
    return buffer[pos];
  }
  const T& At(size_t pos) const {
    if (pos > N) {
      throw ArrayOutOfRange();
    }
    return buffer[pos];
  }
  T& Front() { return buffer[0]; }
  const T& Front() const { return buffer[0]; }
  T& Back() { return buffer[0 + N - 1]; }
  const T& Back() const { return buffer[0 + N - 1]; }
  T* Data() {
    if (this->Size() == 0) {
      return nullptr;
    }
    return buffer;
  }
  const T* Data() const {
    if (this->Size() == 0) {
      return nullptr;
    }

    return buffer;
  }

  [[nodiscard]] bool Empty() const {
    return std::begin(buffer) == std::end(buffer);
  }
  [[nodiscard]] size_t Size() const {
    return std::distance(std::begin(buffer), std::end(buffer));
  }

  void Fill(const T& value) {
    for (size_t i = 0; i < N; ++i) {
      buffer[i] = value;
    }
  }

  void Swap(Array<T, N>& other) {
    for (size_t i = 0; i < N; ++i) {
      T temp = buffer[i];
      this->buffer[i] = other.buffer[i];
      other.buffer[i] = temp;
    }
  }
};

#endif  // ARRAY_H
