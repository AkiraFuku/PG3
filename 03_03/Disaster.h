#pragma once
class Disaster
{
public:
	Disaster();
	~Disaster() ;

	virtual void warn();
protected:
	const char* name_;

};

