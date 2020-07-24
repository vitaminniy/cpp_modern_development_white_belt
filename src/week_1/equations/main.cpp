#include <iostream>
#include <cmath>

/* Cases
 * No output:
 * 0 0 1
 * 1 0 4
 * 2 1 2
 *
 * With output:
 * 2 5 2  => -0.5 1
 * 2 4 2  => -1
 * 0 4 10 => -2.5
 * 1 0 -4 => 2 (-2)
 * 1 -4 0 => 4 0
 * 1 4 0  => -4 0
 */

// NOTE: x in R.
int main() {
	double a = 0, b = 0, c = 0;
	std::cin >> a >> b >> c;
	
	if ((a == 0) && (b == 0))
		return 0;

	if (a == 0) {
		std::cout << (double(-c)/b) << std::endl;

		return 0;
	}

	const int discriminant = std::pow(b, 2) - (4 * a * c);
	if (discriminant < 0) {
		return 0;
	}

	if (discriminant == 0) {
		double x = (double(-b - std::sqrt(discriminant))/(2 * a));
		std::cout << x << std::endl;

		return 0;
	}

	double x1 = (double(-b + std::sqrt(discriminant))/(2 * a));
	double x2 = (double(-b - std::sqrt(discriminant))/(2 * a));
	std::cout << x1 << " " << x2 << std::endl;

	return 0;
}

