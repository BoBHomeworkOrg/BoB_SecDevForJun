#include "pch.h"
#include "ClassB.h"
#include "ClassA.h"

void ClassB::Func(ClassA* p)
{
	printf("hello world\n");
	p->Func(this);
}
