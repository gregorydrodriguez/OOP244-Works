#include <iostream>
using namespace std;
class  Container
{
	unsigned volume;
	unsigned capacity;// fixed

public:
	Container( unsigned v , unsigned ca) {
		capacity = ca;
		volume = v;
	}
	bool isEmpty() const{
		return volume > 0 ? false : true;
	}
	//unsigned int getvolume() const{
	//	return volume;

	//}
	//unsigned int getCapacity() const{
	//	return capacity;

	//}
	ostream& display(ostream& ostr = cout) {
		ostr << "Container VOL: " << volume << " Cap :" << capacity;
		return ostr;
	}
	void add(int v) {
		if (volume + v <= capacity) {
			volume += v;
		}
		else {
			volume = capacity;
		}
	}

	void operator+=(unsigned int v) {
		if (volume + v <= capacity) {
			volume += v;
		}
		else {
			volume = capacity;
		}
	}

	operator bool() const{// casting container to bool 
		return isEmpty();
	}

	operator int() const {
		return volume;
	}


	Container& operator++(int) { // oil++
		Container tem = *this;
		volume++;

		return tem;
	}
	Container& operator++() { //  ++oil
		volume++;
		return *this;
	}
	friend	Container operator+(const Container& a, const Container& b);
	friend Container operator+(const Container& a, int RO);
};

Container operator+(const Container& a, const Container& b) {
	Container newContainer(a.volume + b.volume, a.capacity + b.capacity);
	return newContainer;
}// copying 

Container operator+(const Container& a, int RO) {
	if (a.volume + RO <= a.capacity) {
		return Container (a.volume + RO, a.capacity);
	}
	else {
		return Container(0, 0);
	}
}


int main() {
	Container darkoil(200, 3000);
	Container whiltoil(500, 2000);
	
	Container allOil = darkoil + whiltoil;
	Container newOilContainer = allOil + 200;




	int a = int(whiltoil + darkoil);

	bool isempty = bool(darkoil);

	if (!darkoil) {
		darkoil.display();
	}


	newOilContainer.display();
	
	return 0;
}