#include <string>
#include <sstream>
#include <vector>

namespace ToolBox{

	template < typename T>
	std::string   toString(T x){
		std::stringstream ss;
		std::string s;

		ss << x;
		s = ss.str();
		return s;
	}

	double   toDouble(std::string str){
		double d;
		char * cstr = new char [str.length()+1];

		std::strcpy (cstr, str.c_str());
		d = std::strtod(cstr, &cstr);
		return d;
	}

	std::vector<std::string> split(std::string str, char c)
	{
		std::vector<std::string>	ret;
		size_t							s = 0;
		size_t							found = 0;

		found = str.find(c, found);
		while (found != std::string::npos)
		{
			if (found != 0)
			{
				ret.push_back (str.substr(s, found - s));
				s = found + 1;
			}
			found = str.find(c, found);
		}
		return ret;
	}

	void trim(std::string & str)
	{
		unsigned int end = 0;
		unsigned int start = 0;

		for (std::string::iterator it=str.begin(); it!=str.end(); it++)
		{
			if (*it == ' ')
				start++;
			else
				break;
		}
		for (std::string::reverse_iterator it=str.rbegin(); it!=str.rend(); it++)
		{
			if (*it == ' ')
				end++;
			else
				break;
		}
		str = str.substr(start, str.length() - end - start);
	}

	bool isdigit(std::string str)
	{
		bool point = false;
		bool in = false;

		for (std::string::iterator it=str.begin(); it!=str.end(); ++it)
		{
			if (in == false && (*it >= '0' && *it <= '9'))
				in = true;
			if (!((*it >= '0' && *it <= '9') || (*it == '.' && !point)
				|| (*it == '-' && in == false) || (*it == '+' && in == false) || *it == ' '))
				return false;
			if (*it == ' ' && *(it - 1) != '-' && *(it - 1) != '+')
				return false;
			point = (*it == '.') ? true : point;
		}
		if (!in)
			return false;
		return true;
	}

	bool  isonlyspace(std::string str)
	{
		for (std::string::iterator it=str.begin(); it!=str.end(); ++it)
		{
			if ( *it != ' ')
				return false;
		}
		return true;
	}

	void getsign(std::string & str)//parcourir le debut jusqu'au premier chiffre
	{
		bool b = false;
		char sign[2];
		unsigned int i = 0;
		std::string ret;

		ret = str;


		while ((str[i] == '+' || str[i] == '-' || str[i] == ' ') && i < str.length())
		{
			if (str[i] == '+' || str[i] == '-' )
			{
				if (b == true)
				{
					sign[1] = str[i];
					if ((sign[0] == '+' && sign[1] == '+') || (sign[0] == '-' && sign[1] == '-'))
						ret = '+' + str.substr(i + 1, str.length() - i -1);
					else
						ret = '-' + str.substr(i + 1, str.length() - i -1);
				}
				else
				{
					sign[0] = str[i];
					b = true;
				}

			}
			i++;
		}
		str = ret;
	}


}
