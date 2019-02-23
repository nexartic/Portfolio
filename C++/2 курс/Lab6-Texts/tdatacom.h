#ifndef __DATACOM_H__
#define __DATACOM_H__

#define TextOK   0
#define TextErr -1
#define TextNoDown -2
#define TextNoNext -3
#define TextNoPrev -4


// TDataCom €вл€етс€ общим базовым классом
class TDataCom
{
protected:
	int RetCode; //  од завершени€

	int SetRetCode(int ret)
	{
		return RetCode = ret;
	}
public:
	TDataCom() : RetCode(TextOK) {}
    virtual ~TDataCom() {};
	int GetRetCode()
	{
		int temp = RetCode;
		RetCode = TextOK;
		return temp;
	}
};

#endif
