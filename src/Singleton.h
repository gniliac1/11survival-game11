#pragma once

template <class T>
/**
 * \brief This class implements a Singleton
 */
class Singleton
{

protected:

	static T *singleton;    //!< pointer to an instance, that should be accessible from everywhere in the code

public:

	virtual ~Singleton() {  }

	/**
	 * \brief   creates an instance of type T, if there exists none,
	 *          otherwise returns a pointer to the existing instance
	 * \return  one single instance of T, that is accessible from everywhere in the code
	 */
	static T* Get() {
		// does an instance already exist?
		if (!singleton) {
			// no -> create new instance
			singleton = new T;
		}

		// yes -> return pointer to that instance
		return singleton;

	}

	/**
	 * \brief free the dynamic allocated memory
	 */
	static void Del() {
		// if there was an instance
		if (singleton) {
			// delete it
			delete singleton;
			singleton = nullptr;
		}

	}

};

// initialize the static member variable
template <class T>
T* Singleton<T>::singleton = nullptr;
