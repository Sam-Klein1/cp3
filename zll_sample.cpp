#include <iostream> 
using namespace std;

#include "zany.h"
#include "Dog.h"
#include "ZLL.h"

template <typename T>
void reportZany(const T &param) {
	cout << param << " is ";
	if (!isZany(param)) cout << "not ";
	cout << "zany" << endl;
}

int main() {
    int one = 1;
	int two = 2;
	string one_str = "one";
	string two_str = "Two";
	reportZany(one);
	reportZany(two);
	reportZany(one_str);
	reportZany(two_str);
	Dog one_thing("Beagle", "brown");
	Dog two_thing("Retriever", "black");
	reportZany(one_thing);
	reportZany(two_thing);

	ZLL<int> zll1;
	ZLL<string> zll2;
	ZLL<Dog> zll3;

	zll1.back(1);
	zll2.back("two");
	zll3.back(one_thing);
}
