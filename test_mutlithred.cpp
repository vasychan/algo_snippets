#include <string>
#include <sstream>
#include <thread>
#include <vector>
#include <iostream>

#include <thread> //c++ 11
#include <mutex> //c++ 11
#include <functional>
#include <future> //c++ 11
#include <stdlib.h>
#include <time.h> 
#include <string.h>
#include <unistd.h>
struct engine_threads_item
    {
    typedef         uint32_t    id_t;    
    id_t            m_id;
    typedef         uint32_t    state_t;    
    state_t         m_state;
    typedef         std::string url_t;
    url_t           m_url;

    engine_threads_item() {}

    void set_url(const std::string url) 
        { 
        m_url = url; 
        }
    url_t get_url() const
        { 
        return m_url; 
        }
    void set_state(const state_t state)
        {
        m_state = state;
        }
    state_t get_state() const
        {
        return m_state;
        }
    };

class engine_threads_info
    {
    public:
        typedef std::vector<engine_threads_item> container_t;
    protected:
        std::mutex read_mutex;
        container_t m_container;
    public:
        container_t get_container() 
            {
            std::lock_guard<std::mutex> lock(read_mutex);
            return m_container;
            }
        void resize(int capacity)
            {
            m_container.resize(capacity);
            }
        void remove(const engine_threads_item::id_t idx)
            {
            m_container.erase(m_container.begin() + idx);
            }
        void set_url(const engine_threads_item::id_t idx, const engine_threads_item::url_t url)
            {
            std::lock_guard<std::mutex> lock(read_mutex);
            m_container.at(idx).set_url(url);
            }
        void set_state(const engine_threads_item::id_t idx, const engine_threads_item::state_t state)
            {
            m_container.at(idx).set_state(state);
            }
    };
class test_string
{
    public:
    std::mutex m_mutex;
    std::string m_test;
    char* m_test_char;
    int m_test_int;
    test_string() {} 
    engine_threads_info m_engine_threads_info;

    void execute()
    {

        unsigned int _seed = time(NULL);
        char *t1_cstr = new char[100];
        char *t2_cstr = new char[100];
        m_engine_threads_info.resize(11);
        while(true)
            {
            std::string t1 = "adsfasdo0fisad0fi4qjrklweqjrolasjflasdjflasjdfa";
            std::string t2 = "adfa";

            strcpy(t1_cstr, t1.c_str());
            strcpy(t2_cstr, t2.c_str());
        
            int _rand  = rand_r(&_seed) % 10+ 1;
            if (_rand < 5)
                {
                        m_engine_threads_info.set_url(_rand, t1);
                }
            if (_rand > 5)
                {
                        m_engine_threads_info.set_url(_rand, t2);
                }
            }
            delete [] t1_cstr;
            delete [] t2_cstr;


    }
    
};


int main()
{
     

std::shared_ptr<test_string> test_string_ptr1(new test_string());
std::shared_ptr<test_string> test_string_ptr2(new test_string());
std::thread t1 (&test_string::execute, test_string_ptr1);
std::thread t2 (&test_string::execute, test_string_ptr2);

std::string test_str1; 
std::string test_str2; 
sleep(5);
while (true)
{
    engine_threads_info::container_t container1 = test_string_ptr1->m_engine_threads_info.get_container();
    engine_threads_info::container_t container2 = test_string_ptr2->m_engine_threads_info.get_container();

    for( int i = 1; i < 10 ; i++)
    {
    std::cout << "test_string_ptr1 = " << container1.at(i).get_url() << "\n";
    std::cout << "test_string_ptr2 = " << container2.at(i).get_url() << "\n";
    }
}
t1.join();          
t2.join();
std::cout << "end" << "\n";
          
return 0;
}
