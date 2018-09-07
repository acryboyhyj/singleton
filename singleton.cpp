#include <iostream>
#include <mutex>

template <class T>
class Singleton {
public:
    Singleton& operator=(const Singleton&) = delete;
    Singleton(const Singleton&)            = delete;

    static T* GetInstance() {
        if (s == nullptr) {
            std::lock_guard<std::mutex> lock(m_mutex);
            if (s == nullptr) {
                s = new Singleton();
                return s;
            }
        }
    }
    ~Singleton() {}

private:
    Singleton() = default;
    static T* s;
    static std::mutex m_mutex;
};

template <class T>
std::mutex Singleton<T>::m_mutex;
template <class T>
T* Singleton<T>::s = nullptr;

class SingletonInstance : public Singleton<SingletonInstance> {};
