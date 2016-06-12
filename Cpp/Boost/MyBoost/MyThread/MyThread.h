#ifndef __MY_LIB_MY_THREAD_H_
#define __MY_LIB_MY_THREAD_H_

#include "../MyStdAfx.h"
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>  
#include <boost/thread/once.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
using namespace boost;

namespace MMyLib
{
	class MyThread
	{
	public:
		MyThread();
		~MyThread();
		template<typename F>
		BeginThread(F func)
		{
			boost::thread t(f);
		}
	private:
		function<void()> f;
	};
};

#endif