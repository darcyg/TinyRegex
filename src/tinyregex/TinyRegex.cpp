#include "TinyRegex.h"


namespace tinyregex
{
	TinyRegex::TinyRegex()
	{
	}

	tinyregex::TinyRegex::TinyRegex(const string_t & p)
		:pattern(p)
	{
		//������ʽ
		out = regexParse();
	}

	void TinyRegex::assign(const string_t & p)
	{
		if (p != pattern)
		{
			pattern = p;
			out=regexParse();
		}
	}


	TinyRegex::~TinyRegex()
	{
	}

	//����Ϊ�﷨��
	ExpPtr TinyRegex::regexParse()
	{
		TinyRegexParser par;
		char_t * start = &*(pattern.begin());
		ExpPtr root = par.Parse(start);
		return root;
	}
	






	bool regex_match(const string_t & source, const TinyRegex & pattern, TinyResult & result)
	{
		return false;
	}

}
