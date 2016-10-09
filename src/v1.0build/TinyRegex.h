#pragma once
#include"tr_type.h"
#include"TinyResult.h"
namespace tinyregex
{
	//���ڱ�ʾ�ظ�
	class Repeat
	{
	public:
		Repeat():start(1),end(2),isPositive(true){}
		Repeat(int s, int e, bool ip):start(s), end(e), isPositive(ip) {}
		int start;
		int end;	//��β
		bool isPositive;
	};
	//��ʾһ���ַ��������
	class Token
	{
	public:
		string_t content;
		int priority;
		bool isOperator;
		Repeat repeat;
	};

	inline Token make_token(const string_t &content,int priority,bool isOperator )
	{
		Token temp;
		temp.content = content;
		temp.priority = priority;
		temp.isOperator = isOperator;
		return temp;
	}
	//���ַ�ת����
	inline int wctoi(wchar_t c)
	{
		int wi[10] = { 0,1,2,3,4,5,6,7,8,9 };
		if (c>=L'0'&&c<=L'9')
		{
			return wi[c-L'0'];
		}
		else
		{
			return -1;
		}
	}
	//�ַ�ת����
	inline int wctoi(char c)
	{
		int wi[10] = { 0,1,2,3,4,5,6,7,8,9 };
		if (c >= '0'&&c <= '9')
		{
			return wi[c - '0'];
		}
		else
		{
			return -1;
		}
	}
	//��ʾһ���������ַ�����
	class CharRange
	{
	public:
		char_t start;
		char_t end;
	};
	//������ʽ����
	class TinyRegex
	{
	private:
		string_t pattern;
		std::vector<CharRange> genCharSetTable;
	public:
		TinyRegex();
		TinyRegex(const string_t &p);
		void assign(const string_t &p);
		~TinyRegex();
	private:
		std::vector<Token> regexParse();
		void genCharSetTable(const std::vector<CharRange> &charrange,const std::vector<Token> &re);
		inline void addAnd(int &i, int &envNum, std::vector<Token> & operatorStack, std::vector<Token> &ans);
	};

	bool regex_match(const string_t &source,const TinyRegex &pattern,TinyResult & result);
}

