string addStrings(string num1, string num2)
{
	string output = "";
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	int num1len = num1.length();
	int num2len = num2.length();
	if (num1len <= num2len)
	{
		swap(num1, num2);
		swap(num1len, num2len);
	}
	int carry = 0;
	for (int i = 0; i < num2len; ++i)
	{
		int numdigit = (num1[i]-'0')+(num2[i]-'0')+carry;
		output += to_string((numdigit) % 10);
		carry = numdigit < 10 ? 0 : 1;
	}

	for (int i = num2len; i < num1len; ++i)
	{
		int numdigit = (num1[i] - '0') + carry;
		output += to_string((numdigit) % 10);
		carry = numdigit < 10 ? 0 : 1;
	}
	if (carry)
	{
		output += '1';
	}
	reverse(output.begin(), output.end());
	return output;
}