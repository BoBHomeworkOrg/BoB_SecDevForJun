#include "pch.h"
#include "ClassA.h"

void ClassA::Func(ClassB* p)
{
	printf("hello world\n");
	p->Func(this);
}
