/*
 * =====================================================================================
 *
 *       Filename:  hash_str.cpp
 *
 *    Description:  алгоритм Рабина Карпа, поиск подстроки в строке. O(stroka + text) 
 *
 *        Version:  1.0
 *        Created:  13.10.2016 11:01:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <string>

int main()
{
std::string text("testest");
std::string str("te");
//std::cin >> text;
//std::cin >> str;

std::cout << "str " << str << " , text " << text << "\n";
const unsigned int p = 53;
long long hash = 0, p_pow = 1;

std::vector<std::string> substr;


std::vector<long long> p_pows(std::max(text.length(), str.length()));

// расчитали все степени
for ( int i = 0; i <= p_pows.size(); ++i)
{
    p_pows[i] = p_pows[i-1] * p;
}

// считаем хеши от text
std::vector<long long> text_hashs(std::max(text.length(), str.length()));

for ( size_t i = 0; i < text_hashs.size(); ++i )
    {
    text_hashs[i] = (text[i] - 'a' + 1) * p_pows[i];
    if (i ) 
    {
        text_hashs[i] += text_hashs[i-1];
    }
    std::cout << i << " text_hashs[i] " <<  text_hashs[i] << "\n";
    }

// считаем хеш!!! от str 
long long str_hash = 0;
for ( size_t i = 0; i < str.length(); ++i)
    {
    str_hash += (str[i] - 'a' + 1) * p_pows[i];
    }

std::cout << " str_hash " << str_hash << "\n";
// ищем подстроки одинаковой длины и сравниваем hash

std::cout << " \n\n " << str_hash << "\n";
for ( size_t i = 0; i + str.length() - 1 <  text.size(); ++i )
    {
    long long current_hash = text_hashs[i + str.length() - 1];
    long long prefix_hash = str_hash *  p_pows[i];
    std::cout << "current = " << current_hash << " prefix = " << prefix_hash <<  "\n";
    if (i ) 
        current_hash -= text_hashs[i-1];
    
    if ( current_hash ==  str_hash *  p_pows[i])
    {
        std::cout << "FOUND  current hash " << current_hash << " n in text " << i <<  "\n"; 
    }
    }

std::cout << "str_hash " << str_hash << "\n";
return 0;
}
