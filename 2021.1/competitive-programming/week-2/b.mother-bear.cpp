#include <iostream>
#include <stack>
#include <string>

bool check_palindrome(std::string* sentence,
                      std::stack<char>* reverse_sentence) {
  for (int i = 0; i < sentence->size(); i++) {
    char current_char = (*sentence)[i];
    char reverse_char = reverse_sentence->top();
    reverse_sentence->pop();

    if (current_char != reverse_char) {
      return false;
    }
  }

  return true;
}

int main(void) {
  std::string sentence;
  std::stack<char> reverse_sentence;

  while (std::getline(std::cin, sentence)) {
    if (sentence == "DONE") return 0;

    for (int i = 0, len = sentence.size(); i < len; i++) {
      // convert to lowercase
      sentence[i] = std::tolower(sentence[i]);
      // remove pontuactions
      if (ispunct(sentence[i]) || sentence[i] == ' ') {
        sentence.erase(i--, 1);
        len = sentence.size();
      } else {
        reverse_sentence.push(sentence[i]);
      }
    }

    if (check_palindrome(&sentence, &reverse_sentence)) {
      std::cout << "You won't be eaten!" << std::endl;
    } else {
      std::cout << "Uh oh.." << std::endl;
    }
  }

  return 0;
}