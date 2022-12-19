
#include <string>
class Person{
    std::string country;
    std::string name;
    int personid;
public:
    Person(std::string country, std::string name, int personid){}
    std::string getcountry() ;
    std::string getname();
    int getpersonid();
    
};

