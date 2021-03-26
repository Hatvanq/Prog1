#include "std_lib_facilities.h"

struct Person{

	Person() { };
	Person(string f_name, string l_name, int age);

	string name() const {return first_name + " " + last_name; }

	string f_name() const { return first_name; }

	string l_name() const { return last_name; }

	int age() const {return m_age; } 


private:
	string first_name;
	string last_name;
	int m_age = 0;
};

Person::Person(string f_name, string l_name, int age){
	if(age < 0 || age > 150)
		error("It's not a valid age!");
	else
		m_age = age;

	string test_name = f_name + l_name;
	for(char c : test_name)
		switch(c){
			case ';' :
			case ':' :
			case '"' :
			case '\'' :
			case '[' :
			case ']' :
			case '*' :
			case '&' :
			case '^' :
			case '%' :
			case '$' :
			case '#' :
			case '@' :
			case '!' :
				error("Invalid name!");
				break;
			default:
				first_name = f_name;
				last_name = l_name;
				break;
			}

}

istream& operator>>(istream &is, Person &p)
{
	int is_age;
	string is_f_name;
	string is_l_name;

	is >> is_f_name >> is_l_name >> is_age;
	p = Person{is_f_name, is_l_name, is_age};

	return is;
}

ostream& operator<<(ostream &os, Person p)
{
	os << p.name() << " " << p.age() << endl;

	return os;
}

int main()
{
	Person someone{"Goofy", "Aladar", 0};
	cout << someone;
	
	cout << "Enter some names, if you're done type 'end' !\n";
	vector <Person> Vec_person;
	while(cin >> someone)
		Vec_person.push_back(someone);

	for(Person p : Vec_person)
		cout << p << endl;

	return 0;
}