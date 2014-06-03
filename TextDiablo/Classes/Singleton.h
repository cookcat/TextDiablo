#ifndef __SINGLETON_H__
#define __SINGLETON_H__

template <class T> 
class Singleton 
{ 
public: 
	static inline T& instance() 
	{ 
		static T _instance; 
		return _instance; 
	} 

protected: 
	Singleton(void){}; 
	~Singleton(void){}; 

	Singleton(const Singleton<T>&){}; 
	Singleton<T>& operator= (const Singleton<T> &){}; 
};

#endif 