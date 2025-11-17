

#include <stdio.h>
#include "Disaster.h"
#include "Storm.h"
#include "Earthquake.h"

int main() {

	Disaster* disaster1 = new Storm();
	disaster1->warn();
	delete disaster1;

	Disaster* disaster2 = new Earthquake();
	disaster2->warn();
	delete disaster2;

	return 0;
}