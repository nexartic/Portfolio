#ifndef DAT_VALUE_H
#define DAT_VALUE_H

class TDatValue;
typedef TDatValue *PTDatValue;

class TDatValue 
{
public:
	TDatValue() = default;
	virtual TDatValue* GetCopy() = 0; // создание копии
	~TDatValue() = default;
};

#endif
