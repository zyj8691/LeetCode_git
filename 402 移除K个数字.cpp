/**
给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。

注意:

num 的长度小于 10002 且 ≥ k。
num 不会包含任何前导零。
示例 1 :

输入: num = "1432219", k = 3
输出: "1219"
解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。
示例 2 :

输入: num = "10200", k = 1
输出: "200"
解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
示例 3 :

输入: num = "10", k = 2
输出: "0"
解释: 从原数字移除所有的数字，剩余为空就是0。
*/
/**
class Solution {
public:
    string removeKdigits(string num, int k) {
        
    }
};
*/

class Solution {
public:
	std::string removeKdigits(std::string num, int k) {
		std::vector<int>S;
		std::string result = "";
		for (int i = 0; i < num.length(); i++){
			int number = num[i] - '0';//将字符型的num转化为整数使用
			while (S.size() != 0 &&number<S[S.size()-1] &&k>0){
				S.pop_back();
				k--;
			}
			if (number!=0||S.size()!=0){
				S.push_back(number);
			}
		}
		while (S.size() != 0 && k > 0){
			S.pop_back();
			k--;
		}
		for (int i = 0; i < S.size(); i++){
			result.append(1,'0'+S[i]);
		}
		if (result == ""){
			result = "0";
		}
		return result;
	}
};
int main()
{ 
	Solution solve;
	std::string result = solve.removeKdigits("1432219", 3);
	printf("%s\n", result.c_str());
	std::string result2 = solve.removeKdigits("100200", 1);
	printf("%s\n", result2.c_str());
	return 0;

}