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
		template <typename F>
		MyThread(F func): f(func)
		{
			m_pThread = new boost::thread(f);
		};
		~MyThread(){};
	private:
		function<void()> f;
		boost::thread *m_pThread;
	};
};

#endif