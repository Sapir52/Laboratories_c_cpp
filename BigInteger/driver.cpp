#include "header.h" 

int main() 
{
	BigInteger a("2837456897658923563425345");

	BigInteger b("23784623874623874682736478236");
	
	BigInteger c =a + b;//c = 23787461331521533606299903581 

	c/= "4237467864237846"; // c = 5613602767887 

	BigInteger d = a*b-c; // a * b = 67487845071274625617593006636994700498265622203291420        
						  // a * b - c = 67487845071274625617593006636994700498260008600523533 

	std::cout << "c= " << c << std::endl;
	std::cout <<"d= "<< d << std::endl;

	return 0;
}
