#ifndef __DOSEN_HPP__
#define __DOSEN_HPP__

#include <iostream>
#include "include/person.hpp"

class dosen : public person {
private:
	std::string npp;
	std::string departemen;
	std::string pendidikan;
	std::string matkulajar;

public:
	dosen(std::string id, std::string nama, int dd, int mm, int yy, std::string npp, std::string departemen, std::string pendidikan, std::string matkulajar);

	void setPendidikan(std::string pendidikan);
	std::string getPendidikan();

	void setNPP(std::string npp);
	std::string getNPP();

	void setDepartemen(std::string departemen);
	std::string getDepartemen();

	void setMatkulAjar(std::string matkulajar);
	std::string getMatkulAjar();
};

#endif 
