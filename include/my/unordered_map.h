#ifndef MYCONTAINERS_UNORDERED_MAP_H
#define MYCONTAINERS_UNORDERED_MAP_H

#include <cstddef>
#include <utility>
#include <vector>
#include <forward_list>

namespace my {

template <class Key, class Value>
class unordered_map final {
public:
    using size_type = std::size_t;
    using value_type = std::pair<const Key, Value>;

    unordered_map() = default;
    ~unordered_map() = default;

    [[nodiscard]] bool empty() const noexcept;
    size_type size() const noexcept;
    void clear() noexcept;

    bool insert(const value_type& value);
    // std::pair<iterator,bool> insert( value_type&& value );
    bool insert(value_type&& value);

    size_type count(const Key& key) const;

private:

    struct TableListEntry{
        Key key;
        Value value;
    };

    std::vector<std::forward_list<TableListEntry>> hashTable;
};

}

#include "unordered_map.inl"

#endif //MYCONTAINERS_UNORDERED_MAP_H
