class Singleton {
public:
    Singleton& operator=(const Singleton&) = delete;
    Singleton(const Singleton&)            = delete;

    static Singleton& GetInstance() {
        static Singleton s;
        return s;
    }
    ~Singleton() {}

private:
    Singleton() = default;
};

int main() { static Singleton s = Singleton::GetInstance(); }


