#ifndef MYCONTAINERS_COPIABLE_H
#define MYCONTAINERS_COPIABLE_H

namespace my {

template<typename T>
struct Copiable {
    Copiable(const Copiable<T>& other) = default;
    Copiable& operator=(const Copiable<T>& other) = default;

    virtual ~Copiable() noexcept = default;

    // Copiables must be movable too (https://en.cppreference.com/w/cpp/named_req/CopyConstructible)
    Copiable(Copiable<T>&& other) noexcept = default;
    Copiable& operator=(Copiable<T>&& other) noexcept = default;

};

}

#endif  // MYCONTAINERS_COPIABLE_H
