#pragma once
template <typename T1,typename T2>
class Compare
{
public:
		T1 a;
		T2 b;
		Compare(T1 first, T2 second) : a(first), b(second) {}
		T1 Min()
		{
			return (a < b) ? a : b;
		}
};

