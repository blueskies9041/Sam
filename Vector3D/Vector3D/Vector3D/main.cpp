#include <iostream>
#include "Vector3D.h"

using namespace std;

void PrintVector(Vector3D a_v3Print)
{
	cout << a_v3Print.m_fX << " " << a_v3Print.m_fY << " " << a_v3Print.m_fZ << endl;
}

int main()
{
	Vector3D a(12.0f, 2.0f, 0.5f);
	Vector3D b(4.0f, 5.0f, -0.5f);
	Vector3D c(a);
	Vector3D d;
	Vector3D e(a);
	Vector3D f(a);
	Vector3D g(a);
	Vector3D h(a);
	Vector3D i(0.0f, 0.0f, 2.0f);
	//Constructors
	PrintVector(a); //creation
	PrintVector(b); 
	PrintVector(c); //copy
	PrintVector(d); //empty

	cout << endl;
	//Operators + - * /
	PrintVector(a+b); //+
	PrintVector(a-b); //-
	PrintVector(a * 0.5f); //*
	PrintVector(a / 2.0f); // /

	cout << endl;
	//Operators += -= *= /=
	e += a;
	PrintVector(e);
	f -= a;
	PrintVector(f);
	g *= 1.2f;
	PrintVector(g);
	h /= 2.0f; 
	PrintVector(h);

	cout << endl;
	//Functions
	cout << i.Magnitude() << endl;
	i.Normalize();
	cout << i.Magnitude();
	PrintVector(a.GetNormal());
	cout << a.GetNormal().Magnitude() <<endl;
	cout << 



	

	cout << endl;
	system("pause");
	return 0;
}