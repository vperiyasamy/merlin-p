#include "MemoryCheck.H"

MemoryCheck::MemoryCheck()
{
	b = false;
	e = false;
}

MemoryCheck::~MemoryCheck()
{
}

int
MemoryCheck::begin()
{
	b = true;
	getrusage(RUSAGE_SELF,&b_usage);
	gettimeofday(&mybegintime,NULL);
	return 0;
}

int
MemoryCheck::end()
{
	e = true;
	getrusage(RUSAGE_SELF,&e_usage);
	gettimeofday(&myendtime,NULL);
	return 0;
}

int
MemoryCheck::print(const char* pref)
{
	if (b && e)
	{
		unsigned long int t1;
		unsigned long int t2;
		t1 = b_usage.ru_maxrss;
		t2 = e_usage.ru_maxrss;
		printf("Memory usage (%s) = b: %lu, e: %lu, %lu\n",pref, t1, t2, t2-t1);

		unsigned long int bbs = mybegintime.tv_sec;
		unsigned long int bbu = mybegintime.tv_usec;
		unsigned long int ees = myendtime.tv_sec;
		unsigned long int eeu = myendtime.tv_usec;
		printf("Time usage: %s\t%lu\n", pref, (ees-bbs)*1000000 + (eeu-bbu));
	}
	b = false;
	e = false;
	return 0;
}

