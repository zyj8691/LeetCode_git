/**
����һ�����ַ�����ʾ�ķǸ����� num���Ƴ�������е� k λ���֣�ʹ��ʣ�µ�������С��

ע��:

num �ĳ���С�� 10002 �� �� k��
num ��������κ�ǰ���㡣
ʾ�� 1 :

����: num = "1432219", k = 3
���: "1219"
����: �Ƴ����������� 4, 3, �� 2 �γ�һ���µ���С������ 1219��
ʾ�� 2 :

����: num = "10200", k = 1
���: "200"
����: �Ƶ���λ�� 1 ʣ�µ�����Ϊ 200. ע������������κ�ǰ���㡣
ʾ�� 3 :

����: num = "10", k = 2
���: "0"
����: ��ԭ�����Ƴ����е����֣�ʣ��Ϊ�վ���0��
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
			int number = num[i] - '0';//���ַ��͵�numת��Ϊ����ʹ��
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