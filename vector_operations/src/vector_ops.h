#pragma once

#include <vector>
#include <iostream>
#include <cassert>
#include <type_traits>


namespace task {

template<class T>
concept Derived = std::is_same_v<int, T> || std::is_same_v<double, T>;

template<Derived T>
std::vector<T> operator+(const std::vector<T> &vec) {
    std::vector<T> res_vector;
    res_vector.resize(vec.size());
    for (size_t i = 0; i < res_vector.size(); ++i) {
        res_vector[i] = +vec[i];
    }
    return res_vector;
}

template<Derived T>
std::vector<T> operator-(const std::vector<T> &vec) {
    std::vector<T> res_vector;
    res_vector.resize(vec.size());
    for (size_t i = 0; i < res_vector.size(); ++i) {
        res_vector[i] = -vec[i];
    }
    return res_vector;
}

template<Derived T>
std::vector<T> operator+(const std::vector<T> &first, const std::vector<T> &second) {
    assert(first.size() == second.size());
    std::vector<T> res_vector;
    res_vector.resize(first.size());
    for (size_t i = 0; i < res_vector.size(); ++i) {
        res_vector[i] = first[i] + second[i];
    }
    return res_vector;
}

template<Derived T>
std::vector<T> operator-(const std::vector<T> &first, const std::vector<T> &second) {
    assert(first.size() == second.size());
    std::vector<T> res_vector;
    res_vector.resize(first.size());
    for (size_t i = 0; i < res_vector.size(); ++i) {
        res_vector[i] = first[i] - second[i];
    }
    return res_vector;
}

// dot product
template<Derived T>
T operator*(const std::vector<T> &first, const std::vector<T> &second) {
    assert(first.size() == second.size());
    T res = 0;
    for (size_t i = 0; i < first.size(); ++i) {
        res += first[i] * second[i];
    }
    return res;
}

// cross product
template<Derived T>
std::vector<T> operator%(const std::vector<T> &first, const std::vector<T> &second) {
    assert(first.size() == 3);
    assert(first.size() == second.size());
    std::vector<T> res_vector;
    res_vector.resize(first.size());
    res_vector[0] = first[1] * second[2] - first[2] * second[1];
    res_vector[1] = first[2] * second[0] - first[0] * second[2];
    res_vector[2] = first[0] * second[1] - first[1] * second[0];
    return res_vector;
}

//  collinearity
template<Derived T>
bool operator||(const std::vector<T> &first, const std::vector<T> &second) {
    assert(first.size() == second.size());
    static constexpr double eps = 1e-10;
    double mult = static_cast<double>(first[0]) / second[0];
    for (size_t i = 1; i < first.size(); ++i) {
        if ((static_cast<double>(first[i]) / second[i] - mult < -eps) || (static_cast<double>(first[i]) / second[i] - mult > eps)) {
            return false;
        }
    }
    return true;
}

// co-directivity
template<Derived T>
bool operator&&(const std::vector<T> &first, const std::vector<T> &second) {
    assert(first.size() == second.size());
    return (first || second) && (first * second > 0);
}

template<Derived T>
std::istream &operator>>(std::istream &in, std::vector<T> &vec) {
    T size = 0;
    in >> size;
    vec.resize(size);
    for (auto &elem : vec) {
        in >> elem;
    }
    return in;
}
template<Derived T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec) {
    for (auto &elem : vec) {
        out << elem << " ";
    }
    out << "\n";
    return out;
}

// need new vector or need reverse in place? do all both variation
template<Derived T>
std::vector<T> reverse(const std::vector<T> &vec) {
    std::vector<T> res_vector;
    res_vector.resize(vec.size());
    for (size_t i = 0, j = vec.size() - 1; i < vec.size(); ++i, ++j) {
        res_vector[i] = vec[j];
    }
    return res_vector;
}

template<Derived T>
void reverse(std::vector<T> &vec) {
    for (size_t i = 0; i < vec.size() / 2; ++i) {
        std::swap(vec[i], vec[vec.size() - 1 - i]);
    }
}

std::vector<int> operator|(const std::vector<int>& first, const std::vector<int>& second) {
    assert(first.size() == second.size());
    std::vector<int> res_vector(first.size(), 0);
    for (size_t i = 0; i < first.size(); ++i) {
        res_vector[i] = first[i] | second[i];
    }
    return res_vector;
}

std::vector<int> operator&(const std::vector<int>& first, const std::vector<int>& second) {
    assert(first.size() == second.size());
    std::vector<int> res_vector(first.size(), 0);
    for (size_t i = 0; i < first.size(); ++i) {
        res_vector[i] = first[i] & second[i];
    }
    return res_vector;
}

}  // namespace task
