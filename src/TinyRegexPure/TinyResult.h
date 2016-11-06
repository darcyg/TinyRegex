#pragma once
#include"tr_type.h"
namespace tinyregex
{
	

	class TinyMatch
	{
	public:
		//Դ�ַ���
		char_t * sourceStr;
		//��������
		string_t name;
		//�������
		int id;
		//�ַ���λ��
		StringPos strPos;
		//���ı��п�ʼλ��
		TextPos strStart;
		//�ı��н���λ��
		TextPos strEnd;

	};

	class TinyResult
	{
	private:
		std::vector<TinyMatch> matchlist;
	public:
		TinyResult();
	};
}


