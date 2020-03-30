/**
 * Definition: Abstract Factory provides a interface to create dependent/family of objects
 * without specifying actual implementations of concrete factory classes
 * Note: WoodenFactory class is not implemented. But an equivalent object is created at run time
 */
#include <iostream>

/**
 * Abstract Object Type - Door
 */
class IDoor {
public:
    virtual void getDescription() = 0;
};

/**
 * Concrete Door
 */
class WoodenDoor : public IDoor {
public:
    void getDescription() override {
        std::cout<<"I'm a wooden door."<<std::endl;
    }
};

/**
 * Concrete Door
 */
class IronDoor : public IDoor {
public:
    void getDescription() override {
        std::cout<<"I'm a iron door."<<std::endl;
    }
};

/**
 * Abstract Object Type - DoorFittingExpert
 */
class IDoorFittingExpert {
public:
    virtual void getDescription() = 0;
};

/**
 * Concrete Expert
 */
class Carpenter : public IDoorFittingExpert {
public:
    void getDescription() override {
        std::cout<<"I'm a carpenter and I can fit wooden doors"<<std::endl;
    }
};

/**
 * Concrete Expert
 */
class Welder : public IDoorFittingExpert {
public:
    void getDescription() override {
        std::cout<<"I'm a welder and I can fit iron doors"<<std::endl;
    }
};

/**
 * Abstract Door Factory
 */
class IDoorFactory {
public:
    virtual IDoor* makeDoor() = 0;
    virtual IDoorFittingExpert* makeFittingExpert() = 0;
};

/**
 * Actual DoorFactory
 *
 * @tparam Door
 * @tparam DoorFittingExpert
 */
template <typename Door, typename DoorFittingExpert>
class DoorFactory : public IDoorFactory {
public:
    IDoor* makeDoor() override {
        return  new Door();
    }

    IDoorFittingExpert* makeFittingExpert() override {
        return new DoorFittingExpert();
    }
};


int main() {
    IDoorFactory* woodenFactory = new DoorFactory<WoodenDoor, Carpenter>;
    {
        IDoor* door = woodenFactory->makeDoor();
        IDoorFittingExpert* expert = woodenFactory->makeFittingExpert();
        door->getDescription();
        expert->getDescription();
    }

    IDoorFactory* ironFactory = new DoorFactory<IronDoor, Welder>;
    {
        IDoor* door = ironFactory->makeDoor();
        IDoorFittingExpert* expert = ironFactory->makeFittingExpert();
        door->getDescription();
        expert->getDescription();
    }
    return 0;
}





