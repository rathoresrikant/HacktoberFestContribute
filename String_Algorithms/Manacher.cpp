// d1[i]  and d2[i], denoting the number of palindromes accordingly with odd and even lengths with centers in the position i.

vector<int> d1(n);
for (int i = 0, l = 0, r = -1; i < n; i++) {
	int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
	while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
		k++;
	}
	d1[i] = k--;
	if (i + k > r) {
		l = i - k;
		r = i + k;
	}
}

vector<int> d2(n);
for (int i = 0, l = 0, r = -1; i < n; i++) {
	int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
	while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
		k++;
	}
	d2[i] = k--;
	if (i + k > r) {
		l = i - k - 1;
		r = i + k ;
	}
}