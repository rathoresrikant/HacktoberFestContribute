function removeSubstring(string, substring) {
	return string.replace(new RegExp(substring, 'g'), '');
}
