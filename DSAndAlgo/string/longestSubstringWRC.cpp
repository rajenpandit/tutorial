/*
* Find longest substring length without repeating characters.
* input: abcabcbac
* output: 3
*/

#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

namespace solution1 {
	class LongestSubstringWRC {
		public:
			static unsigned int length(const std::string& s) {
				std::cout << __PRETTY_FUNCTION__ << " = ";

				int n=s.size();
				vector<int> map(256,-1);
				int res=0,count=0;
				for(int i=0;i<n;i++){
					if(map[s[i]]<i-count){
						count++;
					}
					else{
						count=i-map[s[i]];
					}
					res=max(count,res);
					map[s[i]]=i;
				}
				return res;
			}
	};
}

namespace solution2 {
	class LongestSubstringWRC {
		public:
			static unsigned int length(const std::string& s) {
				std::cout << __PRETTY_FUNCTION__ << " = ";

				std::set<char> charSet;
				int i1 = 0;
				int longestSubstringLength = 0;
				for (int i=0; i<s.length(); ++i) {
					if (charSet.find(s.at(i)) == charSet.end()) {
						charSet.insert(s.at(i));
						unsigned int diff = i + 1 - i1;
						if ( diff > longestSubstringLength) {
							longestSubstringLength = diff;
						}
					}
					else {
						while (s.at(i1) != s.at(i)) {
							charSet.erase(s.at(i1));
							i1++;
						} 
						i1++;
					}
				}
				return longestSubstringLength;
			}
	};
}

using namespace solution1;

std::string testStr[] = {
	"abcabcba",
	"acbdabda",
	"pwwkew",
	"pwwk"
};
int main() {
	for(auto s : testStr) {
		std::cout << s << " => using function " << LongestSubstringWRC::length(s) << std::endl;
	}
}
