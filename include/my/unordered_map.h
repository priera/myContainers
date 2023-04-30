#ifndef MYCONTAINERS_UNORDERED_MAP_H
#define MYCONTAINERS_UNORDERED_MAP_H

#include <cstddef>
#include <forward_list>
#include <utility>
#include <vector>

#include "my/input_iterator.h"

namespace my {

template <class Key, class Value>
class unordered_map final {
public:
    struct MyForwardIterator;

    using key_type = Key;
    using size_type = std::size_t;
    using value_type = std::pair<const key_type, Value>;
    using iterator = MyForwardIterator;

    unordered_map();
    ~unordered_map() = default;

    [[nodiscard]] bool empty() const noexcept;
    size_type size() const noexcept;
    void clear() noexcept;

    bool insert(const value_type& value);
    // std::pair<iterator,bool> insert( value_type&& value );
    bool insert(value_type&& value);

    size_type count(const Key& key) const;
    iterator find(const Key& key);

    struct MyForwardIterator : public my::InputIterator<value_type> {
        using MyBase = InputIterator<value_type>;
        using reference = MyBase::reference;
        using pointer = MyBase::pointer;

        reference operator*() override;
        pointer operator->() override;
        MyForwardIterator& operator++() override;
        bool operator==(const MyForwardIterator& other) const noexcept override;
    };

private:
    // Not going to dynamically grow for a toy-example
    static constexpr size_type TABLE_SIZE = 100000;

    struct TableListEntry{
        Key key;
        Value value;
    };

    using TableEntry = std::forward_list<TableListEntry>;

    size_type computeHash(const key_type& key) const;

    std::vector<TableEntry> m_hashTable;
    size_type m_size = 0;
};

}

#include "unordered_map.inl"

#endif //MYCONTAINERS_UNORDERED_MAP_H
