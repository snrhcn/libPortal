#include "Dot1Q.h"

using namespace Portal;
using namespace std;

void Dot1Q::ReDefineActiveFields() {
}

void Dot1Q::Portal() {
}

void Dot1Q::ParseLayerData(ParseInfo* info) {
	short_word next_type = GetType();
	info->next_layer = Protocol::AccessFactory()->GetLayerByID(next_type);
}
