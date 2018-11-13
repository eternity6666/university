// 学生表 数据结构C++类声明和实现（派生类）

// sqlist.h数据结构C++类声明和实现（基类）

#define STUDENT_MAX_SIZE 100
#define STUDENTINCREMENT 10
#define random(a,b) (rand()%(b-a+1)+a)

template <typename ElemType>
class MyStudent //:public SqList<ElemType>
{
public:
	class studentNode
	{
	public:
		double student_id;
		string name;
		ElemType Chinese;
		ElemType English;
		ElemType Math;
		float average;
		ElemType Total;
	};

	//随机学生表
	void RandomStudents();

	
	void readS();

	void displayS();

	MyStudent<ElemType> operator = (MyStudent<ElemType> rightS);
	
	void getAve();

	void getTotal();


	//////////
	void clear();

	//删除第i个元素
	Status deleteStu(int i, studentNode & s);

	//取第i个元素
	Status getStu(int i, studentNode & s);

	//取顺序表存储空间的个数
	int getLength();

	//取顺序表存储空间的大小
	int getStuSize();

	//在第i个元素之前插入一个元素
	Status insertS(int i, studentNode & s);

	//判断顺序表是否为空
	bool isEmpty();

	//查找第i个与e满足compare()关系的序号
	//int locateStu(string s_name, Status(*compare)(string, string));
	int locateStu(string s_name);

	//返回某元素的后继
	Status nextStu(string s_name, studentNode & next_s);

	//返回某元素的前驱
	Status priorStu(string s_name, studentNode & prior_s);

	//在顺序表中顺序查找某元素
	//int sequentialSearch(ElemType e);

	//////////

	MyStudent();

	~MyStudent();

	MyStudent(const MyStudent<ElemType>& otherL);

protected:
	studentNode *studentElem;
	int studentSize;  //当前存储空间的大小
	int length;  //学生表当前的个数
};

template<typename ElemType>
void MyStudent<ElemType>::RandomStudents()
{
	char ch[10][10] = { "小一","小二","小三","小四","小五","小六","小七","小八","小九","小十" };
	studentElem = new studentNode[1000];
	length = 0;
	int n = random(2, 9);
	for (int i = 0; i < n; i++)
	{
		int j = random(1, 10);
		studentElem[i].student_id = i;
		studentElem[i].name = ch[j];
		studentElem[i].Chinese = random(50, 99);
		studentElem[i].Math = random(50, 99);
		studentElem[i].English = random(50, 99);
	}
	length = n;

}

template<typename ElemType>
void MyStudent<ElemType>::readS()
{
	studentElem = new studentNode[1000];
	length = 0;
	int n;
	cout << "请输入学生表中的学生人数：";
	cin >> n;
		for (int i = 0; i <n; i++)
		{
			cout << "请输入学生表第"<<i+1<<"个学生的信息" << endl;
			cout << "\t学号：";
			cin >> studentElem[i].student_id;
			cout << "\t姓名：";
			cin >> studentElem[i].name;
			cout << "\t语文：";
			cin >> studentElem[i].Chinese;
			cout << "\t英语：";
			cin >> studentElem[i].English;
			cout << "\t数学：";
			cin >> studentElem[i].Math;

			length=i+1;

			system("cls");
			displayS();
			cout << "***********************************************************" << endl << endl;
		}

	cout << endl;
}


template<typename ElemType>
void MyStudent<ElemType>::displayS()
{
	getAve();
	int i;
	if (length != 0)
	{
		cout << "当前学生表（采用顺序表存储）有" << length << "个学生" << endl << endl;
		cout << "学号\t" << "姓名\t" << "语文\t" << "英语\t" << "数学\t" << "平均分\t" << "总分" << endl;
		for (i = 0; i < length; i++)
		{
			//cout << studentElem[i].student_id;
			cout << studentElem[i].student_id << "\t" << studentElem[i].name << "\t" << studentElem[i].Chinese << "\t" << studentElem[i].English << "\t" << studentElem[i].Math << "\t" << studentElem[i].average << "\t" << studentElem[i].Total << endl;
		}
	}
	else
	{
		cout << "当前学生表为空";
	}
}

template<typename ElemType>
MyStudent<ElemType> MyStudent<ElemType>::operator = (MyStudent<ElemType> rightS)
{
	if (this != &rightS)
	{
		if (studentSize < rightS.studentSize)
		{
			delete[] studentElem;
			studentElem = new studentNode[rightS.studentSize];
			assert(studentElem != 0);
			studentSize = rightS.studentSize;
		}
		length = rightS.length;
		for (int i = 1; i <= length; ++i)
			studentElem[i - 1] = rightS.studentElem[i - 1];
	}
	return *this;
}

