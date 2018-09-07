#include <iostream>
#include <mutex>

template <class T>
class Singleton {
public:
    Singleton& operator=(const Singleton&) = delete;
    Singleton(const Singleton&)            = delete;

    static T& GetInstance() {
        static T instance;
        return instance;
    }
    virtual ~Singleton() = default;

protected:
    Singleton() = default;
};

class SingletonInstance : public Singleton<SingletonInstance> {
    friend class Singleton<SingletonInstance>;

public:
    void SetValue(int value) { value = m_value; }
    void Print() { std::cout << m_value; }

private:
    SingletonInstance() {}

    ~SingletonInstance() {}

    int m_value;
};

int main() {
    static SingletonInstance& s = Singleton<SingletonInstance>::GetInstance();
    s.SetValue(12);
    s.Print();
    return 0;
}
