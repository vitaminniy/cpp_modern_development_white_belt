#include <iostream>
#include <map>

// NOTE(vitaminniy): а как в плюсах вообще принято обрабатывать ошибки?
// - try-catch?
// - return int?

// NOTE(vitaminniy): простите меня, потомки, за подобный код. Я только начал
// учить сей язык, и еще не знаю его идиом.

// NOTE(vitaminniy): по-хорошему, ни одна из функций кроме `dump` не должна
// иметь такое чудо, как работу с IO. Я бы сделал что-то типа:
// - return std::string
// - return int
// и, возможно, std::vector<std::string> dump вместо void, но позволю себе
// забить хуй, т.к. это всего лишь обучение/изучение языка, а "правильно" я
// буду делать на работе и в других проектах.

void change_capital(std::map<std::string, std::string>& capitals,
				   const std::string& country,
				   const std::string& new_capital);

void rename(std::map<std::string, std::string>& captials,
			const std::string& old_name,
			const std::string& new_name);

void about(const std::map<std::string, std::string>& capitals,
		   const std::string& country);

void dump(const std::map<std::string, std::string>& capitals);

int main() {
	int nqueries = 0;
	std::cin >> nqueries;

	std::map<std::string, std::string> capitals;
	for (int i = 0; i < nqueries; i++) {
		std::string query;
		std::cin >> query;

		// NOTE(vitaminniy): данный код вызывает во мне ненависть, т.к.
		// гораздо проще делать switch по query, но, сука, не в плюсах.
		//
		// В плюсах switch работает по int-ам, т.е. мне нужно считать хэш от
		// query, и при этом иметь константы с посчитанными в compile-time
		// хэшами, а это constexpr функции (нахуя я про это знаю?) расчета хэша
		// от строки.
		//
		// Казалось бы, все должно быть просто, но нет.
		//
		// P.S.: Возможно (скорее всего), существует простое и элегантное
		// решение данной проблемы. Особо я не искал, но что есть, так это:
		// https://habr.com/ru/post/166201

		if (query == "CHANGE_CAPITAL") {
			std::string country, new_capital;
			std::cin >> country >> new_capital;
			change_capital(capitals, country, new_capital);

			continue;
		}

		if (query == "RENAME") {
			std::string old_name, new_name;
			std::cin >> old_name >> new_name;
			rename(capitals, old_name, new_name);

			continue;
		}
		
		if (query == "ABOUT") {
		   std::string country;
		   std::cin >> country;
		   about(capitals, country);

		   continue;
		}

		if (query == "DUMP") {
			dump(capitals);

			continue;
		}
	}

	return 0;
}

void change_capital(std::map<std::string, std::string>& capitals,
				   const std::string& country,
				   const std::string& new_capital) {
	if (capitals.count(country) == 0) {
		capitals[country] = new_capital;
		std::cout << "Introduce new country " << country << " with capital "
				  << new_capital << std::endl;
		return;
	}

	std::string old_capital = capitals[country];
	if (old_capital == new_capital) {
		std::cout << "Country " << country << " hasn't changed its capital"
				  << std::endl;
		return;
	}

	capitals[country] = new_capital;
	std::cout << "Country " << country << " has changed its capital from "
			  << old_capital << " to " << new_capital << std::endl;
}

void rename(std::map<std::string, std::string>& capitals,
			const std::string& old_name,
			const std::string& new_name) {
	if ((old_name == new_name)
		|| (capitals.count(old_name) == 0)
		|| (capitals.count(new_name) == 1)) {
		std::cout << "Incorrect rename, skip" << std::endl;
		return;
	}

	std::string capital = capitals[old_name];
	capitals.erase(old_name);
	capitals[new_name] = capital;

	std::cout << "Country " << old_name << " with capital " << capital
			  << " has been renamed to " << new_name << std::endl;
}


void about(const std::map<std::string, std::string>& capitals,
		   const std::string& country) {
	if (capitals.count(country) == 0) {
		std::cout << "Country " << country << " doesn't exist" << std::endl;
		return;
	}

	// NOTE(vitaminniy): o, kurwa!
	//
	// Т.к. std::map::operator[] (надеюсь, не объебался в синтаксисе)
	// НЕ является константным, то использовать его мы не можем, иначе будет
	// создана запись в словаре, что вызовет нарушение константности.
	// Но мы-то уже проверили, что такой ключ существует => используем
	// std::map::at(const T&) (надеюсь, не объебался в синтаксисе [2]).
	std::string capital = capitals.at(country);
	std::cout << "Country " << country << " has capital " << capital
			  << std::endl;
}

void dump(const std::map<std::string, std::string>& capitals) {
	if (capitals.size() == 0) {
		std::cout << "There are no countries in the world" << std::endl;
		return;
	}

	for (const auto& [country, capital] : capitals) {
		std::cout << country << "/" << capital << " ";
	}

	std::cout << std::endl;
}
