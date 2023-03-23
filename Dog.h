#include <iostream>
class Dog {
	private:
		std::string breed = "";
		std::string color = "";
	public:
		Dog();
		Dog(const std::string &i, const std::string &c);
		bool operator==(const Dog &other) const;
		friend bool isZany(const Dog &t);
		friend std::ostream &operator<<(std::ostream &out,
						const Dog &c);
};
