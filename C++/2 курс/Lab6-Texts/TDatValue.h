#ifndef _DAT_VALUE_
#define _DAT_VALUE_

class TDatValue;
typedef TDatValue *PTDatValue;

class TDatValue {
public:
    virtual TDatValue* GetCopy() = 0;
    ~TDatValue() {}
};

#endif 