template<typename ElemType>
void MyStudent<ElemType>::getAve()
{
	getTotal();
	for (int i = 0; i < length; i++)
	{
		studentElem[i].average=studentElem[i].Total/3;
	}
}

template<typename ElemType>
void MyStudent<ElemType>::getTotal() 
{
	for (int i = 0; i < length; i++)
	{
		studentElem[i].Total = studentElem[i].Chinese + studentElem[i].Math + studentElem[i].English;
	}
}


//////////////////////
template<typename ElemType>
void MyStudent<ElemType>::clear()
{
	length = 0;
}

template<typename ElemType>
Status MyStudent<ElemType>::deleteStu(int i, studentNode & s)
{
	if (i<1 || i>length) return ERROR;
	s = studentElem[i - 1];
	for (int j = i + 1; j <= length; ++j)
	{
		studentElem[j - 2] = studentElem[j - 1];
	}
	--length;
	return OK;
}

template<typename ElemType>
Status MyStudent<ElemType>::getStu(int i, studentNode & s)
{
	if (i<1 || i>length) return ERROR;
	s = studentElem[i - 1];
	return OK;
}

template<typename ElemType>
int MyStudent<ElemType>::getLength()
{
	return length;
}

template<typename ElemType>
int MyStudent<ElemType>::getStuSize()
{
	return studentSize;
}

template<typename ElemType>
Status MyStudent<ElemType>::insertS(int i, studentNode & s)
{
	studentNode *newbase;
	if (i<1 || i>length + 1) return ERROR;
	if (length >= studentSize)
	{
		newbase = new studentNode[studentSize + STUDENTINCREMENT];
		assert(newbase != 0);
		for (int j = 1; j <= length; ++j)
		{
			newbase[j - 1] = studentElem[j - 1];
		}
		delete[] studentElem;
		studentElem = newbase;
		studentSize += STUDENTINCREMENT;
	}
	for (int j = length; j >= i; --j)
	{
		studentElem[j] = studentElem[j - 1];
	}
	studentElem[i - 1] = s;
	++length;
	return OK;
}

template<typename ElemType>
bool MyStudent<ElemType>::isEmpty()
{
	return length ? false : true;
}

//template<typename ElemType>
//int MyStudent<ElemType>::locateStu(string s_name, Status(*compare)(string, string))
//{
//	int i;
//	for (i = 1; i <= length && !(*compare)(studentElem[i - 1].name, s_name); ++i);
//	if (i <= length)
//		return i;
//	else
//		return 0;
//}

template<typename ElemType>
int MyStudent<ElemType>::locateStu(string s_name)
{
	int i;
	for (i = 1; studentElem[i-1].name == s_name; i++);
	if (i <= length)
		return i;
	else
		return 0;
}

template<typename ElemType>
Status MyStudent<ElemType>::nextStu(string s_name, studentNode & next_s)
{
	int i = locateStu(s_name);
	if (i < 1 || i == length)
		return ERROR;
	else
		getStu(i + 1, next_s);
	return OK;
}

template<typename ElemType>
Status MyStudent<ElemType>::priorStu(string s_name, studentNode & prior_s)
{
	int i = locateStu(s_name);
	if (i <= 1)
		return ERROR;
	else
		getStu(i - 1, prior_s);
	return OK;
}

/*
template<typename ElemType>
int SqList<ElemType>::sequentialSearch(ElemType key)
{
	int i;
	for (i = 1; i < n&&key != studentElem[i - 1]; ++1);
	if (i <= n)
		return i;
	else
		return 0;
}
*/


template<typename ElemType>
MyStudent<ElemType>::MyStudent()
{
	studentElem = new studentNode[STUDENT_MAX_SIZE];
	assert(studentElem != 0);
	studentSize = STUDENT_MAX_SIZE;
	length = 0;
}

template<typename ElemType>
MyStudent<ElemType>::MyStudent(const MyStudent<ElemType> & otherS)
{
	studentElem = new studentNode[otherS.studentSize];
	assert(studentElem != 0);
	studentSize = otherS.studentSize;
	length = otherS.length;

	for (int i = 1; i <= length; ++i)
	{
		studentElem[i - 1] = otherS.studentElem[i - 1];
	}
}

template <typename ElemType>
MyStudent<ElemType>::~MyStudent()
{
	delete[] studentElem;
}
