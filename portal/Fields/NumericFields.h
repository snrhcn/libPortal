#ifndef NUMERICFIELDS_H_
#define NUMERICFIELDS_H_

#include <iostream>
#include <ostream>
#include "FieldInfo.h"

namespace Portal {

	class ByteField : public Field<byte> {

		void PrintValue(std::ostream& str) const;

	protected:
		size_t nword;
		size_t nbyte;
		size_t offset;

	public:

		ByteField(const std::string& name, size_t nword, size_t nbyte);

		void Write(byte* raw_data) const;

		void Read(const byte* raw_data);

		FieldInfo* Clone() const;

		virtual ~ByteField();
	};

	class XByteField : public ByteField {
		void PrintValue(std::ostream& str) const;
	public:
		XByteField(const std::string& name, size_t nword, size_t nbyte);
		FieldInfo* Clone() const;
		virtual ~XByteField();
	};

	class TCPFlags : public ByteField {
		static const std::string flags[];
		void PrintValue(std::ostream& str) const;
	public:
		TCPFlags(const std::string& name, size_t nword, size_t nbyte);
		FieldInfo* Clone() const;
		virtual ~TCPFlags();
	};

	class ShortField : public Field<short_word> {

		void PrintValue(std::ostream& str) const;

	protected:
		size_t nword;
		size_t nbyte;
		size_t offset;

	public:

		ShortField(const std::string& name, size_t nword, size_t nbyte);

		void Write(byte* raw_data) const;

		void Read(const byte* raw_data);

		FieldInfo* Clone() const;

		virtual ~ShortField();
	};

	class ShortHostField : public Field<short_word> {

		void PrintValue(std::ostream& str) const;

	protected:
		size_t nword;
		size_t nbyte;
		size_t offset;

	public:

		ShortHostField(const std::string& name, size_t nword, size_t nbyte);

		void Write(byte* raw_data) const;

		void Read(const byte* raw_data);

		FieldInfo* Clone() const;

		virtual ~ShortHostField();
	};

	class ShortHostNetField : public ShortHostField {
	public:
		void Read(const byte* raw_data);
		ShortHostNetField(const std::string& name, size_t nword, size_t nbyte);
		FieldInfo* Clone() const;
		virtual ~ShortHostNetField();
	};

	class XShortField : public ShortField {
		void PrintValue(std::ostream& str) const;
	public:
		XShortField(const std::string& name, size_t nword, size_t nbyte);
		FieldInfo* Clone() const;
		virtual ~XShortField();
	};

	class WordField : public Field<word> {

		void PrintValue(std::ostream& str) const;

	protected:
		size_t nword;
		size_t nbyte;
		size_t offset;

	public:

		WordField(const std::string& name, size_t nword, size_t nbyte);

		void Write(byte* raw_data) const;

		void Read(const byte* raw_data);

		FieldInfo* Clone() const;

		virtual ~WordField();
	};

	class WordHostField : public Field<word> {

		void PrintValue(std::ostream& str) const;

	protected:
		size_t nword;
		size_t nbyte;
		size_t offset;

	public:

		WordHostField(const std::string& name, size_t nword, size_t nbyte);

		void Write(byte* raw_data) const;

		void Read(const byte* raw_data);

		FieldInfo* Clone() const;

		virtual ~WordHostField();
	};

	class XWordField : public WordField {
		void PrintValue(std::ostream& str) const;
	public:
		XWordField(const std::string& name, size_t nword, size_t nbyte);
		FieldInfo* Clone() const;
		virtual ~XWordField();
	};

	class Int64Field : public Field<uint64_t> {

		void PrintValue(std::ostream& str) const;

	protected:
		size_t nword;
		size_t nbyte;
		size_t offset;

	public:

		Int64Field(const std::string& name, size_t nword, size_t nbyte);

		void Write(byte* raw_data) const;

		void Read(const byte* raw_data);

		FieldInfo* Clone() const;

		virtual ~Int64Field();
	};

}

#endif /* NUMERICFIELDS_H_ */
