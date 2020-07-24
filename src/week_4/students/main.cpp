#include <iostream>
#include <string>
#include <vector>

struct Birth {
	int day = 1;
	int month = 1;
	int year = 1970;
};

struct Student {
	std::string name;
	std::string surname;
	Birth birth;
};

void print_name(const Student& s, std::ostream& output) {
	output << s.name << ' ' << s.surname << std::endl;
}

void print_birth(const Birth& b, std::ostream& output) {
	output << b.day << '.' << b.month << '.' << b.year << std::endl;
}

int main() {
	int nstudents = 0;
	std::cin >> nstudents;

	std::vector<Student> students(nstudents);
	for (auto& s : students) {
		std::cin >> s.name >> s.surname >> s.birth.day >> s.birth.month
				 >> s.birth.year;
	}

	int nrequests = 0;
	std::cin >> nrequests;

	std::string query;
	int idx;
	for (int i = 0; i < nrequests; i++) {
		std::cin >> query >> idx;
		
		if (idx > 0 && idx <= students.size()) {
			auto s = students[idx-1];

			if (query == "name") {
				print_name(s, std::cout);
				continue;
			}

			if (query == "date") {
				print_birth(s.birth, std::cout);
				continue;
			}
		}
		
		std::cout << "bad request" << std::endl;
	}
}
