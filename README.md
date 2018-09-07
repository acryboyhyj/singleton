    class Singleton {
    public:
        Singleton& operator=(const Singleton&) = delete;
        Singleton(const Singleton&)            = delete;

        static Singleton* GetInstance() {
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
        static Singleton* s;
        static std::mutex m_mutex;
    };

    std::mutex Singleton::m_mutex;
    Singleton* Singleton::s = nullptr;
    int main() { static Singleton* s = Singleton::GetInstance(); }


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

        int main() { static Singleton& s = Singleton::GetInstance(); }
    

