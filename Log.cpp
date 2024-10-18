#include <iostream>

class Log {
    public:
        enum Level {
            LevelError = 0,
            LevelWarning,
            LevelInfo,
            LevelDebug
        };
    private:
        int m_LogLevel = LevelInfo;
    public:
        void SetLogLevel(int level) {
            m_LogLevel = level;
        }
        void Error(const char* message) {
            if (m_LogLevel >= LevelError) {
                std::cout << "Error: " << message << std::endl;
            }
        }
        void Warning(const char* message) {
            if (m_LogLevel >= LevelWarning) {
                std::cout << "Warning: " << message << std::endl;
            }
        }
        void Info(const char* message) {
            if (m_LogLevel >= LevelInfo) {
                std::cout << "Info: " << message << std::endl;
            }
        }
        void Debug(const char* message) {
            if (m_LogLevel >= LevelDebug) {
                std::cout << "Debug: " << message << std::endl;
            }
        }   
};

int main() {
    Log log;
    log.SetLogLevel(Log::LevelDebug);
    log.Error("This is an error message");
    log.Warning("This is a warning message");
    log.Info("This is an info message");
    log.Debug("This is a debug message");
    return 0;
}