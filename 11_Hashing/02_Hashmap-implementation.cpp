#include <vector>
#include <string>
#include <iostream>

using namespace std;

enum class State
{
    EMPTY,
    ACTIVE,
    DELETED
};

struct HashEntry
{
    string key;
    string value;
    State state = State::EMPTY;
};

class HashMap
{
public:
    int size_ = 0;
    int capacity_ = 0;
    vector<HashEntry> map_;

    HashMap()
    {
        map_.resize(capacity_);
    }

    int hash(const string &key)
    {
        int index = 0;
        for (char c : key)
        {
            index += int(c);
        }
        return index % capacity_;
    }

    void rehash()
    {
        capacity_ *= 2;
        // Make a copy of the old map
        vector<HashEntry> oldMap = map_;

        // Clear and resize the current map
        map_ = vector<HashEntry>(capacity_);
        size_ = 0; // Reset size, put() will recalculate it

        // Re-insert only the ACTIVE items (ignoring DELETED and EMPTY ones)
        for (const auto &entry : oldMap)
        {
            if (entry.state == State::ACTIVE)
            {
                put(entry.key, entry.value);
            }
        }
    }

    string *get(const string &key)
    {
        int index = hash(key);
        // Stop searching ONLY if we hit an EMPTY slot
        while (map_[index].state != State::EMPTY)
        {
            if (map_[index].state == State::ACTIVE && map_[index].key == key)
            {
                return &map_[index].value;
            }
            index = (index + 1) % capacity_;
        }
        return nullptr;
    }

    void put(const string &key, const string &val)
    {
        // Check load factor before inserting
        if (size_ >= capacity_ / 2)
        {
            rehash();
        }

        int index = hash(key);
        int first_deleted = -1;

        // Walk the array until we find the key or an EMPTY slot
        while (map_[index].state != State::EMPTY)
        {
            // Remember the first DELETED slot we see so we can reuse it
            if (map_[index].state == State::DELETED && first_deleted == -1)
            {
                first_deleted = index;
            }
            // If the key already exists, update the value and return
            else if (map_[index].state == State::ACTIVE && map_[index].key == key)
            {
                map_[index].value = val;
                return;
            }
            index = (index + 1) % capacity_;
        }
        // If we found a DELETED slot earlier, reuse it. Otherwise, use the EMPTY slot.
        int target = (first_deleted != -1) ? first_deleted : index;
        map_[target].key = key;
        map_[target].value = val;
        map_[target].state = State::ACTIVE;
        size_++;
    }

    void remove(const string &key)
    {
        int index = hash(key);

        while (map_[index].state != State::EMPTY)
        {
            if (map_[index].state == State::ACTIVE && map_[index].key == key)
            {
                map_[index].state = State::DELETED;

                // FREE THE STRING MEMORY:
                map_[index].key = ""; // Or map_[index].key.clear();
                map_[index].value = "";

                size_--;
                return;
            }
            index = (index + 1) % capacity_;
        }
    }

    void print()
    {
        cout << "Printing size=" << size_ << " capacity=" << capacity_ << endl;
        for (int i = 0; i < capacity_; i++)
        {
            cout << "[" << i << "] ";
            if (map_[i].state == State::ACTIVE)
            {
                cout << map_[i].key << ": " << map_[i].value;
            }
            else if (map_[i].state == State::DELETED)
            {
                cout << "<DELETED>";
            }
            else
            {
                cout << "<EMPTY>";
            }
            cout << endl;
        }
    }
};