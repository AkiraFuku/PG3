#include "Storm.h"

#include <stdio.h>
Storm::Storm()
{
	name_ = "Storm";
}

Storm::~Storm()
{
	printf("%s has ended.\n", name_);
}

void Storm::warn()
{
	printf("Warning! %s approaching!\n", name_);
}
