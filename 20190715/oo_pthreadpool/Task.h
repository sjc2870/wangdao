#pragma once
namespace wd{
class Task{
public:
	virtual void start() = 0;
	virtual ~Task(){}
};
}
