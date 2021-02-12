#include <iostream>
#include <string>

// Runtime polymorphism 
// 1. Inheritance
// 2. function Override  
// 3. Overridden function must be defined as virtual in base class.
// 4. Function call should be from a pointer.
class Animal   // Abstract class
{
public:
    virtual bool hasEyes()
    {
        return true;
    }
    virtual bool canEat(){
        return true;
    }
    virtual bool isWild() = 0;
    virtual std::string eatingHabits() = 0;
    virtual bool isHumanFriendly() = 0;
};

class WildAnimal : public Animal  //abstract class
{
public:
    bool isWild() override{
        return true;
    }
    bool isHumanFriendly() override{
        return false;
    }
};

class DomesticAnimal : public Animal
{
public:
    bool isWild() override{
        return false;
    }
    bool isHumanFriendly() override{
        return true;
    }
};

class Cow : public DomesticAnimal
{
public:
    std::string eatingHabits() override{
        return std::string("Veg");
    }
};

class Tiger : public WildAnimal
{
public:
    std::string eatingHabits() override
    {
        return std::string("NonVeg");
    }
};

void printAnimal(Animal* animal)
{
    std::cout << "Has Eyes:" <<(animal->hasEyes() ? "True" : "False" )<<"\n";
    std::cout << "canEat:" << (animal->canEat() ? "True" : "False") << "\n";
    std::cout << "isWild:" << (animal->isWild() ? "True" : "False") << "\n";
    std::cout << "Eating Habits:" << animal->eatingHabits() << "\n";
    std::cout << "IsHumanFriendly:" << (animal->isHumanFriendly() ? "True" : "False") << "\n";
}

int main(int argc , char ** argv)
{
    // WildAnimal wa;  // Error: WildAnimal is an abstract class
    Tiger t;
    Cow c;
    printAnimal(&t);
    printAnimal(&c);
}
