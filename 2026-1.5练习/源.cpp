string convertToTitle(int columnNumber)
{
    string row;
    while (columnNumber)
    {
        int remainder = columnNumber % 26;
        if (remainder == 0)//如果余数是0，就像上一位借个1（26）出来，让余数强行等于26
        {
            remainder = 26;
            columnNumber -= 26;
        }
        row.push_back(remainder + 64);
        columnNumber /= 26;
    }
    reverse(row.begin(), row.end());
    return row;
}
