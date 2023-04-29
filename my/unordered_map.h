#ifndef MYCONTAINERS_UNORDERED_MAP_H
#define MYCONTAINERS_UNORDERED_MAP_H

#include <cstddef>
#include <utility>

namespace my {

template <class Key, class Value>
class unordered_map {
public:
    using size_type = std::size_t;
    using value_type = std::pair<const Key, Value>;

    [[nodiscard]] bool empty() const noexcept;
    size_type size() const noexcept;
    void clear() noexcept;

    bool insert(const value_type& value );
    // std::pair<iterator,bool> insert( value_type&& value );
    bool insert(value_type&& value );

    size_type count(const Key& key ) const;
};

}

#endif //MYCONTAINERS_UNORDERED_MAP_H
