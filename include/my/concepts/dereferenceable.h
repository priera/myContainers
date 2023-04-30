#ifndef MYCONTAINERS_DEREFERENCEABLE_H
#define MYCONTAINERS_DEREFERENCEABLE_H

namespace my {

template<typename To>
struct Dereferenceable {

    virtual ~Dereferenceable() noexcept = default;

    virtual To& operator*() = 0;
    virtual To* operator->() = 0;
};

}

#endif  // MYCONTAINERS_DEREFERENCEABLE_H
