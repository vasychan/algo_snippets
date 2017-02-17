/*
 * =====================================================================================
 *
 *       Filename:  lru.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27.10.2016 12:12:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>



class cache
{
typedef std::list<std::string> list_t;
typedef std::map<std::string, cached_value > map_t; 

    struct cached_value
    {
    list_t::const_iterator m_list_it;
    std::string value;
    cached_value(const std::string& i_str, list_t::const_iterator l_it ): 
        value(i_str), 
        m_list_it(l_it)
        {
        }
    }
const uint32_t m_limit;
uint32_t m_current_size;

map_t m_map;
mutable list_t m_list;

public:

cache(uint32_t limit): m_limit(limit), m_current_size(0)
    {
    if (limit == 0)
        throw std::exception("blabla");
    }

const std::string& get(const std::string& key) const 
    {
    }

void insert(const std::string& key, const std::string& value)
    {
    if ( value.size() > m_limit )
        throw std::exception("bad value size");

    while ( m_limit < m_current_size + value.size() )
        {
        auto last_it = m_list.crbegin();
        auto map_value_it = m_map.find(*last_it);
        if (map_value_it != m_map.end()
        {
            m_current_size -= (*map_value_it).second.value.size();
            m_map.erase(*last_it);
        }  
        m_list.pop_back();
        }


    cached_value c_value(value, m_list.cbegin()); 
    std::tie<map_t::iterator m_it, bool is_inserted> t = m_map.insert(std::pair<std::string, cached_value>(key, c_value)); 
    
    if (!is_inserted)
    {
        (*m_it).second.value = value;
        auto list_iterator =(*m_it).second.m_list_it; 
        m_list.splice(m_list.begin(), m_list, list_iterator);
        (*m_it).second.m_list_it = m_list.cbegin();

    }
    m_list.push_front(key);

    m_current_size += value.size();
    }

void remove(const std::string& key)
    {
    
    }



}

int main ()
{

return 0;
}
