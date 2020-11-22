#pragma once
#include <type_traits>

template<typename T>
class Singleton
{
private:
    static inline T* singleton = nullptr;
    struct Instance : public T {
        Instance() : T() {}
    };
protected:
    Singleton() noexcept = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    virtual ~Singleton() = default;

public:
    static T* GetInstance() noexcept(std::is_nothrow_constructible<T>::value)
    {
        if (singleton == nullptr)
        {
            singleton = new Instance();
        }
        return singleton;
    }
};