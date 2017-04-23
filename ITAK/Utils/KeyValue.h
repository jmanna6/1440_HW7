// Using my Generic Dictionary components from HW6
//
// Created by Jake on 4/3/2017.
//

#ifndef GENERICDICTIONARY_KEYVALUE_H
#define GENERICDICTIONARY_KEYVALUE_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

template <class K, class V>
class KeyValue
{
public:
    KeyValue<K, V>(K key, V value)
            :   m_key(key),
                m_value(value)
    {}

    KeyValue<K, V>(const KeyValue& rOther)
    {
        this->m_key = rOther.getKey();
        this->m_value = rOther.getValue();
    }

    K getKey() const
    {
        return m_key;
    }

    V getValue() const
    {
        return m_value;
    }

    std::string display() const
    {
        std::cout << m_key << ", " << m_value << std::endl;
    }

private:
    K m_key;
    V m_value;
};


#endif //GENERICDICTIONARY_KEYVALUE_H
