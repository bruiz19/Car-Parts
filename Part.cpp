#include <string>
#include "Part.h"

Part::Part():
      id(0), description("blank") {} // default constructor

Part::Part(int e, std::string desc):
      id(e), description(desc) {} // parameterized constructor

int Part::getID(){
    return id;
}

void Part::setID(int num) {
    id = num;
}

std::string Part::getDescription() {
    return description;
}

void Part::setDescription(std::string desc) {
    description = desc;
}
