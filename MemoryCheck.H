#ifndef _MEMCHECK
#define _MEMCHECK

#include <sys/resource.h>
#include <sys/time.h>
#include <stdio.h>

class MemoryCheck
{
public:
	MemoryCheck();
	~MemoryCheck();
	int begin();
	int end();
	int print(const char*);
private:
	bool b;
	bool e;
	struct rusage b_usage;
	struct rusage e_usage;
	struct timeval mybegintime;
	struct timeval myendtime;
};

#endif //_MEMCHECK
