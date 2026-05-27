#include <iostream>

class Log
{
public: // 변수와 함수는 분리하는 스타일
	const int LogLevelError = 0;
	const int LogLevelWarn = 1;
	const int LogLevelInfo = 2;

private:
	int m_LogLevel; // class 멤버변수 private 한 놈임을 알리는 변수명

public:
	void SetLevel(int lv)
	{
		m_LogLevel = lv;
	}
	void Error(const char* msg)
	{
		if (m_LogLevel >= LogLevelError) {
			std::cout << "[ERROR]: " << msg << std::endl;
		}
	}
	void Warn(const char* msg)
	{
		if (m_LogLevel >= LogLevelWarn) {
			std::cout << "[WARN]: " << msg << std::endl;
		}
	}
	void Info(const char* msg)
	{
		if (m_LogLevel >= LogLevelInfo) {
			std::cout << "[INFO]: " << msg << std::endl;
		}
	}
};

int main(void)
{
	Log log;
	log.SetLevel(log.LogLevelWarn);
	log.Warn("Hello");
	log.Error("Hello");
	log.Info("Hello");
	std::cin.get();
}
