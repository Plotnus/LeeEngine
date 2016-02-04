#pragma once

class Application
{
	virtual void InitApplication() = 0;

	virtual void QuitApplication() = 0;
protected:
	bool bIsInitialized;
};