#include "FieldContainer.h"

using namespace std;
using namespace Portal;

FieldContainer::FieldContainer() {
	/* By default, there aren't overlapped fields */
	overlaped_flag = 0;
}

FieldContainer::FieldContainer(const FieldContainer& fc) {
	const_iterator it;

	overlaped_flag = fc.overlaped_flag;
	ActiveFields = fc.ActiveFields;

	/* Clone each field of the container */
	for(it = fc.begin() ; it < fc.end() ; it++)
		push_back((*it)->CloneField());
}

void FieldContainer::SetActive(size_t nfield) {
	std::set<size_t> OverlappedFields;

	/* Get the field pointer */
	FieldInfo* ptr = (*this)[nfield];

	/* First, check if the field is active */
	if(ActiveFields.find(nfield) == ActiveFields.end()) {
		/* If the field is not active, it may overlap some other field */
		std::set<size_t>::iterator it_active;

		for (it_active = ActiveFields.begin() ; it_active != ActiveFields.end() ; ++it_active) {
			FieldInfo* FieldPtr = (*this)[(*it_active)];
			/* Get information of the active fields */
			size_t nword = FieldPtr->GetWord();

			/* Check if the fields are in the same word */
			if (ptr->GetWord() == nword) {
				size_t bitpos = FieldPtr->GetBit();
				size_t endpos = FieldPtr->GetEnd();

				/* Check intersection */
				if  ( ( (ptr->GetBit() >= bitpos) && (ptr->GetBit() < endpos) ) ||
					  ( (ptr->GetEnd() >  bitpos) && (ptr->GetEnd() <= endpos) )  ) {
					OverlappedFields.insert(*it_active);
				}

			}
		}
		/* And push it into the active fields set */
		ActiveFields.insert(nfield);
	}

	/* Remove overlapped fields, if any */
	std::set<size_t>::iterator it_over;

	for (it_over = OverlappedFields.begin() ; it_over != OverlappedFields.end() ; ++it_over)
		ActiveFields.erase(*it_over);

}

FieldContainer& FieldContainer::operator=(const FieldContainer& right) {
	const_iterator it;

	/* Delete each field of the container */
	for(it = begin() ; it < end() ; it++)
		delete (*it);

	clear();

	/* Clone each field of the container */
	for(it = right.begin() ; it < right.end() ; it++)
		push_back((*it)->CloneField());

	overlaped_flag = right.overlaped_flag;
	ActiveFields = right.ActiveFields;

	return *this;
}

FieldContainer::~FieldContainer() {
	iterator it;

	/* Delete each field of the container */
	for(it = begin() ; it < end() ; it++)
		delete (*it);
}

void FieldContainer::Print(std::ostream& str) const {
	if(!overlaped_flag) {
		const_iterator it;

		/* Delete each field of the container */
		for(it = begin() ; it < end() ; it++)
			str << *(*it) << " , ";

	} else {
		/* Just apply the function to the active fields */
		set<size_t>::const_iterator it_active;

		for (it_active = ActiveFields.begin() ; it_active != ActiveFields.end(); ++it_active)
			str << *(*this)[*it_active] << " , ";
	}

}
