#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;


struct hexwriter
{
	stringstream _numbers,_letters;
	int _start,_width,_position;


	hexwriter(int start,int width) : 
		_start(start), _width(width), _position(0)
	{
	}


	void operator()(char value)
	{
		_numbers << setw(2) << setfill('0') << hex;
		_numbers << static_cast<int>(static_cast<unsigned char>(value)) << ' ';
		_letters << (iscntrl(value)?'.':value);
		if(++_position%_width==0)
			flush();
	}


	void flush()
	{
		if(0!=_position)
		{
			cout << right << setw(8) << hex << _start << " : ";
			cout << left << setw(3*_width) << _numbers.str() << ": " << _letters.str() << endl;
			_position=0;
			_start+=_width;
		}
		_numbers.str("");
		_letters.str("");
	}
};


int main(int argc,char** argv)
{
	int first=(argc>1)?atoi(argv[1]):0;
	int last=(argc>2)?atoi(argv[2]):string::npos;
	int width=(argc>3)?atoi(argv[3]):16;


	typedef istreambuf_iterator<char> cinit;
	string buffer(cinit(cin.rdbuf()),cinit());
	buffer=buffer.substr(first,last);


	hexwriter writer(first,width);
	for_each<string::iterator,hexwriter&>(buffer.begin(),buffer.end(),writer);
	writer.flush();
}

