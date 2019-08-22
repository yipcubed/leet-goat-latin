#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

// https://leetcode.com/problems/goat-latin/

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:

  bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
  }
  string toGoatLatin(string S) {
    istringstream is(S);
    ostringstream os;
    string word;
    string as = "a";
    while (is >> word) {
      if (isVowel(word[0])) {
        os << word;
      } else {
        os << word.substr(1, word.size() - 1) << word[0];
      }
      os << "ma";
      os << as << " ";
      as += "a";
    }
    word = os.str();
    word = word.substr(0, word.size() - 1);
    return word;
  }
};

void test1() {
  string s = "I speak Goat Latin";

  cout << "Imaa peaksmaaa oatGmaaaa atinLmaaaaa? \n" << Solution().toGoatLatin(s) << "--<" << endl;

  s = "The quick brown fox jumped over the lazy dog";

}

void test2() {

}

void test3() {

}