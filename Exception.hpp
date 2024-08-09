#include <exception>
#include <string>

namespace mystl
{
    class my_exception : public std::exception 
    {
        private:
            std::string s;
        public:
            my_exception(const std::string& s) : s(s) {}
            virtual const char* what() const noexcept override 
            {
                return s.c_str();
            }
    };
}