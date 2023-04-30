namespace my {

template <class Key, class Value>
[[nodiscard]] bool unordered_map<Key, Value>::empty() const noexcept {
    return true;
}

template <class Key, class Value>
unordered_map<Key, Value>::size_type unordered_map<Key, Value>::size() const noexcept {
    return 0;
}

template <class Key, class Value>
void unordered_map<Key, Value>::clear() noexcept {}

template <class Key, class Value>
bool unordered_map<Key, Value>::insert(const value_type& value) {
    return false;
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
}  // namespace my