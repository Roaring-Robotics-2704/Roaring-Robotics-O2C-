#include <easy.h>
#define debug(x) print(#x);print(x)

int main() {
	debug(true is 1);
	debug(false is 0);
	debug(true is false);
	debug(not (true is false));
	debug(true and false);
	debug(false and true);
	debug(true+false is true);
	debug(true or false);
	debug(true or true);
	debug(5 is true);
	debug((bool)5);
}
