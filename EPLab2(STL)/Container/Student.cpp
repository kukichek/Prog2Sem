#include"Student.h"

istream& operator>> (std::istream &in, Student &_stud) {
	in >> _stud.name >> _stud.group >> _stud.ball;
	return in;
}

ostream& operator<< (std::ostream &out, Student &_stud) {
	out << _stud.name << '\t' << _stud.group << '\t' << _stud.ball;
	return out;
}