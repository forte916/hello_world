#include <algorithm>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>


using namespace std;


void show_char(char c) { cout << (isprint(c) ? c : '.'); }
void show_hex(char c) { cout << setw(2) << (c & 0xff) << ' '; }


int main(int argc, char** argv) {
	try {
		if (argc != 5)
			throw invalid_argument("Usage: hexdump <file> <start> <end> <width>");
		ifstream in(argv[1], ios::binary);
		if (! in)
			throw invalid_argument("File not found");
		size_t pos(strtoul(argv[2], 0, 0)), end(strtoul(argv[3], 0, 0)), width(strtoul(argv[4], 0, 0));
		if (end < pos || width < 1)
			throw invalid_argument("Invalid arguments");
		in.seekg(pos);
		if (! in)
			throw invalid_argument("Start position is past end of file");
		vector<char> buf(width);
		cout << hex << setfill('0');
		for (; in && pos < end; pos += width) {
			in.read(&buf[0], min(end - pos, width));
			size_t bytes(in.gcount());
			if (bytes) {
				cout << setw(8) << pos << " : ";
				for_each(&buf[0], &buf[bytes], show_hex);
				cout << string(3 * (width - bytes), ' ') << ": ";
				for_each(&buf[0], &buf[bytes], show_char);
				cout << '\n';
			}
		}
		return 0;
	}
	catch (const exception& ex) {
		cerr << "*** " << ex.what() << '\n';
		return 1;
	}
}

