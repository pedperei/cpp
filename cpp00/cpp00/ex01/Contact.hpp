#include <iostream>
#include <cstdio>
//using namespace std;

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_number;
        std::string darkest_secret;

    public:
    Contact();
    ~Contact();
    void setFirst_name(std::string);
    void setLast_name(std::string);
    void setNick_name(std::string);
    void setPhone_number(std::string);
    void setDarkest_secret(std::string);
    std::string getFirst_name(void);
    std::string getLast_name(void);
    std::string getNick_name(void);
    std::string getPhone_number(void);
    std::string getDarkest_secret(void);
    void print_contact(void);

};