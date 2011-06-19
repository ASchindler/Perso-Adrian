#include<iostream>
#include<stdint.h>

main()
{

std::cout << "char size              : " << 8*sizeof(char) <<std::endl;
std::cout << "short size             : " << 8*sizeof(short) <<std::endl;
std::cout << "short int size         : " << 8*sizeof(short int) <<std::endl;
std::cout << "unsigned size          : " << 8*sizeof(unsigned) <<std::endl;
std::cout << "int size               : " << 8*sizeof(int) <<std::endl;
std::cout << "long int size          : " << 8*sizeof(long int) <<std::endl;
std::cout << "long size              : " << 8*sizeof(long) <<std::endl;
std::cout << "unsigned long int size : " << 8*sizeof(unsigned long int) <<std::endl;
std::cout << "long long int size     : " << 8*sizeof(long long int) <<std::endl;
std::cout << "long long size         : " << 8*sizeof(long long) <<std::endl;
std::cout << "float size             : " << 8*sizeof(float) <<std::endl;
std::cout << "double size            : " << 8*sizeof(double) <<std::endl;
std::cout << "#########################" << std::endl;
std::cout << "void*  size            : " << 8*sizeof(void* ) <<std::endl;
std::cout << "size_t size            : " << 8*sizeof(size_t) <<std::endl;
std::cout << "int16_t size           : " << 8*sizeof(int16_t) <<std::endl;
std::cout << "int32_t size           : " << 8*sizeof(int32_t) <<std::endl;
std::cout << "int64_t size           : " << 8*sizeof(int64_t) <<std::endl;
std::cout << "uint16_t size          : " << 8*sizeof(uint16_t) <<std::endl;
std::cout << "uint32_t size          : " << 8*sizeof(uint32_t) <<std::endl;
std::cout << "uint64_t size          : " << 8*sizeof(uint64_t) <<std::endl;
std::cout << "intptr_t size          : " << 8*sizeof(intptr_t) <<std::endl;
std::cout << "uintptr_t size         : " << 8*sizeof(uintptr_t) <<std::endl;
//std::cout << "ulong                  : " << 8*sizeof(ulong) <<std::endl;
}
