#include "FieldType.h"

using namespace std;

FieldFactory FieldFactory::Factory;

static string mid_tab = "    ";

static inline void Printline(ostream& out, const string& line, size_t ident) {
	string str_ident = "";
	for(size_t i = 0 ; i < ident ; i++)
		str_ident += mid_tab;

	out << str_ident << line << endl;
}

static inline void Newline(std::ostream& out) {
	out << endl;
}

FieldType::FieldType(const string& name, const string& type, const string& value_type) :
		name(name), type(type), value_type(value_type) {/* */ }

void FieldType::PrintGet(std::ostream& out) const {
	Printline(out,value_type + "  Get" + name + "() const {",2);
	Printline(out,"return GetFieldValue<" + value_type + ">(Field" + name + ");",3);
	Printline(out,"};",2);
}

void FieldType::PrintSet(std::ostream& out) const {
	Printline(out,"void Set" + name + "(const " + value_type + "& value) {",2);
	Printline(out,"SetFieldValue(Field" + name + ",value);",3);
	Printline(out,"};",2);
}

void FieldType::ReadData(std::ifstream& in) {
	/* Read data of this particular field */
	Read(in);
	/* Read the default value */
	in >> default_value;
}

std::string FieldType::GetDefaultSetter() const {
	return "Set" + name + "(" + default_value + ");";
}

FieldType::~FieldType() { /*  */ }

