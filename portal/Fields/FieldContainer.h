#ifndef FIELDCONTAINER_H_
#define FIELDCONTAINER_H_

#include <iostream>
#include <ostream>
#include <cassert>
#include <vector>
#include <set>

#include "FieldInfo.h"
#include "../Types.h"

namespace Portal {

	class FieldContainer : public std::vector<FieldInfo*> {

		/* Flag if the Container support overlapped fields */
		byte overlaped_flag;
		/* Set of active fields (only used on containers that supports overlapped fields) */
		std::set<size_t> ActiveFields;

	public:
		/* Constructor */
		FieldContainer();

		/* Copy Constructor (clone the fields) */
		FieldContainer(const FieldContainer& fc);
		/* Assignment operator */
		FieldContainer& operator=(const FieldContainer& right);

		/* No argument, any type of return value (apply to active fields) */
		template<class R>
		void Apply(R (FieldInfo::*f)());
		template<class R>
		void Apply(R (FieldInfo::*f)() const);
		/* Apply to all fields no matter if is active or not */
		template<class R>
		void ApplyAll(R (FieldInfo::*f)());
		template<class R>
		void ApplyAll(R (FieldInfo::*f)() const);

		/* One argument, any type of return value (apply to active fields) */
		template<class R, class A>
		void Apply(R(FieldInfo::*f)(A), A a);
		template<class R, class A>
		void Apply(R(FieldInfo::*f)(A) const, A a);
		/* Apply to all fields no matter if is active or not */
		template<class R, class A>
		void ApplyAll(R(FieldInfo::*f)(A), A a);
		template<class R, class A>
		void ApplyAll(R(FieldInfo::*f)(A) const, A a);

		/* Set a field (and put on 1 the set flag) */
		template<class R>
		void SetField(size_t nfield, const R& value);
		/* Just set a field */
		template<class R>
		void SetResetField(size_t nfield, const R& value);

		/* Get Value of a field */
		template<class R>
		R GetField(size_t nfield) const;

		/* Set overlapped field */
		void SetOverlap(byte flag) {overlaped_flag = flag;};
		byte GetOverlap() const {return overlaped_flag;};

		/* Function that set a field as active */
		void SetActive(size_t nfield);

		/* Print the fields */
		void Print(std::ostream& str = std::cout) const;

		virtual ~FieldContainer();
	};

}


template<class R>
void Portal::FieldContainer::ApplyAll(R (FieldInfo::*f)()) {
	/* Apply the function to every field */
	iterator it = begin();
	while(it != end()) {
		((*it)->*f)();
		it++;
	}
}

template<class R>
void Portal::FieldContainer::Apply(R (FieldInfo::*f)()) {
	if(!overlaped_flag) {
		/* Apply the function to every field */
		iterator it = begin();
		while(it != end()) {
			((*it)->*f)();
			it++;
		}
	} else {
		/* Just apply the function to the active fields */
		std::set<size_t>::iterator it_active;

		for (it_active = ActiveFields.begin() ; it_active != ActiveFields.end() ; ++it_active)
			((*this)[*it_active]->*f)();
	}
}

template<class R>
void Portal::FieldContainer::ApplyAll(R (FieldInfo::*f)() const ) {
	/* Apply the function to every field */
	iterator it = begin();
	while(it != end()) {
		((*it)->*f)();
		it++;
	}
}

template<class R>
void Portal::FieldContainer::Apply(R (FieldInfo::*f)() const) {
	if(!overlaped_flag) {
		/* Apply the function to every field */
		iterator it = begin();
		while(it != end()) {
			((*it)->*f)();
			it++;
		}
	} else {
		/* Just apply the function to the active fields */
		std::set<size_t>::iterator it_active;

		for (it_active = ActiveFields.begin() ; it_active != ActiveFields.end() ; ++it_active)
			((*this)[*it_active]->*f)();
	}
}

template<class R, class A>
void Portal::FieldContainer::ApplyAll(R(FieldInfo::*f)(A), A a) {
	iterator it = begin();
	while(it != end()) {
		((*it)->*f)(a);
		it++;
	}
}

template<class R, class A>
void Portal::FieldContainer::Apply(R(FieldInfo::*f)(A), A a) {
	if(!overlaped_flag) {
		iterator it = begin();
		while(it != end()) {
			((*it)->*f)(a);
			it++;
		}
	} else {
		/* Just apply the function to the active fields */
		std::set<size_t>::iterator it_active;

		for (it_active = ActiveFields.begin() ; it_active != ActiveFields.end() ; ++it_active)
			((*this)[*it_active]->*f)(a);
	}
}

template<class R, class A>
void Portal::FieldContainer::ApplyAll(R(FieldInfo::*f)(A) const, A a) {
	const_iterator it = begin();
	while(it != end()) {
		((*it)->*f)(a);
		it++;
	}
}

template<class R, class A>
void Portal::FieldContainer::Apply(R(FieldInfo::*f)(A) const, A a) {
	if(!overlaped_flag) {
		const_iterator it = begin();
		while(it != end()) {
			((*it)->*f)(a);
			it++;
		}
	} else {
		/* Just apply the function to the active fields */
		std::set<size_t>::iterator it_active;

		for (it_active = ActiveFields.begin() ; it_active != ActiveFields.end() ; ++it_active)
			((*this)[*it_active]->*f)(a);
	}
}

template<class R>
void Portal::FieldContainer::SetField(size_t nfield, const R& value) {
	/* Set the field flag */
	(*this)[nfield]->FieldSet();

	if(overlaped_flag)
		/* We should handle the case that this field is overlapping others fields */
		SetActive(nfield);

	/* And set the field */
	SetResetField(nfield,value);
}

template<class R>
void Portal::FieldContainer::SetResetField(size_t nfield, const R& value) {
	/* Get pointer of the field */
	FieldInfo* ptr = (*this)[nfield];
	dynamic_cast<Field<R>* >(ptr)->SetField(value);
}

template<class R>
R Portal::FieldContainer::GetField(size_t nfield) const {
	const FieldInfo* ptr = (*this)[nfield];
	return dynamic_cast<const Field<R>* >(ptr)->GetField();
}

#endif /* FIELDCONTAINER_H_ */
