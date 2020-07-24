#include <algorithm>
#include <vector>

class FunctionPart {
	friend class Function;

	FunctionPart(char op, double value) {
		this->op = op;
		this->value = value;
	}

	double apply(double value) const {
		if (this->op == '+') {
			return value + this->value;
		}
		return value - this->value;
	}

	void invert() {
		if (op == '+') {
			op = '-';
		} else {
			op = '+';
		}
	}
	
	char op;
	double value;
};

class Function {
public:
	Function() = default;

	void AddPart(char op, double value) {
		parts.push_back({op, value});
	}

	double Apply(double value) const {
		for (const auto& p : parts) {
			value = p.apply(value);
		}
		return value;
	}

	void Invert() {
		for (auto& p : parts) {
			p.invert();
		}
		
		std::reverse(parts.begin(), parts.end());
	}
private:
	std::vector<FunctionPart> parts;
};
