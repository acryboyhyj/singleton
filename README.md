  1.dclp,new singleton会有错.编译器将指令重排  
    _instance = // Step 3
    
   operator new(sizeof(Singleton)); // Step 1
     
    new (_instance) Singleton; // Step 2
    
    
     
  线程A执行31后中断，此时s不是空指针，都是指向内存没有正确初始化,不完全对象
    
    
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
    int main() { 
        static Singleton* s = Singleton::GetInstance();
        return 0;
     }




2.meyer's，使用局部静态变量
但是作为保护,删除了拷贝构造，无法返回1个引用.
    
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
    

