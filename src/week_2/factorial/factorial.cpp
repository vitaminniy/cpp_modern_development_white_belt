int Factorial(int n) {
	if (n <= 1) {
		return 1;
	}

	int result = 1;
	while(n > 0) {
		result *= n;
		--n;
	}

	return result;
}
