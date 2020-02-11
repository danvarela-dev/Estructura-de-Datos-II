#include "Person.h"

int main() {
	Person person;
	person.save_Registry();
	person.readFile("Persons.dat");

}