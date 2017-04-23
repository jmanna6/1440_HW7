// Using my Generic Dictionary components from HW6
//
// Created by Jake on 4/3/2017.
//

// validate - doing the right thing
// verify   - doing the thing right

#ifndef GENERICDICTIONARY_DICTIONARY_H
#define GENERICDICTIONARY_DICTIONARY_H

#include <string>

#include "KeyValue.h"

template <class K, class V>
class Dictionary
{
public:
    Dictionary<K, V>(unsigned int count = 10)
    {
        m_sizeReserved = count;
        m_numKeys = 0;
        m_KeyValues = new KeyValue<K, V>*[m_sizeReserved];

        for (unsigned int i = 0; i < m_sizeReserved; i++)
        {
            m_KeyValues[i] = nullptr;
            // std::cout << m_KeyValues[i] << std::endl;
        }
    }

    Dictionary<K, V>(const Dictionary& rOther)
    {
        this->m_numKeys = rOther.getCount();
        this->m_sizeReserved = rOther.getSize();
        this->m_KeyValues = rOther.m_KeyValues;
    }

    ~Dictionary()
    {
        if (m_KeyValues != NULL)
        {
            for (unsigned int i = 0; i < m_sizeReserved; i++)
            {
                delete [] m_KeyValues;
            }
        }
        delete m_KeyValues;
    }

    // NEED to reallocate if there is not enough space
    void add(K key, V value)
    {
        if (m_numKeys >= m_sizeReserved)
        {
            resize();
        }

        m_KeyValues[m_numKeys] = new KeyValue<K, V>(key, value);
        m_numKeys++;
    }

    unsigned int getCount() const
    {
        return m_numKeys;
    }

    unsigned int getSize() const
    {
        return m_sizeReserved;
    }

    // NEED to throw exception for NULL or undefined key
    const KeyValue<K, V> getByKey(K key)
    {
        for (unsigned int i = 0; i < m_numKeys; i++)
        {
            if (key == m_KeyValues[i]->getKey())
            {
                return *m_KeyValues[i];
            }
        }

        throw std::string("Invalid Key");
    }

    // NEED to throw exception if index is out of bounds
    const KeyValue<K, V>& getByIndex(unsigned int index) const
    {
        if (index <= m_numKeys)
        {
            return *m_KeyValues[index];
        }
        else
        {
            throw std::string("Index out of bounds");
        }
    };

    // NEED to throw exception if index is out of bounds
    const KeyValue<K, V>& operator[](unsigned int index) const
    {
        return getByIndex(index);
    }

    // NEED to throw exception for NULL or undefined key
    void removeByKey(K key)
    {
        bool found = false;
        for (unsigned int i = 0; i < m_numKeys; i++)
        {
            if (key == m_KeyValues[i]->getKey())
            {
                found = true;
                removeByIndex(i);
                break;
            }
        }
        if (!found)
        {
            throw std::string("Entered key is not in this Dictionary");
        }
    }

    // NEED to throw exception if index is out of bounds
    void removeByIndex(unsigned int index)
    {
        if (index < m_numKeys)
        {
            delete m_KeyValues[index];
            m_KeyValues[index] = nullptr;
            for (unsigned int i = index; i < m_numKeys - 1; i++)
            {
                m_KeyValues[i] = m_KeyValues[i + 1];
            }
            m_numKeys--;
        }
        else
        {
            throw std::string("Invalid index");
        }
    }

    void print()
    {
        for (unsigned int i = 0; i < m_numKeys; i++)
        {
            m_KeyValues[i]->display();
        }
        std::cout << "Number of pairs: " << m_numKeys << std::endl;
        std::cout << "Size reserved: " << m_sizeReserved << std::endl;
    }

    void resize()
    {
        m_sizeReserved *= 2;
        KeyValue<K, V>** pTmp = new KeyValue<K, V>*[m_sizeReserved];
        for (unsigned int i = 0; i < m_sizeReserved; i++)
        {
            pTmp[i] = nullptr;
        }

        for (unsigned int i = 0; i < m_numKeys; i++)
        {
            pTmp[i] = m_KeyValues[i];
        }

        m_KeyValues = pTmp;
    }


private:
    KeyValue<K, V>** m_KeyValues;
    unsigned int m_numKeys;
    unsigned int m_sizeReserved;
};


#endif //GENERICDICTIONARY_DICTIONARY_H
