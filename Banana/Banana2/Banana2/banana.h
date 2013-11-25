#ifndef _BANANA_H_ 
#define _BANANA_H_ 
#include <string.h> 
#include <iostream> 

 
class Banana 
{ 
public: 

	Banana& operator = (const Banana& from) 
	{
		if(&from != this)
		{
			strcpy(m_Name, from.m_Name);
			strcpy(m_Saying, from.m_Saying);
			strcpy(m_Unit, from.m_Unit);
			m_Weight = from.m_Weight;

			return *this;
		}
	}

	 Banana() 
	 { 
		 m_Name = new char[16]; 
		 m_Saying = new char[256]; 
		 m_Unit = new char[16]; 
		 m_Weight = 120.0f; 
		 strcpy( m_Name, "Banana " ); 
		 strcpy( m_Saying, "Bananas are good for you, they are full of potassium!" ); 
		 strcpy( m_Unit, "grams" ); 
	} 
	 Banana(int test)
	 {
		 m_Name = new char[16]; 
		 m_Saying = new char[256]; 
		 m_Unit = new char[16]; 
		 m_Weight = 0.0f;
	 }
	 Banana(const Banana& from)
	 {
		m_Name = new char[16]; 
		m_Saying = new char[256]; 
		m_Unit = new char[16]; 

		strcpy(m_Name, from.m_Name);
		strcpy(m_Saying, from.m_Saying);
		strcpy(m_Unit, from.m_Unit);
		m_Weight = from.m_Weight;
	 }
	 ~Banana() 
	 {} 
 
	void Display() 
	 { 
		std::cout << m_Name << "is awesome. " << m_Saying << std::endl; 
		std::cout << "This " << m_Name << " weighs " << m_Weight << " " << m_Unit << std::endl; 
	 } 



private: 
	 char *m_Name; 
	 char *m_Saying; 
	 float m_Weight; 
	 char *m_Unit; 
}; 
 
#endif 