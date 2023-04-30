#ifndef MYCONTAINERS_INPUT_ITERATOR_H
#define MYCONTAINERS_INPUT_ITERATOR_H

#include "my/concepts/copiable.h"
#include "my/concepts/default_constructible.h"
#include "my/concepts/dereferenceable.h"

namespace my {

template<typename Of>
struct InputIterator : public my::Copiable<InputIterator<Of>>,
                       public my::Dereferenceable<Of>,
                       public my::DefaultConstructible
{
    using value_type = Of;
    using reference = value_type&;
    using pointer = value_type*;

    explicit InputIterator() = default;

    virtual InputIterator<Of>& operator++() = 0;
    virtual bool operator==(const InputIterator<Of>& other) const noexcept = 0;
};

template<typename Of>
bool operator==(const InputIterator<Of>& left, const InputIterator<Of>& right) {
    return left.operator==(right);
}

template<typename Of>
bool operator!=(const InputIterator<Of>& left, const InputIterator<Of>& right) {
    return !(left == right);
}

}

#endif  // MYCONTAINERS_INPUT_ITERATOR_H