#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <iomanip>
#include <stack>
using namespace std;
const int maxnlen = 1e4;

class Grammar {
private:
	set<char>Vn;
	set<char>Vt;
	char S;
	map<char, set<string> > P;
	map<char,set<char> >FIRST;
	map<char,set<char> >FOLLOW;
	map<string, string>Table;
public:
	Grammar(string filename) {
		Vn.clear();
		Vt.clear();
		P.clear();
		FIRST.clear();
		FOLLOW.clear();
		ifstream in(filename);
		if (!in.is_open()) {
			cout << "文法  文件打开失败" << endl;
			exit(1);
		}
		char *buffer = new char[maxnlen];
		in.getline(buffer, maxnlen, '#');
		string temps = "";
		bool is_sethead = 0;
		for (int i = 0; i < strlen(buffer); i++) {
			if (buffer[i] == '\n' || buffer[i] == ' ')continue;
			if (buffer[i] == ';') {
				if (!is_sethead) {
					this->setHead(temps[0]);
					is_sethead = 1;
				}
				this->add(temps);
				temps = "";
			}
			else
				temps += buffer[i];
		}
		delete buffer;
		/*
			输出Vn，Vt，set
			
		*/
		
	}
	void setHead(char c) {
		S = c;
	}
	void add(string s) {
		char s1 = s[0];
		string s2="";
		int num = 0;
		for (int i = 0; i < s.length() ; i++) {
			if (s[i] == '>')num=i;
			if (num == 0)continue;
			if (i > num)
				s2 += s[i];
		}
		s2 += ';';
		Vn.insert(s1);
		string temp = "";
		for (char s : s2) {
			if (!isupper(s) && s != '|'&&s != ';'&&s!='@')Vt.insert(s);
			if (s == '|' || s == ';') {
				P[s1].insert(temp);
				temp = "";
			}
			else {
				temp += s;
			}
		}
	}
	void print() {
		cout << "当前分析文法为：" << endl << endl;
		for (set<char>::iterator it = Vn.begin(); it != Vn.end(); it++) {
			char cur_s = *it;
			for (set<string>::iterator it1 = P[cur_s].begin(); it1 != P[cur_s].end(); it1++) {
				string cur_string = *it1;
				cout << cur_s << "->" << cur_string << endl;
			}
		}
	}
	void getFirst() {
		FIRST.clear();
		//判断迭代次数
		int iter = 4;
		while (iter--) {
			for (set<char>::iterator it = Vn.begin(); it != Vn.end(); it++) {
				char cur_s = *it;
				/*
				cur_s->cur_string[0]
					a加到A的FIRST集
				cur_s->cur_string[0]
					B的FITRST集加到A的FIRST集
				*/
				for (set<string>::iterator it1 = P[cur_s].begin(); it1 != P[cur_s].end(); it1++) {
					string cur_string = *it1;
					if (!isupper(cur_string[0])) {
						FIRST[cur_s].insert(cur_string[0]);
					}
					else {
						char nxt_s = cur_string[0];
						for (set<char>::iterator it2 = FIRST[nxt_s].begin(); it2 != FIRST[nxt_s].end(); it2++) {
							if ((*it2) != '@') {
								FIRST[cur_s].insert(*it2);
							}
						}
					}
				}
			}
		}
		//输出FIRST集
		cout << "FIRST集为：" << endl << endl;
		for (set<char>::iterator it = Vn.begin(); it != Vn.end();it++) {
			char cur_s = *it;
			cout << "FIRST()   " << cur_s ;
			for (set<char>::iterator it1 = FIRST[cur_s].begin(); it1 != FIRST[cur_s].end(); it1++) {
				 cout<<"       " << *it1 ;
			}
			cout << endl;
		}
	}
	void getFollow() {
		FOLLOW.clear();
		FOLLOW[S].insert('#');
		//判断迭代次数
		int iter = 4;
		while (iter--) {
			for (set<char>::iterator it = Vn.begin(); it != Vn.end(); it++) {
				char cur_s = *it;
				/*
				cur_s->cur_string[0]
				a加到A的FIRST集
				cur_s->cur_string[0]
				B的FITRST集加到A的FIRST集
				*/
				for (set<string>::iterator it1 = P[cur_s].begin(); it1 != P[cur_s].end(); it1++) {
					string cur_string = *it1;
					for (int i = 0; i < cur_string.length() - 1; i++) {
						/*
							B->Ac
							将c加到A的follow集
						*/
						if (isupper(cur_string[i]) && !isupper(cur_string[i + 1])) {
							FOLLOW[cur_string[i]].insert(cur_string[i + 1]);
						}
						/*
							B->AC
							将C的first集加到A的follow集
						*/
						if (isupper(cur_string[i]) && isupper(cur_string[i + 1])) {
							//遍历C的first去除@，加到A的follow集
							for (auto it2 = FIRST[cur_string[i + 1]].begin(); it2 != FIRST[cur_string[i + 1]].end(); it2++) {
								if((*it2)!='@')
								FOLLOW[cur_string[i]].insert(*it2);
							}
						}
						
					}
					/*
					AC/ACK为最后两个或者三个
					B->AC
					B->ACK(K的first集含有@)
					将B的follow集加入到C的follow集
					*/
					int len = cur_string.length();
					if ( (len>=1&&isupper(cur_string[len - 1])) ) {
						for (auto it2 = FOLLOW[cur_s].begin(); it2 != FOLLOW[cur_s].end(); it2++) {
							if(isupper(cur_string[len - 1]))
								FOLLOW[cur_string[len - 1]].insert(*it2);
						}
					}
					if ((len >= 2 && isupper(cur_string[len - 2]) && isupper(cur_string[len - 1]) && FIRST[cur_string[len - 1]].count('@') > 0)) {
						for (auto it2 = FOLLOW[cur_s].begin(); it2 != FOLLOW[cur_s].end(); it2++) {	
							FOLLOW[cur_string[len - 2]].insert(*it2);
						}
					}
				}
			}
		}
		//输出FOLLOW集
		cout << "FOLLOW集为：" << endl << endl;
		for (set<char>::iterator it = Vn.begin(); it != Vn.end(); it++) {
			char cur_s = *it;
			cout << "FOLLOW()  " << cur_s;
			for (set<char>::iterator it1 = FOLLOW[cur_s].begin(); it1 != FOLLOW[cur_s].end(); it1++) {
				cout << "       " << *it1;
			}
			cout << endl;
		}
	}
	void getTable() {
		set<char>Vt_temp;
		for (char c : Vt) {
			Vt_temp.insert(c);
		}
		Vt_temp.insert('#');
		for (auto it = Vn.begin(); it != Vn.end(); it++) {
			char cur_s = *it;
			for (auto it1 = P[cur_s].begin(); it1 != P[cur_s].end(); it1++) {
				/*
				产生式为
					cur_s->cur_string
				*/
				string cur_string = *it1;
				if (isupper(cur_string[0])) {
					char first_s = cur_string[0];
					for (auto it2 = FIRST[first_s].begin(); it2 != FIRST[first_s].end(); it2++) {
						string TableLeft = "";
						TableLeft = TableLeft +cur_s + *it2;
						Table[TableLeft] = cur_string;
					}
					
				}
				else {
					string TableLeft = "";
					TableLeft = TableLeft+ cur_s + cur_string[0];
					Table[TableLeft] = cur_string;
				}	
			}
			if (FIRST[cur_s].count('@') > 0) {
				for (auto it1 = FOLLOW[cur_s].begin(); it1 != FOLLOW[cur_s].end(); it1++) {
					string TableLeft = "";
					TableLeft =TableLeft+ cur_s + *it1;
					Table[TableLeft] = "@";
				}
			}
		}
		/*
			检查出错信息：即表格中没有出现过的
		*/
		
		
		for (auto it = Vn.begin(); it != Vn.end(); it++) {
			for (auto it1 = Vt_temp.begin(); it1 != Vt_temp.end(); it1++) {
				string TableLeft = "";
				TableLeft =TableLeft+ *it + *it1;
				if (!Table.count(TableLeft)) {
					Table[TableLeft] = "error";
				}
			}
		}
		
		/*
			显示Table
		*/
		cout << "显示table表：" << endl << endl;
		cout.setf(std::ios::left);
		for (auto it1 = Vt_temp.begin(); it1 != Vt_temp.end(); it1++) {
			if (it1 == Vt_temp.begin())cout << setw(10) << " ";
			cout << setw(10) << *it1;
		}
		cout << endl;
		for (auto it = Vn.begin(); it != Vn.end(); it++) {
			for (auto it1 = Vt_temp.begin(); it1 != Vt_temp.end(); it1++) {
				string TableLeft="";
				if (it1 == Vt_temp.begin())cout << setw(10) << *it;
				TableLeft =TableLeft+ *it + *it1;
				cout << *it << "->" << setw(7) << Table[TableLeft];
			}
			cout << endl;
		}
	}
	/*
		每一次分析一个输入串
		Sign为符号栈,出栈字符为x
		输入字符串当前字符为a
	*/
	bool AnalyzePredict(string inputstring){
		stack<char>Sign;
		Sign.push('#');
		Sign.push(S);
		int StringPtr = 0;
		char a = inputstring[StringPtr++];
		bool flag = true;
		while (flag) {
			char x = Sign.top();
			Sign.pop();
			//如果是终结符,直接移出符号栈
			if (Vt.count(x)) {
				if (x == a)a = inputstring[StringPtr++];
				else
					return false;
			}
			else {
				//如果不是终结符，
				//如果是末尾符号
				if (x == '#') {
					if (x == a)flag = false;
					else
						return false;
				}
				else {
					//如果是非终结符，需要移进操作
					string left = "";
					left += x;
					left += a;
					if (Table[left] != "error") {
						string right = Table[left];
//						cout << left << "---->" << right << endl;
						for (int i = right.length() - 1; i >= 0; i--) {
							Sign.push(right[i]);
						}
						
					}
					else {
						return false;
					}
				}
			}		
		}
		return true;
	}
	/*
		消除左递归
	*/
	void remove_left_recursion(){
		string tempVn = "";
		for (auto it = Vn.begin(); it != Vn.end(); it++) {
			tempVn += *it;
		}
		
		for (int i = 0; i < tempVn.length(); i++) {
			char pi = tempVn[i];
			set<string>NewPRight;
			for (auto it = P[pi].begin(); it != P[pi].end(); it++) {
				bool isget = 0;
				string right = *it;
				for (int j = 0; j < i; j++) {
					char pj = tempVn[j];
					if (pj == right[0]) {
						isget = 1;
						for (auto it1 = P[pj].begin(); it1 != P[pj].end(); it1++) {
							string s = *it1 + right.substr(1);
							NewPRight.insert(s);
						}
					}
				}
				if (isget == 0) {
					NewPRight.insert(right);
				}
			}
			/*
			for (int j = 0; j < i; j++) {
				char pj=tempVn[j];
				for (auto it = P[pi].begin(); it != P[pi].end(); it++) {
					string right = *it;
					if (right[0] == pj) {
						for (auto itpj = P[pj].begin(); itpj != P[pj].end(); itpj++) {
							string s = *itpj + right.substr(1);
							NewPRight.insert(s);
						}
					}
					else {
						NewPRight.insert(right);
					}
				}
			}
			*/
			if(i!=0)
				P[pi] = NewPRight;

			remove_left_gene(pi);
		}
	}
	/*
		提取左因子
	*/
	void remove_left_gene(char c) {
		char NewVn;
		for (int i = 0; i < 26; i++) {
			NewVn = i + 'A';
			if (!Vn.count(NewVn)) {
				break;
			}
		}
		bool isaddNewVn = 0;
		for (auto it = P[c].begin(); it != P[c].end(); it++) {
			string right = *it;
			
			if (right[0] == c) {
				isaddNewVn = 1;
				
				break;
			}
		}
		if (isaddNewVn) {
			set<string>NewPRight;
			set<string>NewPNewVn;
			for (auto it = P[c].begin(); it != P[c].end(); it++) {
				string right = *it;
				if (right[0] != c) {
					right += NewVn;
					NewPRight.insert(right);
				}
				else {
					right = right.substr(1);
					right += NewVn;
					NewPNewVn.insert(right);
				}
			}
			Vn.insert(NewVn);
			NewPNewVn.insert("@");
			P[NewVn] = NewPNewVn;
			P[c] = NewPRight;
		}
	}
	void ShowByTogether() {
		for (auto it = Vn.begin(); it != Vn.end(); it++) {
			cout << *it << "->";
			char c = *it;
			for (auto it1 = P[c].begin(); it1 != P[c].end(); it1++) {
				if (it1 == P[c].begin())cout << *it1;
				else
					cout << "|" << *it1;
					
			}
			cout << endl;
		}
	}
};
int main() {
	/*
	文法测试
	E->T|E+T;
	T->F|T*F;
	F->i|(E);

	A->+TA|@;
	B->*FB|@;
	E->TA;
	F->(E)|i;
	T->FB;
	直接将上面两个测试样例放在Gramar_test.txt中
	*/
	string filename_gramer = "D:\\c++Project\\fundamentals_of_compiling\\Parsing\\Gramar_test.txt";
    filename_gramer = "E:\\code\\university\\CS\\3\\编译原理\\实验\\in.txt";
	Grammar *grammar=new Grammar(filename_gramer);
	cout << "/-------------------------没有消除左递归-----------------------------/" << endl;
	cout << "规格显示：" << endl;
	grammar->ShowByTogether();
	cout << endl;
	grammar->getFirst();
	cout << endl;
	grammar->getFollow();
	cout << endl;
	grammar->getTable();
	
	cout << "/--------------------------------------------------------------------/" << endl<<endl<<endl;


	cout << "/-------------------------已经消除左递归-----------------------------/" << endl;
	/*
	消除左递归之后的判断
	*/
	grammar->remove_left_recursion();
	cout << "规格显示：" << endl;
	cout << endl;
	grammar->ShowByTogether();
	grammar->getFirst();
	cout << endl;
	grammar->getFollow();
	cout << endl;
	grammar->getTable();
	
	cout << "/--------------------------------------------------------------------/" << endl << endl << endl;
	cout << "/-------------------------对词法进行分析----------------------------/" << endl;
	/*
		目前的想法是使用第一个实验分离出不同的单词，对单词操作，
		如果单词为+，*，等于他本身，否则等于i;
		以下直接使用实验一的输出文本
	*/
	string filename= "D:\\c++Project\\fundamentals_of_compiling\\Parsing\\out.txt";
	ifstream in(filename);
	char buffer[200];
	string inf="";
	int num = 0;
//	cout << "文法分析结果为：" << endl << endl;
	if (in.is_open()) {
		while (!in.eof()) {
			in.getline(buffer, 100);
//			cout << buffer << endl;
			inf += buffer;
			num++;
		}
	}
	string row = "";
	for (int i = 0; i < num-1; i++) {
		int ptr = i * 13;
		string temp = "";
		for (int j = 1; j <= 5; j++) {
			if (inf[j+ptr] == ' ')continue;
			else
				temp += inf[ptr+j];
		}
		if (temp == "+" || temp == "-" || temp == "*" || temp == "/" || temp == ">" || temp == "<" || temp == "=" || temp == "(" || temp == ")") {
			row += temp;
		}
		else {
			if (temp == ";") {
				row += "#";
				cout << "当前row为:   " << row << endl;
				if (grammar->AnalyzePredict(row)) {
					cout << "                                         正确" << endl;
				}
				else
					cout << "                                         错误" << endl;
				row = "";
			}
			else {
				row += "i";
			}
		}
	}
	cout << "/--------------------------------------------------------------------/" << endl << endl << endl;
	system("pause");
	return 0;
}