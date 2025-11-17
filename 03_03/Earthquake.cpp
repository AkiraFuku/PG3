#include "Earthquake.h"
#include <stdio.h>

Earthquake::Earthquake()
{
	name_ = "Earthquake";
}

Earthquake::~Earthquake()
{
	printf("%s has ended.\n", name_);
}

void Earthquake::warn()
{
	printf("Warning! %s approaching!\n", name_);
}
