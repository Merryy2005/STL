#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include <map>


class Car
{
    public:
        int speed;
        int hp;
        std::string name;
    public:
        Car() : speed(0) , hp(0) , name("")
        {}
        Car(int speed , int hp , std::string name) : speed(speed) , hp(hp) , name(name)
        {}
        bool operator== (const Car& other) const
        {
            return speed == other.speed && hp == other.hp && name == other.name;
        }
        friend std::ostream& operator<<(std::ostream& os, const Car& obj) 
        {
            os << "Name: " << obj.name << ", Speed: " << obj.speed << ", HP: " << obj.hp;
            return os;
        }       
        ~Car(){};
};

struct hash
{
        std::size_t operator()(const Car& c) const
        {
            std::size_t h1 = std::hash<int>()(c.speed);
            std::size_t h2 = std::hash<int>()(c.hp);
            std::size_t h3 = std::hash<std::string>()(c.name);
            return h1 ^ (h2 << 1) ^ (h3 << 2);
        }
};

#endif // CAR_H