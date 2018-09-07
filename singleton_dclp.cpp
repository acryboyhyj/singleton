#include <iostream>
#include <mutex>

template <typename T>
class Singleton {
public:
    static T& Instance() {
        if (m_pInstance == NULL) {
            std::lock_guard<std::mutex> lock(m_mutex);
            if (m_pInstance == NULL) {
                m_pInstance = new T();
            }
            return *m_pInstance;
        }
        return *m_pInstance;
    }

protected:
    Singleton() {}
    ~Singleton() {}

private:
    Singleton(const Singleton& rhs) {}
    Singleton& operator=(const Singleton& rhs) {}

    static T* m_pInstance;
    static std::mutex m_mutex;
};

template <typename T>
T* Singleton<T>::m_pInstance = NULL;

static std::mutex m_mutex;

int main() {
    static int& s = Singleton<int>::Instance();
    return 0;
}
