#include <iostream>
#include <string>
#include <windows.h>
bool is_mark(char);
size_t word_size(size_t,size_t,std::string&);
void plus_word(const std::string&, std::string&, size_t, size_t);
int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	std::string str{};
	std::cout << "Enter your string" << std::endl;
	std::getline(std::cin, str);
	size_t size = str.size();
	size_t max_length = 0;
	size_t word_start = 0;
	size_t temp = 0;
	size_t word_end = 0;
	std::string word{};
	for (size_t i = 0; i < size; i++) {
		if (is_mark(str[i]) == 0) {
			word_start = i;
			while (i < size && is_mark(str[i]) == 0) {
				i++;
			}
			word_end = i;
			temp = word_size(word_start, word_end, str);
			if (temp > max_length) {
				max_length = temp;
			}
			i--;
		}
	}
	std::string answer{};
	for (size_t j = 0; j < size; j++) {
		if (is_mark(str[j]) == 0) {
			word_start = j;
			while (j < size && is_mark(str[j]) == 0) {
				j++;
			}
			word_end = j;
			temp = word_size(word_start, word_end, str);
			if (temp == max_length) {
				plus_word(str, answer, word_start, word_end);
			}
		}
	}
	std::cout << answer;
}
bool is_mark(char sym) {
	if (sym >= 'A' && sym <= 'Z') { return false; }
	if (sym >= 'a' && sym <= 'z') { return false; }
	if (sym >= '0' && sym <= '9') { return false; }
	unsigned char usym = static_cast<unsigned char>(sym);
	if (usym >= 192 && usym <= 223 && usym != 215) { return false; }
	if (usym >= 224 && usym <= 255 && usym != 247) { return false; }
	if (usym == 168 || usym == 184) { return false; }
	else
	return true;
}
size_t word_size(size_t word_start,size_t word_end,std::string& str) {
	std::string word{};
	size_t size = word_end - word_start;
	word.resize(size);
	for (size_t temp = 0; temp < size; temp++) {
		word[temp] = str[temp + word_start];
	}
	for (size_t i = 0; i < size; i++) {
		for (size_t j = i + 1; j < size;) {
			if (word[i] == word[j]) {
				word.erase(j, 1);
				size--;
			}
			else j++;
		}
	}
	return word.size();
}
void plus_word(const std::string& str, std::string& answer, size_t word_start, size_t word_end) {
	for (size_t i = word_start; i < word_end; i++) {
		answer += str[i];
	}
	answer = answer + ' ';
}