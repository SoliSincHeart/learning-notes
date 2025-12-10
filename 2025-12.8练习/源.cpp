int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}


//ax+by=gcd(a,b)
int xGCD(int a, int b, int& x, int& y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	int x1, y1, gcd = xGCD(b, a % b, x1, y1);
	x = y1, y = x1 - (a / b) * y1;
	return gcd;
}