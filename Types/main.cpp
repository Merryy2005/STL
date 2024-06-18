#include "Car.hpp"
#include <unordered_map>

int main()
{
    std::unordered_map<Car, std::string , hash> cars;
    Car c1(100,200,"BMW");
    Car c2(105,300,"Walkswagen");
    Car c3(130,150,"Honda");
    cars.emplace(c1 , "Bob");
    cars.emplace(c2 , "Mark");
    cars.emplace(c3 , "Mike");
    for (const auto& pair : cars) 
    {
        std::cout << "Car: " << pair.first << ", Owner: " << pair.second << std::endl;
    }    
    return 0;
}