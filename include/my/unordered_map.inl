#include <algorithm>

namespace my {

template <class Key, class Value>
unordered_map<Key, Value>::unordered_map() :
    m_hashTable(TABLE_SIZE) {
}

template <class Key, class Value>
[[nodiscard]] bool unordered_map<Key, Value>::empty() const noexcept {
    return m_size == 0;
}

template <class Key, class Value>
unordered_map<Key, Value>::size_type unordered_map<Key, Value>::size() const noexcept {
    return m_size;
}

template <class Key, class Value>
void unordered_map<Key, Value>::clear() noexcept {
    m_hashTable.clear();
    m_size = 0;
}

template <class Key, class Value>
bool unordered_map<Key, Value>::insert(const value_type& value) {
    const size_type index = computeHash(value.first) % TABLE_SIZE;
    TableEntry& entryList = m_hashTable[index];
    const auto it = std::ranges::find_if(entryList, [&](const value_type& entryValue) {
        return entryValue.first == value.first;
    });

    if (it != entryList.end()) {
        return false;
    }

    const auto insertedIt = entryList.insert_after(entryList.before_begin(), {value.first, value.second});
    m_size++;
    return true;
}

// std::pair<iterator,bool> insert( value_type&& value );
template <class Key, class Value>
bool unordered_map<Key, Value>::insert(value_type&& value) {
    return false;
}

template <class Key, class Value>
unordered_map<Key, Value>::size_type unordered_map<Key, Value>::count(const Key& key) const {
    return 0;
}

template<class Key, class Value>
unordered_map<Key, Value>::iterator unordered_map<Key, Value>::find(const Key& key) {
    const size_type index = computeHash(key) % TABLE_SIZE;
    TableEntry& entryList = m_hashTable[index];
    const auto it = std::ranges::find_if(entryList, [&](const value_type& entryValue) {
        return entryValue.first == key;
    });

    if (it == entryList.end()) {
        return end();
    }

    typename MyForwardIterator::value_type foundValue = *it;
    return MyForwardIterator(&foundValue);
}

template<class Key, class Value>
unordered_map<Key, Value>::iterator unordered_map<Key, Value>::end() const {
    return MyForwardIterator();
}

template <class Key, class Value>
unordered_map<Key, Value>::size_type unordered_map<Key, Value>::computeHash(const key_type& key) const {
    // Instead of using std::hash, I'm implementing a type-agnostic hash generator
    // May lead to a lot of conflicts, but that's not the point

    const size_type iterations = sizeof(key_type) / sizeof(unsigned char);
    const auto bytesView = reinterpret_cast<const unsigned char*>(&key);
    size_type computedHash = 0;

    for (size_type it = 0; it < iterations; it++) {
        computedHash ^= bytesView[it];
        computedHash <<= 1;
    }

    return computedHash;
}

template <class Key, class Value>
unordered_map<Key, Value>::MyForwardIterator::MyForwardIterator() :
    MyBase(),
    m_p(nullptr) {}

template <class Key, class Value>
unordered_map<Key, Value>::MyForwardIterator::MyForwardIterator(pointer p) :
    MyBase(),
    m_p(p) {}

template <class Key, class Value>
unordered_map<Key, Value>::MyForwardIterator::reference
unordered_map<Key, Value>::MyForwardIterator::operator*() {
    return *m_p;
}

template <class Key, class Value>
unordered_map<Key, Value>::MyForwardIterator::pointer
unordered_map<Key, Value>::MyForwardIterator::operator->() {
    return m_p;
}

template <class Key, class Value>
unordered_map<Key, Value>::MyForwardIterator& unordered_map<Key, Value>::MyForwardIterator::operator++() {

}

template <class Key, class Value>
bool my::unordered_map<Key, Value>::MyForwardIterator::equalTo(const my::unordered_map<Key, Value>::MyForwardIterator& other) const noexcept {
    return m_p == other.m_p;
}

}  // namespace my

template <class Key, class Value>
bool operator==(const typename my::unordered_map<Key, Value>::iterator& left, const typename my::unordered_map<Key, Value>::iterator& right) noexcept {
    return left.equalTo(right);
}