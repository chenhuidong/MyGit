#include "MyThread.h"

void MMyLib::MyThread::Join()
{
	m_pThread->join();
}
