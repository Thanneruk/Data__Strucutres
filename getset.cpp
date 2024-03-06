#include <iostream>
#include <string>

class Person {
private:
    std::string name;       // Store name as a string
    int age;                // Store age as an integer
    double height;          // Store height in centimeters as a double
    char gender;            // Store gender as a single character ('M' for male, 'F' for female, etc.)
    bool isMarried;         // Store marital status as a boolean (true for married, false for single)

public:
    // Getter for name
    std::string getName() const {
        return name;
    }

    // Setter for name
    void setName(const std::string& newName) {
        name = newName;
    }

    // Getter for age
    int getAge() const {
        return age;
    }


    // Setter for age
    void setAge(int newAge) {
        if (newAge >= 0) {
            age = newAge;
        }
        else {
            std::cerr << "Age cannot be negative." << std::endl;
        }
    }

    // Getter for height
    double getHeight() const {
        return height;
    }

    // Setter for height
    void setHeight(double newHeight) {
        height = newHeight;
    }

    // Getter for gender
    char getGender() const {
        return gender;
    }

    // Setter for gender
    void setGender(char newGender) {
        gender = newGender;
    }

    // Getter for marital status
    bool getIsMarried() const {
        return isMarried;
    }

    // Setter for marital status
    void setIsMarried(bool newStatus) {
        isMarried = newStatus;
    }
};

int main() {
    Person person;
    person.setName("Alice");        // Set the name of the person
    person.setAge(30);              // Set the age of the person
    person.setHeight(165.5);        // Set the height of the person
    person.setGender('F');          // Set the gender of the person
    person.setIsMarried(true);      // Set the marital status of the person

    // Print information about the person
    std::cout << "Name: " << person.getName() << std::endl;
    std::cout << "Age: " << person.getAge() << std::endl;
    std::cout << "Height: " << person.getHeight() << " cm" << std::endl;
    std::cout << "Gender: " << person.getGender() << std::endl;
    std::cout << "Marital Status: " << (person.getIsMarried() ? "Married" : "Single") << std::endl;

    return 0;
}