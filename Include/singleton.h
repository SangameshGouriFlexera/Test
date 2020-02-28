#pragma once

/////////////////////////////////////////////////////////////////////
// CSingleton
// Template class for wrapping any ordinary class to make it a singleton
//
// T:	Class that you want to use as a singleton
/////////////////////////////////////////////////////////////////////
template<class T>
class CSingleton : public T
{
public:
	static CSingleton* Instance()
	{
		if(_instance==0)
		{
			_instance = new CSingleton();
		}
		return _instance;
	}
	~CSingleton()
	{
		_instance = 0;
	}
protected:
	CSingleton(){};

private:
	static CSingleton* _instance;
};
