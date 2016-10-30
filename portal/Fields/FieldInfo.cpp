#include "FieldInfo.h"

using namespace std;

Portal::FieldInfo::FieldInfo(const std::string& name, word nword, word bitpos, word length) :
	name(name), nword(nword), bitpos(bitpos), length(length), field_set(0) {

	if(bitpos > 31)
		cerr << "[@] ERROR on FieldInfo: bitpos = " << bitpos << " ; name = " << name << endl;
}

void Portal::FieldInfo::PrintDebug() const {
	cout << endl;
	cout << "name = "      << dec << name            << " ";
	cout << "nword = "     << dec << nword           << " ";
	cout << "bitpos = "    << dec << bitpos          << " ";
	cout << "length = "    << dec << length          << " ";
	cout << "field_set = " << dec << (word)field_set << endl;
}

Portal::FieldInfo* Portal::FieldInfo::CloneField() const {
	FieldInfo* ptr = Clone();
	ptr->field_set = field_set;
	return ptr;
}

namespace Portal {

	ostream& operator<<(ostream& str, Portal::FieldInfo const& data) {
		data.Print(str);
		return str;
	}

}
