#include "MyThread.h"

void MMyLib::IMyThread::Join()
{
	m_pThread->join();
}
