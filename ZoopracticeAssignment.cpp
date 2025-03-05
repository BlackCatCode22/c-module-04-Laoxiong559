#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>


class Animal {
protected:
    std::string name;
    int age;
    std::string species;

public:

    Animal(std::string name, int age, std::string species)
        : name(name), age(age), species(species) {}


    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getSpecies() const { return species; }


    void setName(const std::string& name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setSpecies(const std::string& species) { this->species = species; }


    virtual void displayDetails() const {
        std::cout << "Name: " << name << ", Age: " << age << ", Species: " << species << std::endl;
    }
};


class Hyena : public Animal {
private:
    std::string laughType;

public:

    Hyena(std::string name, int age, std::string laughType)
        : Animal(name, age, "Hyena"), laughType(laughType) {}


    std::string getLaughType() const { return laughType; }


    void setLaughType(const std::string& laughType) { this->laughType = laughType; }


    void displayDetails() const override {
        Animal::displayDetails();
        std::cout << "Laugh Type: " << laughType << std::endl;
    }
};


class Lion : public Animal {
private:
    std::string maneColor;

public:

    Lion(std::string name, int age, std::string maneColor)
        : Animal(name, age, "Lion"), maneColor(maneColor) {}


    std::string getManeColor() const { return maneColor; }


    void setManeColor(const std::string& maneColor) { this->maneColor = maneColor; }


    void displayDetails() const override {
        Animal::displayDetails();
        std::cout << "Mane Color: " << maneColor << std::endl;
    }
};


class Tiger : public Animal {
private:
    std::string stripePattern;

public:

    Tiger(std::string name, int age, std::string stripePattern)
        : Animal(name, age, "Tiger"), stripePattern(stripePattern) {}


    std::string getStripePattern() const { return stripePattern; }


    void setStripePattern(const std::string& stripePattern) { this->stripePattern = stripePattern; }


    void displayDetails() const override {
        Animal::displayDetails();
        std::cout << "Stripe Pattern: " << stripePattern << std::endl;
    }
};


class Bear : public Animal {
private:
    std::string furColor;

public:

    Bear(std::string name, int age, std::string furColor)
        : Animal(name, age, "Bear"), furColor(furColor) {}


    std::string getFurColor() const { return furColor; }


    void setFurColor(const std::string& furColor) { this->furColor = furColor; }


    void displayDetails() const override {
        Animal::displayDetails();
        std::cout << "Fur Color: " << furColor << std::endl;
    }
};

int main() {

    std::vector<std::string> hyenaNames = {
        "Shenzi", "Banzai", "Ed", "Zig", "Bud", "Lou", "Kamari", "Wema", "Nne", "Madoa", "Prince Nevarah"
    };

    std::vector<std::string> lionNames = {
        "Scar", "Mufasa", "Simba", "Kiara", "King", "Drooper", "Kimba", "Nala", "Leo", "Samson", "Elsa", "Cecil"
    };

    std::vector<std::string> bearNames = {
        "Yogi", "Smokey", "Paddington", "Lippy", "Bungle", "Baloo", "Rupert", "Winnie the Pooh", "Snuggles", "Bert"
    };

    std::vector<std::string> tigerNames = {
        "Tony", "Tigger", "Amber", "Cosimia", "Cuddles", "Dave", "Jiba", "Rajah", "Rayas", "Ryker"
    };

    std::vector<Animal*> animals;

    for (const auto& name : hyenaNames) {
        animals.push_back(new Hyena(name, 5, "Cackling"));
    }

    for (const auto& name : lionNames) {
        animals.push_back(new Lion(name, 7, "Golden"));
    }

    for (const auto& name : bearNames) {
        animals.push_back(new Bear(name, 3, "Brown"));
    }

    for (const auto& name : tigerNames) {
        animals.push_back(new Tiger(name, 9, "Striped"));
    }


    std::map<std::string, int> speciesCount;

    for (const auto& animal : animals) {
        speciesCount[animal->getSpecies()]++;
    }


    std::ofstream outputFile("newAnimals.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    for (const auto& pair : speciesCount) {
        outputFile << "Species: " << pair.first << std::endl;
        outputFile << "Count: " << pair.second << std::endl;

        for (const auto& animal : animals) {
            if (animal->getSpecies() == pair.first) {
                animal->displayDetails();
                outputFile << std::endl;
            }
        }

        outputFile << std::endl;
    }

    outputFile.close();


    for (auto& animal : animals) {
        delete animal;
    }

    return 0;
}
