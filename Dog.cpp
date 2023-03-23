#include <iostream>

#include "Dog.h"

Dog::Dog() {
	breed = "";
	color = "";
}

Dog::Dog(const std::string &i, const std::string &c) {
	breed = i;
	color = c;
}

bool Dog::operator==(const Dog &other) const {
	return ((breed == other.breed) &&
		(color == other.color));
}

bool isZany(const Dog &t) {
	return (t.color == "brown");
}

std::ostream &operator<<(std::ostream &out, const Dog &c) {
	out << c.breed << " [" << c.color << "]";
	return out;
}
