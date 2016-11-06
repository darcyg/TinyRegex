#pragma once
#ifndef TINYREGEXPURE
#define TINYREGEXPURE
#include"tr_type.h"
namespace tinyregex
{
	class Token
	{
	public:
		//Դ�ַ���
		const char_t * sourceStr;
		//�ַ���λ��
		StringPos strPos;
	};
	class TinyRegexPure
	{
	private:
		string_t exp;
	public:
		TinyRegexPure();
		TinyRegexPure(const string_t & str);
		//����������ʽ
		std::vector<Token> compile(const string_t &exp);
		//ת��ΪToken
		std::vector<Token> GetToken(const string_t &exp);
	};
}
#endif // !TINYREGEXPURE

